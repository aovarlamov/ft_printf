# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 17:11:04 by kbethel           #+#    #+#              #
#    Updated: 2020/01/31 10:55:56 by kbethel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES = ft_printf.c \
			check_struct.c \
			change_width.c \
			ft_ftoa_prf.c \
			ft_itoa_plus.c \
			ft_strnchr.c \
			param_flags.c \
			param_others.c \
			param.c \
			print_bx.c \
			print_c.c \
			print_d_i.c \
			print_f.c \
			print_o.c \
			print_p.c \
			print_proc.c \
			print_s.c \
			print_u.c \
			print_x.c \
			writer.c \
			add_flags.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all