#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "DiList.h"


int main(void) {
	List lista;
	int error;
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
//	PrintAll(lista);	//63, 1903.78, 10.5, 109.73, 76, 7.5
        error=decreaseAfter(&lista,1,63);
        if(error==0)
              printf("OK\n");
        else
              printf("Error\n");
//        printf("\nlista meta apo afairesi 63 apo kathe stoixeio\n\n");
//        PrintAll(lista);
	destroy(&lista);
	return 1;
}
