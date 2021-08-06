# include "mylibrary.h"
#include "Fill_the_void.h"

t_tet	*lstnew_tetri(const char *str, char fill)
{
	t_tetri	*tetri;
	t_tet	*node;

	if (!(tetri = create_tetrimino(str, fill)))
		return (NULL);
	if (!(node = ft_lstnew((void *)tetri, sizeof(*tetri))))
	{
		free_tetrimino(&tetri);
		return (NULL);
	}
	return (node);
}

/*
** Frees a list of tetriminoes
*/

void	lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

/*
** The function lstadd_tetri() adds a tetrimino to the tlist of tetriminoes,
** assigning the correct letter for the tetriminoes' order.
*/

int		lstadd_tetri(t_tet **head, t_tet **tail, char *t_str, int t_count)
{
	if (t_count && ((*tail)->next =
		lstnew_tetri(t_str, 'A' + t_count)))
		*tail = (*tail)->next;
	else if ((*head = lstnew_tetri(t_str, 'A' + t_count)))
		*tail = *head;
	else
	{
		ft_lstdel(head, &lstdel_tetri);
		return (-1);
	}
	return (0);
}