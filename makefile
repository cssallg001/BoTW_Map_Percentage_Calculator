all: main
main: map_percent_calculator.cpp
	g++ map_percent_calculator.cpp -o main
	./main
	rm main
