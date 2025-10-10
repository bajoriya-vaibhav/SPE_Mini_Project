pipeline {
    agent any

    environment {
        DOCKERHUB_CREDS = credentials('dockerhub-creds')  // Jenkins credentials (username + password)
        IMAGE_NAME = "spe_mini_calculator"
        IMAGE_TAG = "latest"
        DOCKER_IMAGE = "${DOCKERHUB_CREDS_USR}/${IMAGE_NAME}:${IMAGE_TAG}"
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

        stage('Docker Build') {
            steps {
                sh "docker build -t ${DOCKER_IMAGE} ."
            }
        }

        stage('Push Docker Image') {
            steps {
                sh "echo ${DOCKERHUB_CREDS_PSW} | docker login -u ${DOCKERHUB_CREDS_USR} --password-stdin"
                sh "docker push ${DOCKER_IMAGE}"
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