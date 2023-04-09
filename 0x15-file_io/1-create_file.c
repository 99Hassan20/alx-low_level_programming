#include "main.h"

/**
 *create_file - create a file
 *@filename: the name of the file to create
 *@text_content: the content of the created file
 *Return: 1 on success else -1 is returned
 */

int create_file(const char *filename, char *text_content)
{
	int	fd;
	int r;
	int i;

	i = 0;
	r = 0;
	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_CREAT, 0600);
	if (fd < 0)
		return (-1);
	if (text_content)
	{
		while (text_content[i])
		{
			r += write(fd, &text_content[i], 1);
			i++;
		}
		if (r < 0 || text_content[r])
			return (-1);
	}
	close(fd);
	return (1);
}
