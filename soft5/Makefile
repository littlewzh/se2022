NAME  := verifyapp

all:$(NAME)

$(NAME):
	./a.sh
run: all
	./$(NAME)
clean:
	rm -rf build $(NAME) *.csv
include ./build/Makefile
include ../Makefile
