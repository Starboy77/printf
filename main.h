#ifndef MAIN
#define MAIN
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define SHORT 1
#define LONG 2
#define VAR(x) ((x) == 1 ? (1) : (0))
/**
 * struct buffer - struct
 * @buffer: store strings
 * @start: shares with buffer
 * @len: buffer length
 */

typedef struct buffer
{
	char *buffer;
	char *start;
	unsigned int len;
}  buffer_t;

/**
 * struct specifier - struct
 * @s: charcater to be compared
 * @func: a function pointer
 */

typedef struct specifier
{
	char s;

	int (*(func))(va_list ptr, buffer_t *print, int arr);
}  spec_t;


int isnull(buffer_t *print, const char *format);
int print_end(buffer_t *print, va_list ptr, int final);
int check_zero(long int res, buffer_t *print);
int _printf(const char *format, ...);
int _strlen(char *s);
int rot13(va_list ptr, buffer_t *print, int arr);
int rev_str(va_list ptr, buffer_t *print, int arr);
int print_d_i(va_list ptr, buffer_t *print, int arr);
int _putchar(char c);
int string(va_list ptr, buffer_t *print, int arr);
int modulo(va_list ptr, buffer_t *print, int arr);
int cha(va_list ptr, buffer_t *print, int arr);
int custom_b(va_list ptr, buffer_t *print, int arr);
int custom_u(va_list ptr, buffer_t *print, int arr);
int custom_o(va_list ptr, buffer_t *print, int arr);
int custom_x(va_list ptr, buffer_t *print, int arr);
int custom_X(va_list ptr, buffer_t *print, int arr);
int custom_S(va_list ptr, buffer_t *print, int arr);
int hex_lower(unsigned long int x, buffer_t *print);
int hex_upper(int x, buffer_t *print);
int convert_p(va_list ptr, buffer_t *print, int arr);
int flag(int i, const char *format, buffer_t *print);
int (*spec(char s))(va_list ptr, buffer_t *print, int arr);
long int ret(int re, buffer_t *print);
int ret_none(int re, buffer_t *print);
char *rot(char *s);


int not_spec(int i, const char *format, buffer_t *print);
void convert_p_hex(int i, int *arr, buffer_t *print);
void convert_hex_upper(int i, int *arr, buffer_t *print);
int out_array(unsigned int res, buffer_t *print, int arr);
int width(int i, const char *format);

/* buffer free func */
buffer_t *init_buffer(void);
void free_buf(buffer_t *print);
unsigned int _memcpy(buffer_t *print, const char *src, unsigned int n);



int flag_sub(int arr, int i, int j, const char *format, buffer_t *print,
	     char *small, char *big, char oct, char *space, char *zero);
#endif
