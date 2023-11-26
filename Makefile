# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:04:03 by avolcy            #+#    #+#              #
#    Updated: 2023/11/26 20:10:27 by avolcy           ###   ########.fr        #
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
CC = cc
CFLAGS = -Wall -Werror -Wextra  
#-----------------------------------#

#============SRCS============#
#wilcard is used to refer to al the .c of the specified directory
EXE_SRC = $(EXE_SRCDIR)/ft_bigsort2.c $(EXE_SRCDIR)/ft_push.c \
		  $(EXE_SRCDIR)/ft_sort3.c $(EXE_SRCDIR)/ft_utils.c \
		  $(EXE_SRCDIR)/ft_error.c $(EXE_SRCDIR)/ft_revrotate.c \
		  $(EXE_SRCDIR)/ft_sort5.c $(EXE_SRCDIR)/push_swap.c \
		  $(EXE_SRCDIR)/ft_input.c $(EXE_SRCDIR)/ft_rotate.c \
		  $(EXE_SRCDIR)/ft_swap.c
EXE_OBJ = $(EXE_SRC:.c=.o)
#---------------------------#

#===TARGETS===#
all: $(EXECUT)

#===============|___COMPILATIONS__|======================#
$(LIB):
	@$(MAKE) -C $(LIB_DIR)
#-------------------------------------------------#

%.o: $(EXE_SRCDIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC)#-fsanitize=address
#------------------------------------------------------------#

$(NAME): $(EXE_OBJ) Makefile $(INC)
	$(BUILT_LIB) $@ $^
#-----------------------------------#

$(EXECUT): $(LIB) $(NAME)
	$(CC) $(CFLAGS) $^ -o $@ #-g -fsanitize=address
#--------------------------------------------------#

.PHONY: all clean fclean re

#=============|_CLEAN_UP_|=======================#
clean:
	@$(RM) $(EXE_OBJ)
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "All objects was deleted successfuly✅"

fclean: clean
	@$(RM) $(EXECUT) $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "push_swap deleted successfuly✅"
#------------------------------------------------#

re: fclean all
#--------------#
