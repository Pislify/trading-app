g++ src/*.cpp -o ./out/* -c
g++ ./out/*.o -o ./bin/app -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./bin/app
