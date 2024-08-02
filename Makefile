# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:11:52 by ssuchane          #+#    #+#              #
#    Updated: 2024/08/02 19:04:32 by ssuchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_PRECOMPILE_FLAGS = -c
C_DEBUG_FLAG = -g

NAME =	push_swap
SRCS =	algorithm.c \
    	errors.c \
		ft_split.c \
    	handle_input.c \
    	op_rotate.c \
    	op_swap_push.c \
		push_cost.c	\
		push_swap.c \
    	setup.c \
		sort.c \
    	update.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(C_PRECOMPILE_FLAGS) $< -o $@ 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug: $(LIBFT)
	$(CC) $(CFLAGS) $(C_DEBUG_FLAG) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus