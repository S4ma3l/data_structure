#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp = NULL;
void createList(int);

void main()
{
    int ch, len;
    printf("How many elements do you want to enter to the linked list?");
    scanf("%d", &len);
    createList(len);
}

void createList(int len)
{
    int i, dat;
    for (i = 1; i <= len; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &dat);
        enterData(dat);
    }
    temp = head;
}
void enterData(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = newNode;
        newNode->data = data;
        newNode->next = NULL;
        temp = head = newNode;
        // printf("Entered at first spot and address address to head\n");
    }
    else
    {
        temp->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
        temp = newNode;
        // printf("Entered at next spot and address address to previous node's next part\n");
    }
}
