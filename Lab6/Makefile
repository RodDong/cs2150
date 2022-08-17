CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 
DEBUG=-g

OBJECTS = timer.o hashTable.o wordPuzzle.o

wordPuzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

hashTable.o: hashTable.cpp hashTable.h

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

.PHONY: clean

clean:
	 -rm -f *.o *~ a.out