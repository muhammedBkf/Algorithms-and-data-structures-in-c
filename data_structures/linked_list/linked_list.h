typedef struct linked_list
{
    struct node *head;
    struct node *tail;
    int nodeNumber;
} List;
typedef struct node
{
    int data;
    struct node *next;
} node;

//This function initializes an empty list
List *initialization();

//This function creates a linked list with 'number' node
List *create(int number);

//This function will display the data value of each node
void read(List *list);

//This function returns a pointer to the node which is before "actual"
node *previous(List *list, node *actual);

//This function will swap the adjacent nodes a and b without changing data (the node a must be situated before b)
void swap(List *list, node *a, node *b);

//This function will insert a node with "number" as data value at the beginnig
void insert_beginnig(List *list, int number);

//This function will insert a node with "number" as data value at the end
void insert_end(List *list, int number);

//Sort the linked list
void sort(List *list);

//fill the linked list with "nodeNumber" node and its data value is situated between min and max
void randomFill(List *list, int nodeNumber, int min, int max);

//This function will destroy the linked list and all its nodes and free the memory
void destroy(List *list);
