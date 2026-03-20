NAME		:= math_shell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
INC			:= includes

SRCSDIR		:= srcs
OBJSDIR		:= objs

SRCS		:=	main.c \
				tokenizer.c \
				parser.c \
				executor.c \
				utils.c
OBJS		:= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re