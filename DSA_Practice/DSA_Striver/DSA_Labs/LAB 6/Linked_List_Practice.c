#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *next;    
};

struct node* createNode(int data) {
    struct node* newNode = (Struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Overflow! Can't allocate memory.\n");
    }
    else {
        newNode -> data=data;
        newNode -> next=NULL;
    }
    return newNode;
}

struct node* insertAtBeggining(struct node *head, int data) {
    struct node *head=createNode(data);
    if(newNode==NULL) {
        return head;
    }
    newNode->next=head;
    head=newNode;
    printf("Inserted %d at the beggining.\n",data);
    return head;
}

struct node* insertatEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if(newNode==NULL) {
        printf("Overflow! can't allocate memory. \n");
    }

    if (head == NULL) {
        printf("List was empty. Inserted %d at the end.\n", data);
        return newNode;
    }

    struct node* ptr=head;
    while(ptr->next != NULL) {
        ptr=ptr->next;
    }

    ptr->next=newNode;

    printf("Inserted %d at the end.\n",data);
    return head;
}

struct node* insertAfter(struct node *head, int targetData, int newData) {
    struct node *ptr=head;
    while(ptr->next!=NULL){
        if(ptr->data==targetData){
            struct node* newNode = createNode(data);
            if(newNode==NULL){
                return head;
            }
            newNode->next=ptr->next;
            ptr->next=newNode;

            printf("Inserted %d after %d. \n",newData,targetData);
        }
        ptr=ptr->next;
    }
    printf("-> Node with data %d not found.\n", targetData);
    return head;  
}

struct node* insertBefore(struct node *head, int targetData, int newData) {
    if (head == NULL) {
        printf("-> List is empty, cannot insert before.\n");
        return NULL;
    }
    if(head->data==targetData) {
        return insertinBeggining(int head,newData);
    }
    
    struct node *ptr=head;
    while(ptr->next != NULL) {
     if (ptr->next->data == targetData) {
            struct node* newNode = createNode(newData);
            if (newNode == NULL) {
                return head;
            }
            
            newNode->next = ptr->next;
            ptr->next = newNode;
            
            printf("-> Inserted %d before %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;   
    }
    printf(" Node with data %d not found.\n", targetData);
    return head;
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = head;
    printf("CURRENT LIST: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void freeList(struct node *head) {
    struct node *ptr = head;
    struct node *temp;
    
    printf("\nFreeing pointers! \n");
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("Pointers freed.\n");
}

struct node* traversalToEnd(struct node* head){
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    struct node* ptr=head;
    while(ptr->next != NULL) {
        ptr=ptr->next;
    }
    printf("The last node is: %d",ptr->data);

    return ptr;
}

struct node* deleteAtBeggining(struct node* head){
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    struct node *temp = head;
    head = head->next;
    
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
    
    return head;   
}

struct node* deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("Deleted %d (the last node) from the end.\n", head->data);
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    struct node *preptr = NULL;
    
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    struct node* temp=ptr->next;
    ptr->next=NULL;
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);

    preptr->next = NULL;
    printf("Deleted %d from the end.\n", ptr->data);
    free(ptr);
    
    return head;
}

struct node* deleteAfterNode(struct node *head, int targetData) {
    struct node *ptr = head;

    while (ptr != NULL && ptr->data != targetData) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("No node found with data %d.\n", targetData);
        return head; 
    }

    
    if (ptr->next == NULL) {
        printf("Node %d is the last node, nothing to delete after it.\n", targetData);
        return head; 
    }

    struct node *temp = ptr->next; 
    ptr->next = temp->next;        
    
    printf("Deleted node with data %d.\n", temp->data);
    free(temp);

    return head;
}