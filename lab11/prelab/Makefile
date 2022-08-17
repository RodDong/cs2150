CXX = clang++

CXXFLAGS = -Wall -g


OBJECTS = topological.o  graph.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~