#include "../includes/libs.h"

void	free_tokens(t_token *arg)
{
	t_token	*current;
	t_token	*next;

	if (!arg)
		return ;
	current = arg;
	while (current->next || next)
	{
		free(current);
		next = current->next;
	}
	free(next);
}

char	*get_token_name(enum e_type type)
{
	if (type == TOK_INT)
		return ("TOK_INT");
	if (type == TOK_ADD)
		return ("TOK_ADD");
	if (type == TOK_SUB)
		return ("TOK_SUB");
	if (type == TOK_MUL)
		return ("TOK_MUL");
	if (type == TOK_DIV)
		return ("TOK_DIV");
	if (type == TOK_PLEFT)
		return ("TOK_PLEFT");
	if (type == TOK_PRIGHT)
		return ("TOK_PRIGHT");
	if (type == TOK_EOF)
		return ("TOK_EOF");
	if (type == TOK_ERROR)
		return ("TOK_ERROR");
	return ("UNKNOWN");
}

int	token_nb(t_token *tokens)
{
	int	i;

	i = 0;
	if (tokens)
	{
		while (tokens->next)
		{
			i++;
			tokens = tokens->next;
		}
	}
	return (i);
}

void	print_tokens(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current->type != TOK_EOF)
	{
		printf("[%s]", get_token_name(current->type));
		if (current->next)
		{
			printf(" ");
			current = current->next;
		}
		else
			break ;
	}
	printf("\n");
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_node *create_node(t_token *token)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (node);
	node->token = token;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	print_ast(t_node *node, int depth)
{
	int			i;

	if (!node)
		return ;
	i = 0;
	while (i < depth)
	{
		printf("	");
		i++;
	}
	switch (node->token->type)
	{
		case TOK_ADD:
			printf("[+]\n");
			break ;
		case TOK_SUB:
			printf("[-]\n");
			break ;
		case TOK_DIV:
			printf("[/]\n");
			break ;
		case TOK_MUL:
			printf("[*]\n");
			break ;
		default :
			printf("[%ld]\n", node->token->value);
			break ;
	}
	print_ast(node->left, depth + 1);
	print_ast(node->right, depth + 1);
	return ;
}
