#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct
{
	unsigned int prio;
	char payload[256];
	unsigned long size;
	char rq;
}Msg;

int compara(Msg m1, Msg m2)
{
	if (m1.rq != m2.rq)
		return m2.rq - m1.rq;
	if (m1.prio != m2.prio)
		return m1.prio - m2.prio;
	if (m1.size != m2.size)
		return m2.size - m1.size;
	return strcmp(m1.payload, m2.payload);
}

void insertion(Msg* arr)
{
	Msg aux;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j > 0; j--)
			if (compara(arr[j], arr[j - 1]) < 0)
			{
				aux = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = aux;
			}
			else
				break;
	}
}

int pivot(Msg* arr, int i, int j, int k)
{
	if ((compara(arr[i], arr[j]) >= 0 && compara(arr[i], arr[k]) <= 0) || (compara(arr[i], arr[j]) <= 0 && compara(arr[i], arr[k]) >= 0))
		return i;
	else
		if ((compara(arr[j], arr[i]) >= 0 && compara(arr[j], arr[k]) <= 0) || (compara(arr[j], arr[i]) <= 0 && compara(arr[j], arr[k]) >= 0))
			return j;
		else
			return k;
}

void qs(Msg* arr, int prim, int ultim)
{
	if (prim < ultim)
	{
		int st = prim + 1;
		int dr = ultim;
		int poz = pivot(arr, prim, (prim + ultim) / 2, ultim);
		Msg piv = arr[poz];
		Msg aux = arr[prim];
		arr[prim] = arr[poz];
		arr[poz] = aux;
		while (st <= dr)
		{
			while (compara(arr[st], piv) < 0)
				st++;
			while (compara(arr[dr], piv) > 0)
				dr--;
			if (st < dr)
			{
				Msg aux1 = arr[st];
				arr[st] = arr[dr];
				arr[dr] = aux1;
				st++;
				dr--;
			}
			else
				st++;

		}
		aux = arr[dr];
		arr[dr] = arr[prim];
		arr[prim] = aux;
		qs(arr, prim, dr - 1);
		qs(arr, dr + 1, ultim);
	}
}

int main(void)
{
	Msg arr[] = { {2, "pqrst", 15, '0'}, {6, "uvwxy", 20, '1'}, {6, "fghij", 8, '1'}, {2, "klmno", 15, '0'}, {5, "abcde", 4, '1'} };
	insertion(arr);
	printf("Insertion:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%u %s %u %c\n", arr[i].prio, arr[i].payload, arr[i].size, arr[i].rq);
	printf("\nQuicksort:\n");
	Msg arr1[] = { {2, "pqrst", 15, '0'}, {6, "uvwxy", 20, '1'}, {6, "fghij", 8, '1'}, {2, "klmno", 15, '0'}, {5, "abcde", 4, '1'} };
	qs(arr1, 0, 4);
	for (int i = 0; i < SIZE; i++)
		printf("%u %s %u %c\n", arr1[i].prio, arr1[i].payload, arr1[i].size, arr1[i].rq);
	return 0;
}