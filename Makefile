NAME = push_swap


${NAME}:
	cc -Wall -Wextra -Werror -g -o ${NAME} *.c -L./libft -lft

clean:
	rm -f ${NAME}

fclean: clean
	rm -f ${NAME}

re	: fclean ${NAME}

git:
	git add .
	git commit -m ${NAME}
	git push

norm:
	norminette