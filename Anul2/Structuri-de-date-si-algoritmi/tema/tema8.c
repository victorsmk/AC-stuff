#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int info;
	struct Node* next;
}Node_t;

Node_t* makeNode(int info) {
	Node_t* new = (Node_t*)malloc(sizeof(Node_t));
	if (new)
	{
		new->info = info;
		new->next = NULL;
	}
	return new;
}

void stergeNod(Node_t** prim, int info) {
    Node_t* temp = *prim;
    Node_t* prev = NULL;

    // Cazul 1: Lista este goala
    if (temp == NULL) {
        printf("Lista este goala, nu se poate sterge informatia %d\n", info);
        return;
    }

    // Cazul 2: Nodul de sters este primul (capul listei)
    if (temp != NULL && temp->info == info) {
        *prim = temp->next;
        free(temp);           
        printf("Nodul cu cheia %d a fost sters\n", info);
        return;
    }

    // Cazul 3: Nodul de sters se afla in interiorul listei
    while (temp != NULL && temp->info != info) {
        prev = temp;
        temp = temp->next;
    }

    // Cazul 4: Cheia nu a fost gasita
    if (temp == NULL) {
        printf("Cheia %d nu a fost gasita in lista\n", info);
        return;
    }

    // Elimina nodul din lista
    prev->next = temp->next;
    free(temp);
    printf("Nodul cu cheia %d a fost sters\n", info);
}

void print_list(Node_t* prim)
{
	Node_t* nod;
	for (nod = prim; nod != NULL; nod = nod->next)
		printf("%d->", nod->info);
	printf("NULL\n");
}

int main(void)
{
	Node_t* prim = NULL;
	prim = makeNode(1);
	prim->next = makeNode(2);
	prim->next->next = makeNode(3);
	prim->next->next->next = makeNode(4);
    printf("Lista initiala:\n");
    print_list(prim);
    stergeNod(&prim, 2);
    printf("Lista dupa ce a fost sters nodul cu cheia 2:\n");
    print_list(prim);
    stergeNod(&prim, 5);
    stergeNod(&prim, 1);
    printf("Lista dupa ce a fost sters primul nod:\n");
    print_list(prim);
    stergeNod(&prim, 4);
    printf("Lista dupa ce a fost sters ultimul nod:\n");
    print_list(prim);
	return 0;
}