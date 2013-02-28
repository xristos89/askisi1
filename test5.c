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
	if (test_addRandom())
	{
		printf("Success\n");
	}
	else
	{
		printf("Failed\n");
	}
}

int test_addRandom()
{
	int i, result, pos;
	Node *node_ptr;

	// Create list
	List list = create();

	// Add 10 items (all values = 1)
	for ( i=0 ; i<10 ; i++ )
	{
		add(&list, i+1, 1.0);
	}

	// Perform addRandom
	pos = addRandom(&list, 1.0);
	
	// Value at 'pos' should now be 1.0
	// Find 'pos'
	node_ptr = list.Head;
	for ( i=0 ; i<pos ; i++ )
	{
		assert(node_ptr != NULL);
		node_ptr = node_ptr->epomenos;
	}
	// Confirm data change
	result = node_ptr->dedomena == 1.0;

	// Release resources
	destroy(&list);

	return result;
}
