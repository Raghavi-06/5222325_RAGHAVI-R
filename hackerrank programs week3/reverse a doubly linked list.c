
struct DoublyLinkedListNode* reverse(struct DoublyLinkedListNode* head)
 {
    struct DoublyLinkedListNode*curr=head;
    struct DoublyLinkedListNode*temp=NULL;

    while(curr!=NULL)
     {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    if (temp!=NULL) 
    {
        head=temp->prev;
    }
    return head;
}