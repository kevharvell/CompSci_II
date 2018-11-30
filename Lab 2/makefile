CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o output_letters.o count_letters.o

SRCS = main.cpp output_letters.cpp count_letters.cpp

HEADERS = output_letters.hpp count_letters.hpp

LangstonAnt: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o letterCounter

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} letterCounter

zip:
	zip -D Lab2_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile file_fun.txt

#target: dependencies
#	rule