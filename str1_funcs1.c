#include "shell.h"

/**
* _strcat - The two strings concatenates
* @dest: The pointer to string destination.
* @src: The pointer to string source.
*
* * Return: The pointer to string destination.
*/

char *_strcat(char *dest, const char *src)
{
	char *destTemp = dest;
	const char *srcTemp = src;
		while (*destTemp != '\0')

	{
			destTemp++;
	}

		while (*srcTemp != '\0')
	{
			*destTemp++ = *srcTemp++;
	}
	*destTemp = '\0';

	return (dest);
}

/**
 * * _strncat - Two strings concatenates where n number
 * * of bytes are copied from the source.
 * * @dest: The pointer to string destination.
 * * @src: The pointer to string source.
 * * @n: The src number of bytes to copy from..
 * *
 * * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

		for (i = 0; i < n && src[i] != '\0'; i++)
	{
			dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
i}

