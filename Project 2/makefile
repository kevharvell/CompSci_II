
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o InputValidation.o Menu.o

SRCS = main.cpp Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp InputValidation.cpp Menu.cpp

HEADERS = Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp InputValidation.hpp Menu.hpp

DiceWar: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o ZooTycoon

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} ZooTycoon

zip:
	zip -D Project2_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile Design+Reflection.pdf

#target: dependencies
#	rule