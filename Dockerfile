FROM gcc:13

WORKDIR /app

COPY src/ ./src/

RUN g++ -std=c++20 -O2 src/*.cpp -o app

CMD ["./app"]
