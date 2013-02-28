#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DiList.h"



//Sunarthsh dhmiourgias listas
List create(void)
{				
	List lista;
	lista.Head = NULL;   	//arxikopoihsh tou deikti ston prwto komvo me NULL
	lista.Last = NULL;	//arxikopoihsh tou deikti ston teleutaio komvo me NULL
	lista.megethos = 0;  	//arxikopoihsh arithmou komvwn listas me 0
	return lista;
}


//Sunarthsh elegxou kenhs listas
int empty(List lista)			//epistrefei 1 an einai keni,
{					//alliws epistrefei 0
    return (lista.megethos == 0);
}


//Sunarthsh katastrofhs listas
void destroy(List *lista)
{
	ListNode current_node;
	current_node = lista->Head;
	while(current_node != NULL)			//epanalipsi gia kathe komvo tis listas
	{
		lista->Head = current_node->epomenos;	//o deiktis Head tha deixnei ston epomeno komvos
		free(current_node);			//apodesmeusi tou trexon komvou
		current_node->epomenos = NULL;		//arxikopoioiisi tou deikti epomenos me NULL
		current_node = lista->Head;		//o trexon komvos deixnei ton epomeno komvo
	}
	lista->Last = NULL;				//allagh tou deikti last se NULL
	lista->megethos = 0;				//i oura pleon den exei kanena komvo 
}

//Sunarthsh pou ektupwnei ta periexomena tis listas
void PrintAll(List lista)
{
	ListNode current_node;

	current_node = lista.Head;
	while(current_node != NULL)
	{
		printf("stoixeio = %f\n",current_node->dedomena);
		current_node = current_node->epomenos;
	}
}
