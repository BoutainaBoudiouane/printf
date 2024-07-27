#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>

#define BUF_SIZE 1024
#define TO_LOWER 1
#define TO_UNSIGNED 2

/**
 * enum boolean - Enumeration representing boolean values.
 * @FALSE: Represents the boolean value 'false' (0).
 * @TRUE: Represents the boolean value 'true' (1).
 */
typedef enum boolean
{
	FALSE = 0,
	TRUE = 1
} bool;

/**
 * struct parameters - Structure to hold various formatting
 *		parameters for data printing.
 * @is_unsign: Flag for indicating if the data is unsigned.
 * @plus_flag: Flag for the '+' flag in the format specifier.
 * @space_flag: Flag for the ' ' (space) flag in the format specifier.
 * @hashtag_flag: Flag for the '#' (hashtag) flag in the format specifier.
 * @zero_flag: Flag for the '0' (zero) flag in the format specifier.
 * @minus_flag: Flag for the '-' (minus) flag in the format specifier.
 * @width: The minimum field width for the printed data.
 * @precision: The precision for numeric conversions.
 * @h_modifier: Flag for the 'h' length modifier in the format specifier.
 * @l_modifier: Flag for the 'l' length modifier in the format specifier.
 */
typedef struct parameters
{
	bool is_unsign;
	bool plus_flag;
	bool space_flag;
	bool hashtag_flag;
	bool zero_flag;
	bool minus_flag;
	bool h_modifier;
	bool l_modifier;

	unsigned int width;
	unsigned int precision;
} params_t;

/**
 * struct specifier - Structure to hold format specifiers
 *		and their handling functions.
 * @specifier: Format specifier string.
 * @handler: Function pointer to the corresponding handling function.
 */
typedef struct specifier
{
	const char *specifier;
	int (*handler)(va_list, params_t *);
} specifier_t;

/* helper_function.c */
int put_char(int c);
int put_string(const char *s);
int is_flag(char c, const char *string);
int _strlen(char *s);

/* parse_functions.c file */
const char *parse_flags(const char *p_flag, params_t *params);
const char *parse_width(const char *p_width,
						params_t *params, va_list args);
const char *parse_precision(const char *p_precision,
							params_t *params, va_list args);
const char *parse_length_modifier(const char *p_modifier, params_t *params);

/* specifier_handler.c */
int (*get_specifier(const char *p_specifier))(va_list args, params_t *params);
void params_init_default(params_t *params);

/* utils_number.c */
char *convert_to(long int nbr, int base, int flags);
int left_shift_number(char *s, params_t *params);
int right_shift_number(char *s, params_t *params);
int print_number(char *s, params_t *params);

/* utils_string.c */
int print_to(const char *start, const char *stop, const char *except);
int make_print(const char *p_spec, va_list args, params_t *params);

/* print_functions.c */
int print_char(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);

/* convert_functions.c */
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);
int print_binary(va_list args, params_t *params);

/* new_prints.c */
int print_rev_string(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);
int print_S(va_list args, params_t *params);

/* rest_prints.c */
int print_unsigned(va_list args, params_t *params);
int print_address(va_list args, params_t *params);

/* _printf.c */
int _printf(const char *format, ...);

#endif
