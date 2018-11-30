
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o List.o InputValidation.o Menu.o

SRCS = main.cpp List.cpp InputValidation.cpp Menu.cpp

HEADERS = List.hpp InputValidation.hpp Menu.hpp

doublyLinkedList: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o doublyLinkedList

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} doublyLinkedList

zip:
	zip -D Lab6_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile

#target: dependencies
#	rule