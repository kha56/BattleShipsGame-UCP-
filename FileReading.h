#include<stdlib.h>
#include<stdio.h>

struct Node
{
    char name[10];
    struct Node* next;
};

typedef struct Ship
{
    char location; 
    int numLocation;
    char direction; 
    int length; 
    char shipName[300];
    char graphics;
}ship_l;


typedef struct Board 
{
    int width; 
    int height; 
    //Two dimensional array of items 
    ship_l** gui; 

}board_t; 



//Declaring it in headers file so other class can access the value
int width, height;
int lineCount; //Counting how many lines theres going to be in the file that is reading 
ship_l* ship; //Making the Ship global variable
//missile_list_t* missiles;
void FileReading(char* boardName,char* missileName);
void createFile();
void createMissiles();
