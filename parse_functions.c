#include "main.h"

/**
 * parse_flags - Parse flags in the format specifier
 * @p_flag: Pointer to the current position in the format specifier
 * @params: Pointer to the params_t structure to update the flags
 * Return: Pointer to the next position in the format specifier
 *      after parsing the flags
 * Done by Boutaina and Ali.
 */
const char *parse_flags(const char *p_flag, params_t *params)
{
	switch (*p_flag)
	{
		case ' ':
			params->space_flag = TRUE;
			break;
		case '+':
			params->plus_flag = TRUE;
			break;
		case '-':
			params->minus_flag = TRUE;
			break;
		case '#':
			params->hashtag_flag = TRUE;
			break;
		case '0':
			params->zero_flag = TRUE;
			break;
		default:
			return (p_flag);
	}
	if (is_flag(*++p_flag, "+- #0"))
		parse_flags(p_flag++, params);
	return (p_flag);
}

/**
 * parse_width - Parse the width field in the format specifier
 * @p_width: Pointer to the current position in the format specifier
 * @params: Pointer to the params_t structure to update the width
 * @args: va_list for variable argument list (used for argument retrieval)
 * Return: Pointer to the next position in the format specifier
 *      after parsing the width field
 */
const char *parse_width(const char *p_width, params_t *params, va_list args)
{
	unsigned int width = 0;
	int width_val;
	va_list args_copy;

	va_copy(args_copy, args);
	if (*p_width == '*')
	{
		width_val = va_arg(args_copy, int);
		if (width_val < 0)  // Handle negative width values
			width = 0;     // Or handle it as needed
		else
			width = (unsigned int)width_val;
		p_width++;
	}
	else
	{
		while (*p_width >= '0' && *p_width <= '9')
			width = width * 10 + (*p_width++ - '0');
	}
	params->width = width;
	return (p_width);
}

/**
 * parse_precision - Parse the precision field in the format specifier
 * @p_precision: Pointer to the current position in the format specifier
 * @params: Pointer to the params_t structure to update the precision
 * @args: va_list for variable argument list (used for argument retrieval)
 * Return: Pointer to the next position in the format specifier
 *      after parsing the precision field
 */
const char *parse_precision(const char *p_precision,params_t *params, va_list args)
{
	unsigned int precision = 0;
	va_list args_copy;

	va_copy(args_copy, args);
	if (*p_precision != 46)
		return (p_precision);
	p_precision++;
	if (*p_precision == 42)
		precision = va_arg(args_copy, unsigned int), p_precision++;
	else
		while (*p_precision >= 48 && *p_precision <= 57)
			precision = precision * 10 + (*p_precision++ - 48);
	params->precision = precision;
	return (p_precision);
}

/**
 * parse_length_modifier - Parse the length modifier field
 *      in the format specifier
 * @p_modifier: Pointer to the current position in the format specifier
 * @params: Pointer to the params_t structure to update the length modifier
 * Return: Pointer to the next position in the format specifier
 *      after parsing the length modifier field
 */
const char *parse_length_modifier(const char *p_modifier, params_t *params)
{
	if (*p_modifier == 'h')
		params->h_modifier = TRUE, p_modifier++;
	else if (*p_modifier == 'l')
		params->l_modifier = TRUE, p_modifier++;
	return (p_modifier);
}
