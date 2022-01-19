# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 01:49:38 by cbeaurai          #+#    #+#              #
#    Updated: 2021/09/27 20:16:10 by cbeaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

SRC  	= parse/parse.c error/wrong.c parse/parse_utils.c utils/utils.c \
		  parse/check_map.c utils/mlx_utils.c window/display.c window/hooks.c \
		  window/moves.c window/display_utils.c window/bg_utils.c
		  
OBJS 	= $(SRC:.c=.o)

CC 	 	= clang

CFLAGS 	= -Wall -Werror -Wextra

ARRCS	= ar rcs

LFT		= ./global

LIB	=  -L. -l_solong -L ./global -lft -L ./mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd 

RM		= rm -f

all		: $(LFT) $(OBJS) ${NAME}

.c .o	:
#			${CC} ${CFLAGS} -Imlx -c $< -o $(<:.c=.o)	#mac
			${CC} ${CFLAGS} -I ./inc -I ./mlx_linux -c $< -o $(<:.c=.o)  #linux

MAKE_LIB= ${MAKE} -C ${LFT}

${NAME}	:	${OBJS}
#			${MAKE_LIB}							#Mac
			${MAKE_LIB} && make -C ./mlx_linux  #Linux
			${ARRCS} lib_solong.a ${OBJS}
#			${CC} ${CFLAGS} main.c -o ${NAME} -Lmlx -lmlx -framework OpenGL -framework AppKit -L./global -lft -L. -l_solong #mac
			${CC} ${CFLAGS} main.c -o ${NAME} ${LIB}	#linux

clean	:
			${RM} ${OBJS} lib_solong.a
			${MAKE_LIB} clean

fclean	:	clean
			${RM} ${NAME}
			${MAKE_LIB} fclean

re		:	fclean all
