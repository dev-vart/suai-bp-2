CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: run

run: usingstopwatch
	.\usingStopWatch.exe

usingstopwatch:
	$(CC) $(FLG) usingStopWatch.cpp stopWatchClass.cpp -o usingStopWatch

clean:
	rm -rf usingStopWatch

rebuild: clean all