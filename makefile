main: Fun.o
	g++ -o main main.cpp funkcijos.o
fun:
	g++ -c funkcijos.cpp
clean:
	rm *.o main