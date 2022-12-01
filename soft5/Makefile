NAME  := verifyapp

all: $(NAME)
	mkdir build
	cd build
	cmake ..
	make 
	cd ..
run: all
	./$(NAME)

include ../Makefile
