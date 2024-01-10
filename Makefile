#compile and link the application
all: main

#run the application
run: main
	./main

#run the test file
run: test
	./test

#link main.o, student.o, stu_sort.o, and list.o to executable main
main: main.o student.o stu_sort.o list.o test.o
	g++ -g -o main main.o student.o stu_sort.o list.o test.o

#compile the main.cpp to main.o
main.o: main.cpp student.hpp stu_sort.hpp list.hpp test.hpp
	g++ -g -c main.cpp

#link test.o, student.o, stu_sort.o, and list.o to executable test
test: test.o student.o stu_sort.o list.o
	g++ -g -o test test.o student.o stu_sort.o list.o

#compile the test.cpp to test.o
test.o: test.cpp student.hpp stu_sort.hpp list.hpp test.hpp
	g++ -g -c test.cpp

#compile the student.cpp to student.o
student.o: student.cpp student.hpp
	g++ -g -c student.cpp

#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp stu_sort.hpp 
	g++ -g -c stu_sort.cpp

#compile the list.cpp to list.o
list.o: list.cpp list.hpp
	g++ -g -c list.cpp

#remove built files
clean:
	rm -rf main main.o student.o stu_sort.o list.o test.o *~
