#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int num);
void printList(struct Node *head);
void append(struct Node **head, int num);
void prepend(struct Node **head, int num);
void deleteByKey(struct Node **head, int key);
void deleteByValue(struct Node **head, int value);
void insertAfterKey(struct Node **head, int key, int value);
void insertAfterValue(struct Node **head, int searchValue, int newValue);

int main()
{
    struct Node *head = NULL;
    int choice, data, key, value;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete by Key\n");
        printf("5. Delete by Value\n");
        printf("6. Insert After Key\n");
        printf("7. Insert After Value\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Linked List: ");
                printList(head);
                break;
            case 2:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 3:
                printf("Enter data to prepend: ");
                scanf("%d", &data);
                prepend(&head, data);
                break;
            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(&head, key);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 6:
                printf("Enter key to insert after: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfterKey(&head, key, value);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAfterValue(&head, value, data);
                break;
            case 8:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to create a new node
struct Node *createNode(int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->number = num;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

// Function to append a node at the end of the linked list
void append(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Function to prepend a node at the beginning of the linked list
void prepend(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node by key from the linked list
void deleteByKey(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->number == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->number != key)
    {
        prev = temp;
        temp = temp
