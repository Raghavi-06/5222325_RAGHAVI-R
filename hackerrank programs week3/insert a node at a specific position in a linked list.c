
struct SinglyLinkedListNode*insertNodeAtPosition(struct SinglyLinkedListNode*head,int data,int position)
 {
    struct SinglyLinkedListNode* newNode = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    newNode->data=data;
    newNode->next=NULL;

    if (position==0)
     {
        newNode->next=head;
        return newNode;
    }
    struct SinglyLinkedListNode*curr=head;
    for(int i=0; i<position-1 && curr!=NULL;i++) 
    {
     curr=curr->next;
    }
    newNode->next=curr->next;
    curr->next=newNode;
    return head;
}
