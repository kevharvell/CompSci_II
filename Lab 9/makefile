
CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g
LDFLAGS = -lboost_date_time

OBJS = main.o InputValidation.o Menu.o bufferPalindrome.o

SRCS = main.cpp InputValidation.cpp Menu.cpp bufferPalindrome.cpp

HEADERS = InputValidation.hpp Menu.hpp bufferPalindrome.hpp

Lab9: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} ${HEADERS} -o Lab9

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm ${OBJS} Lab9

zip:
	zip -D Lab9_Harvell_Kevin.zip ${SRCS} ${HEADERS} makefile

#target: dependencies
#	rule