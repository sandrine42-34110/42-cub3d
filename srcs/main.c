#include "cub3d.h"

int main(int argc, char **argv)
{
	t_all	*all;

	all = init_all(argc, argv);
	if (!all)
		return (1);
	return (0);
}