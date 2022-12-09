DIR=/usr/local
INC=include
# SRCS=srcs
TSRCS=test_srcs/testFile.cpp
# TEST=testFile

all:
	c++ -o main main.cpp -std=c++14

test:
	c++ -o testFile $(TSRCS) -isystem -I${DIR}/include -I$(INC) -L${DIR}/lib -pthread -lgtest -std=c++14
	./testFile

clean:
	rm -rf testFile main