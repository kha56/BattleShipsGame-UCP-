typedef struct MissileNode 
{
    //It can store any data types 
    void* missile; 
    struct MissileNode* next;
}missile_node_t;

//List of Nodes 
typedef struct MissileList 
{
    missile_node_t* head; 
    int count; 
}missile_list_t;

int count;
void addToList(missile_list_t* list, void* newMissile);
missile_list_t* missiles; //Declaring the missiles so it become global variables 


