#include "../includes/libs.h"

enum e_type	lexer(char c)
{
	enum e_type	ret;

	if (c == '+')
		ret = TOK_ADD;
	else if (c == '-')
		ret = TOK_SUB;
	else if (c == '*')
		ret = TOK_MUL;
	else if (c == '/')
		ret = TOK_DIV;
	else if (c >= '0' && c <= '9')
		ret = TOK_INT;
	else if (c == '(')
		ret = TOK_PLEFT;
	else if (c == ')')
		ret = TOK_PRIGHT;
	else
		ret = TOK_ELSE;
	return (ret);
}

t_token	*craft_token(char **p)
{
	t_token		*tok;

	while (**p && is_space(**p))
		(*p)++;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (tok);

	tok->type = lexer(**p);
	printf("DEBUG: '%c' type = %u\n", **p, tok->type);

	if (tok->type == TOK_INT)
		tok->value = strtol(*p, p, 10);
	else
	{
		tok->value = 0;
		(*p)++;
	}
	return (tok);
}

t_token	*tokenize(char *av, t_token *tokens)
{
	t_token	*current;
	char	*p;

	current = tokens;
	p = av;
	while (*p != '\0')
	{
		if (*p == '\0')
			current->type = TOK_EOF;
		else
		{
			current->next = craft_token(&p);
			current = current->next;
		}
	}
	return (tokens);
}
