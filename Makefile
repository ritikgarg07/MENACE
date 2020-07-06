CXX = g++
CXXFLAGS = -Wall -g -std=c++17

main.out: main.o data.o transform.o game.o display.o logger.o
	${CXX} ${CXXFLAGS} -o main.out bin/main.o bin/data.o bin/transform.o bin/game.o bin/display.o bin/logger.o

main.o: src/main.cc 
	${CXX} ${CXXFLAGS} -c src/main.cc -o bin/main.o

data.o: src/data.cc
	${CXX} ${CXXFLAGS} -c src/data.cc -o bin/data.o

display.o: src/display.cc
	${CXX} ${CXXFLAGS} -c src/display.cc -o bin/display.o

game.o: src/game.cc
	${CXX} ${CXXFLAGS} -c src/game.cc -o bin/game.o

transform.o: src/transform.cc
	${CXX} ${CXXFLAGS} -c src/transform.cc -o bin/transform.o

logger.o: src/logger.cc
	${CXX} ${CXXFLAGS} -c src/logger.cc -o bin/logger.o


