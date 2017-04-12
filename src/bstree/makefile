testbin=testbtree
testdir=./test
CC=gcc
CXX=g++
CXXFLAGS=-g 
INCLUDES= -I./ -I../
SOURCES=$(shell find . -maxdepth 1 -name "*.cxx")
OBJS=$(patsubst %.cxx, %.o, $(SOURCES) )
OBJDIR=./objs
RM=rm


%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

$(testbin): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(testdir)/$@ $(testdir)/$@.cxx $(OBJS)

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MM $^>>./.depend

clean:
	$(RM) -f $(OBJS) ~* ./.depend

include .depend
