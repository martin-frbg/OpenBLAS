pipeline {
    agent dockerfile osuosl/ubuntu-s390x

    stages {
        stage('Build') {
            steps {
                make
            }
        }

node {
        stage('Build') {
            make
        }
}
