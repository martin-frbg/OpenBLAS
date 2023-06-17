pipeline {
    agent { 
        docker {
            alwaysPull true
            image 'osuosl/ubuntu-s390x'
            label 'osuosl/ubuntu-s390x'
        }
    }
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
