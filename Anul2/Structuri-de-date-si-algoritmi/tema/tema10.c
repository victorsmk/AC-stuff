#include <stdio.h>
//Singurul mod in care acest exercitiu poate fi rezolvat
//este daca presupunem ca tabloul este ordonat crescator
//Altfel Divide et Impera nu are sens, si am aplica doar cautare liniara

int cauta_index(int* arr, int st, int dr) {
    if (st > dr) {
        return -1;
    }
    int mij = st + (dr - st) / 2;
    if (arr[mij] == mij) {
        return mij;
    }
    if (arr[mij] > mij) {
        return cauta_index(arr, st, mij - 1);
    }
    return cauta_index(arr, mij + 1, dr);
}

void print_array(int* arr, int size)
{
    printf("Indecsi: ");
    for (int i = 0; i < size; i++)
        printf("%d ", i);
    printf("\nNumere: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = { -2, 0, 1, 2, 4, 8, 10 };
    print_array(arr, 7);
    int rez = cauta_index(arr, 0, 6);
    if (rez != -1)
        printf("a[i] = i s-a gasit la pozitia: %d\n", rez);
    else
        printf("Nu s-a gasit niciun i pentru care a[i] = i\n");
	return 0;
}