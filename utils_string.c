#include "main.h"

/**
 * print_to - Print characters from start to stop (excluding except).
 * @start: Pointer to the start of the character range.
 * @stop: Pointer to the end of the character range.
 * @except: Pointer to the character to exclude from printing.
 * Return: Number of characters printed.
 * The team project done by Boutaina and Ali.
 */
int print_to(const char *start, const char *stop, const char *except)
{
	int sum = 0;
	const char *p_start = start;

	for (; p_start <= stop; p_start++)
		if (p_start != except)
			sum += put_char(*p_start);
	return (sum);
}

/**
 * make_print - Get the appropriate print function and call it.
 * @p_spec: Pointer to the current character in the format specifier.
 * @args: va_list pointing to the argument list.
 * @params: Pointer to the parameters structure.
 * Return: Number of characters printed by the selected print function.
 */
int make_print(const char *p_spec, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(p_spec);

	if (f)
		return (f(args, params));
	return (0);
}
