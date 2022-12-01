ifeq ($(NAME),)
$(error Should make in each lab's directory)
endif

.PHONY: all git clean commit-and-make cleant

.DEFAULT_GOAL := commit-and-make
commit-and-make: git all
cleant:
	rm -f $(basename $(shell find ../files -mindepth 1 -name "*.cpp")) \
	$(shell find ../files -name "*.txt" ! -name "*stdin_format.txt") ../files/*.csv \
	
git:
	@git add -A --ignore-errors
	@while (test -e .git/index.lock); do sleep 0.1; done
	@(uname -a && uptime) | git commit -F - -q --no-verify --allow-empty
	@sync
