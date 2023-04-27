CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = a.out

OBJECTS = main.o BruteForce.o Edge.o Graph.o Heuristic.o
TO = hamPathToTSP.o BruteForce.o Edge.o Graph.o Heuristic.o
FROM = longestToHam.o BruteForce.o Edge.o Graph.o Heuristic.o

make run: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

to: $(TO)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TO)

from: $(FROM)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(FROM)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TO) $(FROM) $(TARGET) *~