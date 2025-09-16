//node structure
typedef struct node
{
    int data;
    struct node* next;
} node;

//count no. of nodes in SLL
int count_nodes(node* head)
{
    int count = 0;               //initialize count = 0
    if(head == NULL)             //if there is no node in list, return 0
        return 0;
    
    node* temp = head;           //create a temp pointer and point it to head
    while(temp != NULL) {
        count++;                 //increment count for each node
        temp = temp->next;       //move temp to next node
    }
    return count;                //return the count
}

