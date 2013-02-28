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
    if(increaseAfter(list, 1, 0.3) != -1){
       printf("error: increaseAfter with empty list\n");
       return 0;
    }
    
    for(i = 0; i < 6; i++){
         if(add(&list, i+1, items[i]) == -1){
             printf("error: list add\n");
             destroy(&list);
             return 0;
         }
    }

    printf("dinoume atopo position\n>");
    if(increaseAfter(list, -1, 0.3) != -1){
       printf("error: increaseAfter with wrong position\n");
       destroy(&list);
       return 0;
    }
    printf("dinoume position megalutero apo to megethos ths listas\n>");
    if(increaseAfter(list, 10, 0.3) != -1){
       printf("error: increaseAfter with wrong position\n");
       destroy(&list);
       return 0;
    }
    
    printf("elegxoume th swsth leitourgia..\n");
    if(increaseAfter(list, 3, 0.5) < 0){
         printf("error: increaseAfter  normal use\n");
         destroy(&list);
         return 0;
    }
    listItems = getItems(list);
    if(listItems == NULL){
      printf("error:  getItems normal use\n");
      destroy(&list);
      return 0;
    }
    for(i = 0; i < 6; i++){
        if((i > 3) && (items[i] + 0.5 != listItems[i])){
            printf("error:  increaseAfter wrong values\n");
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
