CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: compile run

run: compile
	.\handler.exe

compile:
	$(CC) $(FLG)  handler.cpp massiv.cpp -o handler.exe

clear:
	del /q *.exe

rebuild: clear all

