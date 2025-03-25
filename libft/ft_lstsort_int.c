#include "libft.h"

void ft_lstsort_int(int *lst, int size)
{
	int wrapper;
	int i;

	i = 0;
	while (i < (size - 1))
	{
		if (lst[i] > lst[i + 1])
		{
			wrapper = lst[i];
			lst[i] = lst[i + 1];
			lst[i + 1] = wrapper;
			i = 0;
		}
		else
			i++;
	}
}
