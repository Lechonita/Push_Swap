# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 17:12:32 by jrouillo          #+#    #+#              #
#    Updated: 2023/01/30 17:11:08 by jrouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM NAME
NAME = push_swap


# SOURCES
SRC_PATH = src/
SRCS = push_swap.c \
		controls.c \
		stacks.c \
		push.c \
		swap.c \
		rotate.c \
		rev_rotate.c \
		sort.c \
		utils.c \
		smart.c \
		lis.c \
		cost.c \
		cheapest_moves.c \
		cost_utils.c
SRC = $(addprefix $(SRC_PATH), $(SRCS))


# OBJECTS
OBJ_PATH = obj/
OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJS))


# FLAGS
FLAGS = -Wall -Werror -Wextra -fsanitize=address,undefined -g2


# INCLUDE
INC =  -I ./includes/ \
	-I ./libft/


# LIBFT
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a


# FONT COLORS
_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_CYAN=\033[36m


# RULES
all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -n "$(_GREY).${END}"
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@echo "$(_GREY)Compiling${_END}"
	@make -sC $(LIBFT_PATH)
	@echo "$(_GREEN)\n"
	@echo ".____    .___________________________________ _________                       .__.__             .___ ._."
	@echo "|    |   |   \______   \_   _____/\__    ___/ \_   ___ \  ____   _____ ______ |__|  |   ____   __| _/ | |"
	@echo "|    |   |   ||    |  _/|    __)    |    |    /    \  \/ /  _ \ /     \\____ \ |  |  | _/ __ \ / __ |  | |"
	@echo "|    |___|   ||    |   \|     \     |    |    \     \___(  <_> )  Y Y  \  |_> >  |  |_\  ___// /_/ |   \|"
	@echo "|_______ \___||______  /\___  /     |____|     \______  /\____/|__|_|  /   __/|__|____/\___  >____ |   __"
	@echo "        \/           \/     \/                        \/             \/|__|                \/     \/   \/${_END}"

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)
	@echo "$(_GREEN)\n"
	@echo "\______   \    |   \/   _____//   |   \   /   _____/  \    /  \/  _  \\______    \ \_   ___ \  ____   _____ ______ |__|  |   ____   __| _/ | |"
	@echo " |     ___/    |   /\_____  \/    ~    \  \_____  \\    \/\/   /  /_\  \|     ___/ /    \  \/ /  _ \ /     \\____ \ |  |  | _/ __ \ / __ |  | |"
	@echo " |    |   |    |  / /        \    Y    /  /        \\         /    |    \    |     \     \___(  <_> )  Y Y  \  |_> >  |  |_\  ___// /_/ |   \|"
	@echo " |____|   |______/ /_______  /\___|_  /  /_______  / \__/\  /\____|__  /____|      \______  /\____/|__|_|  /   __/|__|____/\___  >____ |   __"
	@echo "                           \/       \/           \/       \/         \/                   \/             \/|__|                \/     \/   \/${_END}"

clean:
	@make -sC $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "${_BOLD}${_CYAN}It's so clean, call me Mr. Clean"
	@echo "                                    ▄▄R▀▀▀▀▀▀▀Φ▄,"
	@echo "                                 ,▄▀'           ╙█▄"
	@echo "                                ╓█'               ▀▌"
	@echo "                                ╫▌ ▄µ,         ,,  █"
	@echo "                                █M ▀▀*▀▀▌   Φ▀▀▀▀█⌐█⌐"
	@echo "                              ╓▄█⌐╔,╔Ñ▓N,ù j,╬▓N.╦═█▓▄"
	@echo "                              █]╓N╙▌  ' ╦M    '    Ω½█M"
	@echo "                              ╙█░  ║█Φ▀╙ ═≈*╙'▀╗▄  M▓█"
	@echo "                               ╟█  ╢█╣█▄▄▄▄▄▄╦⌐╙╜  K█╟"
	@echo "                                ║▌  ███▌╙¥╧M╜*  ╓H █║"
	@echo "                                 █▄╥ ▀██▄      4▀╓█"
	@echo "                                 ▐▌╙████████▓█▄▀▀ █"
	@echo "                                 ║▌ ███████▀╙     █"
	@echo "                          ,,,,╓▄Φ█H ╫█████▀       ║█▓▄▄,,,,"
	@echo "                 ,▄▄K▀▀▀▀▀╙**''*w ' ╝█▀██▌    ,▄▄▓▀╙,ó''**╙╙▀▀▀▀▀Φ▄,"
	@echo "              ,▄▀▀                     '*╙▀▀╙*'   *'               ▀█▄"
	@echo "             ▄▀                                                      '█▄"
	@echo "            █M      ,,;╥,                                              ▀▌"
	@echo "           █╨ ,▄▄█▀▀▀ÅÖ╙*▀▀▄                                ,           ╙█"
	@echo "         .█*  ╫▌═*****═    '▀Φ▄          ,╓▄▄▄▄▄▄▄▄▄▄▄,   ╓▌  ,,╓,,      ╙▌"
	@echo "         █*  ,▄██▀▀╨╜╜╨¥▄▄▄▄▄▄██##ΦΦ▀▀▀▀▀╙''        ''*▀▀▀█▄▀▀*'''*╙▀Φ▄µ  ║▌"
	@echo "        ║▌,▄▀▀    ▄Å▀▀╙└                         ,«═≈       '*         ╫▀▄,█"
	@echo "        ║██'  ╓A*                           .r^'    ''''',,,wXww,,     ┼ ╠▀█M"
	@echo "         █ ,* H                       ,«ⁿ*,▄╦^,,2*≈««≈^'            '  ╙╔ ,█'"
	@echo "         █▀   *═*^^*,2w,,,≈╚*   ,,══*^^*''',,,  '                     ,,Ñ«▀▀*,'^w"
	@echo "       ,,█«══**]««╗ j  ,,╥,«╓═*,≈^*'''']╔▌   ╛ ╠  ⁿ««,,.   ,«═^*,,,*'╓═ⁿ]UA'   H ½"
	@echo "       ½ñ''▐  ╣,  ¼,«▄╜H ╔═'╓*     ,▄▄,*▓   ] ,**≥═*,,'*╥╓╨,═' ,   ß╔▌  ║,ª▌  .  Ñ'"
	@echo "      î▓ ╓ j ▓╓▌ ]▓ ╚M^   æ'   ,═*'    j▌   H ║▀,═'    H ╓╩ ,╨▐▌  ╓ ▓   ╔'║M  û ]╔"
	@echo "      ░▌ █ j▓¿█  ╟▌ ╝   ╓╨    ╔'       ▓   ]  ╓╩ ,^█M ,'é' ╔  ▓   ╩▐▌  j' █   ' ÑH"
	@echo "     ╙▓ ]█  ╔╟▌ ╚█ ╔▌] ▄'    A        ╓▌  ,H,╩  /,/* «'▓  j' ║Γ  j █   M ║M  ╚ ╔]"
	@echo "     ¼▌ H█ / █▄═╨▀╙'* ╣     ñ         ▓   ╚╓▌   ',«^  ▓   ┼ ╓▀   N╔▌  ]  █  ,  H'"
	@echo "    $╝M^ *'  ,,«═*^ÜÑ╫⌐    ╔         j▌  .½█   Ö'     ▌   ╨═\╣  ╔ █ ,,H ╚▀*╙' ]]"
	@echo "   .w«══**«══**''  ],▌     H         █   ñ║H   Ω  ,«*V▓   ,═╫▌xm'*╙''.,««═**«╙═"
	@echo "    ''             ╠║H    :         ╔▌  , ║▌     ,«*  {▀╙*  ,,«═ⁿ*Ω≈~ⁿ^'"
	@echo "                   H█            ,  █   Å ,▀▀Mª** ,«^,^╙╧»»═^^''"
	@echo "                   ì╢▄     *««≈^' 'á▀*╙' ,H╙ºqⁿî2≈ⁿ'"
	@echo "                   ╙ █▄         ,«' ,*,»═^^"
	@echo "                     %╙▀#╦▄╦#ª*' ,ⁿ,═'"
	@echo "                      '╨╦════*^2═^'"
	@echo "                           ''${_END}"

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft