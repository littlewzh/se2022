NAME  := judgeapp
FILES ?= files/50A files/4A

SRCS    := $(shell find . -maxdepth 1 -name "judgeapp.cpp")
DEPS    := $(shell find . -maxdepth 1 -name "*.h") $(SRCS)
CFLAGS  += -O1 -ggdb -Wall -Werror -Wno-unused-result -Wno-unused-value -Wno-unused-variable

.PHONY: all run git clean commit-and-make

.DEFAULT_GOAL := commit-and-make
commit-and-make: all git
all: $(NAME)
run: all
	./$(NAME) $(FILES)
$(NAME): $(DEPS)
	g++ $(CFLAGS) $(SRCS) -o $@


clean:
	@rm -f *.txt   $(basename $(shell find . -mindepth 2 -name "*.cpp")) \
	$(shell find . -name "*.txt" ! -name "*stdin_format.txt") $(NAME)  *.csv  \
	
git:
	@git add -A --ignore-errors
	@while (test -e .git/index.lock); do sleep 0.1; done
	@(uname -a && uptime) | git commit -F - -q --no-verify --allow-empty
	@sync
