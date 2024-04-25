int main()
{
    struct Node *head = NULL;
    int choice, data, exitFlag = 0;

    while (!exitFlag)
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
            exitFlag = 1;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
