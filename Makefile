NAME		=	fdf

MLX_DIR		=	./minilibx
MLX_LIB		=	$(addprefix $(MLX_DIR), libmlx.a)
MLX_LNK		=	-L ./miniLibX -l mlx -framework OpenGL -framework AppKit

SRCS		=	fdf.c read_map.c split.c ft_atoi.c draw.c utils.c controls.c\
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS		=	$(SRCS:.c=.o)
				
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.PHONY		:	all bonus clean fclean re

all			:	$(NAME)

%.o:			%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) 	:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -lm -o $(NAME)

clean		:	
	@rm -f $(OBJS) $(OBJS_B)

fclean		:	clean
	@rm -f $(NAME) $(NAME_B)

re:			fclean all