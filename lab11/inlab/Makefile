CXX = clang++

CXXFLAGS = -O2 -Wall -g


OBJECTS = middleearth.o  traveling.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) 
	doxygen

clean:
	-rm -f *.o *~