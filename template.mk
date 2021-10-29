# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    template.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:49:12 by agautier          #+#    #+#              #
#    Updated: 2021/10/29 15:05:05 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TEMPLATE_MK
	TEMPLATE_MK = 1

S		=	
I		=	./
O		=	obj/
D		=	dep/


OBJ			=	$(SRC:$S%.cpp=$O%.o)
DEP			=	$(SRC:$S%.cpp=$D%.d)

CXX			=	c++

CXXFLAGS	+=	-I$I
CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS	+=	-g3 -fsanitize=address

LDFLAGS		+=	-g3 -fsanitize=address

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.cpp
	$(CXX) $(CXXFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(wildcard $(OBJ))
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)

endif
