#Makefile for homework 18.12

chat: main.o User.o Message.o
	g++ main.o User.o Message.o -o hw

main.o: main.cpp
	g++ -c main.cpp

User.o: User.cpp
	g++ -c User.cpp

Message.o: Message.cpp
	g++ -c Message.cpp

clean:
	rm -rf *.o *.txt hw

