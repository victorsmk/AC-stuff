#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *in = NULL;
	if ((in = fopen("file.in", "r")) == NULL)
	{
		perror("Nu s-a deschis fisierul\n");
		exit(-1);

	}
	int n, num1, num2;
	char ch;
	fscanf(in, "%d", &n);
	fgetc(in);
	for (int i = 0; i < n; i++)
	{
		ch = fgetc(in);
		while (ch != ' ')
		{
			putchar(ch);
			ch = fgetc(in);
		}
		fscanf(in, "%d%d", &num1, &num2);
		printf(" %d\n", num1 + num2);
		fgetc(in);
	}
	fclose(in);
	return 0;
}