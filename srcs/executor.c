#include "../includes/libs.h"

long	calc_ast(t_node *node)
{
	long	res;

	res = 0;
	if (!node)
		return (res);

	switch (node->token->type)
	{
		case TOK_INT:
			return (node->token->value);
		case TOK_ADD:
			return (calc_ast(node->left) + calc_ast(node->right));
		case TOK_SUB:
			return (calc_ast(node->left) - calc_ast(node->right));
		case TOK_MUL:
			return (calc_ast(node->left) * calc_ast(node->right));
		case TOK_DIV:
		{
			if (node->right->token->type == TOK_INT && node->right->token->value == 0)
			{
				printf("ERROR (DIVIDE_BY_0)\n");
				exit(1);
			}
			return (calc_ast(node->left) / calc_ast(node->right));
		}
		default :
			return (res);
	}
}
