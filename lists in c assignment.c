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
    int choice, data;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printList(head);
            break;
        case 2:
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 5:
            return 0; // Exit the program
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
