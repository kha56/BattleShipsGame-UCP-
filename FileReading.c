#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 
#include "FileReading.h"
#include "LinkedList.h"

#define MAX 1000 

void FileReading(char* boardName,char* missileName)
{


    //THis is for testing wether the scanning is right or not 
    //printf("%s", argv[1]);

    //This is for Dynamically allocating the array 
    //ship_l* ship; 
    
    //This is for for loopps;
    int i = 0; 

    char str[MAX];
    char fileInput[MAX];
    void* secondStr;
    void* input;
    //Making the size dynamic
    secondStr = (void*)malloc(MAX*sizeof(void)); 
    input = malloc(MAX*sizeof(void*));

    
    
    //Variables for the graph 
    //static int width, height;



    //Creating a file for the board  
    FILE *boardFile;
    //Creating a file for the missile
    FILE* missileFile;

    //Opening the boardFile using the command line arguments 
    boardFile = fopen(boardName, "r");

    //Opening the missileFile using the command line arguments
    missileFile = fopen(missileName, "r");

    if(missileFile == NULL)
    {
        fprintf(stderr,"The file is empty");
    }

    if(boardFile == NULL)
    {
        fprintf(stderr,"The file is empty");
    }

    //Allocating the size of the misssileList 
    missiles = calloc(MAX, sizeof(missile_list_t));
    
    //Reading the missiles into the file 
    while(fgets(fileInput,MAX,missileFile) != NULL)
    {
        secondStr = (void*)malloc(MAX*sizeof(char));
        strcpy(secondStr, fileInput);
        //This is just for printing out from the secondSTR  
        //printf("%s\n", secondStr);
        //THis will then add to the linkedlist 
        addToList(missiles,secondStr);


    }
    fclose(missileFile);


    //Firstly scanning the first value of the file aka WIDTH and HEIGHT 
    fscanf(boardFile, "%d,%d", &width,&height);
    //THis will skip to the next lien or  gets the next character 
    getc(boardFile);

    //Allocating the size of the list of ships 
    ship = (ship_l*)malloc(width*sizeof(ship_l));

    //Counting number of lines in the file 
    lineCount = 0;

    while(fgets(str, MAX, boardFile) != NULL)
    {
        //Reading a string with a space inside of it 
        sscanf(str,"%c%d %c %d %299[^\n]", &ship[i].location,&ship[i].numLocation,&ship[i].direction,&ship[i].length,ship[i].shipName);

        //Throwing the exceptions 
        if(ship[i].numLocation > width)
        {
            fprintf(stderr,"The location is bigger than width");
            exit(0);
        }
        if(ship[i].numLocation > height)
        {
            fprintf(stderr,"The location is bigger than height");
            exit(0);
        }

        if(ship[i].length > width && ship[i].length > height)
        {
            fprintf(stderr,"The length is bigger than the board size");
            exit(0);
        }
        lineCount = lineCount + 1;
        //lineCount = lineCount + 1;
        //Incrementing the loop so when the loop is filled with data it will change to another loop
        i++;
    }
    fclose(boardFile);

    /*
    //Printing out the Board file data 
    for(int i =0; i < 3; i++)
    {
        printf("%c%d %c %d %3s\n", ship[i].location,ship[i].numLocation,ship[i].direction,ship[i].length,ship[i].shipName);

    }
    */

    //Printing out the Missile file data 
    count = 0;
    missile_node_t* current = missiles->head; 
    while (current !=NULL)
    {
        printf("%s\n",((void*)current->missile));
        current = current-> next;
        count = count + 1;
        
    }

    



    


}

void createFile()
{
    //Delcaring the variables of the board 
    int width; 
    int height;
    char location; 
    int numLocation; 
    char direction; 
    int length; 
    char shipName[300];
    int numShips;

    FILE* boardFile; 
    char createBoardName[100];
    printf("Enter the name of the file: \n");
    scanf("%s",createBoardName);
    //printf("%s", createBoardName);
    boardFile = fopen(createBoardName, "w");

    if( boardFile == NULL)
    {
        printf("NULL");
        exit(0);
    }
    printf("How many Ships do you want to add?");
    scanf("%d", &numShips);

    //Couldve loop these and put it inside the array to have mutli ships input from the user
    printf("Enter the Width of the board: \n");
    scanf("%d", &width);

    printf("Enter the Height of the board: \n");
    scanf("%d", &height);
    fprintf(boardFile,"%d,%d\n",width,height);

    for(int i = 0; i < numShips; i++)
    {
        printf("Enter the Location of the Ship: \n");
        scanf(" %c%d", &location,&numLocation);

        printf("Enter the Direction of the Ship: \n");
        scanf(" %c", &direction);

        printf("Enter the Length of the Ship: \n");
        scanf(" %d", &length);
        
        printf("Enter the Name Of the Ship: \n");
        scanf(" %[^\n]s",shipName);

        fprintf(boardFile,"%c%d %c %d %s\n", location,numLocation,direction,length,shipName);
        

    }

    
    

 
    
    fclose(boardFile);

}

void createMissiles()
{
    //Delcaring the variables of the board 

    char missileName[300];
    int numMissile;

    FILE* missileFile; 
    char fileName[100];
    printf("Enter the name of the file: \n");
    scanf("%s",fileName);
    //printf("%s", createBoardName);
    missileFile = fopen(fileName, "w");

    if( missileFile == NULL)
    {
        printf("NULL");
        exit(0);
    }
    printf("How many missiles do you want to add?");
    scanf("%d", &numMissile);


    //Couldve loop these and put it inside the array to have mutli ships input from the user
    for(int i = 0; i < numMissile; i++)
    {
        printf("Enter the Name Of the Ship: \n");
        scanf(" %[^\n]s",missileName);

        fprintf(missileFile,"%s\n",missileName);

    }
    fclose(missileFile);
    

}



