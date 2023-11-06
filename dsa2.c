#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

void createnode(struct Node** head, int row, int col, int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->row = row;
    newnode->col = col;
    newnode->value = value;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct Node* head,int n,int m){
    struct Node* temp = head;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(temp != NULL && temp->row==i&& temp->col==j)
            {printf(" %d ",temp->value);
            temp=temp->next;
        }
            else
            printf(" 0 ");
        }
        printf("\n");
    }
    
}

int main() {
    int i, j, l, n, a, b, c;
    struct Node* head = NULL;
    
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &j, &l);
    
    printf("Enter the number of non-zero elements:\n");
    scanf("%d", &i);
    
    for (n = 0; n < i; n++) {
        printf("Enter the row no., col no., and value respectively:\n");
        scanf("%d %d %d", &a, &b, &c);
        createnode(&head, a, b, c);
    }
    display(head,j,l);
    return 0;
}

