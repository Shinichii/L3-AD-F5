CXX=g++-5
CFLAGS= -std=c++11 -lstdc++fs
LDFLAGS=
EXEC=hello

all: $(EXEC)

hello : L3-AD-F5-file_Finder.o L3-AD-F5-parser.o L3-AD-F5-main.o
	$(CXX) -o hello L3-AD-F5-file_Finder.o L3-AD-F5-parser.o L3-AD-F5-main.o $(LDFLAGS)
	
L3-AD-F5-file_Finder.o: L3-AD-F5-file_Finder.cpp L3-AD-F5-file_Finder.h
	$(CXX) -c L3-AD-F5-file_Finder.cpp L3-AD-F5-file_Finder.h $(CFLAGS)

L3-AD-F5-parser.o: L3-AD-F5-parser.cpp L3-AD-F5-parser.h
	$(CXX) -c L3-AD-F5-parser.cpp L3-AD-F5-parser.h $(CFLAGS)

L3-AD-F5-main.o: L3-AD-F5-main.cpp
	$(CXX) -c L3-AD-F5-main.cpp $(CFLAGS)

clean:
	rm -rf *.o

aurel: clean
	rm $(EXEC)
