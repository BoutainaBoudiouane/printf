#include "main.h"

/**
 * print_octal - Function to print an octal number.
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct.
 * Return: The number of characters printed.
 */
int print_octal(va_list args, params_t *params)
{
	unsigned long digit;
	int len = 0;
	va_list args_copy;

	va_copy(args_copy, args);
	if (params->l_modifier)
		digit = (unsigned long) va_arg(args_copy, long);
	else if (params->h_modifier)
		digit = (unsigned short int) va_arg(args_copy, int);
	else
		digit = (unsigned int) va_arg(args_copy, int);
	if (params->hashtag_flag && digit)
		len += put_char(48), params->width ? params->width-- : 0;
	params->is_unsign = TRUE;
	return (len += print_number(convert_to(digit, 8, TO_UNSIGNED), params));
}

/**
 * print_hex - Function to print a hexadecimal number in lowercase.
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct.
 * Return: The number of characters printed.
 */
int print_hex(va_list args, params_t *params)
{
	unsigned long digit;
	int len = 0;
	va_list args_copy;

	va_copy(args_copy, args);
	if (params->l_modifier)
		digit = (unsigned long) va_arg(args_copy, long);
	else if (params->h_modifier)
		digit = (unsigned short int) va_arg(args_copy, int);
	else
		digit = (unsigned int) va_arg(args_copy, int);
	if (params->hashtag_flag && digit)
		len += put_string("0x"), params->width ? params->width -= 2 : 0;
	params->is_unsign = TRUE;
	return (len += print_number(convert_to(digit, 16,
					TO_LOWER | TO_UNSIGNED), params));
}

/**
 * print_HEX - Function to print a hexadecimal number in uppercase.
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct.
 * Return: The number of characters printed.
 */
int print_HEX(va_list args, params_t *params)
{
	unsigned long digit;
	int len = 0;
	va_list args_copy;

	va_copy(args_copy, args);
	if (params->l_modifier)
		digit = (unsigned long) va_arg(args_copy, long);
	else if (params->h_modifier)
		digit = (unsigned short int) va_arg(args_copy, int);
	else
		digit = (unsigned int) va_arg(args_copy, int);
	if (params->hashtag_flag && digit)
		len += put_string("0X"), params->width ? params->width -= 2 : 0;
	params->is_unsign = TRUE;
	return (len += print_number(convert_to(digit, 16, TO_UNSIGNED), params));
}

/**
 * print_binary - Function to print an unsigned decimal number in binary format
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct.
 * Return: The number of characters printed.
 */
int print_binary(va_list args, params_t *params)
{
	unsigned long digit;
	int len = 0;
	va_list args_copy;

	va_copy(args_copy, args);
	digit = (unsigned int)va_arg(args_copy, int);
	if (params->hashtag_flag && digit)
		len += put_char(48), params->width ? params->width-- : 0;
	return (len += print_number(convert_to(digit, 2, 0), params));
}
