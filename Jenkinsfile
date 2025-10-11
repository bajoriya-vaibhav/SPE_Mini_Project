pipeline {
    agent any

    environment {
        IMAGE_NAME = "spe_mini_calculator"
        IMAGE_TAG = "latest"
        EMAIL_ID_TO_SEND = "vaibhav.bajoriya@iiitb.ac.in"
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/bajoriya-vaibhav/SPE_Mini_Project.git'
            }
        }

        stage('Build') {
            steps {
                sh 'make clean && make'
            }
        }

        stage('Test') {
            steps {
                sh 'make test'
            }
        }

        stage('Docker Build & Push') {
            steps {
                // Use withCredentials to safely handle DockerHub secrets
                withCredentials([usernamePassword(credentialsId: 'dockerhub-creds', 
                                                  usernameVariable: 'DOCKERHUB_USER', 
                                                  passwordVariable: 'DOCKERHUB_PASS')]) {
                    script {
                        def DOCKER_IMAGE = "${DOCKERHUB_USER}/${IMAGE_NAME}:${IMAGE_TAG}"

                        // Ensure Buildx is available
                        sh 'docker buildx version || echo "Buildx not found, using legacy builder"'

                        // Docker build
                        sh "docker build -t ${DOCKER_IMAGE} ."

                        // Docker login & push
                        sh "echo $DOCKERHUB_PASS | docker login -u $DOCKERHUB_USER --password-stdin"
                        sh "docker push ${DOCKER_IMAGE}"
                    }
                }
            }
        }

        stage('Deploy with Ansible') {
            steps {
                sh 'ansible-playbook -i ansible/inventory.ini ansible/playbook.yml'
            }
        }
    }

    post {
        success {
            echo "Successfully executed the pipeline"
            emailext(
                to: "${EMAIL_ID_TO_SEND}",
                subject: "SUCCESS: Pipeline ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """
                <b>Build successful!</b><br>
                Job: ${env.JOB_NAME}<br>
                Build Number: ${env.BUILD_NUMBER}<br>
                URL: <a href="${env.BUILD_URL}">${env.BUILD_URL}</a>
                """,
                mimeType: 'text/html'
            )
        }
        failure {
            echo "Failed to execute the pipeline"
            emailext(
                to: "${EMAIL_ID_TO_SEND}",
                subject: "FAILURE: Pipeline ${env.JOB_NAME} #${env.BUILD_NUMBER}",
                body: """
                <b>Build failed!</b><br>
                Job: ${env.JOB_NAME}<br>
                Build Number: ${env.BUILD_NUMBER}<br>
                URL: <a href="${env.BUILD_URL}">${env.BUILD_URL}</a>
                """,
                mimeType: 'text/html'
            )
        }
        cleanup {
            cleanWs()
        }
    }
}
