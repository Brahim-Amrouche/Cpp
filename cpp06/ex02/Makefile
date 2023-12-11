NAME = convert

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Base.cpp main.cpp A.cpp B.cpp C.cpp

CC = c++

OBJECT_FILES = $(patsubst %.cpp,%.o,$(SRCS))

%.o : %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJECT_FILES)
	$(CC) $(FLAGS) $^ -o $(NAME)

clean :
	rm -rf ${OBJECT_FILES}

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re