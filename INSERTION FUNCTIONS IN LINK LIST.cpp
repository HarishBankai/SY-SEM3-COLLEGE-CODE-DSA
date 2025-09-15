typedef struct node
{
    int data;
    struct node* next;
} node;

//Insert at the beginning of the linked list
void insert_beginning()
    {
        node*newnode;
        newnode=(node*)malloc(sizeof(node));            //allocation memory for newnode
        printf("enter new data");
        scanf("%d",&newnode->data);

    //we have created a newnode and now we are going to link it to the head

        newnode->next=NULL;
        newnode->next=head;                            //linking newnode to head
        head=newnode;                                  //updating head to newnode
    }

//Insert at the end of the linked list

void insert_end()
{
    node*newnode, *p;

    newnode=(node*)malloc(sizeof(node));            //allocation memory for newnode
    printf("enter new data");                       
    scanf("%d",&newnode->data);
    newnode->next=NULL;                             //newnode next is null as it will be the last node

    //we have created a newnode and now we are going to link it to the last node

    p=head;                                        //start traversing from head
    while(p->next!=NULL)                            //traversing to the last node
    {
        p=p->next;
    }
    p->next=newnode;                                //link
}


//Insert at any position in the linked list

void insert_inbetween()
{
    node*newnode, *p;                                   //allocation memory for newnode

    //p is a pointer which will traverse the linked list. now we will take the location from the user where he wants to insert the newnode

    int i, loc;                                         //location to insert newnode
    printf("enter the location"); 
    scanf("%d",&loc);

    //we have taken the location from the user now we will traverse to that location and insert the newnode

    newnode=(node*)malloc(sizeof(node));                //allocation memory for newnode
    printf("enter new data");
    scanf("%d",&newnode->data);

    //we have created a newnode and now we are going to link it to the location

    newnode->next = NULL;                                //newnode next is null as it will be the last node
    p=head;                                              //start traversing from head
    while(i=0;i<loc-2;i++)                               //traversing to the node before the location
    {
        p=p->next;                                       //traversing to the next node
        newnode->next=p->next;                           //linking newnode to the next of p
        p->next=newnode;                                 //linking p to newnode
    }
}

