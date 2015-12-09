NAME = wolf3d

SRC_DIR = srcs/

SRC = main.c \
	  key_hook.c \
	  img_put.c \
	  init.c \
	  draw.c \
	  ray.c \
	  map.c \
	  clean.c \
	  init2.c

OBJ			=	$(SRC:.c=.o)

INC			=	-I./includes -I./libft/includes
LINK		=	-Llibft -lft $(LDFLAGS) $(MLXFLAGS)

CFLAGS		=	-Wall -Wextra -Werror -g3 -g -pedantic
EXTRAFLAGS	=	--analyze -Weverything -Wno-missing-prototypes -Qunused-arguments
LDFLAGS		=	-L/usr/X11/lib
MLXFLAGS	=	-L $(INC_MLX) -lmlx -framework OpenGL -framework AppKit	 -g
FLAGS		=	$(CFLAGS) $(MLXFLAGS) $(LDFLAGS)
INC_MLX		=	minilibx

CC			=	gcc
RM			=	rm -v

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	make -C minilibx/ clean
	make -C minilibx/
	make -C libft/ fclean
	make -C libft/
	$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean		:
	make -C minilibx/ clean
	make -C libft/ clean
	$(RM) -f $(OBJ)

fclean		:	clean
	make -C minilibx/ clean
	make -C libft/ fclean
	$(RM) -f $(NAME)

re			:	fclean all

%.o			:	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
