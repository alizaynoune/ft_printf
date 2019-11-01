# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/31 14:45:40 by alzaynou          #+#    #+#              #
#    Updated: 2019/04/07 16:57:27 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_*.c
GCC = gcc -c -Wall -Werror -Wextra
all: $(NAME)

$(NAME):
	$(GCC) $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
