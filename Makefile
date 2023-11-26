# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:04:03 by avolcy            #+#    #+#              #
#    Updated: 2023/11/26 16:13:43 by avolcy           ###   ########.fr        #
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
CFLAGS = -Wall -Werror -Wextra -g 
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
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC)# -fsanitize=address

$(NAME): $(EXE_OBJ) Makefile $(INC)
	$(BUILT_LIB) $@ $^

$(EXECUT): $(LIB) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ -g #-fsanitize=address

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
