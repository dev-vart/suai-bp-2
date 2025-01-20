CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: run

run: usingTimeClass
	.\usingTimeClass.exe

usingTimeClass:
	$(CC) $(FLG) usingTimeClass.cpp timeClass.cpp -o usingTimeClass

clean:
	rm -rf usingTimeClass

rebuild: clean all