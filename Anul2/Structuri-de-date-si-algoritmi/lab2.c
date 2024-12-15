#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 30

typedef struct
{
	char cnp[13];
	int an_nastere;
	char gen;
}Person;

int add_to_set(Person* set, int current_size, char *cnp, int an_nastere, char gen)
{
	if (current_size > MAX_SIZE)
		return current_size;
	for (int i = 0; i < current_size; i++)
		if (strcmp(set[i].cnp, cnp) == 0)
			return current_size;
	strcpy(set[current_size].cnp, cnp);
	set[current_size].an_nastere = an_nastere;
	set[current_size].gen = gen;
	current_size++;
	return current_size;
}

int remove_from_set(Person* set, int current_size, char* cnp)
{
	for (int i = 0; i < current_size; i++)
	{
		if (strcmp(set[i].cnp, cnp) == 0)
		{
			for (int j = i; j < current_size - 1; j++)
						set[j] = set[j + 1];
			current_size--;
		}
			
	}
	return current_size;
}

int count(Person* set, int current_size)
{
	return current_size;
}

void print_set(Person* set, int current_size)
{
	
	for (int i = 0; i < current_size; i++)
		printf("%s %d %c\n", set[i].cnp, set[i].an_nastere, set[i].gen);
	printf("\n");
}

int main(void)
{
	int current_size = 0;
	Person* set = NULL;
	set = malloc(MAX_SIZE * sizeof(Person));
	current_size = add_to_set(set, current_size, "5050414350011", 2005, 'M');
	current_size = add_to_set(set, current_size, "5030606696969", 2003, 'F');
	print_set(set, current_size);
	current_size = remove_from_set(set, current_size, "5050414350011");
	print_set(set, current_size);
	return 0;
}