#include "shell.h"

/**
 * add_node - a function that adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: string field of node
 * @num: number
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *n_head;

	if (!head)
		return (NULL);
	n_head = malloc(sizeof(list_t));
	if (!n_head)
		return (NULL);
	_memset((void *)n_head, 0, sizeof(list_t));
	n_head->num = num;
	if (str)
	{
		n_head->str = _strdup(str);
		if (!n_head->str)
		{
			free(n_head);
			return (NULL);
		}
	}
	n_head->next = *head;
	*head = n_head;
	return (n_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: string
 * @num: node index used by history
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - a function that prints str element of a list_t linked list
 * @h: pointer to first node
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 * Return: 1 on success, 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *c_node, *p_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		c_node = *head;
		*head = (*head)->next;
		free(c_node->str);
		free(c_node);
		return (1);
	}
	c_node = *head;
	while (c_node)
	{
		if (i == index)
		{
			p_node->next = c_node->next;
			free(c_node->str);
			free(c_node);
			return (1);
		}
		i++;
		p_node = c_node;
		c_node = c_node->next;
	}
	return (0);
}

/**
 * free_list - a function that frees all nodes of a list
 * @head_ptr: pointer to head node
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *c_node, *next_node, *f_node;

	if (!head_ptr || !*head_ptr)
		return;
	f_node = *head_ptr;
	c_node = f_node;
	while (c_node)
	{
		next_node = c_node->next;
		free(c_node->str);
		free(c_node);
		c_node = next_node;
	}
	*head_ptr = NULL;
}

