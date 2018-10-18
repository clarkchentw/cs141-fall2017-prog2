all: prog2.cc

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

