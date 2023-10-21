def BooleanToStr(value) {
    return (value) ? "ON" : "OFF"
}

node {
    def SELECTED_BRANCH = "develop"

    stage("Clone repository") {
        SELECTED_BRANCH = input(message: "Select active branch", parameters: [
            [$class: "ChoiceParameterDefinition", 
                choices: "origin/master\ndevelop", 
                name: "Active branch", 
                description: "Select option the relevant branch"]
        ])

        git url: "https://github.com/timcogames/sway.module_core.git", branch: "${SELECTED_BRANCH}"
        sh "git submodule update --init --recursive"
    }

    def APPLIED_THIRD_PARTY_DIR = ""
    def APPLIED_GOOGLE_TEST_ROOT_DIR = ""
    def ENABLED_GOOGLE_TESTS = "ON"
    def ENABLED_COVERAGE = "OFF"

    stage("Build options") {
        def options = input(message: "Build options", ok: "Run", parameters: [
            // choice(name: "BUILD_TYPE", choices: "Release\nDebug", description: "Select build type"),
            string(name: "THIRD_PARTY_DIR", defaultValue: "/Users/<USER_NAME>/Documents/Third-party", description: ""),
            booleanParam(name: "GOOGLE_TESTS", defaultValue: true, description: ""),
            booleanParam(name: "COVERAGE", defaultValue: false, description: "")
        ])

        APPLIED_THIRD_PARTY_DIR = options["THIRD_PARTY_DIR"]
        APPLIED_GOOGLE_TEST_ROOT_DIR = "${APPLIED_THIRD_PARTY_DIR}/googletest"
        ENABLED_GOOGLE_TESTS = options["GOOGLE_TESTS"]
        ENABLED_COVERAGE = options["COVERAGE"]
    }

    stage("Build") {
        git url: "https://github.com/timcogames/sway.module_core.git", branch: "${SELECTED_BRANCH}"
        sh "mkdir -p build"
        dir("./build") {
            sh "/opt/homebrew/Cellar/cmake/3.22.1/bin/cmake \
                -DCMAKE_BUILD_TYPE=${SELECTED_BRANCH == "origin/master" ? "Release" : "Debug"} \
                -DGLOB_GTEST_ROOT_DIR=${APPLIED_GOOGLE_TEST_ROOT_DIR} \
                -DMODULE_CORE_ENABLE_TESTS=${BooleanToStr(ENABLED_GOOGLE_TESTS)} \
                -DMODULE_CORE_ENABLE_COVERAGE=${BooleanToStr(ENABLED_COVERAGE)} ../"
            sh "/opt/homebrew/bin/cmake --build ./"
        }
    }

    stage("Tests") {
        if (ENABLED_GOOGLE_TESTS) {
            dir("./bin") {
                if (SELECTED_BUILD_TYPE == "debug") {
                    sh "./dbg/module_core_tests"
                } else {
                    sh "./module_core_tests"
                }
            }
        } else {
            println "echo Tests is disabled"
        }
    }

    stage("Codecov") {
        if (ENABLED_COVERAGE && SELECTED_BRANCH == "master") {
            sh "/opt/homebrew/opt/lcov/bin/lcov --directory ./build/ --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1"
            sh "/opt/homebrew/opt/lcov/bin/genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/"
            publishHTML(target: [
                allowMissing: false,
                alwaysLinkToLastBuild: false,
                keepAll: true,
                reportDir: "code_coverage_report",
                reportFiles: "index.html",
                reportName: "LCov Report"
            ])

            withCredentials([string(credentialsId: "MODULE_CORE_CODECOV_TOKEN", variable: "CODECOV")]) {
                sh "curl -s https://codecov.io/bash | bash -s - -t $CODECOV || echo \"Codecov failed to upload\""
            }
        }
    }
}
