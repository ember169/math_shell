/* ************************************************************************** */
/*                                                                            */
/*  RECURSIVE DESCENT PARSER	                                              */
/*                                                                            */
/*  Recursively builds an ABSTRACT SYNTAX TREE from the tokenized input.      */
/*                                                                            */
/*  Input:                                                                    */
/*  	t_tokens *tokens	  Pointer to the tokenized user input (av[1]) 	  */
/*                                                                            */
/*  Levels of priority:                                                       */
/*  	- parse_expr	 lv1  Lowest priority (+ and -). Calls lv2.			  */
/*  	- parse_term	 lv2  Medium priority (* and /). Calls lv3.           */
/*  	- parse_factor	 lv3  Highest priority (INT and (EXPR)).              */
/*                                                                            */
/*  Note:																	  */
/*  	If parse_factor finds '(', it calls parse_expr (recursion loop).	  */
/*                                                                            */
/*  Output:                                                                   */
/*  	t_node *node		  Pointer toward the AST "root" node			  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libs.h"

/*
** parse_factor:
**     Handles INT. If '(' or ')' consumes token and sends it back to 
**	   parse_expression.
**
**     @param *token  Pointer to currently processed token.
**     @return *node  Pointer to made node.
*/
t_node	*parse_factor(t_token **token)
{
	t_node	*node;

	node = NULL;
	if ((*token)->type == TOK_INT)
		node = create_node(*token);
	else if ((*token)->type == TOK_PLEFT || (*token)->type == TOK_PRIGHT)
	{
		*token = (*token)->next;
		node = parse_expression(token);
	}
	*token = (*token)->next;
	return (node);
}

/*
** parse_term:
**     Handles * and /
**
**     @param *token  Pointer to currently processed token.
**     @return *node  Pointer to made node.
*/
t_node	*parse_term(t_token **token)
{
	t_node	*parent;
	t_node	*node;

	node = parse_factor(token);
	while ((*token)->type == TOK_DIV || (*token)->type == TOK_MUL)
	{
		parent = create_node(*token);
		parent->left = node;
		*token = (*token)->next;
		parent->right = parse_factor(&*token);
		node = parent;
	}
	return (node);
}

/*
** parse_expression:
**     Handles + and -
**
**     @param *token  Pointer to currently processed token.
**     @return *ast   Pointer to ast (where to put nodes).
**     @return Valeur Pointer to "root" nodes.
*/
t_node	*parse_expression(t_token **token)
{
	t_node	*parent;
	t_node	*node;

	node = parse_term(token);
	while ((*token)->type == TOK_ADD || (*token)->type == TOK_SUB)
	{
		parent = create_node(*token);
		parent->left = node;
		*token = (*token)->next;
		parent->right = parse_term(&*token);
		node = parent;
	}
	return (node);
}
