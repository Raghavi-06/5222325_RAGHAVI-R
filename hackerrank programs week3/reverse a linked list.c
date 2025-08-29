
struct SinglyLinkedListNode* reverse(struct SinglyLinkedListNode* head)
 {
    struct SinglyLinkedListNode* prev = NULL;
    struct SinglyLinkedListNode* curr = head;
    struct SinglyLinkedListNode* next = NULL;

    while (curr != NULL)
     {
        next = curr->next;   
        curr->next = prev;    
        prev = curr;          
        curr = next;         
    }
    return prev; 
}
