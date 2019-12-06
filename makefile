final: driver.o directory.o file.o hash.o
	g++ -o plagiarismCatcher driver.o directory.o file.o hash.o
driver.o: driver.cpp directory.h file.h hash.h
	g++ -c driver.cpp 
directory.o: directory.cpp directory.h file.h
	g++ -c directory.cpp
file.o: file.cpp file.h
	g++ -c file.cpp
hash.o: hash.cpp hash.h
	g++ -c hash.cpp
