# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:04:03 by avolcy            #+#    #+#              #
#    Updated: 2023/10/26 14:44:11 by avolcy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#=====VARIABLES====#
RM = rm -rf
HEADER = $(INC)
EXE_SRCDIR = srcs
EXECUT = push_swap
NAME = push_swap.a
BUILT_LIB = ar rcs
#-----------------#

#=========PATHS==========#
INC = ./inc/push_swap.h
LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a
#------------------------#

#============FLAGS===================#
CC = gcc
FLAGS = -Wall -Werror -Wextra -c
#-----------------------------------#

#============SRCS============#
#wilcard is used to refer to al the .c of the specified directory
EXE_SRC = $(wildcard $(EXE_SRCDIR)/*.c)
EXE_OBJ = $(EXE_SRC:.c=.o)
#---------------------------#

#===TARGETS===#
all: $(EXECUT)

#===============COMPILATIONS======================#
$(LIB):
	$(MAKE) -C $(LIB_DIR)

%.o: $(EXE_SRCDIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC)


$(NAME): $(EXE_OBJ)
	$(BUILT_LIB) $@ $^

$(EXECUT): $(LIB) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ 
#-------------------------------------------------#

#==============CLEAN_UP======================#
clean:
	@$(RM) $(EXE_OBJ)
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "All objects was deleted successfuly✅"

fclean: clean
	@$(RM) $(EXECUT) $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "push_swap deleted successfuly✅"
#------------------------------------------#

re: fclean all

.PHONY: all clean fclean re
