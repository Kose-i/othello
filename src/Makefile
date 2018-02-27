run: main
	./main
main: main.o Board.o Player.o
	g++ -o main main.o Board.o Player.o
main.o: main.cpp
	g++ -I../include -c main.cpp
Board.o: Board.cpp
	g++ -I../include -c Board.cpp
Player.o: Player.cpp
	g++ -I../include -c Player.cpp
clean:
	rm main.o Board.o Player.o main
