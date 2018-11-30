
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o InputValidation.o searchSortIO.o

SRCS = main.cpp InputValidation.cpp searchSortIO.cpp

HEADERS = InputValidation.hpp searchSortIO.hpp

SearchSort: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o SearchSort

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} SearchSort

zip:
	zip -D Lab8_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile Design+Reflection.pdf

#target: dependencies
#	rule