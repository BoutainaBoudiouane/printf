#include "main.h"

/**
 * print_char - Print a single character.
 * @args: va_list pointing to the character argument.
 * @params: Pointer to the parameters structure.
 * Return: Number of characters printed (always 1 for a single char).
 */
int print_char(va_list args, params_t *params)
{
	unsigned int width = params->width ? params->width : 1, len = 0;
	va_list args_copy;
	int ch;

	va_copy(args_copy, args);
	ch = va_arg(args_copy, int);
	if (params->minus_flag)
		len += put_char(ch);
	while (--width)
		len += put_char(32);
	if (!params->minus_flag)
		len += put_char(ch);
	return ((int)(len));
}

/**
 * print_string - Print a null-terminated string.
 * @args: va_list pointing to the string argument.
 * @params: Pointer to the parameters structure.
 * Return: Number of characters printed.
 */
int print_string(va_list args, params_t *params)
{
	va_list args_copy;
	char *s;
	unsigned int width = params->width, precision = params->precision;
	unsigned int len = 0, str_len = 0, print_len = 0;

	va_copy(args_copy, args);
	s = va_arg(args_copy, char *);
	if (!s)
		s = "(null)";
	while (s[print_len] && (precision == UINT_MAX || print_len < precision))
		print_len++, str_len++;
	if (params->minus_flag)
		while (print_len--)
			len += put_char(*s++);
	while (width-- > str_len)
		len += put_char(32);
	if (!params->minus_flag)
		while (print_len--)
			len += put_char(*s++);
	return ((int)(len));
}

/**
 * print_int - Function to print an integer.
 * @args: The va_list containing the integer argument.
 * @params: The parameters struct specifying formatting options.
 * Return: The number of characters printed.
 */
int print_int(va_list args, params_t *params)
{
	long digit;
	va_list args_copy;

	va_copy(args_copy, args);
	if (params->l_modifier)
		digit = va_arg(args_copy, long);
	else if (params->h_modifier)
		digit = (short int) va_arg(args_copy, int);
	else
		digit = (int) va_arg(args_copy, int);
	return (print_number(convert_to(digit, 10, 0), params));
}

/**
 * print_percent - Function to print a percent sign.
 * @args: The va_list containing the arguments (unused).
 * @params: The pointer to the params_t struct (unused).
 * Return: Always returns 1 (number of characters printed).
 */
int print_percent(va_list args __attribute__((unused)),
				  params_t *params __attribute__((unused)))
{
	return (put_char('%'));
}
