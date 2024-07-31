#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @args: A va_list pointing to the unsigned integer argument.
 * @params: A pointer to the parameters struct for formatting.
 * Return: The number of characters printed.
 * The team project done by Boutaina and Ali.
 */
int print_unsigned(va_list args, params_t *params)
{
	unsigned long digit;
	va_list args_copy;

	va_copy(args_copy, args);
	if (params->l_modifier)
		digit = (unsigned long) va_arg(args_copy, long);
	else if (params->h_modifier)
		digit = (unsigned short int) va_arg(args_copy, int);
	else
		digit = (unsigned int) va_arg(args_copy, int);
	params->is_unsign = TRUE;
	return (print_number(convert_to(digit, 10, TO_UNSIGNED), params));
}

/**
 * print_address - Function to print the address of a pointer.
 * @args: The va_list containing the arguments.
 * @params: The pointer to the params_t struct.
 * Return: The number of characters printed.
 */
int print_address(va_list args, params_t *params)
{
	uintptr_t digit;
	uint8_t byte;
	int len = 0, i = 7, upper_nibble, lower_nibble;
	va_list args_copy;
	char buffer[50];
	char *p_nbr = &buffer[49];
	static char *array;

	array = "0123456789abcdef";
	*p_nbr = '\0';
	va_copy(args_copy, args);
	digit = va_arg(args_copy, uintptr_t);
	if (!digit)
		return (put_string("(nil)"));
	do {
		byte = digit & 0xFF;
		upper_nibble = (byte >> 4) & 0xF;
		lower_nibble = byte & 0xF;
		*--p_nbr = array[lower_nibble];
		*--p_nbr = array[upper_nibble];
		digit >>= 8;
	} while (i-- > 0);
	while (*p_nbr == 48)
		p_nbr++;
	*--p_nbr = 'x';
	*--p_nbr = '0';
	return (len += print_number(p_nbr, params));
}
