#include <stdio.h>
#include <stdlib.h>
#include "DiList.h"

int main()
{
    List list;
    double  items[] = {0.3, 9.7, 88, 7.7, 5.3, 4.2}, *listItems;
    int i;

    list = create();
    printf("dinoume mia kenh list\n>");
    listItems = getItems(list);
    if(listItems != NULL){
       printf("error: getItems with empty list\n");
       free(listItems);
       destroy(&list);
       return 0;
    }
    printf("peirazoume to megethos\n>");
    list.megethos = -1;
    listItems = getItems(list);
    if(listItems != NULL){
       printf("error: getItems with wrong megethos\n");
       free(listItems);
       destroy(&list);
       return 0;
    }
    list.megethos = 0;
    for(i = 0; i < 6; i++){
         if(add(&list, i+1, items[i]) == -1){
             printf("error: list add\n");
             destroy(&list);
             return 0;
         }
    }
    list.megethos--;
    printf("mikrainoume esfalmena to megethos\n>");
    listItems = getItems(list);
    if(listItems != NULL){
       printf("error: getItems with wrong megethos\n");
       free(listItems);
       destroy(&list);
       return 0;
    }
    list.megethos++;
    printf("kanoume mia kanonikh ektelesh..\n");
    listItems = getItems(list);
    if(listItems == NULL){
      printf("error:  getItems normal use\n");
      destroy(&list);
      return 0;
    }
    for(i = 0; i < 6; i++){
        if(items[i] != listItems[i]){
            printf("error:  getItems wrong values\n");
	    free(listItems);
    	    destroy(&list);
            return 0;
        } 
    }    
    printf("\nok!!\n");

    free(listItems);
    destroy(&list);
    return 1;
}
