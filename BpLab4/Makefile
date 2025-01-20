CC=g++
FLG=-std=c++14 -Wall -Werror -Wextra

all: run

run: usingWorkerClass
	.\project.exe

usingWorkerClass:
	$(CC) $(FLG) usingWorkerClass.cpp WorkerClass.cpp -o project

menuWorkers:
	$(CC) $(FLG) menuWorkers.cpp WorkerClass.cpp -o project
	.\project.exe

clean:
	del /q *.exe

rebuild: clean all