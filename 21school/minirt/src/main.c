#include <mlx.h>

int main(int args, char **argv)
{
	if (args > 3 || parse(argv[1]) == -1)
	{
		printerror();
		return (-1);
	}
}
