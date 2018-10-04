CC = g++
source = main Circle
link = $(addsuffix .o,$(source))
out = main
%.o :%.c
	${CC} $^ -c -o $@
${out}:${link}
	${CC} $^ -o $@
clean:
	find . -name "*.o" -exec rm {} \;

help:
	@echo "Hello World!"

.PHONY:clean
