pipeline {
    agent docker

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
