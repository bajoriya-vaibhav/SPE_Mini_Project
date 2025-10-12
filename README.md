# Scientific Calculator with DevOps

This project implements a simple scientific calculator in C++ and demonstrates a full DevOps CI/CD pipeline using Jenkins, Docker, and Ansible.

## Features
- Square root (√x)
- Factorial (!x)
- Natural logarithm (ln(x))
- Power function (x^b)

## DevOps Toolchain
- **Source Control**: GitHub
- **Build**: Make (g++)
- **Testing**: C++ assert-based unit tests
- **CI/CD**: Jenkins with GitHub webhook
- **Local Tunneling**: ngrok (for exposing local Jenkins)
- **Containerization**: Docker (multi-stage build)
- **Container Registry**: Docker Hub
- **Deployment**: Ansible

---

## Prerequisites

### For Windows Users
- Windows 10/11 with WSL2
- Docker Desktop for Windows
- GitHub account
- Docker Hub account

### For Linux Users
- Ubuntu 20.04+ / Debian 11+ / Fedora 35+ (or equivalent)
- GitHub account
- Docker Hub account

---

## Complete Setup Guide

Choose your operating system:
- [Windows (WSL2)](#setup-for-windows-wsl2)
- [Linux (Native)](#setup-for-linux-native)

---

## Setup for Windows (WSL2)

### 1. Install WSL2 and Ubuntu

```powershell
# In Windows PowerShell (Run as Administrator)
wsl --install
wsl --set-default-version 2

# Restart your computer if prompted
```

**Install Ubuntu from Microsoft Store**, then open Ubuntu terminal and continue with steps below.

### 2. Update WSL and Install Dependencies

```bash
# Update package list
sudo apt update && sudo apt upgrade -y

# Install required packages
sudo apt install -y build-essential git curl wget
```

### 3. Install Java (Required for Jenkins)

```bash
# Install OpenJDK 17
sudo apt install -y openjdk-17-jdk

# Verify installation
java -version
```

### 4. Install Jenkins

```bash
# Add Jenkins repository key
curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io-2023.key | sudo tee \
  /usr/share/keyrings/jenkins-keyring.asc > /dev/null

# Add Jenkins repository
echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
  https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
  /etc/apt/sources.list.d/jenkins.list > /dev/null

# Update package list
sudo apt update

# Install Jenkins
sudo apt install -y jenkins

# Start Jenkins service
sudo service jenkins start

# Check Jenkins status
sudo service jenkins status

# Get initial admin password
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
```

**Access Jenkins**: Open browser and go to `http://localhost:8080`

### 5. Install Docker in WSL

```bash
# Install Docker
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Add your user to docker group
sudo usermod -aG docker $USER

# Apply group changes (or restart WSL)
newgrp docker

# Verify Docker installation
docker --version
```

**Important**: Make sure **Docker Desktop for Windows** is running with WSL2 integration enabled:
- Open Docker Desktop → Settings → Resources → WSL Integration
- Enable integration with your Ubuntu distribution

### 6. Install Ansible

```bash
# Install Ansible
sudo apt update
sudo apt install -y software-properties-common
sudo add-apt-repository --yes --update ppa:ansible/ansible
sudo apt install -y ansible

# Install Docker collection for Ansible
ansible-galaxy collection install community.docker

# Verify installation
ansible --version
```

### 7. Install ngrok

```bash
# Download ngrok
wget https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-amd64.tgz

# Extract
tar -xvzf ngrok-v3-stable-linux-amd64.tgz

# Move to /usr/local/bin
sudo mv ngrok /usr/local/bin/

# Verify installation
ngrok version
```

**Sign up and authenticate ngrok**:
1. Create account at [ngrok.com](https://ngrok.com)
2. Get your auth token from dashboard
3. Authenticate:
   ```bash
   ngrok config add-authtoken YOUR_AUTH_TOKEN
   ```

---

## Setup for Linux (Native)

### 1. Update System and Install Dependencies

#### For Ubuntu/Debian:
```bash
# Update package list
sudo apt update && sudo apt upgrade -y

# Install required packages
sudo apt install -y build-essential git curl wget openjdk-17-jdk
```

### 2. Verify Java Installation

```bash
# Check Java version
java -version
javac -version
```

### 3. Install Jenkins

#### For Ubuntu/Debian:
```bash
# Add Jenkins repository key
curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io-2023.key | sudo tee \
  /usr/share/keyrings/jenkins-keyring.asc > /dev/null

# Add Jenkins repository
echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
  https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
  /etc/apt/sources.list.d/jenkins.list > /dev/null

# Update and install Jenkins
sudo apt update
sudo apt install -y jenkins

# Start and enable Jenkins
sudo systemctl start jenkins
sudo systemctl enable jenkins

# Check status
sudo systemctl status jenkins

# Get initial admin password
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
```

**Access Jenkins**: Open browser and go to `http://localhost:8080`

### 4. Install Docker

#### For Ubuntu/Debian:
```bash
# Remove old Docker versions (if any)
sudo apt remove -y docker docker-engine docker.io containerd runc

# Install Docker using convenience script
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Add your user to docker group
sudo usermod -aG docker $USER

# Apply group changes
newgrp docker

# Start and enable Docker
sudo systemctl start docker
sudo systemctl enable docker

# Verify installation
docker --version
docker ps
```

### 5. Install Ansible

#### For Ubuntu/Debian:
```bash
# Install Ansible
sudo apt update
sudo apt install -y software-properties-common
sudo add-apt-repository --yes --update ppa:ansible/ansible
sudo apt install -y ansible

# Install Docker collection for Ansible
ansible-galaxy collection install community.docker

# Verify installation
ansible --version
```

#### For Fedora/RHEL/CentOS:
```bash
# Install Ansible
sudo dnf install -y ansible

# Install Docker collection for Ansible
ansible-galaxy collection install community.docker

# Verify installation
ansible --version
```

### 6. Install ngrok

```bash
# Download ngrok (for Linux AMD64)
wget https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-amd64.tgz

# Extract
tar -xvzf ngrok-v3-stable-linux-amd64.tgz

# Move to /usr/local/bin
sudo mv ngrok /usr/local/bin/

# Clean up
rm ngrok-v3-stable-linux-amd64.tgz

# Verify installation
ngrok version
```

**Sign up and authenticate ngrok**:
1. Create account at [ngrok.com](https://ngrok.com)
2. Get your auth token from dashboard
3. Authenticate:
   ```bash
   ngrok config add-authtoken YOUR_AUTH_TOKEN
   ```

---

## Running the CI/CD Pipeline

### Step 1: Start Jenkins

#### For WSL2:
```bash
# Start Jenkins service
sudo service jenkins start

# Check status
sudo service jenkins status
```

#### For Native Linux:
```bash
# Start Jenkins service
sudo systemctl start jenkins

# Check status
sudo systemctl status jenkins
```

**Access at**: `http://localhost:8080`

### Step 2: Start Docker

#### For WSL2:
```bash
# Make sure Docker Desktop is running on Windows
# Verify Docker in WSL
docker ps

# If not working, check Docker Desktop settings
```

#### For Native Linux:
```bash
# Start Docker service
sudo systemctl start docker

# Check status
sudo systemctl status docker

# Verify
docker ps
```

### Step 3: Start ngrok Tunnel

```bash
# Expose Jenkins on port 8080
ngrok http 8080

# Copy the generated HTTPS URL (e.g., https://xxxx-xx-xx-xxx-xx.ngrok-free.app)
# Keep this terminal open
```

### Step 4: Configure Jenkins

1. **Initial Setup**:
   - Open `http://localhost:8080` in browser
   - Enter the initial admin password (from Step 1)
   - Install suggested plugins
   - Create admin user

2. **Install Required Plugins**:
   - Go to `Manage Jenkins` → `Plugins` → `Available plugins`
   - Search and install:
     - Docker Pipeline
     - Ansible
     - Email Extension Plugin
   - Restart Jenkins after installation

3. **Add Docker Hub Credentials**:
   - Go to `Manage Jenkins` → `Credentials` → `System` → `Global credentials`
   - Click `Add Credentials`
   - Kind: `Username with password`
   - Username: Your Docker Hub username
   - Password: Your Docker Hub password or access token
   - ID: `dockerhub-creds`
   - Description: `Docker Hub credentials`
   - Click `Create`

4. **Create Pipeline Job**:
   - Click `New Item`
   - Enter name: `Scientific-Calculator-Pipeline`
   - Select `Pipeline`
   - Click `OK`
   - Under `Pipeline` section:
     - Definition: `Pipeline script from SCM`
     - SCM: `Git`
     - Repository URL: `https://github.com/bajoriya-vaibhav/SPE_Mini_Project.git`
     - Branch: `*/main`
     - Script Path: `Jenkinsfile`
   - Click `Save`

### Step 5: Configure GitHub Webhook

1. Go to your GitHub repository: `https://github.com/bajoriya-vaibhav/SPE_Mini_Project`
2. Click `Settings` → `Webhooks` → `Add webhook`
3. Configure webhook:
   - **Payload URL**: `https://your-ngrok-url/github-webhook/`
     (Replace with your ngrok HTTPS URL from Step 3)
   - **Content type**: `application/json`
   - **SSL verification**: Enable SSL verification
   - **Events**: Select `Just the push event`
   - Click `Add webhook`

4. Verify webhook:
   - You should see a green checkmark if configured correctly
   - GitHub will send a test ping

### Step 6: Test the Pipeline

```bash
# Clone repository (if not already cloned)
git clone https://github.com/bajoriya-vaibhav/SPE_Mini_Project.git
cd SPE_Mini_Project

# Make a change
echo "# Testing CI/CD" >> test.txt

# Commit and push
git add .
git commit -m "Test CI/CD pipeline trigger"
git push origin main

# Watch Jenkins automatically trigger the build
# Go to http://localhost:8080 and check your pipeline
```

---

## Local Development

### Build the Calculator

```bash
# Clone repository
git clone https://github.com/bajoriya-vaibhav/SPE_Mini_Project.git
cd SPE_Mini_Project

# Clean and build
make clean
make

# Run calculator
./calculator
```

### Run Tests

```bash
# Compile and run tests
make test
```

### Build Docker Image Locally

```bash
# Build image
docker build -t spe_mini_calculator:latest .

# Run container interactively
docker run -it spe_mini_calculator:latest

# Or run in detached mode
docker run -d --name calculator spe_mini_calculator:latest
```

### Deploy with Ansible

```bash
# Run Ansible playbook
ansible-playbook -i ansible/inventory.ini ansible/playbook.yml

# Verify deployment
docker ps

# Check container logs
docker logs calculator

# Execute calculator in container
docker exec -it calculator /bin/calc
```

---

## Project Structure

```
SPE_Mini_Project/
├── src/
│   ├── main.cpp              # Main calculator program with menu
│   └── calculator.cpp        # Calculator implementation
├── include/
│   └── calculator.h          # Calculator class header
├── tests/
│   └── test_calculator.cpp   # Unit tests with detailed output
├── ansible/
│   ├── inventory.ini         # Ansible inventory (localhost)
│   └── playbook.yml          # Deployment playbook
├── Dockerfile                # Multi-stage Docker build
├── Jenkinsfile              # CI/CD pipeline definition
├── Makefile                 # Build automation
└── README.md                # This file
```

---

## CI/CD Pipeline Stages

The Jenkins pipeline consists of the following stages:

1. **Checkout**: Clone code from GitHub repository
2. **Build**: Compile C++ code using `make clean && make`
3. **Test**: Run unit tests using `make test`
4. **Docker Build & Push**: Build Docker image and push to Docker Hub
5. **Deploy with Ansible**: Deploy container using Ansible playbook

---

## Common Commands Reference

### Jenkins Commands
```bash
# WSL2
sudo service jenkins start
sudo service jenkins stop
sudo service jenkins restart
sudo service jenkins status

# Native Linux
sudo systemctl start jenkins
sudo systemctl stop jenkins
sudo systemctl restart jenkins
sudo systemctl status jenkins
```

### Docker Commands
```bash
# List containers
docker ps -a

# Remove container
docker rm -f calculator

# List images
docker images

# Remove image
docker rmi spe_mini_calculator:latest

# View logs
docker logs calculator

# Execute command in container
docker exec -it calculator /bin/calc

# Clean up everything
docker system prune -a
```

### Git Commands
```bash
# Check status
git status

# Add changes
git add .

# Commit
git commit -m "Your message"

# Push to GitHub
git push origin main

# Pull latest changes
git pull origin main
```

### Build Commands
```bash
# Clean build artifacts
make clean

# Build calculator
make

# Run tests
make test

# Build and run
make && ./calculator
```

---

## References

- **Jenkins Documentation**: [jenkins.io](https://www.jenkins.io/doc/)
- **Docker Documentation**: [docs.docker.com](https://docs.docker.com/)
- **Ansible Documentation**: [docs.ansible.com](https://docs.ansible.com/)