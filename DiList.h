#ifndef __DiList__
#define __DiList__


typedef struct node *ListNode;

typedef struct node
{
	double dedomena;   	/*dedomena komvou*/
	ListNode epomenos; 	/*deiktis ston epomeno komvo*/
}Node;

typedef struct list
{
	ListNode Head; 		/*deiktis ston prwto komvo*/
	ListNode Last; 		/*deiktis ston teleutaio komvo*/
	int megethos; 	   	/*megethos listas*/
}List;


/*dhlwsh sunarthsewn*/
double * getItems(List);
int add(List *, int, double);
int increaseAfter(List, int, double);
int decreaseAfter(List *, int, double);
int addRandom(List* , double);
int checkDelete(List *, int, double);
int removeRandom(List *, double *);
int reverse(List *);

/*Basikes sunarthshs diaxeirhshs listas*/
List create(void);
int empty(List);
void destroy(List *);
void PrintAll(List);

#endif



