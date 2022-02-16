 #include <stdio.h>
 #include <stdlib.h>
 

struct Node{
    int data;
    struct Node *next;
};

//===================Create========================
struct Node * create(struct Node *head){
    struct Node *temp, *currentNode;
    int num;
    
    printf("\nEnter the  number of nodes to insert : ");
    scanf("%d",&num);
    printf("\n");
      
      for (int i = 0; i < num; i++)
    {
      currentNode = (struct Node *) malloc (sizeof (struct Node));
      printf ("Enter the data of node : ");
      scanf ("%d", &currentNode->data);

      if (i == 0)
	{
	  head = temp = currentNode;
	}
      else
	{
	  temp->next = currentNode;
	  temp = currentNode;
	}

    }

    temp->next = NULL;
    temp = head;
    
    return head;
}

//===================Display========================
void displayLL(struct Node *head){
    
    struct Node *ptr=head;
    
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

//===================Insert Before========================
struct Node * insertBefore(struct Node *head){
    int value,data;    
    printf("\nData in nodes are :\n");
    displayLL(head);
        
    printf("\nEnter the value of Node before which you want to Insert : ");
    scanf("%d",&value);
            
    printf("\nEnter the data to Insert : ");
    scanf("%d",&data);
            
    struct Node *ptr=head;
    struct Node *pre=ptr;
    
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    
    while(ptr!=NULL && ptr->data!=value){
    
        pre=ptr;
        ptr=ptr->next;
    }
    
    if(ptr==NULL){
        printf("\nNo Node found with given data\n");
        return head;
    }
    else if(ptr==head){
        newnode->next=head; 
        head=newnode;
    }
    else{
        pre->next=newnode;
        newnode->next=ptr;
    }

    printf("\n\nData in nodes after inserting is :\n");
    displayLL(head);
    
    return head;
}

//==================Insert After==========================
void insertAfter(struct Node *head){
    int value ,data ;
    printf("\nData in nodes are :\n");
    displayLL(head);
            
    printf("\n\nEnter the value of Node after which you want to Insert : ");
    scanf("%d",&value);
            
    printf("\nEnter the data to Insert : ");
    scanf("%d",&data);
    
    struct Node *ptr=head;
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    
    while(ptr!=NULL && ptr->data!=value  ){
        ptr=ptr->next;
    }

    if(ptr==NULL){
        printf("\nNo Node found with given data\n");
    } 
    else{
        newnode->next=ptr->next;
        ptr->next=newnode;
        printf("\nData in nodes after inserting is :\n");
        displayLL(head);    
     }
     
}

//==================Delete==========================
struct Node * delete(struct Node *head){
    int value;
    printf("\nData in nodes are :\n");
    displayLL(head);
            
    printf("\n\nEnter the value of Node to Delete : ");
    scanf("%d",&value);
    
    struct Node *ptr=head;
    struct Node *pre=ptr;
    
    while(ptr!=NULL && ptr->data!=value){
        pre=ptr;
        ptr=ptr->next;
    }
    
     if(ptr==NULL){
        printf("\nNo Node found with given data\n");  
    }
    else if(ptr==head){
        ptr=head->next;
        free(head);
        head=ptr;
    }
    else{
        pre->next=ptr->next;
        free(ptr);
    }
    
    printf("\nData in nodes after deletion is :\n");
    displayLL(head);    
    
    return head;
}    


//===================main========================
int main()
{
  struct Node *head;
  int choice;
  do{
      printf("---------Linked List Oprations---------\n");
      printf("1  -->  Create\n");
      printf("2  -->  Display\n");
      printf("3  -->  Insert before a Node\n");
      printf("4  -->  Insert after a Node\n");
      printf("5  -->  Delete\n");
      printf("6  -->  Exit\n");
      printf("\nEnter your choice : ");
      scanf("%d",&choice);
      
      switch(choice){
          case 1:
            head=create (head);
            break;
            
          case 2:
            printf("\nThe elements of Linked List are \n");
            displayLL(head);
            break;
          
          case 3:
            head=insertBefore(head); 
            break;
          
          case 4:  
            insertAfter(head);
            break;
          
          case 5:
            head=delete(head);
            break;
            
          case 6: 
            break;
          
          default: 
            printf("Please select a correct option!\n");
      }
     printf("\n");
     printf("\n");
  }while(choice!=6);
  
    return 0;
}


