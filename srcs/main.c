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
	printf("\n=== TOKENS ===\n\n");
	print_tokens(tokens);

	ast = malloc(sizeof(t_node));
	if (!ast)
		return (free_tokens(tokens), printf("ERROR\n"));
	ast = parse_expression(&tokens);
	printf("\n=== A.S.T. ===\n\n");
	print_ast(ast, 0);
	printf("\n=== RESULT ===\n\n");
	printf("Result: %ld\n\n", calc_ast(ast));
	free_tokens(tokens);
	free_ast(ast);
	return (0);
}
