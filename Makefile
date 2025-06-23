# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 17:01:46 by vhasanov          #+#    #+#              #
#    Updated: 2025/06/13 19:30:50 by vhasanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_count.c ft_init_stack.c ft_isEmpty.c ft_pop.c ft_push_swap.c \
	   ft_push.c ft_quick_sort.c ft_r_rotate.c ft_rotate.c ft_swap.c main.c \
	   ft_sort3.c ft_stack_op.c ft_free_stack.c ft_error_handler.c
	   
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I. -Ilib_ft

NAME = push_swap

LIBFT_DIR = lib_ft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	
clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)
	
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: all clean fclean re