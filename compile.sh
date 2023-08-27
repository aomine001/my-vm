C_FLAGS=-I./

set -x

mkdir -p tmp
g++ main.cpp $C_FLAGS -c -o tmp/main.o
g++ instructions.cpp $C_FLAGS -c -o tmp/instructions.o

g++ tmp/*.o -o app

./app