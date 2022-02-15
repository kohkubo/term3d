
NAME		= term3d
includes	= ./includes
src_dir		= srcs
obj_dir		= objs
obj			= $(src:%.c=$(src_dir)/%.o)
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(includes:%=-I%)

src =\
	./term3d.c \
	./vect/vect1.c \
	./vect/vect2.c \
	./vect/vect3.c \

all		: $(NAME)

$(NAME)	: $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(NAME)

clean	:
	$(RM) $(obj)
	$(RM) -r $(NAME).dSYM

fclean	: clean
	$(RM) $(obj)
	$(RM) $(NAME)

re		: fclean all

gtestdir	=	./test
gtest		=	$(gtestdir)/gtest $(gtestdir)/googletest-release-1.11.0
srcs_test = ./$(src_dir)/vect/vect1.c \
			./$(src_dir)/vect/vect2.c \
			./$(src_dir)/vect/vect3.c \

testdir = ./gtest

$(gtest):
	mkdir -p $(dir ../test)
	curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	tar -xvzf release-1.11.0.tar.gz googletest-release-1.11.0
	rm -rf release-1.11.0.tar.gz
	python googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py $(gtestdir)
	mv googletest-release-1.11.0 $(gtestdir)

test: $(gtest) fclean
	clang++ -std=c++11 \
	$(testdir)/gtest.cpp $(gtestdir)/googletest-release-1.11.0/googletest/src/gtest_main.cc $(gtestdir)/gtest/gtest-all.cc \
	-g -fsanitize=address -fsanitize=undefined -fsanitize=leak \
	-I$(gtestdir) -I/usr/local/opt/llvm/include -I$(includes) -lpthread $(srcs_test) -o tester
	./tester
	rm -rf tester
	rm -rf tester.dSYM
