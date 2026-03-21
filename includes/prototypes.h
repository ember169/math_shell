#ifndef PROTOTYPES_H
# define PROTOTYPES_H

// TOKENIZATION
t_token	*tokenize(char *string);
t_node	*craft_tree(t_token *tokens);

// UTILS
void	free_tokens(t_token *arg);
int		token_nb(t_token *tokens);
void	print_tokens(t_token *tokens);
int		is_digit(char c);
int		is_space(char c);

#endif