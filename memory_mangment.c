#include "main.h"

/**
 **_realloc_ -  Reallocates A Memory Block Using Malloc And Free
 *@ptr: Pointer
 *@old_size: Previous Size Of The Pointer
 *@new_size: New Size Of The Pointer
 *Return: Void Pointer Rellocated Memory
 */
void *_realloc_(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		array_fill(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memocpy_(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * _freeall_ - Free Array Of Char Pointer And Char Pointer
 * @cmd:Array Pointer
 * @line:Char Pointer
 * Return: Void
 */
void _freeall_(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memocpy_ - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Much You Will Copy)
 *Return: Void Pointer
 */
char *_memocpy_(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * array_fill - Fill An Array By Constant Byte
 * @a:Void Pointer
 * @el: Int
 * @len:Length Int
 *Return: Void Pointer
 */
void *array_fill(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc_ -  Allocates Memory For An Array, Using Malloc.
 * @size: Size
 * Return: Void Pointer
 */
void *_calloc_(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
