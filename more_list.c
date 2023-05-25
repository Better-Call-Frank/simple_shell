#include "shell.h"

/**
 * list_len - a function that determines length of linked list
 * @h: first node
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - a function that returns an array of strings
 * @head: pointer to first node
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		if (h->str)
			_puts(h->str);
		else
			_puts("(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * node_starts_with - a function that returns node whose
 * string starts with prefix
 * @node: head
 * @prefix: string
 * @c: next character after prefix
 * Return: node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *pointer = NULL;

	while (node)
	{
		pointer = starts_with(node->str, prefix);
		if (pointer && ((c == -1) || (*pointer == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - a function that gets the index of a node
 * @head: head
 * @node: node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

