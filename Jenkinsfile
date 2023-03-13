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

                recordCoverage(tools: [[parser: 'JACOCO']],
                    id: 'jacoco', name: 'JaCoCo Coverage',
                    sourceCodeRetention: 'EVERY_BUILD',
                    qualityGates: [
                        [threshold: 60.0, metric: 'LINE', baseline: 'PROJECT', unstable: true],
                        [threshold: 60.0, metric: 'BRANCH', baseline: 'PROJECT', unstable: true]
                    ]
                )
            }
        }
    }
}
