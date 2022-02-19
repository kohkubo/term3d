
NAME		= term3d
includes	= ./includes
src_dir		= srcs
obj_dir		= objs
obj			= $(src:%.c=$(src_dir)/%.o)
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address $(includes:%=-I%) -MMD -MP -O2
dep			= $(obj:.o=.d)

src =\
	./data.c \
	./term3d.c \
	./draw.c \
	./calc/rotate.c \
	./calc/camera.c \
	./calc/triangle.c \
	./move.c \
	./loader.c \
	./parse_and_assign.c \
	./vect/vect1.c \
	./vect/vect2.c \
	./vect/vect3.c \
	./vect/vect4.c \
	./vect/vect5.c \
	./debug.c \

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
srcs_test = \
	./$(src_dir)/draw.c \
	./$(src_dir)/data.c \
	./$(src_dir)/calc/rotate.c \
	./$(src_dir)/calc/camera.c \
	./$(src_dir)/calc/triangle.c \
	./$(src_dir)/debug.c \
	./$(src_dir)/move.c \
	./$(src_dir)/loader.c \
	./$(src_dir)/parse_and_assign.c \
	./$(src_dir)/vect/vect1.c \
	./$(src_dir)/vect/vect2.c \
	./$(src_dir)/vect/vect3.c \
	./$(src_dir)/vect/vect4.c \
	./$(src_dir)/vect/vect5.c \

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
	-g -fsanitize=address -fsanitize=undefined \
	-I$(gtestdir) -I/usr/local/opt/llvm/include -I$(includes) -lpthread $(srcs_test) -o tester
	./tester
	rm -rf tester
	rm -rf tester.dSYM

-include $(dep)
