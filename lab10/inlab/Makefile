CXX = clang++

CXXFLAGS = -Wall -g


OBJECTS = heapNode.o heap.o huffmandec.o 

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~