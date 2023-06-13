// Omer MEMES


#include <stdio.h>
#include <stdlib.h>

static int SIZE = 0;

struct Node
{
    int Value;
    struct Node *Next;
};

int GetAPositiveNumber(char Message[])
{
    int Number;
    do
    {
        printf("\n%s\n: ", Message);
        scanf("%d", &Number);
    } while (Number < 0);

    return Number;
}

struct Node *InsertAtBeginning(struct Node *Head, int Value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->Value = Value;
    NewNode->Next = Head;
    Head = NewNode;
    SIZE++;
    return Head;
}

struct Node *InsertAtEnd(struct Node *Head, int Value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->Value = Value;
    NewNode->Next = NULL;

    if (Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        struct Node *Current = Head;
        while (Current->Next != NULL && Current != NULL)
        {
            Current = Current->Next;
        }
        Current->Next = NewNode;
    }

    SIZE++;

    return Head;
}

struct Node *Find(struct Node *Head, int Value)
{
    struct Node *Current = Head;

    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return NULL;
    }
    else
    {
        while (Current->Value != Value && Current != NULL)
        {
            Current = Current->Next;
        }
        return Current;
    }

    return Head;
}

struct Node *InsertAfter(struct Node *Head, int PrevValue, int Value)
{

    if (Head == NULL)
    {
        printf("\n[ Previous Cannot Be Empty ..!! ]\n");
    }
    else
    {
        struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
        struct Node *PrevNode = Head;

        int Counter = 0;
        while (PrevNode->Value != PrevValue && PrevNode != NULL)
        {
            PrevNode = PrevNode->Next;

            if (Counter == SIZE)
            {
                printf("\n[ Value Not Founded ..!! ]\n");
                return Head;
            }
        }

        NewNode->Next = PrevNode->Next;
        NewNode->Value = Value;
        PrevNode->Next = NewNode;
    }

    SIZE++;

    return Head;
}

struct Node *DeleteFirstNode(struct Node *Head)
{
    struct Node *Current = Head;
    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return Head;
    }
    else
    {
        Head = Current->Next;
        free(Current);
    }

    SIZE--;

    return Head;
}

struct Node *DeleteLastNode(struct Node *Head)
{
    struct Node *Current = Head;
    struct Node *Prev = Head;
    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return Head;
    }
    else if (Current->Next == NULL)
    {
        Head = NULL;
        free(Current);
    }
    else
    {
        while (Current->Next != NULL && Current != NULL)
        {
            Prev = Current;
            Current = Current->Next;
        }

        Prev->Next = NULL;
        free(Current);
    }

    SIZE--;

    return Head;
}

struct Node *Delete(struct Node *Head, int Value)
{
    struct Node *Current = Head;
    struct Node *Prev = Head;

    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return Head;
    }
    else if (Current->Next == NULL)
    {
        Head = NULL;
        free(Current);
    }
    else
    {
        while (Current->Value != Value && Current != NULL)
        {
            Prev = Current;
            Current = Current->Next;
        }

        Prev->Next = Current->Next;
        free(Current);
    }

    SIZE--;

    return Head;
}

int Size()
{
    return SIZE;
}

int GetFirstItem(struct Node *Head)
{
    if (Head != NULL)
    {
        return Head->Value;
    }

    printf("\n[ Node Empty ..!! ]\n");
    return 0;
}

int GetLastItem(struct Node *Head)
{
    if (Head != NULL)
    {
        struct Node *Current = Head;
        while (Current->Next != NULL)
        {
            Current = Current->Next;
        }
        return Current->Value;
    }

    printf("\n[ Node Empty ..!! ]\n");
    return 0;
}

void Print(struct Node *Head)
{
    struct Node *Current = Head;
    while (Current != NULL)
    {
        printf("%d   ", Current->Value);
        Current = Current->Next;
    }
    printf("\n\n");
}

int main()
{
    system("cls");

    struct Node *Head = NULL;

    Head = InsertAtBeginning(Head, 5);
    Head = InsertAtBeginning(Head, 4);
    Head = InsertAtBeginning(Head, 3);
    Head = InsertAtBeginning(Head, 2);

    Head = InsertAtEnd(Head, 6);
    Head = InsertAtEnd(Head, 7);

    struct Node *N1 = Find(Head, 2);
    Head = InsertAfter(N1, 7, 7);
    Print(Head);

    Head = DeleteFirstNode(Head);
    Print(Head);

    Head = DeleteLastNode(Head);
    Print(Head);

    printf("\n\nSize:  %d ", Size());

    // struct Node* N1 = Find(Head, 2);
    // printf("\n%d ", N1->Value);

    system("pause>0");
    return 0;
}
