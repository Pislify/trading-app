g++ src/*.cpp -I ./src/ -o ./out/* -c 
g++ ./out/*.o -o ./bin/app -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
cd bin
./app
cd ..
