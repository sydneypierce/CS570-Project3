CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = a.out

OBJECTS = main.o BruteForce.o Edge.o Graph.o Heuristic.o

make: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET) *~