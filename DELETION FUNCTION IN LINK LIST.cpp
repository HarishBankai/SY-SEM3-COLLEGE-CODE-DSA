typedef struct node
{
    int data;
    struct node* next;
} node;

void delete_beg()
{
    node* q;                                        //temporary node to store the address of head
    q=head;                                         //storing head address in q
    printf("deleted element is %d",q->data);        //printing the data of the node to be deleted
    
    head=head->next;                                //updating head to next node  
    free(q);                                        //freeing the memory of the deleted node
}   

void delete_end()
{
    node*q, *p;                               //temporary node to store the address of head
    p=head;                                   //storing head address in p

//if there is only one node, then we will delete that node and update head to null

    while(p->next->next!=NULL)
    {
        p=p->next;                             //traversing to the second last node
        q=p->next;                             //storing the address of last node in q
        printf("deleted element is %d",q->data); //printing the data of the node to be deleted
        p->next=NULL;                          //updating second last node next to null
        free(q);                               //freeing the memory of the deleted node
    }
}

void delete_inbetween()
{
    node* q, *p;                               //temporary node to store the address of head
    int loc,i;
    printf("enter the location");
    scanf("%d",&loc);

//if there is only one node, then we will delete that node and update head to null

    p=head;                                   //storing head address in p
    for(i=0;i<loc-2;i++)                      //traversing to the node before the location
    {
        p=p->next;
    }
    q=p->next;                                //storing the address of node to be deleted in q
    printf("deleted element is %d",q->data); //printing the data of the node to be deleted
    p->next=q->next;                         //updating the next of previous node to next of the node to be deleted
    free(q);                                 //freeing the memory of the deleted node
}