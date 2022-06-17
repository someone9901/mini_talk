# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamssafi <aamssafi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 03:49:27 by aamssafi          #+#    #+#              #
#    Updated: 2022/04/28 18:47:28 by aamssafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME = server
CNAME = client

all : $(SNAME) $(CNAME)

$(SNAME) : server.c
	@gcc -Wall -Wextra -Werror server.c -o $(SNAME)

$(CNAME) : client.c
	@gcc -Wall -Werror -Wextra client.c -o $(CNAME)

clean :
	@rm -f $(SNAME) $(CNAME)

fclean : clean

re : clean all