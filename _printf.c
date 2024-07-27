#include "main.h"

/**
 * _printf - Custom printf function that formats and prints output.
 * @format: A pointer to a string containing format specifiers.
 * Return: The number of characters printed.
 * Done by Boutaina and Ali.
 */
int _printf(const char *format, ...)
{
	int nbr_char = 0;
	va_list args_p;
	const char *str = (char *) format, *start;
	params_t params;

	va_start(args_p, format);
	if (!format || (format[0] == 37 &&
					(!format[1] || (format[1] == 32 && !format[2]))))
		return (-1);
	for (; *str; str++)
	{
		if (*str != 37)
		{
			nbr_char += put_char(*str);
			continue;
		}
		params_init_default(&params);
		start = str;
		str++;
		str = parse_flags(str, &params);
		str = parse_width(str, &params, args_p);
		(*--str == '*') ? va_arg(args_p, int) : 0, str++;
		str = parse_precision(str, &params, args_p);
		(*--str == '*' && params.precision != UINT_MAX) ?
			va_arg(args_p, int) : 0, str++;
		str = parse_length_modifier(str, &params);
		if (!get_specifier(str))
			nbr_char += print_to(start, str,
			params.h_modifier || params.l_modifier ? str - 1 : 0);
		else
		{
			nbr_char += make_print(str, args_p, &params);
			(*str != '%') ? va_arg(args_p, int) : 0;
		}
	}
	put_char(EOF), va_end(args_p);
	return (nbr_char);
}
