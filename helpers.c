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
