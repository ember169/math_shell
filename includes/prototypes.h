#ifndef PROTOTYPES_H
# define PROTOTYPES_H

t_token	*tokenize(char *av, t_token *tokens);
void	print_tokens(t_token *tokens);
void	free_tokens(t_token *arg);
int		is_digit(char c);
int		is_space(char c);

#endif