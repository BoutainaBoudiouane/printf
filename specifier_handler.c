#include "main.h"

/**
 * get_specifier - Get the appropriate specifier function
 *      for the current character
 * @p_specifier: Pointer to the current position in the format specifier
 * Return: Pointer to the appropriate specifier function, NULL if not found
 * Done by Boutaina and Ali.
 */
int (*get_specifier(const char *p_specifier))(va_list args, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"%", print_percent},
		{"b", print_binary},
		{"r", print_rev_string},
		{"R", print_rot13},
		{"S", print_S},
		{NULL, NULL}
	};
	const specifier_t *current_specifier = specifiers;

	for (; current_specifier->specifier; current_specifier++)
		if (*p_specifier == *(current_specifier->specifier))
			return (current_specifier->handler);
	return (NULL);
}

/**
 * params_init_default - Function to initialize a params_t structure
 *      with default values.
 * @params: Pointer to the params_t structure to be initialized.
 */
void params_init_default(params_t *params)
{
	if (params)
	{
		params->is_unsign = FALSE;
		params->plus_flag = FALSE;
		params->space_flag = FALSE;
		params->hashtag_flag = FALSE;
		params->zero_flag = FALSE;
		params->minus_flag = FALSE;
		params->width = 0;
		params->precision = UINT_MAX;
		params->h_modifier = FALSE;
		params->l_modifier = FALSE;
	}
}
