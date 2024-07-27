#include "main.h"

/**
 * convert_to - Convert a number to a string representation in a given base.
 * @nbr: The number to be converted.
 * @base: The base to use for conversion.
 * @flags: Flags to control conversion behavior.
 * Return: A pointer to the string representation of the converted number.
 */
char *convert_to(long int nbr, int base, int flags)
{
	static char buffer[50];
	char *p_nbr = &buffer[49];
	static char *array;
	unsigned long n = (nbr < 0 && !(flags & TO_UNSIGNED)) ? -nbr : nbr;

	*p_nbr = '\0';
	array = (flags & TO_LOWER) ? "0123456789abcdef" : "0123456789ABCDEF";
	do {
		*--p_nbr = array[n % base];
		n /= base;
	} while (n != 0);
	if (!(flags & TO_UNSIGNED) && nbr < 0)
		*--p_nbr = '-';
	return (p_nbr);
}

/**
 * left_shift_number - Function to left-align and print a number
 *      with proper formatting.
 * @s: The string representation of the number to be printed.
 * @params: Pointer to the parameters struct containing formatting flags.
 * Return: The number of characters printed.
 */
int left_shift_number(char *s, params_t *params)
{
	unsigned int len = 0, neg = (!params->is_unsign && *s == '-'),
			str_len = _strlen(s);
	char padding_char = (params->zero_flag && !params->minus_flag) ? 48 : ' ';

	if (neg && str_len < params->width && padding_char == 48)
		s++;
	if (!neg && !params->is_unsign)
	{
		if (params->plus_flag)
			*--s = '+', str_len++;
		else if (params->space_flag)
			*--s = ' ', str_len++;
	}

	len += put_string(s);
	while (str_len++ < params->width)
		len += put_char(padding_char);
	return ((int)(len));
}

/**
 * right_shift_number - Function to right-align and print a number
 *      with proper formatting.
 * @s: The string representation of the number to be printed.
 * @params: Pointer to the parameters struct containing formatting flags.
 * Return: The number of characters printed.
 */
int right_shift_number(char *s, params_t *params)
{
	unsigned int len = 0, neg = (!params->is_unsign && *s == '-'),
	str_len = _strlen(s);
	char padding_char = params->zero_flag ? 48 : ' ';

	if (neg && padding_char == 48)
		len += put_char('-'), s++;
	if (!neg && (params->plus_flag || (!params->plus_flag && params->space_flag)))
		str_len++;
	if (!neg && !params->is_unsign && padding_char == 48)
	{
		if (!params->plus_flag)
		{
			if (params->space_flag)
				len += put_char(' ');
		}
		else
			len += put_char('+');
	}
	while (str_len++ < params->width)
		len += put_char(padding_char);
	if (neg && padding_char == ' ')
		len += put_char('-'), s++;
	if (!neg && !params->is_unsign && padding_char == ' ')
	{
		if (!params->plus_flag)
		{
			if (params->space_flag)
				len += put_char(' ');
		}
		else
			len += put_char('+');
	}
	return ((int)(len += put_string(s)));
}

/**
 * print_number - Function to print a number with proper formatting.
 * @s: The string representation of the number to be printed.
 * @params: Pointer to the parameters struct containing formatting flags.
 * Return: The number of characters printed.
 */
int print_number(char *s, params_t *params)
{
	unsigned int len = _strlen(s);
	int neg = (!params->is_unsign && *s == '-');

	if (!params->precision && *s == 48 && !s[1])
		s = "";
	if (neg)
		s++, len--;
	if (params->precision != UINT_MAX)
		while (len++ < params->precision)
			*--s = 48;
	if (neg)
		*--s = '-';
	return (params->minus_flag ?
			left_shift_number(s, params) :
			right_shift_number(s, params));
}
