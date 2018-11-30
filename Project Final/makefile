
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o CandleRoom.o Game.o GhostRoom.o InputValidation.o Menu.o Room.o Space.o

SRCS = main.cpp CandleRoom.cpp Game.cpp GhostRoom.cpp InputValidation.cpp Menu.cpp Room.cpp Space.cpp

HEADERS = CandleRoom.hpp Game.hpp GhostRoom.hpp InputValidation.hpp Menu.hpp Room.hpp Space.hpp

HauntedHouse: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o HauntedHouse

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} HauntedHouse

zip:
	zip -D Final_Project_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile Design+Reflection.pdf

#target: dependencies
#	rule