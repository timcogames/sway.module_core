pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                git url: 'https://github.com/timcogames/sway.module_core.git', branch: 'master'
                sh 'mkdir -p build'
                dir('./build') {
                    sh '/opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -DMODULE_CORE_ENABLE_TESTS=ON ../'
                    sh '/opt/homebrew/bin/cmake --build ./'
                }
            }
        }
    }
}
