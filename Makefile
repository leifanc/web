proc : listen.o
	gcc -o proc listen.o
listen.o : listen.cpp
	gcc -c listen.cpp

make clean:
	rm -rf proc 
	rm -rf listen.o