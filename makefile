CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror

all: gradebook

gradebook: main.o grades.o Student.o Grade.o LinkedList.o
    $(CXX) $(CXXFLAGS) -o gradebook main.o grades.o Student.o Grade.o LinkedList.o

main.o: main.cpp grades.h Student.h Grade.h LinkedList.h
    $(CXX) $(CXXFLAGS) -c main.cpp

grades.o: grades.cpp grades.h Student.h Grade.h LinkedList.h
    $(CXX) $(CXXFLAGS) -c grades.cpp

Student.o: Student.cpp Student.h
    $(CXX) $(CXXFLAGS) -c Student.cpp

Grade.o: Grade.cpp Grade.h
    $(CXX) $(CXXFLAGS) -c Grade.cpp

LinkedList.o: LinkedList.cpp LinkedList.h LinkedListNode.h
    $(CXX) $(CXXFLAGS) -c LinkedList.cpp

clean:
    rm -f gradebook *.o
