#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp = NULL;
void createList(int);
void enterData(int);
void display();
void enterAtFrontOfList();
void enterAtEndOfList();
void enterAtSpecifiedIndex();
void operations();

void main()
{
    int ch, len;
    printf("Do you want to create a linked list? (1 for yes, 0 for no)");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("How many elements do you want to enter to the linked list?");
        scanf("%d", &len);
        createList(len);
        break;
    case 0:
        break;
    }
    operations();
}
void operations()
{
    int ch;
    printf("\nWhich operation do you want to perform on the linked list?\n [0. To Exit, 1.Display 2.Enter data at front of list 3.Enter data at end of list 4. Enter data at a certain index]: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
        return;
        break;
    case 1:
        display();
        break;

    case 2:
        enterAtFrontOfList();
        break;
    case 3:
        enterAtEndOfList();
        break;
    case 4:
        enterAtSpecifiedIndex();
        break;
    }
    operations();
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
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
void enterAtFrontOfList()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}
void enterAtEndOfList()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    printf("Enter the data to be inserted");
    scanf("%d", &newNode->data);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void enterAtSpecifiedIndex()
{
    int pos, i;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("At which position do you want to insert the element?[starting from 1]");
    scanf("%d", &pos);
    if (pos <= 1)
    {
        enterAtFrontOfList();
        return;
    }
    printf("Enter the data to be inserted");
    scanf("%d", &newNode->data);
    temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}