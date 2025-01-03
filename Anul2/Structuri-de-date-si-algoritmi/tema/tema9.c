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

void print_list(Node_t* prim)
{
    Node_t* nod;
    for (nod = prim; nod != NULL; nod = nod->next)
        printf("%d->", nod->info);
    printf("NULL\n");
}

int numara(Node_t* nod)
{
    if (nod == NULL)
        return 0;
    return 1 + numara(nod->next);
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
    int nrNoduri = numara(prim);
    printf("Numar de noduri: %d\n", nrNoduri);
    return 0;
}