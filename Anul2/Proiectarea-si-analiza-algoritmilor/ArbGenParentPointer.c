#include<stdio.h>
#include<stdint.h>
#include"ArbGenParentPointer.h"


TTree InitTree(TTree a) {
	for (int i = 0; i < MAXNODES; i++) {
		a.nodes[i].primfiu = 0;
		a.nodes[i].fratedreapta = 0;
		a.nodes[i].key = 0;
	}
	a.size = 0;
	return a;
}

TTree InsertNode(TTree a, TKey key, TNodeRef  primfiu, TNodeRef  fratedreapta) {
	a.size++;
	a.nodes[a.size].key = key;
	a.nodes[a.size].primfiu = primfiu;
	a.nodes[a.size].fratedreapta = fratedreapta;
	return a;
}

void printArray(TTree a) {
	printf("\nIndex: ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", i);
	}
	printf("\nKey:   ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", a.nodes[i].key);
	}
	printf("\nFirst: ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", a.nodes[i].primfiu);
	}
	printf("\nRight: ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%5d ", a.nodes[i].fratedreapta);
	}
	printf("\n------------------------------------");
}

/*void printNode(TNode node, char* message) {
	printf("\n%s Key: %d, Parent: %d\n", message, node.key, node.parent);
}
TNodeRef parent(TTree a, TNodeRef noderef) {
	return a.nodes[noderef].parent;
}

TNodeRef getRoot(TTree a) {
	if (a.size < 1) return 0;
	return 1;
}
TNodeRef findNodeIndex(TTree a, TNode node) {
	for (uint8_t i = 0; i <= a.size; i++) {
		if (a.nodes[i].key == node.key && a.nodes[i].parent == node.parent) return i;
	}
	return 0;
}
TNodeRef firstChild(TTree a, TNodeRef index) {
	if (!index) return 0;
	for (uint8_t i = 1; i <= a.size; i++) {
		if (a.nodes[i].parent == index) return i;
	}
	return 0;
}

TKey nodeKey(TTree a, TNodeRef noderef) {
	if (noderef > a.size) return 0;
	return a.nodes[noderef].key;
}

TNode nodeByRef(TTree a, TNodeRef noderef) {
	return a.nodes[noderef];
}

TNodeRef rightSibling(TTree a, TNodeRef noderef) {
	if (!noderef) return 0;
	for (TNodeRef i = noderef + 1; i <= a.size; i++) {
		if (a.nodes[i].parent == a.nodes[noderef].parent) return i;
	}
	return 0;
}

TTree deleteNode(TTree a, TNodeRef noderef) {
	a.nodes[noderef].key = 0;
	a.nodes[noderef].parent = 0;

	for (TNodeRef i = noderef; i <= a.size; i++) {
		if (a.nodes[i].parent == noderef) {
			a.nodes[i].key = 0;
			a.nodes[i].parent = 0;
		}
	}

	for (TNodeRef i = noderef; i <= a.size; ) {
		if (a.nodes[i].parent == 0 && a.nodes[i].key == 0) {
			for (TNodeRef j = i + 1; j <= a.size; j++) {
				if (a.nodes[j].parent > i) a.nodes[j].parent--;
				a.nodes[j - 1] = a.nodes[j];

			}
			a.size--;
		}
		if (a.nodes[i].parent != 0 && a.nodes[i].key != 0) i++;
	}
	printArray(a);

	return a;
}*/