#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include "FileReading.h"
#include "LinkedList.h"
#include "Game.h"


int main(int argc, char *argv[])
{
    int menuInput;
    //int numMissiles = 0;
    //missile_node_t* current = missiles->head; 
    char* boardName = argv[1];
    char* missileName = argv[2];
    if(argc > 3)
    {
        fprintf(stderr,"Only put two filenames\n");
        exit(0);
    }
    //printf("%s", name);

    //Play(boardName,missileName);

    //This will allow the user to play game game again and again until it hits exit
    do 
    {
        printf("1. Play the Game\n");
        printf("2. List all missiles\n");
        printf("3. Create Board File\n");
        printf("4. Create Missile File\n");
        printf("0. Exit\n");
        scanf("%d", &menuInput);
        
        
        
        switch (menuInput)
        {
            
        case 1:
        Play(boardName,missileName);
        
        break;
        
        case 2:
        FileReading(boardName,missileName);
        break;

        case 3: 
        createFile();
        break;

        case 4: 
        createMissiles();
        break; 

        case 0: 
        exit(0);
        break;
        }
    }
    while(menuInput != 0);

}