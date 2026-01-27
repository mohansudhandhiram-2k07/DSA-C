    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define MAX 101


    struct audio
    {
        char audio[MAX];
        struct audio * next;
        struct audio * prev;
    };

    

    void insert_at_pos(struct audio **head);
    void create_list(struct audio **head);
    struct audio *create_node();
    char *get_string();
    void display(struct audio *head);

int main() {
    struct audio *audio_head = NULL;
    struct audio *video_head = NULL;
    struct audio *image_head = NULL;

    int choice;

    while (1) {
        printf("\n1. Audio List\n2. Video List\n3. Image List\n0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        struct audio **current = NULL;

        switch(choice) {
            case 1:
                current = &audio_head; 
                break;
            case 2: 
                current = &video_head; 
                break;
            case 3: 
                current = &image_head; 
                break;
            case 0: 
                exit(0);
            default: 
                printf("Invalid choice\n"); 
                continue;
        }

        printf("\n1. Create List\n2. Insert at Pos\n3. Display\nChoice: ");
        int op; scanf("%d", &op);

        switch(op) {
            case 1: create_list(current); break;
            case 2: insert_at_pos(current); break;
            case 3: display(*current); break;
            default: printf("Invalid operation\n");
        }
    }
}
    void create_list(struct audio** head)
    {
        struct audio *temp = *head;
        struct audio *newnode;
        int choice = 1;
        
        
        do
        {
            struct audio *newnode  = create_node();
            
            if(temp == NULL)
            {
                
                temp = newnode;
                *head = temp;
            }
            else
            {
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
            }
            printf("\ndo you want to add another node?(0/1): ");
            scanf("%d",&choice);
        }while(choice);
        
        
    }
    struct audio *create_node()
    {
        struct audio* newnode = (struct audio *)malloc(sizeof(struct audio));
        if(newnode == NULL)
        {
            printf("memory full!!\n");
            exit(EXIT_FAILURE);
        }
        newnode->next = NULL;
        newnode->prev = NULL;
        char *str = get_string();
        strcpy(newnode->audio,str);
        return newnode;
    }

    char *get_string()
    {
        char *name = (char *)malloc(MAX);
        printf("\nENTER NAME:");
        scanf("%s",name);
        return name;
    }
    void display(struct audio *head)
    {
        while(head != NULL)
        {
            printf("%s\n",head->audio);
            head = head->next;
        }

    }
    void insert_at_pos(struct audio **head)
    {
        struct audio *temp = *head;
        if((*head) == NULL)
        {
            printf("NO LINKED LIST FOUND!!\n");
            return;
        }
        int pos;
        printf("\nENTER POSITION TO INSERT: ");
        scanf("%d",&pos);
        struct audio *newnode = create_node();
        if(pos == 1)
        {
            newnode->next = *head;
            *head = newnode;
            temp->prev = newnode;
            return;
        }
        for(int i = 1; i<pos-1;i++)
        {
            if(temp->next == NULL)
            {
                printf("invalid position\n");
                return;
            }
            temp = temp->next;
        }
        if(temp->next != NULL)
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
        }
    }


