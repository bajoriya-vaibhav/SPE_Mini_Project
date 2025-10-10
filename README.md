# Scientific Calculator with DevOps

This project implements a simple scientific calculator in C++ and demonstrates a full DevOps pipeline.

## Features
- Square root
- Factorial
- Natural logarithm
- Power function

## DevOps Toolchain
- **Source Control**: GitHub
- **Build**: Make
- **Testing**: C++ assert tests
- **CI/CD**: Jenkins with GitHub webhook (ngrok for local testing)
- **Containerization**: Docker
- **Deployment**: Ansible

## Setup
```bash
make
./calculator