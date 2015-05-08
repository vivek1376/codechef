#include <stdio.h>
#include <string.h>

int main()
{
	char matrix[110][110], line[110];
	int i=3,j=4;
	if ( ( (matrix[i][j] == 's' || matrix[i][j] == 'S') &&
                        (matrix[i][j + 1] == 'p' || matrix[i][j + 1] == 'P') &&
                        (matrix[i][j + 2] == 'o' || matrix[i][j + 2] == 'O') &&
                        (matrix[i][j + 3] == 'o' || matrix[i][j + 3] == 'O') &&
                        (matrix[i][j + 4] == 'n' || matrix[i][j + 4] == 'N')) ||
                        ( (matrix[i][j] == 's' || matrix[i][j] == 'S') &&
                          (matrix[i + 1][j] == 'p' || matrix[i + 1][j] == 'P') &&
                          (matrix[i + 2][j] == 'o' || matrix[i + 2][j] == 'O') &&
                          (matrix[i + 3][j] == 'o' || matrix[i + 3][j] == 'O') &&
                          (matrix[i + 4][j] == 'n' || matrix[i + 4][j] == 'N')))
                          
		printf("y\n");
		else
		printf("n\n");
	return 0;
}
