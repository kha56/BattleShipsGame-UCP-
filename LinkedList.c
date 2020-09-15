#include <stdio.h> 
#include <stdlib.h>
#include "LinkedList.h" 

//This is for addding the new missile into the list 
void addToList(missile_list_t* list, void* newMissile)
{
    missile_node_t*  newNode = calloc(1, sizeof(missile_node_t));
    newNode->missile = newMissile; 
    newNode->next = list->head; 
    list->head = newNode; 
    
}

