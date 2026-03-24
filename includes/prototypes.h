#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// TOKENIZATION
t_token	*tokenize(char *string);

// PARSING
t_node	*parse_expression(t_token **token);

// EXECUTION
long	calc_ast(t_node *node);

// UTILS
void	free_tokens(t_token *arg);
int		token_nb(t_token *tokens);
void	print_tokens(t_token *tokens);
int		is_digit(char c);
int		is_space(char c);
t_node	*create_node(t_token *token);
void	print_ast(t_node *node, int depth);
void	free_ast(t_node *head);


#endif