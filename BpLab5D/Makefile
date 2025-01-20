CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: run

run: Labor_5D
	.\Labor_5D.exe

Labor_5D:
	$(CC) $(FLG) Labor_5D.cpp -o Labor_5D.exe

clean:
	del /q *.exe

rebuild: clean all

