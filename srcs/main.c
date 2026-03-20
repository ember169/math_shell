#include "../includes/libs.h"

int	main(int ac, char **av)
{
	t_token	*tokens;

	if (ac < 2)
		return (1);
	tokens = malloc(sizeof(t_token));
	if (!tokens)
		return (printf("ERROR\n"));
	if (!tokenize(av[1], tokens))
		return (printf("ERROR\n"));
	print_tokens(tokens);
	free_tokens(tokens);
	return (0);
}
