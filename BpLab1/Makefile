CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: run

run: usingrange
	.\usingRange.exe

usingrange:
	$(CC) $(FLG) usingRange.cpp rangeClass.cpp -o usingRange

clean:
	rm -rf usingRange

rebuild: clean all