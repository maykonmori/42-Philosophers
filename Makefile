# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 21:11:58 by mjose-ye          #+#    #+#              #
#    Updated: 2022/04/05 20:55:10 by mjose-ye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

HEADER = philosophers.h

INCLUDE = -I ./includes/

FOLDER = ./src/

FOLDER_OBJS = ./objs/

SRC =	$(FOLDER)philosophers.c $(FOLDER)validate.c $(FOLDER)utils.c \
		$(FOLDER)init.c $(FOLDER)func_philo.c $(FOLDER)actions.c

OBJS =	$(patsubst $(FOLDER)%.c, $(FOLDER_OBJS)%.o, $(SRC))

CC = gcc -g

CFLAGS = -Wextra -Werror -Wall

all:$(NAME)

$(FOLDER_OBJS)%.o: $(FOLDER)%.c
	@mkdir -p $(FOLDER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) ./objs/*.o -o  $(NAME) -pthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all