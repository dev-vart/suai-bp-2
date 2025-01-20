CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: run

run: lie
	.\lie.exe

lie:
	$(CC) $(FLG) platypus.cpp lie.cpp -o lie.exe

clean:
	del /q *.exe

rebuild: clean all

