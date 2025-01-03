#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char ID[5];
	char name[10];
	int age;
}Student;

void generic_sort(void *arr, size_t element_size, int size, int (*function)(const void*, const void*))
{
	int check = 0;
	char* x, * y;
	for (int i = 0; i < size - 1; i++)
	{
		check = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			x = (char*)arr + element_size * j;
			y = (char*)arr + element_size * (j + 1);
			if (function(x, y) > 0)
			{
				check = 1;
				void* aux = malloc(element_size);
				memcpy(aux, x, element_size);
				memcpy(x, y, element_size);
				memcpy(y, aux, element_size);
				free(aux);
			}
		}
		if (!check)
			break;
	}
}

int compare_by_name(const void* x, const void* y) {
	Student* s1 = (Student*)(x);
	Student* s2 = (Student*)(y);
	return strcmp(s1->name, s2->name);
}

int compare_by_age(const void* x, const void* y) {
	Student* s1 = (Student*)(x);
	Student* s2 = (Student*)(y);
	return (s1->age - s2->age);
}

void print(Student* students, int size)
{
	for (int i = 0; i < size; i++)
		printf("ID: %s, Name: %s, Age: %d\n", students[i].ID, students[i].name, students[i].age);
}

int main(void)
{
	Student students[] = { {"0001", "Marcel", 20}, {"0002", "Vicentiu", 19}, {"0003", "Andrei", 21}};
	print(students, 3);
	printf("\nSortare dupa nume: \n");
	generic_sort(students, sizeof(Student), 3, compare_by_name);
	print(students, 3);
	printf("\nSortare dupa varsta: \n");
	generic_sort(students, sizeof(Student), 3, compare_by_age);
	print(students, 3);
	return 0;
}