
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o Menu.o InputValidation.o Die.o LoadedDie.o Game.o

SRCS = main.cpp Die.cpp LoadedDie.cpp Game.cpp InputValidation.cpp Menu.cpp

HEADERS = Die.hpp LoadedDie.hpp Game.hpp InputValidation.hpp Menu.hpp

DiceWar: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o DiceWar

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} DiceWar

zip:
	zip -D Lab3_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile Design+Reflection.pdf

#target: dependencies
#	rule