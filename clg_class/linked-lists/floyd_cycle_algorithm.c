struct node *floyd_cycle(struct node* head)
{
    struct node* fast = head;
    struct node* slow = head;
    while(fast != NULL /*even condition*/ && fast->next !=NULL /*odd condition*/ )
        {
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                while(slow!=fast)

                {
                    slow = slow->next;
                    fast = fast->next;

                }
                printf("loop detected at: %d ",fast->data);
                return fast;
            }

        }
    printf("NO LOOP DETECTED!");
    return NULL;    

}


void remove_loop(struct node *flyod_cycle_result)
{
    //code...
}