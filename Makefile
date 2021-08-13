qpy: lib.o file_handling.o prints.o searching.o qpy.o
	g++ -o qpy lib.o file_handling.o prints.o searching.o qpy.o

lib.o: ../lib/src/lib.cpp
	g++ -c ../lib/src/lib.cpp

file_handling.o: ../lib/src/file_handling.cpp
	g++ -c ../lib/src/file_handling.cpp

prints.o: ../lib/src/prints.cpp
	g++ -c ../lib/src/prints.cpp

searching.o: ../lib/src/searching.cpp
	g++ -c ../lib/src/searching.cpp

qpy.o:	qpy.cpp
	g++ -c qpy.cpp

clean:
	rm *.o qpy
