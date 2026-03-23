#include "../includes/libs.h"

int	main(int ac, char **av)
{
	t_token	*tokens;
	t_node	*ast;

	if (ac < 2)
		return (1);

	tokens = tokenize(av[1]);
	if (!tokens)
		return (printf("ERROR\n"));
	// print_tokens(tokens);

	ast = malloc(sizeof(t_node));
	if (!ast)
		return (free_tokens(tokens), printf("ERROR\n"));
	ast = parse_expression(&tokens);
	print_ast(ast, 0);
	free_tokens(tokens);
	return (0);
}
