#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DiList.h"


int main(void) {
        List lista;
        ListNode temp_node;
        int i;
        double temp_array[6];
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
//        PrintAll(lista);        //63, 1903.78, 10.5, 109.73, 76, 7.5
        i=1;
        temp_node=lista.Head;
        while(i<=lista.megethos){
             temp_array[i-1]=temp_node->dedomena;
             i=i+1;
             temp_node=temp_node->epomenos;
        }
        reverse(&lista);
        temp_node=lista.Head;
        for(i=0;i<6;i++){
             if(temp_array[5-i]!=temp_node->dedomena)
                  break;
             else{
                  temp_node=temp_node->epomenos;
             } 
        }
        if(i==6)
             printf("OK\n");
        else
             printf("Error\n");
//        printf("\nlista meta tin antistrofi:\n\n");
//        PrintAll(lista);
//        reverse(&lista);
//        printf("\nlista meta tin antistrofi:\n\n");
//        PrintAll(lista);
        destroy(&lista);
        return 1;
}
