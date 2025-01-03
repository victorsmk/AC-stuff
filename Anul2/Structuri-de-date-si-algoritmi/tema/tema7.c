#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10000

int linear_search(int* arr, int size, int el)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == el)
			return i;
	return -1;
}
int binary_search(int* arr, int size, int el) {
   int st = 0, dr = size - 1;
   while (st <= dr) {
       int mij = st + (dr - st) / 2;
       if (arr[mij] == el)
           return mij;
       if (arr[mij] < el)
           st = mij + 1;
       else
           dr = mij - 1;
   }
   return -1;
}

int main(void)
{
    int dimensiuni[NUM];
    for (int i = 0; i < NUM; i++)
        dimensiuni[i] = 10000 * (i + 1);
    printf("Dimensiune\tLiniara (ms)\tBinara (ms)\n");
    for (int i = 0; i < NUM; i++) {
        int n = dimensiuni[i];
        int* arr = (int*)malloc(n * sizeof(int));
        if (arr)
        {
            arr[0] = rand() % n;
            for (int j = 1; j < n; j++) {
                arr[j] = arr[j - 1] + rand() % (n - arr[j - 1] + 1);
            }
            int x = rand() % n;
            clock_t start = clock();
            linear_search(arr, n, x);
            clock_t end = clock();
            double timpLiniara = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            start = clock();
            binary_search(arr, n, x);
            end = clock();
            double timpBinara = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            printf("%d\t\t%.2lf\t\t%.2lf\n", n, timpLiniara, timpBinara);
            free(arr);
        }
    }
	return 0;
}