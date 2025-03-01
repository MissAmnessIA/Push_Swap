NAME				= push_swap

LIBFT				= libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

 
SRC					= $(SRC_DIR)get_nodes.c \
					  $(SRC_DIR)check_args.c \
					  $(SRC_DIR)create_stack_a.c \
					  $(SRC_DIR)moves.c \
					  $(SRC_DIR)push_swap.c \
					  $(SRC_DIR)set_values.c \
					  $(SRC_DIR)sort_stacks.c \
					  $(SRC_DIR)target_node.c \
					  $(SRC_DIR)utils_list.c \
					  $(SRC_DIR)utils.c

OBJ					= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

start:
						@make all

$(LIBFT):
						@make -C ./libft

all:				$(NAME)

$(NAME):			$(OBJ) $(LIBFT)
						@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)
						@make clean -C ./libft

fclean:				clean
						@$(RM) $(NAME)
						@$(RM) $(LIBFT)

re:					fclean all

.PHONY:				start all clean fclean re