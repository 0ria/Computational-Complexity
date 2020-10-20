IDIR =../include
CXX=g++ -g -std=c++11 -o main
CFLAGS=-I$(IDIR) -g

ODIR=../src
#LDIR =../files

LIBS=-lm

_OBJ = main.o Cleaner.o FSA.o Alphabet.o Transition.o State.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main
main: ${OBJ} 
	$(CXX) $(CXXFLAGS) ${OBJ} 

	#rm -rf $(OBJS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~