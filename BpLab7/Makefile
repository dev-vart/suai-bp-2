CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: compile run

run:
	.\handler.exe

compile:
	$(CC) $(FLG)  handler.cpp -o handler.exe

noflags:
	$(CC) handler.cpp -o handler.exe
	.\handler.exe

clear:
	del /q *.exe

rebuild: clear all

