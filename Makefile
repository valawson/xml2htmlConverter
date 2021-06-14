UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
LINKOPTIONS = -Wl,-search_paths_first -Wl,-dead_strip -v
else
LINKOPTIONS = -Wl,--gc-sections -Wl,--strip-all
endif

LIBB = libs/tinyxml2
LIBINCLUDE = libs/tinyxml2

INCLUDE += -I./include/
CFLAGS += -Iinclude/

INCLUDE += -I./libs/
COMPILEOPTIONS  = -std=c++17 -O3 -fdata-sections -ffunction-sections
WARNINGS = -Wall -Wextra

CFLAGS += -I$(LIBINCLUDE)
LDFLAGS += -L$(LIBB) -static -ltinyxml2

MAIN 	  = xml2html.o
OBJECTS   = xml2html.o
EXEC 	  = xml2html
TEST_EXEC = xml2html

CPP_SRCFILES := row.cpp xml2html.cpp table.cpp
CPP_OBJS := $(patsubst %.cpp,%.o, $(CPP_SRCFILES))

#############################################################

all : ${EXEC}

MakeLib:
	cd libs/tinyxml2 && make

%.o: %.cpp
	$(CXX) $(COMPILEOPTIONS) $(INCLUDE) -c -o $@ $<

%.o: %.c
	$(CC) $(COMPILEOPTIONS) $(INCLUDE) -c -o $@ $<
 
${MAIN} : xml2html.cpp table.cpp row.cpp MakeLib
	${CXX} ${COMPILEOPTIONS} $(INCLUDE) -c $< -o $@ $(LIBB)/libtinyxml2.a
 
${EXEC} : ${OBJECTS} main.cpp $(CPP_OBJS)
	${CXX} ${LINKOPTIONS} $(CPP_OBJS) $(INCLUDE) main.cpp -o ${EXEC} $(LIBB)/libtinyxml2.a

clean :
	rm *.gch *.o test/cd_catalog.html test/different_col_count.html *.txt ${EXEC}

testBasic :
	./${EXEC} test/cd_catalog.xml
	diff test/cd_catalog.html test/cd_catalog-result.html

testDifferentCol :
	./${EXEC} test/different_col_count.xml
	diff test/different_col_count.html test/different_col_count-result.html

testNoInput :
	./${EXEC} > outputNoInputFail.txt && ([ $$? -eq 0 ] && echo "Unexpected success!") || echo "Expected Failure!"
	diff outputNoInputFail.txt test/expectedOutputNoInputFail.txt

testBadInput :
	./${EXEC} blah.xml > outputBadInputFail.txt && ([ $$? -eq 0 ] && echo "Unexpected success!") || echo "Expected Failure!"
	diff outputBadInputFail.txt test/expectedOutputBadInputFail.txt

test : ${EXEC} testBasic testDifferentCol testNoInput testBadInput