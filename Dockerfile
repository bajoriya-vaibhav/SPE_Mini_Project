# Use GCC as base image
FROM gcc:latest

# Set working directory
WORKDIR /app

# Copy source code
COPY . /app

# Build the calculator
RUN make

# Set the default command to run the calculator
CMD ["/app/calculator"]
