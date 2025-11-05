CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = 

SRC = main
all: $(SRC)

clean:
	rm -f $(SRC).map $(SRC).o $(SRC)

$(SRC):	$(SRC).o
	$(CXX) $(LDFLAGS) $(SRC).o -o $(SRC)

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:	clean
