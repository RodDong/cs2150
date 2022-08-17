CXX = clang++

CXXFLAGS = -Wall -g


OBJECTS = heapNode.o heap.o huffmanenc.o 

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~