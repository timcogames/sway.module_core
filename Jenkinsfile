node {
    stage('Build') {
        git url: 'https://github.com/timcogames/sway.module_core.git', branch: 'master'
        sh 'mkdir -p build'
        dir('./build') {
            sh '/opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -DCUSTOM_GTEST_ROOT_DIR=/Users/apriori85/Documents/Third-party/googletest -DMODULE_CORE_ENABLE_TESTS=ON -DMODULE_CORE_ENABLE_COVERAGE=ON ../'
            sh '/opt/homebrew/bin/cmake --build ./'
        }

        sh '/opt/homebrew/opt/lcov/bin/lcov --directory ./build/ --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1'
        sh '/opt/homebrew/opt/lcov/bin/genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/'
        publishHTML(target: [
            allowMissing: false,
            alwaysLinkToLastBuild: false,
            keepAll: true,
            reportDir: 'code_coverage_report',
            reportFiles: 'index.html',
            reportName: "LCov Report"
        ])

        withCredentials([string(credentialsId: 'CODECOV_TOKEN', variable: 'CODECOV')]) {
            sh 'curl -s https://codecov.io/bash | bash -s - -t $CODECOV || echo "Codecov failed to upload"'
        }
    }
}
