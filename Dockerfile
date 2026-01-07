FROM gcc:13

WORKDIR /app

COPY data/input.txt ./data/input.txt
COPY data/nk_input_small_0.txt ./data/nk_input_small_0.txt
COPY data/nk_input_small_1.txt ./data/nk_input_small_1.txt
COPY data/nk_input_large.txt ./data/nk_input_large.txt

COPY src/ ./src/

RUN g++ -std=c++20 -O2 src/*.cpp -o app

CMD ["./app"]
