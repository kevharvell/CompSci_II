
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o Menu.o InputValidation.o Barbarian.o BlueMen.o Character.o Die.o Game.o HarryPotter.o List.o Medusa.o Vampire.o

SRCS = main.cpp Menu.cpp InputValidation.cpp Barbarian.cpp BlueMen.cpp Character.cpp Die.cpp Game.cpp HarryPotter.cpp List.cpp Medusa.cpp Vampire.cpp

HEADERS = Menu.hpp InputValidation.hpp Barbarian.hpp BlueMen.hpp Character.hpp Die.hpp Game.hpp HarryPotter.hpp List.hpp Medusa.hpp Vampire.hpp

FantasyCombatTournament: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o FantasyCombatTournament

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} FantasyCombatTournament

zip:
	zip -D Project3_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile Design+Reflection.pdf

#target: dependencies
#	rule