
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o Queue.o InputValidation.o Menu.o

SRCS = main.cpp Queue.cpp InputValidation.cpp Menu.cpp

HEADERS = Queue.hpp InputValidation.hpp Menu.hpp

circularLinkedList: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o circularLinkedList

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} circularLinkedList

zip:
	zip -D Lab7_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile

#target: dependencies
#	rule