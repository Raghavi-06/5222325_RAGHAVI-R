
struct SinglyLinkedListNode*mergeLists(struct SinglyLinkedListNode*head1,struct SinglyLinkedListNode*head2)
 {
   
    if (head1==NULL) return head2;
    if (head2==NULL) return head1;
    struct SinglyLinkedListNode* result = NULL;
    
    if (head1->data<=head2->data) 
    {
        result=head1;
        result->next=mergeLists(head1->next,head2);
    } 
    else
     {
        result=head2;
        result->next=mergeLists(head1,head2->next);
    }
    return result;
}
