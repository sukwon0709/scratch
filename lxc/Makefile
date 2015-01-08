all: test

CFLAGS = -ggdb

test: test.cpp
	${CXX} ${CFLAGS} $< -o $@ -llxc

clean:
	rm -r test
