#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//silincek
#include <stdio.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int size_a;
	int size_b;
} t_stack;

void print_stack_a(t_stack *stack);

//error
void	ft_free(char **argv, t_stack *stack, int control);
void	ft_free_list(char **av, t_stack *stack, int control);

//split
char	**ft_split(char const *s, char c);

int	ft_first_seperation(t_stack *stack, int len);

//ft_atoi
int	ft_ps_atoi(char *str, t_stack *stack, char **av, int control);

//utils
int	find_len(char **list);
int	ft_sort(t_stack *stack, int size);
int sort_three(t_stack *s);
int is_sorted(t_stack *stack);

// RULES A
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	pa(t_stack *stack);

// RULES B
void sb(t_stack *stack);
void rb(t_stack *stack);
void rrb(t_stack *stack);
void pb(t_stack *stack);
void	rr(t_stack	*s, int print);
void	ss(t_stack	*s, int print);

int ft_quicksort_a(t_stack *stack, int len, int count);
int ft_quicksort_b(t_stack *stack, int len, int count);

int	ft_sort_small_a(t_stack *s);
int	ft_sort_small_a2(t_stack *s, int len);
int	ft_sort_small_b(t_stack *s, int len);

void	bubble_sort(int *tmp_stack, int size);
int	find_pivot(int *pivot, int *stack_a, int size);
int	ft_is_sorted(int *stack_a, int size, int flag);
int	ft_push(t_stack *stack, int len, int flag);

//utils_funcs
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif