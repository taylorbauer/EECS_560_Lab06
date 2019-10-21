Lab06: main.o MaxHeap.o MinHeap.o Menu.o
	g++ -std=c++11 main.o MaxHeap.o MinHeap.o Menu.o -o Lab06
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ -std=c++11 -c MaxHeap.cpp
MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -std=c++11 -c MinHeap.cpp

clean:
	rm -f test *.o