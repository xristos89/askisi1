#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "DiList.h"


int main(void)
{
	ListNode current_node;
	List lista;
	int position, i; 
	double index, *array;
	
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

	array = malloc((lista.megethos)*sizeof(double));
	if(array == NULL)
	{
		printf("Memory is full, so test case failed\n");
		return 0;
	}

	i = 0;
	current_node = lista.Head;
	while(current_node != NULL)
	{
		array[i] = current_node->dedomena;
		i++;
		current_node = current_node->epomenos;
		
	}

	position = removeRandom(&lista, &index);
	printf("position = %d and index = %f\n\n", position, index);

	i = 0;
	current_node = lista.Head;
	while(current_node != NULL)
	{
		if(i+1 == position)
			i++;
		if(array[i] != current_node->dedomena)
		{
			printf("Error!!!\n");
			return 0;
		}
		i++;
		current_node = current_node->epomenos;
	}
	printf("Ok!!!\n");
	//PrintAll(lista);

	free(array);
	destroy(&lista);	
	return 1;
}