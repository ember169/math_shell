/* ************************************************************************** */
/*                                                                            */
/*  TOKENIZER / LEXER			                                              */
/*                                                                            */
/*  Uses a set of rules (LEXER) to transform characters into tokens.	      */
/*                                                                            */
/*  Input:                                                                    */
/*  	char 	*string	 Pointer to the user input (av[1]) 	  				  */
/*                                                                            */
/*  Functions:                                                      		  */
/*  	- tokenize		 Init list head, asks for tokens, init list tail	  */
/*  	- craft_token	 Init and return single token, moves pointers	      */
/*  	- lexer	 		 Return given char token type according to ruleset	  */
/*                                                                            */
/*  Note:																	  */
/*  	Usage of pointer arithmetic in order to keep up with strtol			  */
/*                                                                            */
/*  Output:                                                                   */
/*  	t_token *token		  Pointer toward the head of token list		 	  */
/*                                                                            */
/* ************************************************************************** */

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
		ret = TOK_ERROR;
	return (ret);
}

t_token	*craft_token(char **p)
{
	t_token		*tok;

	tok = malloc(sizeof(t_token));
	if (!p || !tok)
		return (tok);

	tok->type = lexer(**p);
	// printf("DEBUG: '%c' type = %u\n", **p, tok->type);
	tok->next = NULL;

	if (tok->type == TOK_INT)
		tok->value = strtol(*p, p, 10);
	else
	{
		tok->value = 0;
		(*p)++;
	}
	return (tok);
}

t_token	*tokenize(char *string)
{
	t_token	head;
	t_token	*current;
	char	*p;

	head.next = NULL;
	current = &head;
	p = string;
	while (*p)
	{
		while (*p && is_space(*p))
			p++;
		if (*p == '\0')
			break ;
		current->next = craft_token(&p);
		current = current->next;
	}

	current->next = malloc(sizeof(t_token));
	if (!current->next)
		return (current->next);
	current->next->type = TOK_EOF;
	current->next->next = NULL;

	return (head.next);
}
