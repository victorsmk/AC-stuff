#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ss
{
	char serviceName[128];
	int serviceID;
	char type;
	struct ss* next;
}Service;

typedef struct cn
{
	char address[128];
	char datacenter[128];
	int nr_servicii;
	struct cn* next;
	Service* service;
}ClusterNode;

ClusterNode* makeClusterNode(char* address, char* datacenter)
{
	ClusterNode* newNod = NULL;
	newNod = (ClusterNode*)malloc(sizeof(ClusterNode));
	if (newNod)
	{
		strcpy(newNod -> address, address);
		strcpy(newNod -> datacenter, datacenter);
		newNod -> nr_servicii = 0;
		newNod->next = NULL;
		newNod->service = NULL;
	}
	return newNod;
}

Service* makeService(char* serviceName, int serviceID, char type)
{
	Service* newNod = NULL;
	newNod = (Service*)malloc(sizeof(Service));
	if (newNod)
	{
		strcpy(newNod->serviceName, serviceName);
		newNod->serviceID = serviceID;
		newNod->type = type;
		newNod->next = NULL;
	}
	return newNod;
}

int checkAddress(ClusterNode* prim, char* address)
{
	if (prim != NULL)
	{
		for (ClusterNode* nod = prim; nod->next != NULL; nod = nod->next)
			if (strcmp(address, nod->address) == 0)
				return 0;
	}
	return 1;
}

ClusterNode* add_node(ClusterNode* prim, char* address, char* datacenter)
{
	if (checkAddress(prim, address))
	{
		ClusterNode* newNode = makeClusterNode(address, datacenter);
		if (newNode)
		{
			newNode->next = prim;
			prim = newNode;
		}
	}
	return prim;
}

int checkService(ClusterNode* prim, int serviceID)
{
	if (prim != NULL)
	{
		for (ClusterNode* cluster = prim; cluster->next != NULL; cluster = cluster->next)
			if (cluster->service != NULL)
			{
				for (Service* nod = cluster->service; nod->next != NULL; nod = nod->next)
					if (nod->serviceID == serviceID)
						return 0;
			}
	}
	return 1;
}

void add_service(ClusterNode* prim, ClusterNode* destinatie, char* serviceName, int serviceID, char type)
{
	if (checkService(prim, serviceID))
	{
		Service* newService = makeService(serviceName, serviceID, type);
		if (newService)
		{
			newService -> next = destinatie->service;
			destinatie->service = newService;
			destinatie->nr_servicii++;
		}
	}
}

void printList(ClusterNode* prim)
{	
	for (ClusterNode* nod = prim; nod->next != NULL; nod = nod->next)
	{
		printf("%s %s %d Services:\n", nod -> address, nod -> datacenter, nod -> nr_servicii);
		if (nod->service != NULL)
		{
			for (Service* service = nod->service; service->next != NULL; service = service->next)
				printf("%s %d %c, ", service->serviceName, service->serviceID, service->type);
			printf("\n");
		}
	}
}

void sterge_nod(ClusterNode* prim, char* address)
{
	ClusterNode* sters = prim;
	ClusterNode* prec = prim;
	int found = 0;
	while ((sters != NULL) && strcmp(sters->address, address))
	{
		prec = sters;
		sters = sters->next;
	}
	if (sters != NULL)
	{
		printf("Numar servicii: %d\n", sters->nr_servicii);
		prec->next = sters->next;
		free(sters);
	}
	else
		printf("Adresa invalida\n");
}

int main(void)
{
	ClusterNode* prim = NULL;
	prim = add_node(prim, "address1", "datacenter1");
	prim = add_node(prim, "address1", "datacenter1");
	prim = add_node(prim, "address2", "datacenter2");
	prim = add_node(prim, "address3", "datacenter3");
	prim = add_node(prim, "address2", "datacenter2");
	add_service(prim, prim, "serviceName1", 1, 0);
	add_service(prim, prim, "serviceName2", 2, 1);
	add_service(prim, prim, "serviceName1", 1, 0);
	sterge_nod(prim, "address1");
	printList(prim);
	return 0;
}