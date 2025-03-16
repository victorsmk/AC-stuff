#include <stdio.h>
#include <stdlib.h>
#include"ArbGenParentPointer.h"

void preordine(TTree tree, TNodeRef noderef)
{
	printf("Key: %hhd, Parent: %hhd\n", tree.nodes[noderef].key, tree.nodes[noderef].parent);
	int child = firstChild(tree, noderef);
	while (child)
	{
		preordine(tree, child);
		child = rightSibling(tree, child);
	}
}

void postordine(TTree tree, TNodeRef noderef)
{
	int child = firstChild(tree, noderef);
	while (child)
	{
		postordine(tree, child);
		child = rightSibling(tree, child);
	}
	printf("Key: %hhd, Parent: %hhd\n", tree.nodes[noderef].key, tree.nodes[noderef].parent);
}

void inordine(TTree tree, TNodeRef noderef)
{
	int child = firstChild(tree, noderef);
	if (child)
		inordine(tree, child);
	printf("Key: %hhd, Parent: %hhd\n", tree.nodes[noderef].key, tree.nodes[noderef].parent);
	while (child)
	{
		child = rightSibling(tree, child);
		if (child)
			inordine(tree, child);
	}
}

int main(int argc, char **argv)
{
	FILE* in = NULL;
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		printf("Eroare la deschiderea fisierului de citire");
		exit(-1);
	}
	TTree* tree = malloc(sizeof(TTree));
	if (tree)
	{
		TNodeRef k, p;
		*tree = InitTree(*tree);
		while (fscanf(in, "%hhd %hhd", &k, &p) == 2)
			*tree = InsertNode(*tree, p, k);
		printArray(*tree);
		printf("\nPreordine:\n");
		preordine(*tree, 1);
		printf("\nPostordine:\n");
		postordine(*tree, 1);
		printf("\nInordine:\n");
		inordine(*tree, 1);
	}
	fclose(in);
	return 0;
}