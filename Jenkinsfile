pipeline {
    agent any
    
    environment {
        BUILD_DIR = 'build'
        SOURCE_DIR = '.'
        GCOV_DIR = 'coverage_report'
        CMAKE_EXECUTABLE = '/usr/bin/cmake'
    }
    
    stages {
        stage('Checkout SCM') {
            steps {
                // Checkout the code from your GitHub repository
                git 'https://github.com/Trivedha33/Build_Job_C-.git'
            }
        }
        
        stage('Clean Workspace') {
            steps {
                sh '''
                    rm -rf ${BUILD_DIR}
                    rm -rf ${GCOV_DIR}
                    mkdir -p ${BUILD_DIR}
                '''
            }
        }
        
        stage('Configure') {
            steps {
                dir(BUILD_DIR) {
                    sh '''
                        ${CMAKE_EXECUTABLE} -DCMAKE_BUILD_TYPE=Debug \
                            -DCMAKE_CXX_FLAGS="--coverage -fprofile-arcs -ftest-coverage" \
                            -DCMAKE_EXE_LINKER_FLAGS="--coverage -fprofile-arcs -ftest-coverage" \
                            ${WORKSPACE}/${SOURCE_DIR}
                    '''
                }
            }
        }
        
        stage('Build') {
            steps {
                dir(BUILD_DIR) {
                    sh 'cmake --build . -- -j$(nproc)'
                }
            }
        }
        
        stage('Test') {
            steps {
                dir(BUILD_DIR) {
                    sh 'ctest --output-on-failure'
                }
            }
        }
        
        stage('Generate Coverage') {
            steps {
                sh 'mkdir -p ${GCOV_DIR}'
                
                sh '''
                    lcov --capture --directory ${BUILD_DIR} --output-file ${GCOV_DIR}/coverage.info
                    lcov --remove ${GCOV_DIR}/coverage.info '/usr/include/*' '/usr/lib/*' '*/tests/*' --output-file ${GCOV_DIR}/filtered_coverage.info
                    genhtml ${GCOV_DIR}/filtered_coverage.info --output-directory ${GCOV_DIR}/html
                '''
                
                archiveArtifacts artifacts: "${GCOV_DIR}/**/*", fingerprint: true
                
                publishHTML(target: [
                    allowMissing: false,
                    alwaysLinkToLastBuild: false,
                    keepAll: true,
                    reportDir: "${GCOV_DIR}/html",
                    reportFiles: 'index.html',
                    reportName: 'Coverage Report'
                ])
            }
        }
    }
    
    post {
        always {
            cleanWs(patterns: [[pattern: '**/*.gcda', type: 'INCLUDE'],
                             [pattern: '**/*.gcno', type: 'INCLUDE']])
        }
        
        success {
            echo 'Pipeline completed successfully!'
        }
        
        failure {
            echo 'Pipeline failed! Check the logs for details.'
        }
    }
}
