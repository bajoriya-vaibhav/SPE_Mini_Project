# FROM gcc:latest AS build

# WORKDIR /app
# COPY . /app

# RUN make

# FROM scratch

# COPY --from=build /app/calculator /bin/calc

# CMD ["/bin/calc"]
FROM alpine:latest AS build

WORKDIR /app

# Install build tools
RUN apk add --no-cache \
    g++ \
    make \
    musl-dev

COPY Makefile .
COPY include/ include/
COPY src/ src/

RUN make

# Stage 2: Runtime
FROM scratch
COPY --from=build /app/calculator /bin/calc
CMD ["/bin/calc"]