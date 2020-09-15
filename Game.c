#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "FileReading.h"
#include "LinkedList.h"

//This is fro pinting in colours 
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
#define MAGENTA "\033[1;35m"

//Remove Some Colour(Conditional Compilation 1)
//When called mono the program no longer prints any colours 
//#define MONO
//When called DEBUG it will locate all the ships on the board by using magenta colour 
//#define DEBUG


board_t* createGui();
//Going to set this as a const cause we not going to change anything to it 
void printGui(const board_t* gui);



void Play(char* boardName, char* missileName) 
{
   


    //char* boardName = argv[1];
    //char* missileName = argv[2];
    /*
    if(argc > 3)
    {
        fprintf(stderr,"Only put two filenames\n");
        exit(0);
    }
    */

    FileReading(boardName,missileName);
    //This is just for testing global variables 
    //printf("%d", width);
    //printf("%d", height);


    //printBoard();
    //ship_l* ship = (ship_l*)malloc(width*sizeof(ship_l));
    /*
    for(int i =0; i < 3; i++)
    {
        printf("%c%d %c %d %3s\n", ship[i].location,ship[i].numLocation,ship[i].direction,ship[i].length,ship[i].shipName);

    }
    */
    board_t* board = createGui(); 
    //board->gui[2][2].graphics = 'C';
    //printGui(board);

    //Ge the user input aka Entering Coordinates  
    char Column;
    int Row; 

    //Lets find how many missiles are there
    
    //printf("%d", count);

    //Keep asking userinput until there is no missiles left
    int numberOfTargets = 0;
    missile_node_t* current = missiles->head;
    //void* Single = "Single";
    
    do
    {
        printGui(board);
        //Caculating of how many missiles left 
        printf("Missiles left: %d\n", count-numberOfTargets);
        printf("Current Missile: %s\n\n", current->missile);
           
        printf("Enter next Target:");
        scanf(" %c%d", &Column,&Row);
      
        char upperCaseColumn = toupper(Column);

        //Checking the value of the Column value into Int 
        int numColumn = (int)upperCaseColumn-64;
        //printf("%d", numColumn);

        //printf("%d", height);
        //This is for checking Entered Coordinates is within the range or not 
        if(Row > height)
        {
            fprintf(stderr,"Your inputed Row data is bigger than the board size or Invalid\n");
            //go back to main menu 
            exit(0);
        }
        if(numColumn > width)
        {
            fprintf(stderr,"Your inputed Column data is bigger than the board sizeor Invalid\n");
            //Go back to main menu
            exit(0); 

        }

        //This si where it adds to the gui
        //Had to change the NULL into '\0' due to a int to void warning
        if(board->gui[Row][numColumn].graphics == '\0')
        {
    
            
            /*
            if((char*)current->missile)->"Single")
            {
                printf("This works");
            }
            */
           //This is for colour
           
            board->gui[Row][numColumn].graphics = 'X';
            #ifndef MONO
            printf(RED "| %c | MissFIRE!!\n" RESET,board->gui[Row][numColumn].graphics);
            #endif

            #ifdef MONO
            printf("| %c | MissFIRE!!\n",board->gui[Row][numColumn].graphics);
            #endif


        }
        else 
        {
            
            board->gui[Row][numColumn].graphics = '0';
            #ifndef MONO
            printf(GREEN "| %c | Enemy DOWN!!\n" RESET,board->gui[Row][numColumn].graphics);
            #endif

            #ifdef MONO
            printf("| %c | Enemy DOWN!!\n",board->gui[Row][numColumn].graphics);
            #endif
            

        }

        numberOfTargets = numberOfTargets+1;
        current = current-> next; 
        
    }
    while(numberOfTargets < count);
    {
        //The final board view
        printGui(board);
    }    
}




board_t* createGui()
{
    board_t* newGui = calloc(1, sizeof(board_t));
    //Setting the width and height from the FILE IO 
    newGui->width = width+1; //+1 for the borders of the game 
    newGui->height = height+1;

    //printf("%d",newGui->height);

    //Creating a 2D array and giving dynamic size 
    newGui->gui = calloc(newGui->height,sizeof(ship_l*));

    //Creating each row
    int i; 
    for(i = 0; i < newGui->height; i++)
    {
        //Array of Items
        //Overwriting each row 
        newGui->gui[i] = calloc(newGui->width, sizeof(ship_l));

    }
    /*
    if(ship[0].location == 'D')
    {

        newGui->gui[D][ship[0].numLocation]
        //printf();
    }
    */
    //populate the world
    //TODO
    //Need to set the location to automatic but will 
    //Why cant I set to that [4][4]
    

    
   /*
   int a = 1;
   int b = 2; 
   int c = 3; 
   int d = 4;
   int e = 5;
   */
   /*
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j<height; j++)
        {
            switch(ship[i].location)
            {
                case 'A': 
                //Seting the A into the value of 1 so it can be set on the graph 
                
                //newGui->gui[a][ship[i].numLocation].numLocation = ship[]
                //int numLocationLocal = ship[j].numLocation;
                //newGui->gui[a][numLocationLocal]                 
                break;

                case 'B':
                 
                printf("HELLO BBBB\n");
                break;

                case 'C':
                
                printf("Hello CCC\n");
                break; 

                case 'D':
                
                printf("Hello DDD\n");
                break; 

                case 'E': 
                
                printf("hello EEE\n");
                break;
            }  
        }
        

    }
    */
   //Giving out values to the border of the graph
   /*
    char c; 
    for (c = 'A'; c <= 'Z'; ++c)
    {
        for(int i =1; i < newGui->width; i++)
        {
        //for (c = 'A'; c <= 'Z'; ++c)
            newGui->gui[0][i].graphics = c; 
        }
    }
    */
   //Making the width boorder automatic
     for(int i = 1; (i < newGui->width) && (i <= 'Z' - 'A') ; i++)
    {
        newGui->gui[0][i].graphics = i + 'A' - 1; 
    }
  
   /*
    newGui->gui[0][1].graphics = 'A';
    newGui->gui[0][2].graphics = 'B';
    newGui->gui[0][3].graphics = 'C';
    newGui->gui[0][4].graphics = 'D';
    newGui->gui[0][5].graphics = 'E';
    */
    //Automating the HEIGHT Symbols
    for(int i = 1; i < newGui->height; i++)
    {
        //This will change the int into char 

            newGui->gui[i][0].graphics = i+'0';

    }
    /*
    newGui->gui[1][0].graphics = '1';
    newGui->gui[2][0].graphics = '2';
    newGui->gui[3][0].graphics = '3';
    newGui->gui[4][0].graphics = '4';
    */
    /*
    //Making the above automatic 
    char c; // For alphabets 
    for(int i= 0; i < newGui->width; i++)
    {
        for(int j = 1; j < newGui->height; j++)
        {
            for( c = 'A'; c <= 'Z'; ++c)
            {
                newGui->gui[i][j].graphics = c; 
            }
        
        }
        
    }
    */
    //newGui->gui[4][0].graphics = '4';
    //Testing how many ships in the file
    //printf("%d", lineCount);
    //int numLocationColumn = (int)ship[i].location -64;

    for(int i =0; i < lineCount; i++)
    {
        int numLocationColumn = (int)ship[i].location -64;
        //printf("%d", numLocationColumn);
        newGui->gui[ship[i].numLocation][numLocationColumn].location = ship[i].location;
        newGui->gui[ship[i].numLocation][numLocationColumn].numLocation = ship[i].numLocation;
        newGui->gui[ship[i].numLocation][numLocationColumn].direction = ship[i].direction;
        newGui->gui[ship[i].numLocation][numLocationColumn].length = ship[i].length;
        strcpy(newGui->gui[ship[i].numLocation][numLocationColumn].shipName,ship[i].shipName);
        newGui->gui[ship[i].numLocation][numLocationColumn].graphics = '#';

        
        if(ship[i].direction == 'S')
        {
            //printf("%d\n", i);
            //printf("South\n");
            
            //printf("West\n");
            //printf("%d\n", ship[i].length);

            for(int j = i+1; j <= ship[i].length; j++)
            {
                newGui->gui[j][numLocationColumn].graphics = '#';
                    //newGui->gui[j][1].graphics = '0'; 
            }
               //newGui->gui[]
               /*
            
            for(int j = i; j <= ship[i].length; j++)
            {
                newGui->gui[j][numLocationColumn].graphics = '0';
                //newGui->gui[j][1].graphics = '0'; 
            }
            */
               
        }
        if(ship[i].direction == 'W')
        {
             //printf("%d\n", i);
            //printf("West\n");
            //printf("%d\n", ship[i].length);

            for(int j = 1;  j <= ship[i].length-1; j++)
            {
                newGui->gui[numLocationColumn][ship[i].numLocation-j].graphics = '#';
                //newGui->gui[numLocationColumn][ship[i].numLocation-1].graphics = '0';
                
                //printf("HelloWORLD\n");
            }
        }

        if(ship[i].direction == 'E')
        {
            //printf("East\n");
            for(int j = 1; j <= ship[i].length-1; j++)
               {
                   //have to switch the sides [][] because it has to be opposite of W ^^^
                    newGui->gui[ship[i].numLocation][numLocationColumn+j].graphics = '#';
                    //newGui->gui[j][1].graphics = '0'; 
               }
        }
        if(ship[i].direction == 'N')
        {
            //printf("North\n");

            for(int j = i-1; j <= ship[i].length; j++)
            {
                newGui->gui[j][numLocationColumn].graphics = '#';
                    //newGui->gui[j][1].graphics = '0'; 
            }

        }
        
        


    }

   /*  
    //Setting the values of the read file into the double array list using the for loop
    for(int i = 0; i < lineCount; i++)
    {
       //newGui->gui[4][ship[i].numLocation].location = ship[i].location;
       switch(ship[i].location)
       {

           case 'A':
           // A is equal to 1
           //[1][1]
            int numLocationColumn = (int)ship[i].location - 64;
           newGui->gui[ship[i].numLocation][1].location = ship[i].location;
           newGui->gui[ship[i].numLocation][1].numLocation = ship[i].numLocation;
           newGui->gui[ship[i].numLocation][1].direction = ship[i].direction;
           newGui->gui[ship[i].numLocation][1].length = ship[i].length;
           strcpy(newGui->gui[ship[i].numLocation][1].shipName,ship[i].shipName);
           newGui->gui[ship[i].numLocation][1].graphics = '0';
           int numLocationColumn = (int)ship[i].location - 64;
           
           if(ship[i].direction == 'S')
            {
               //newGui->gui[]
               for(int j = i+1; j <= ship[i].length; j++)
               {
                    newGui->gui[j][numLocationColumn].graphics = '0';
                    //newGui->gui[j][1].graphics = '0'; 
               }
               
            }
            

            if(ship[i].direction == 'N')
            {
                //GOing north will be -1 the width 1,2,3,4 because its going up 
               //newGui->gui[]
               for(int j = i-1; j <= ship[i].length; j++)
               {
                    newGui->gui[j][1].graphics = '0';
                    //newGui->gui[j][1].graphics = '0'; 
               }
               
            }

            if(ship[i].direction == 'E')
            {
               //newGui->gui[]
               for(int j = i+1; j <= ship[i].length; j++)
               {
                    newGui->gui[1][j].graphics = '0';
                    //newGui->gui[j][1].graphics = '0'; 
               }
               
            }

            if(ship[i].direction == 'W')
            {
               //newGui->gui[]
               for(int j = i-1; j <= ship[i].length; j++)
               {
                    newGui->gui[1][j].graphics = '0';
                    //newGui->gui[j][1].graphics = '0'; 
               }
               
            }
            
           
           
           break;

           case 'B': 
           //[3][2]
           
           newGui->gui[ship[i].numLocation][2].location = ship[i].location;
           newGui->gui[ship[i].numLocation][2].numLocation = ship[i].numLocation;
           newGui->gui[ship[i].numLocation][2].direction = ship[i].direction;
           newGui->gui[ship[i].numLocation][2].length = ship[i].length;
           strcpy(newGui->gui[ship[i].numLocation][2].shipName,ship[i].shipName);
           newGui->gui[ship[i].numLocation][2].graphics = '0';

           
           break;

           case 'C':
           newGui->gui[ship[i].numLocation][3].location = ship[i].location;
           newGui->gui[ship[i].numLocation][3].numLocation = ship[i].numLocation;
           newGui->gui[ship[i].numLocation][3].direction = ship[i].direction;
           newGui->gui[ship[i].numLocation][3].length = ship[i].length;
           strcpy(newGui->gui[ship[i].numLocation][3].shipName,ship[i].shipName);
           newGui->gui[ship[i].numLocation][3].graphics = '0';

            if(ship[i].direction == 'E')
            {
                //printf("%d", i);
               //newGui->gui[]
               //newGui->gui[2][4].graphics = '0';
               for(int j = i+i; j <= 2; j++)
               {
                   newGui->gui[2][j].graphics = '0';
                    //newGui->gui[2][4].graphics = '0';
                    //newGui->gui[j][1].graphics = '0'; 
               }
               
              //printf("E is here");
               
            }

           
           break;

           case 'D':
           newGui->gui[ship[i].numLocation][4].location = ship[i].location;
           newGui->gui[ship[i].numLocation][4].numLocation = ship[i].numLocation;
           newGui->gui[ship[i].numLocation][4].direction = ship[i].direction;
           newGui->gui[ship[i].numLocation][4].length = ship[i].length;
           strcpy(newGui->gui[ship[i].numLocation][4].shipName,ship[i].shipName);
           newGui->gui[ship[i].numLocation][4].graphics = '0';
           break;

           //Will keep going until 'Z'

       }   
    } */
    
   

    /*
    newGui->gui[4][4].location = ship[0].location;
    newGui->gui[4][4].numLocation = ship[0].numLocation;
    newGui->gui[4][4].direction = ship[0].direction;
    newGui->gui[4][4].length = ship[0].length;
    strcpy(newGui->gui[4][4].shipName,ship[0].shipName);
    newGui->gui[4][4].graphics = '0';
    */
    
    /*
    newGui->gui[1][1].location = ship[1].location;
    newGui->gui[1][1].numLocation = ship[1].numLocation;
    newGui->gui[1][1].direction = ship[1].direction;
    newGui->gui[1][1].length = ship[1].length;
    strcpy(newGui->gui[1][1].shipName,ship[1].shipName);
    newGui->gui[1][1].graphics= '0';
    //Cause it is E 2 
   // newGui->gui[4][2].graphics = '0';
    */
    //You have to count opposite 
    /*
    newGui->gui[2][3].location = ship[2].location;
    newGui->gui[2][3].numLocation = ship[2].numLocation;
    newGui->gui[2][3].direction = ship[2].direction;
    newGui->gui[2][3].length = ship[2].length;
    strcpy(newGui->gui[2][3].shipName,ship[2].shipName);
    newGui->gui[2][3].graphics = '0';
    */
    

    return newGui;
}

    
#ifndef MONO
void printGui(const board_t* board)
{
    printf("Welcome to the Gui of the Game:\n");

    int i, j;
    char hash = '#';
    //char x = 'X';
    
    for(i = 0; i < board->height; i++)
    {
        for(j = 0; j < board->width; j++)
        {        
        
            
            if(board->gui[i][j].graphics == '\0')
            {
                //printf("\033[0;34m");
                printf(BLUE "| %c |" RESET, hash);
                //printf("\033[0m");
            }
         
            
                       
            else
            {
               #ifndef DEBUG
               printf(BLUE "| %c |" RESET, board->gui[i][j].graphics );
               #endif
               //This will print out the Ships that are currently located on the Board
               #ifdef DEBUG
               printf(MAGENTA "| %c |" RESET, board->gui[i][j].graphics);
               #endif


            
            }
            

            /*
           
            if(board->gui[i][j].graphics == '0')
            {
                printf(RED "| X |" RESET);
            }
            else
            {
                printf(BLUE "| # |" RESET);
            }
            
            
           */
           /*
            if(board->gui[i][j].graphics == NULL)
            {
            
                printf(BLUE "| # |" RESET);
                
            }
            if(board->gui[i][j].graphics == 'X')
            {
                printf(RED "| %c |" RESET, board->gui[i][j].graphics);
            }
             if(board->gui[i][j].graphics == '0')
            {
                printf(GREEN "| %c |" RESET, board->gui[i][j].graphics);
            }
                      
            else
            {
                printf(BLUE "| %c |" RESET, board->gui[i][j].graphics);
            }
            */
            
        }
        printf("\n");
    }
}
#endif

#ifdef MONO
void printGui(const board_t* board)
{
    printf("Welcome to the Gui of the Game:\n");

    int i, j;
    char hash = '#';
    //char x = 'X';
    
    for(i = 0; i < board->height; i++)
    {
        for(j = 0; j < board->width; j++)
        {        
        
            
            if(board->gui[i][j].graphics == '\0')
            {
                //printf("\033[0;34m");
                printf("| %c |",hash);
                //printf("\033[0m");
            }
         
            
                       
            else
            {
  
               #ifndef DEBUG
               printf("| %c |", board->gui[i][j].graphics );
               #endif
               //This will print out the Ships that are currently located on the Board
               #ifdef DEBUG
               printf("| %c |", board->gui[i][j].graphics);
               #endif
            
            }
            
           /*
            if(board->gui[i][j].graphics == '0')
            {
                printf(RED "| X |" RESET);
            }
            else
            {
                printf(BLUE "| # |" RESET);
            }
            */
           /*

            if(board->gui[i][j].graphics == NULL)
            {
            
                printf(BLUE "| # |" RESET);
                
            }
            if(board->gui[i][j].graphics == 'X')
            {
                printf(RED "| %c |" RESET, board->gui[i][j].graphics);
            }
             if(board->gui[i][j].graphics == '0')
            {
                printf(GREEN "| %c |" RESET, board->gui[i][j].graphics);
            }
                      
            else
            {
                printf(BLUE "| %c |" RESET, board->gui[i][j].graphics);
            }
            */
        }
        printf("\n");
    }
}
#endif


/*
void printBoard()
{
    int i,j; 
    for(i =0; i < height;i++)
    {
        for(j= 0; j < width; j++)
        {
            printf("______");
            printf("|    |");
        }

    }
    
    
} 
*/
