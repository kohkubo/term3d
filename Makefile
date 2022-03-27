NAME		= term3d
includes	= ./includes
obj_dir		= objs
obj			= $(src:%.c=%.o)
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(includes:%=-I%) -MMD -MP -O2
dep			= $(obj:.o=.d)

src = ./srcs/term3d.c \
	$(src_sub)

src_sub =\
	./srcs/data.c \
	./srcs/config.c \
	./srcs/init.c \
	./srcs/draw.c \
	./srcs/rotate.c \
	./srcs/ray/camera.c \
	./srcs/ray/intersect.c \
	./srcs/control/getch.c \
	./srcs/control/control1.c \
	./srcs/control/control2.c \
	./srcs/control/control3.c \
	./srcs/control/control4.c \
	./srcs/control/control5.c \
	./srcs/control/control6.c \
	./srcs/load/load.c \
	./srcs/load/store.c \
	./srcs/load/ft_split.c \
	./srcs/shading.c \
	./srcs/thread.c \
	./srcs/utils.c \
	./srcs/signal.c \
	./srcs/vect/vect1.c \
	./srcs/vect/vect2.c \
	./srcs/vect/vect3.c \
	./srcs/vect/vect4.c \
	./srcs/vect/vect5.c \
	./srcs/debug.c \

.PHONY: all
all		: $(NAME)

$(NAME)	: $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(NAME)

.PHONY: clean
clean	:
	$(RM) $(obj) $(dep)
	$(RM) -r $(NAME).dSYM

.PHONY: fclean
fclean	: clean
	$(RM) $(NAME)

.PHONY: re
re		: fclean all

.PHONY: leak
leak:
	leaks -q -atExit -- ./term3d hoge

gtestdir	=	./test
gtest		=	$(gtestdir)/gtest $(gtestdir)/googletest-release-1.11.0
testdir = ./gtest

$(gtest):
	mkdir -p $(dir ../test)
	curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	tar -xvzf release-1.11.0.tar.gz googletest-release-1.11.0
	rm -rf release-1.11.0.tar.gz
	python googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py $(gtestdir)
	mv googletest-release-1.11.0 $(gtestdir)

.PHONY: test
test: $(gtest) fclean
	clang++ -std=c++11 \
	$(testdir)/gtest.cpp $(gtestdir)/googletest-release-1.11.0/googletest/src/gtest_main.cc $(gtestdir)/gtest/gtest-all.cc \
	-g -fsanitize=address -fsanitize=undefined -O0 \
	-I$(gtestdir) -I/usr/local/opt/llvm/include -I$(includes) -lpthread $(src_sub) -o tester
	./tester
	rm -rf tester
	rm -rf tester.dSYM

.PHONY: cave
cave: CFLAGS = $(includes:%=-I%) -fprofile-arcs -ftest-coverage -O0
cave: re
	./term3d ./sample/42.tri
	lcov -c -b . -d . -o cov_test.info
	genhtml cov_test.info -o cov_test
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete
	find . -name "*.info" -delete
	open cov_test/index-sort-f.html

.PHONY: bench
bench:
	gsed -i 's/#include "benchmark\/export\.h"/#include "\.\.\/build\/include\/benchmark\/export\.h"/' benchmark/include/benchmark/benchmark.h
	g++ gbench/* $(src_sub) -std=c++11 -isystem benchmark/include -Lbenchmark/build/src -lpthread -I$(includes) -o mybenchmark -DBENCH
	./mybenchmark --benchmark_out="benchmark.txt" --benchmark_out_format=console

-include $(dep)
