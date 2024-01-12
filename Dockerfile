FROM gcc:latest
WORKDIR /app
COPY . /app
RUN gcc -o myapp TurnHanoi.cpp -lstdc++
CMD ["./myapp"]