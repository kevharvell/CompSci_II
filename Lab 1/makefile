
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o determinant.o readMatrix.o

SRCS = main.cpp determinant.cpp readMatrix.cpp

HEADERS = determinant.hpp readMatrix.hpp

matrixCalculator: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o matrixCalculator

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} matrixCalculator

#target: dependencies
#	rule