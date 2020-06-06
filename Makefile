chess: build/CSquare.o build/CBoard.o build/CMove.o build/CGame.o build/CCommand.o build/CApplication.o build/main.o build/CPlayer.o build/CPlayerArtificial.o
	mkdir -p build
	g++ build/CSquare.o build/CBoard.o build/CMove.o build/CGame.o build/CCommand.o build/CApplication.o build/main.o build/CPlayer.o build/CPlayerArtificial.o -o chess

build/main.o: main.cpp src/CApplication.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c main.cpp -o build/main.o

build/CApplication.o: src/CApplication.cpp src/CApplication.h src/CGame.h src/CGame.cpp src/CCommand.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CApplication.cpp -o build/CApplication.o

build/CCommand.o: src/CCommand.cpp src/CCommand.h src/ECommand.h src/CGame.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CCommand.cpp -o build/CCommand.o

build/CGame.o: src/CGame.cpp src/CGame.h src/CBoard.h src/CMove.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CGame.cpp -o build/CGame.o

build/CBoard.o: src/CBoard.cpp src/CBoard.h src/CSquare.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CBoard.cpp -o build/CBoard.o

build/CMove.o: src/CMove.cpp src/CMove.h src/CBoard.h src/EPiece.h src/EColour.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CMove.cpp -o build/CMove.o

build/CSquare.o: src/CSquare.cpp src/CSquare.h src/EPiece.h src/EColour.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CSquare.cpp -o build/CSquare.o

build/CPlayer.o: src/CPlayer.cpp src/CPlayer.h src/EColour.h src/CBoard.h
	mkdir -p build
	g++  -g -Wall -pedantic -std=c++11 -c src/CPlayer.cpp -o build/CPlayer.o

build/CPlayerArtificial.o: src/CPlayerArtificial.cpp src/CPlayerArtificial.h src/CPlayer.h
	mkdir -p build
	g++ -g -Wall -pedantic -std=c++11 -c src/CPlayerArtificial.cpp -o build/CPlayerArtificial.o

clean:
		rm chess
		rm -r build

.PHONY: clean



