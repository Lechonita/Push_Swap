# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 17:12:32 by jrouillo          #+#    #+#              #
#    Updated: 2023/02/02 14:25:37 by jrouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM NAME
NAME = push_swap
NAME_CHECKER = checker


# PATH
SRC_PATH = src/
OBJ_PATH = obj/


# SOURCES PUSH SWAP
SRC_PS = push_swap.c \
		controls.c \
		utils.c \
		smart.c \
		lis.c \
		cost.c \
		cheapest_moves.c \
		cost_utils.c \
		swap.c \
		rotate.c \
		rev_rotate.c \
		push.c \
		stacks.c \
		sort.c


# SOURCES CHECKER
SRC_CHK = checker_bonus.c \
			get_next_line_bonus.c \
			controls.c \
			utils.c \
			smart.c \
			lis.c \
			cost.c \
			cheapest_moves.c \
			cost_utils.c \
			swap.c \
			rotate.c \
			rev_rotate.c \
			push.c \
			stacks.c \
			sort.c


# SOURCE FILES
SRC_PS2 = $(addprefix $(SRC_PATH)pushswap/, $(SRC_PS))
SRC_CHK2 = $(addprefix $(SRC_PATH)checker/, $(SRC_CHK))


# OBJECTS
OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CHK = $(SRC_CHK:.c=.o)


# OBJECT FILES
OBJ_PS2 = $(addprefix $(OBJ_PATH), $(OBJ_PS))
OBJ_CHK2 = $(addprefix $(OBJ_PATH), $(OBJ_CHK))


# FLAGS
FLAGS = -Wall -Werror -Wextra


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


# PUSH SWAP RULES
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
	@echo " __    ____  ____  ____  ____     ___  _____  __  __  ____  ____  __    ____  ____  "
	@echo "(  )  (_  _)(  _ \( ___)(_  _)   / __)(  _  )(  \/  )(  _ \(_  _)(  )  ( ___)(  _ \ "
	@echo " )(__  _)(_  ) _ < )__)   )(    ( (__  )(_)(  )    (  )___/ _)(_  )(__  )__)  )(_) )"
	@echo "(____)(____)(____/(__)   (__)    \___)(_____)(_/\/\_)(__)  (____)(____)(____)(____/\n${_END}"

$(NAME): $(OBJ_PS2)
	@gcc $(FLAGS) $(OBJ_PS2) $(LIBFT) $(INC) -o $(NAME)
	@echo "$(_GREEN)\n"
	@echo " ____  __  __  ___  _   _    ___  _    _    __    ____     ___  _____  __  __  ____  ____  __    ____  ____  "
	@echo "(  _ \(  )(  )/ __)( )_( )  / __)( \/\/ )  /__\  (  _ \   / __)(  _  )(  \/  )(  _ \(_  _)(  )  ( ___)(  _ \ "
	@echo " )___/ )(__)( \__ \ ) _ (   \__ \ )    (  /(__)\  )___/  ( (__  )(_)(  )    (  )___/ _)(_  )(__  )__)  )(_) )"
	@echo "(__)  (______)(___/(_) (_)  (___/(__/\__)(__)(__)(__)     \___)(_____)(_/\/\_)(__)  (____)(____)(____)(____/ \n${_END}"


# CHECKER RULES
bonus: all $(OBJ_PATH) $(NAME_CHECKER)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -n "$(_GREY).${END}"
	@gcc $(FLAGS) -c $< -o $@ $(INC)

$(NAME_CHECKER): $(OBJ_CHK2)
	@gcc $(FLAGS) $(OBJ_CHK2) $(LIBFT) $(INC) -o $(NAME_CHECKER)
	@echo "$(_GREEN)\n"
	@echo "  ___  _   _  ____  ___  _  _  ____  ____     ___  _____  __  __  ____  ____  __    ____  ____  "
	@echo " / __)( )_( )( ___)/ __)( )/ )( ___)(  _ \   / __)(  _  )(  \/  )(  _ \(_  _)(  )  ( ___)(  _ \ "
	@echo "( (__  ) _ (  )__)( (__  )  (  )__)  )   /  ( (__  )(_)(  )    (  )___/ _)(_  )(__  )__)  )(_) )"
	@echo " \___)(_) (_)(____)\___)(_)\_)(____)(_)\_)   \___)(_____)(_/\/\_)(__)  (____)(____)(____)(____/ \n${_END}"


# GENERAL RULES
clean:
	@make -sC $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "${_BOLD}${_CYAN}It's so clean, call me Mr. Clean${_END}"
	@echo "${_BOLD}${_CYAN}\n"
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
	@rm -f $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re libft
