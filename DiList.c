#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "DiList.h"

#define TRUE 1
#define FALSE 0




double * getItems(List list)
{
	double* items;
	int i;
	ListNode curr;

	if(list.megethos < 0){
		printf("Sfalma sto megethos ths listas\n");
		return NULL;
	}
	else if(list.megethos == 0){
		printf("h lista einai kenh\n");
		return NULL;
	}
	items = malloc(sizeof(double)*list.megethos);
	if(items == NULL)
	{
		printf("H mnhmh einai gemath\n");
		return NULL;
	}
	curr = list.Head;
	i = 0;
	while(curr != NULL){
		if(i >= list.megethos){
			printf("h lista periexei perissotera stoixeia apo to megethos pou exei dhlwthei\n");
			free(items);
			return NULL;
		}
		items[i] = curr->dedomena;
		curr = curr->epomenos;
		i++;
	}

	return items;
}

//Sunarthsh eisagwghs neou stoixeiou index sti lista sti thesi position
int add(List *lista, int position, double index)
{
	int current_node;
	ListNode new_node, current, temp;

	if(position <= 0)
	{
		printf("Mh egkyrh thesi eisagwghs stoixeiou\n");
		return -1;
	}

	if(position > (lista->megethos)+1)
	{
		printf("Lanthasmenh thesi eisagwghs stoixeiou\n");
		return -1;
	}

	new_node = malloc(sizeof(Node));
	if(new_node == NULL)
	{
		printf("Memory is full\n");
		return -1;
	}

	new_node->dedomena = index;
	if(empty(*lista) == 1)				//H lista einai kenh
	{
		new_node->epomenos = NULL;
		lista->Head = new_node;
		lista->Last = new_node;
		lista->megethos = 1;
		return 0;
	}

	if(position == 1)				//Eisagwgh neou komvou stin arxi tis listas
	{
		new_node->epomenos = lista->Head;
		lista->Head = new_node;
	}
	else if(position == (lista->megethos)+1)	//Eisagwgh neou komvou sto telos tis listas
	{
		new_node->epomenos = NULL;
		(lista->Last)->epomenos = new_node;
		lista->Last = new_node;
	}
	else
	{
		current = lista->Head;
		current_node = 1;
		while(current_node < position-1)
		{
			current = current->epomenos;
			current_node++;
		}
		new_node->epomenos = current->epomenos;
		current->epomenos = new_node;
	}
	(lista->megethos)++;
	return 0;
}

int increaseAfter(List list, int position, double number)
{
      ListNode curr;
       int i;
      if(empty(list)){
          printf("kenh lista\n");
          return -1;
      }
      if(position <= 0){
          printf("h dwthhsa thesh den exei nohma\n");
          return -1;
      }
      if(list.megethos < position){
          printf("h dwthhsa thesh den uparxei sth lista\n");
          return -1;
      }
      i = 1;
      curr = list.Head;
      while(curr != NULL){
           if(i >= position){
              curr->dedomena += number;
           }  
	   i++;
	   curr = curr->epomenos;
      }      
      return 1;
}

//Sunarthsh pou afairei ena stoixeio apo mia tuxai thesi
int removeRandom(List *lista, double *index)
{
	int random, counter;
	long curtime;
	ListNode temp_node, previous_node;

	curtime = time(NULL);
	srand((unsigned int) curtime);
	random = rand()%(lista->megethos) + 1;
	
	if(random == 1)					//diagrafh prwtou komvou
	{
		temp_node = lista->Head;
		lista->Head = temp_node->epomenos;
		*index = temp_node->dedomena;	
	}
	else if(random == lista->megethos)	//diagrafh teleutaiou komvou	
	{
		previous_node = NULL;
		temp_node = lista->Head;
		while(temp_node != lista->Last)
		{
			previous_node = temp_node;
			temp_node = temp_node->epomenos;
		}
		*index = (temp_node)->dedomena;
		previous_node->epomenos = NULL;	
		lista->Last = previous_node;
	}
	else
	{
		counter = 1;
		previous_node = NULL;
		temp_node = lista->Head;
		while(counter != random)
		{
			previous_node = temp_node;
			temp_node = temp_node->epomenos;
			counter++;
		}
		previous_node->epomenos = temp_node->epomenos;
		*index = temp_node->dedomena;
	}
	free(temp_node);
	(lista->megethos)--;
	return random;
}





//symartisi pou afiarei enan arithmo apo kathe stoixeio pou briksetai meta apo mia sygkekrimeni thesi
//kai parallila afairei apo tin lista osa stoixeia ginoun isa me 0 meta tin afairesi
int decreaseAfter(List *lista,int thesi,double afaireteos){
        int i;
        ListNode temp_node,temp_node2;
        if(thesi>lista->megethos){
              printf("Mi egkyri thesi\n");
              return -1;
        }
        i=1;
        temp_node=lista->Head;
        while(i<thesi){
             temp_node2=temp_node;
             temp_node=temp_node->epomenos;
             i=i+1;
        }
        //twra eimaste stin thesi poy theloume
        while(i<=lista->megethos){
             temp_node->dedomena=temp_node->dedomena-afaireteos;
             if(temp_node->dedomena==0.0){     //prepei na afairethei o kombos
                  if(i!=lista->megethos){
                       if(i!=1){
                            temp_node2->epomenos=temp_node->epomenos;
                       }
                       else{
                            lista->Head=temp_node->epomenos;
                       }
                       lista->megethos=lista->megethos-1;
                       free(temp_node);
                       if(i!=1)
                            temp_node=temp_node2->epomenos;
                       else{
                            temp_node=(lista->Head);
                       }
                  }
                  else{
                       temp_node2->epomenos=NULL;
                       free(temp_node);
                       lista->megethos=lista->megethos-1;
                  }
             }
             else{
                  temp_node2=temp_node;
                  if(i!=lista->megethos)
                       temp_node=temp_node->epomenos;
                  i=i+1;
             }
        }
        return 0;
}





//i sunartisi ayti antistrefei tin lista
int reverse(List *lista){
        ListNode temp_node,temp_node2,temp_node3;
        temp_node=lista->Head;
        lista->Head=lista->Last;
        lista->Last=temp_node;
        temp_node2=temp_node->epomenos;
        temp_node->epomenos=NULL;
        while(temp_node2!=NULL){
               temp_node3=temp_node;
               temp_node=temp_node2;                             
               temp_node2=temp_node->epomenos;
               temp_node->epomenos=temp_node3;
        }
        return 1;
}



int addRandom(List *list, double value)
{
	int rand_pos, i;
	Node *node_ptr;

	// List must contain at least one item
	if (list->megethos == 0)
		return -1;

	// Decide random position (zero-based)
	srand ( time(NULL) );
	rand_pos = rand() % list->megethos;

	if(add(list, rand_pos, value) == -1)
	   return -1;

	// Return position
	return rand_pos;
}



// 1 for deleted item
// 0 for not deleted
// -1 for error
int checkDelete(List *list, int pos, double value)
{
	// Check input
	if (list == NULL)
		return -1;
	if (pos > list->megethos)
		return -1;
	if (pos <= 0)
		return -1;

	if ( pos == 1 )
	{
		// First item in the list
		if ( list->Head->dedomena == value )
		{
			// Remove first node
			Node *node_ptr = list->Head->epomenos;
			free(list->Head);
			list->Head = node_ptr;
			if ( list->Head == NULL )
				list->Last = NULL; // The first node was also the last one

			list->megethos--;

			return 1;
		}
		else
		{
			// Do not remove
			return 0;
		}
	}
	else
	{
		// Not the first item in the list

		// Find item
		Node *node_ptr = list->Head->epomenos;
		Node *node_ptr_prev = list->Head;
		int i;
		for ( i=2 ; i<pos ; i++ )
		{
			node_ptr = node_ptr->epomenos;
			node_ptr_prev = node_ptr_prev->epomenos;
		}

		if ( node_ptr->dedomena == value )
		{
			// Remove item
			node_ptr_prev->epomenos = node_ptr->epomenos;
			if ( node_ptr == list->Last )
				list->Last = node_ptr_prev; // Deleting last node
			free(node_ptr);

			list->megethos--;

			return 1;
		}
		else
		{
			// Do not remove
			return 0;
		}
	}
}
