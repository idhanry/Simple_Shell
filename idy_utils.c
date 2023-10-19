#include "shell.h"
/**
 * _memcpy - Memory from the source to destination copies
 * @dest: The destination
 * @src: The source
 * @n: The memory size to be copied
 * Return: The destination memory
 */
void *_memcpy(void *dest, void *src, size_t n)
{
	char *cdest = (char *)(dest);
	const char *csrc = (const char *)(src);
	size_t i = 0;

	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
/**
 * _realloc - The realloc function
 * @ptr: The old pointer malloc
 * @size: The new size
 * Return: The new ptr
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
/**
 * _strdup - strdup()
 * @s: The string
 * Return: The duplicate of s
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	_memcpy(new_str, s, len);

	return (new_str);
}
/**
 * _strcat - strcat()
 * @dest: The string destination
 * @src: string source
 * Return: The string concatenate
 */
char *_strcat(char *dest, const char *src)
{
	char *p = dest;
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		p[i] = src[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
/**
 * _strchr - The strchr implementation
 * @str: The string to search.
 * @character: The find character.
 * Return: The str pointer
 */
char *_strchr(const char *str, int character)
{
    /*Loop through the str until char is found*/
	while (*str)
	{
		if (*str == character)
		{
			return ((char *)str);/*Return the address of the char*/
		}
		str++;
	}
	return (NULL);
}
