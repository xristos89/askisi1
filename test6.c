#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "DiList.h"

#define TRUE 1
#define FALSE 0


main()
{
	printf("Testing\n");
	if (test_checkDelete())
	{
		printf("Success\n");
	}
	else
	{
		printf("Failed\n");
	}
}


int test_match(List list, double expectation[], int expectedSize)
{
	Node *node_ptr;
	int i;

	if (list.megethos != expectedSize)
		return FALSE;
	node_ptr = list.Head;
	for ( i=0 ; i<list.megethos ; i++ )
	{
		assert(node_ptr!=NULL);
		if ( node_ptr->dedomena != expectation[i] )
			return FALSE;
		node_ptr = node_ptr->epomenos;
	}

	return TRUE;
}


int test_checkDelete()
{
	int i;

	double tv1[] = {1,2,3,4,5}; // initial
	double tv2[] = {2,3,4,5}; // after removing 1 from first
	double tv3[] = {2,3,4}; // after removing 5 from fourth
	double tv4[] = {2,4}; // after removing 3 from second
	double tv5[] = {4}; // after removing 2 from first

	// Create list
	List list = create();
	for ( i=5 ; i>0 ; i-- )
	{
		add(&list, 1, i);
	}

	// These should have no effect
	i=0;
	i += checkDelete(&list, 1, 10.0);
	i += checkDelete(&list, 3, 10.0);
	i += checkDelete(&list, 4, 10.0);	
	// Test above
	if ( !test_match(list, tv1, 5) )
		return FALSE;
	if ( i!=0 )
		return FALSE;

	// Remove 1 from first
	i = checkDelete(&list, 1, 1.0);
	// Test
	if ( !test_match(list, tv2, 4) )
		return FALSE;
	if ( i!=1 )
		return FALSE;

	// Remove 5 from fourth
	i = checkDelete(&list, 4, 5.0);
	// Test
	if ( !test_match(list, tv3, 3) )
		return FALSE;
	if ( i!=1 )
		return FALSE;

	// Remove 3 from second
	i = checkDelete(&list, 2, 3.0);
	// Test
	if ( !test_match(list, tv4, 2) )
		return FALSE;
	if ( i!=1 )
		return FALSE;

	// Remove 2 from first
	i = checkDelete(&list, 1, 2.0);
	// Test
	if ( !test_match(list, tv5, 1) )
		return FALSE;
	if ( i!=1 )
		return FALSE;

	// Remove 4 from first
	i = checkDelete(&list, 1, 4.0);
	// Test
	if ( list.Head != NULL && list.Last != NULL && list.megethos!=0 )
		return FALSE;
	if ( i!=1 )
		return FALSE;

	return TRUE;
}
