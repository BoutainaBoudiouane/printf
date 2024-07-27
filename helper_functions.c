#include "main.h"

/**
 * put_char - Function to write a character to the standard output.
 * @c: The character to be written.
 * Return: On success, returns 1. Otherwise, returns -1.
 * Done by Boutaina and Ali.
 */
int put_char(int c)
{
	static int i;
	static char buf[BUF_SIZE];

	if (c == EOF || i >= BUF_SIZE)
		write(1, buf, i), i = 0;
	if (c != EOF)
		buf[i++] = (char) c;
	return (1);
}

/**
 * put_string - Function to write a null-terminated string
 *              to the standard output.
 * @s: The input string to be written.
 * Return: The number of characters written.
 */
int put_string(const char *s)
{
	const char *_start = s;

	while (*s)
		put_char(*s++);
	return ((int)(s - _start));
}

/**
 * is_flag - Check if a given character is inside the given string.
 * @c: The character to check for.
 * @string: The string to search in.
 * Return: 1 if the character is found, 0 otherwise.
 */
int is_flag(char c, const char *string)
{
	if (string == NULL)
		return (0);
	while (*string)
		if (c == *string++)
			return (1);
	return (0);
}

/**
 * _strlen - Function to calculate the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
