#include "main.h"

/**
 * print_rev_string - Function to print a string in reverse.
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct (not used in this function).
 * Return: The number of characters printed.
 */
int print_rev_string(va_list args, params_t __attribute__((unused)) *params)
{
	va_list args_copy;
	char *s;
	unsigned int len = 0, str_len;

	va_copy(args_copy, args);
	s = va_arg(args_copy, char *);

	if (!s || (uintptr_t) s == 3)
		return (put_string("(null)"));
	str_len = _strlen(s);
	while (str_len--)
		len += put_char(s[str_len]);
	return ((int)(len));
}

/**
 * print_rot13 - Prints a string in ROT13 encoding.
 * @args: A va_list containing the string to be printed.
 * @params: A pointer to the params_t structure (not used in this function).
 * Return: The number of characters printed.
 */
int print_rot13(va_list args, params_t __attribute__((unused)) *params)
{
	va_list args_copy;
	char *s;
	int base;
	unsigned int len = 0;

	va_copy(args_copy, args);
	s = va_arg(args_copy, char *);

	if (!s || (uintptr_t) s == 3)
		return (put_string("(null)"));
	for (; *s; s++)
	{
		if ((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122))
			base = *s >= 97 ? 97 : 65, len += put_char((*s - base + 13) % 26 + base);
		else
			len += put_char(*s);
	}
	return ((int)(len));
}

/**
 * print_S - Prints a string with non-printable characters
 *      shown in hexadecimal.
 * @args: A va_list containing the string to be printed.
 * @params: A pointer to the params_t structure (not used in this function).
 * Return: The number of characters printed.
 */
int print_S(va_list args, params_t __attribute__((unused)) *params)
{
	va_list args_copy;
	char *s, *hex;
	unsigned int len = 0;

	va_copy(args_copy, args);
	s = va_arg(args_copy, char *);

	if (!s || (uintptr_t) s == 3)
		return (put_string("(null)"));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			len += put_string("\\x");
			hex = convert_to(*s, 16, 0);
			if (!hex[1])
				len += put_char(48);
			len += put_string(hex);
		}
		else
		{
			len += put_char(*s);
		}
	}
	return ((int)(len));
}
