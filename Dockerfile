FROM gcc:latest AS build

WORKDIR /app
COPY . /app

RUN make

FROM scratch

COPY --from=build /app/calculator /bin/calc

CMD ["/bin/calc"]