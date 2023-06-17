pipeline {
    agent any

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
