#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct
{
	unsigned int prio;
	char payload[256];
	unsigned long size;
	char rq;
}Msg;

int compara (Msg m1, Msg m2)
{
	if (m1.rq != m2.rq)
		return m2.rq - m1.rq;
	if (m1.prio != m2.prio)
		return m1.prio - m2.prio;
	if (m1.size != m2.size)
		return m2.size - m1.size;
	return -strcmp(m1.payload, m2.payload);
}

void insertion (Msg* arr)
{
	Msg aux;
	for (int i = 0; i < SIZE; i++)
	{
		aux = arr[i];
		for (int j = i + 1; j > 0 && compara(arr[j], arr[j + 1]) >= 0; j--)
			{
				arr[i] = arr[j];
				arr[j] = aux;
			}
	}
}

int main(void)
{
	
	return 0;
}