pipeline {
    agent { 
        docker {
            image 'osuosl/ubuntu-s390x'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'make clean && make'
            }
        }
        stage('CMakeBuild') {
            steps {
                sh 'make clean && mkdir build && cd build && cmake -DDYNAMIC_ARCH=1 .. && make'
            }
        }
    }
}
