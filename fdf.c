#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	int		i; // to check
	int 	fd;
	char 	*str;
	char 	**ar;

	i = 0;
	ar = (char**)malloc(sizeof(char*) * 2048);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (get_next_line(fd, &str))
		ar[i++] = str;
	i = 0;
	//Validate
	//В каждой строке должнo быть одинаковое количество координат
	while (ar[i])
		printf("%s\n", ar[i++]);
	return (0);
}
		
