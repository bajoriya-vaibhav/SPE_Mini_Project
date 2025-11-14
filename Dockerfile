# FROM gcc:latest AS build

# WORKDIR /app
# COPY . /app

# RUN make

# FROM scratch

# COPY --from=build /app/calculator /bin/calc

# CMD ["/bin/calc"]

FROM gcc:11-alpine AS build

WORKDIR /app
COPY Makefile .
COPY include/ include/
COPY src/ src/

# Install make (Alpine doesn't include it)
RUN apk add --no-cache make

RUN make

# Final stage remains same
FROM scratch
COPY --from=build /app/calculator /bin/calc
CMD ["/bin/calc"]