#compile and link the application
all: mainFinal

#run the application
run: mainFinal
	./mainFinal

#link mainFinal.o and student.o to executable mainFinal
mainFinal: mainFinal.o student.o
	g++ -g -o mainFinal mainFinal.o student.o

#compile the mainFinal.cpp to mainFinal.o
mainFinal.o: mainFinal.cpp student.hpp
	g++ -g -c mainFinal.cpp

#compile the student.cpp to student.o
student.o: student.cpp student.hpp
	g++ -g -c student.cpp

#remove built files
clean:
	rm -rf mainFinal mainFinal.o student.o *~
