@echo off
g++ -fdiagnostics-color=always -g src/main.cpp -I include
g++ *.o -o bin\main -Llib -lsfml-system -lsfml-graphics -l sfml-window -lsfml-audio
bin\main.exe