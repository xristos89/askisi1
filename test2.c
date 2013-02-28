#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DiList.h"


int main(void)
{
	List lista;
	ListNode temp_node;
	double array[] = {63,1903.78,10.5,109.73,76,7.5};
	int i;

	lista = create();
	if(add(&lista, 1, 10.5) == -1)
	{
		printf("apetuxe h eisagwgh neou stoixeiou sti listas\n");
		return 0;
	}

	if(add(&lista, 2, 76) == -1)
	{
		printf("apetuxe h eisagwgh neou stoixeiou sti listas\n");
		return 0;
	}

	if(add(&lista, 1, 63) == -1)
	{
		printf("apetuxe h eisagwgh neou stoixeiou sti listas\n");
		return 0;
	}
	if(add(&lista, 3, 109.73) == -1)
	{
		printf("apetuxe h eisagwgh neou stoixeiou sti listas\n");
		return 0;
	}

	if(add(&lista, 2, 1903.78) == -1)
	{
		printf("apetuxe h eisagwgh neou stoixeiou sti listas\n");
		return 0;
	}

	if(add(&lista, 6, 7.5) == -1)
	{
		printf("apetuxe h eisagwgh neou stoixeiou sti listas\n");
		return 0;
	}

	i = 0;
	temp_node = lista.Head;
	while(temp_node != NULL)
	{
		if(array[i] != temp_node->dedomena)
		{
			printf("Error!!!\n");
			return 0;
		}
		i++;
		temp_node = temp_node->epomenos;
	}
	printf("Ok!!!\n");

	//PrintAll(lista);	//63, 1903.78, 10.5, 109.73, 76, 7.5
	destroy(&lista);

	return 1;
}