#include "monty.h"

/**
 * getline - Read a line from a stream and store it in a buffer.
 * @lineptr: Pointer to the buffer where the line is stored.
 * @n: Pointer to the size of the buffer.
 * @stream: Input stream to read from.
 *
 * Return: characters read
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
size_t bufsize = 0;
ssize_t chars_read = 0;

if (!lineptr || !n || !stream)
{
return (-1); /* Invalid input */
}

if (*lineptr == NULL || *n == 0)
{
*n = 128; /* Initial buffer size */
*lineptr = (char *)malloc(*n);
if (*lineptr == NULL)
{
return (-1); /* Memory allocation failed */
}
}

chars_read = read_line(lineptr, bufsize, stream);
if (chars_read == -1)
{
free(*lineptr);
*lineptr = NULL;
return (-1);
}

return (chars_read);
}

/**
 * read_line - Read a line from a stream and store it in a buffer.
 * @lineptr: Buffer where the line is stored.
 * @bufsize: Size of the buffer.
 * @stream: Input stream to read from.
 * Returns: Number of characters read on success, -1 on failure or EOF.
 */
ssize_t read_line(char **lineptr, size_t bufsize, FILE *stream)
{
ssize_t chars_read = 0;

while (1)
{
int c = fgetc(stream);

if (c == EOF)
{
if (chars_read == 0)
{
return (-1);
}
return (chars_read);
}

if (chars_read >= (ssize_t)(bufsize - 1))
{
bufsize += 128;
if (resize_buffer(lineptr, bufsize) == -1)
{
return (-1);
}
}

(*lineptr)[chars_read] = c;
chars_read++;

if (c == '\n')
{
break;
}
}

(*lineptr)[chars_read] = '\0';
return (chars_read);
}

/**
 * resize_buffer - Resize and reallocate a buffer.
 * @lineptr: Pointer to the buffer to be resized.
 * @new_size: New size of the buffer.
 * Returns: 0 on success, -1 on failure.
 */
ssize_t resize_buffer(char **lineptr, size_t new_size)
{
char *new_ptr = realloc(*lineptr, new_size);
if (new_ptr == NULL)
{
free(*lineptr);
*lineptr = NULL;
return (-1);
}
*lineptr = new_ptr;
return (0);
}
