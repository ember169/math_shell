#ifndef STRUCTURES_H
# define STRUCTURES_H

enum e_type
{
	TOK_INT,
	TOK_ADD,
	TOK_SUB,
	TOK_MUL,
	TOK_DIV,
	TOK_PLEFT,
	TOK_PRIGHT,
	TOK_EOF,
	TOK_ERROR
};

typedef struct s_token
{
	enum e_type		type;
	long			value;
	struct s_token	*next;
}	t_token;

typedef struct s_node
{
	t_token			*token;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

#endif