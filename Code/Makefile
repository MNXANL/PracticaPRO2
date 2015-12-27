FLAGS = -D_JUDGE_ -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x -D_GLIBCXX_DEBUG -Werror

all: program.exe

program.exe:
	g++ -c *.cc $(FLAGS)
	g++ -o program.exe *.o $(FLAGS)

practica.tar:
	tar -cvf practica.tar *.hh *.cc *.txt equip.pdf html.zip Makefile Doxyfile

clean:
	rm *.o
	rm *.exe
	rm *.tar