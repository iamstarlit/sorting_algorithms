#include "sort.h"

/**
 * swap - Swaps the contents of two memory locations of a given size.
 * @a: Pointer to the first memory location.
 * @b: Pointer tot the second memory location.
 * @size: Size of the memory locations to swap, in bytes.
 *
 * Description: The contents of the memory locations are copied
 * to temporary memory before swap, to ensure that the swap is done
 * correctly even if the memory locations overlap.
 */
void swap(void *a, void *b, size_t size)
{
	void *tmp = malloc(size);  /* Allocate temporary memory */

	memcpy(tmp, a, size);  /* Copy contents of `a` to `tmp` */
	memcpy(a, b, size);  /* Copy contents of `b` to `a` */
	memcpy(b, tmp, size);  /* Copy contents of `tmp` to `b` */

	free(tmp);  /* Free temporary memory */
}


/**
 * swap_node - Swaps a node with its previous node.
 * @node: Pointer to node to be swapped.
 * @list: Pointer to the head node of the list.
 *
 * Return: Pointer to the node that was just swapped.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node, *next_node;

	prev_node = node->prev;
	next_node = node->next;

	/* Update the next and prev pointers of the nodes */
	if (prev_node)
		prev_node->next = next_node;

	if (next_node)
		next_node->prev = prev_node;

	node->prev = prev_node->prev;
	prev_node->prev = node;
	prev_node->next = node->next;
	node->next = prev_node;

	/* If the previous node is now the head node */
	if (node->prev == NULL)
		*list = node;

	return (node);
}
