#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 6
#define MAX 100
int h[T];

void generare_simpla(int* h)
{
	int i;
	h[T - 1] = 1;
	for (i = T - 2; i >= 0; i--)
	{
		h[i] = 3 * h[i + 1] + 1;
	}
}

void generare_fibonacci(int* h) 
{
	h[T - 1] = 0;
	if (T > 1) 
		h[T - 2] = 1; 
	for (int i = T - 3; i >= 0; i--) 
		h[i] = h[i + 1] + h[i + 2];
}

//Functia e luata de pe curs
void shell_sort(int a[], int n, void (*generare)(int *))
{
	int i, j, k, hCnt, H; 
	int tmp;
	generare(h);
	//pentru fiecare increment
	for (i = 0; i < T; i++)
	{
		H = h[i]; //incrementul curent
	 //pentru fiecare subtablou
		for (hCnt = 0; hCnt < H; hCnt++)
		{ //insetion_sort pentru subtablou
			for (j = H + hCnt; j < n;j += H)
				//se selecteaza elementele cu pasul H
			{
				tmp = a[j];
				for (k = j; (k - H >= 0) && tmp < a[k - H]; k -= H)
					a[k] = a[k - H];
				a[k] = tmp;
			}
		}
	}
}

void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int dimensiuni[MAX];
	for (int i = 0; i < MAX; i++)
		dimensiuni[i] = (i + 1) * 1000;
	printf("Dimensiune\tSimpla (ms)\tFibonacci (ms)\n");
	for (int i = 0; i < MAX; i++)
	{
		int size = dimensiuni[i];
		int* arr1 = (int*)malloc(size * sizeof(int));
		int* arr2 = (int*)malloc(size * sizeof(int));
		if (arr1 && arr2)
		{
			for (int j = 0; j < size; j++)
			{
				arr1[j] = rand() % 1000;
				arr2[j] = rand() % 1000;
			}
			clock_t start = clock();
			shell_sort(arr1, size, generare_simpla);
			clock_t end = clock();
			double timpClasica = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

			start = clock();
			shell_sort(arr2, size, generare_fibonacci);
			end = clock();
			double timpFibonacci = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

			printf("%d\t\t%.2lf\t\t%.2lf\n", size, timpClasica, timpFibonacci);
			free(arr1);
			free(arr2);
		}
	}
	return 0;
}