.PHONY:	all clean fclean re bonus output clean_output

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	fdf

LIBMLX		=	libmlx.a

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	srcs/

DIR_LIBFT	=	libft/

DIR_MLX		=	mlx/

#DIR_HEAD	=	head/

# ---- Files ---- #

#HEAD		=	fdf.h

SRCS		=	main.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all			:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${LIBMLX} ${LIBFT} #${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${LIBMLX}		:
					make ${LIBMLX} -C ${DIR_MLX}

${LIBFT}		:
					make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile #${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -Imlx -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean_lib		:	
					make clean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

fclean_lib		:	
					make fclean -C ${DIR_LIBFT}
					make fclean -C ${DIR_MLX}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

clean_all		:	clean clean_lib
					${RM} ${DIR_OBJS}

fclean_all		:	fclean fclean_lib
					${RM} ${NAME} ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_MLX}, ${MLX}}

re				:	fclean all
