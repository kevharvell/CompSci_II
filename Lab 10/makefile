
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o FibonacciNR.o FibonacciR.o

SRCS = main.cpp FibonacciNR.cpp FibonacciR.cpp

HEADERS = FibonacciNR.hpp FibonacciR.hpp

Lab10: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o Lab10

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} Lab10

zip:
	zip -D Final_Project_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile Reflection.pdf

#target: dependencies
#	rule