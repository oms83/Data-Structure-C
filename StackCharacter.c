#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int SIZE = 0;

struct Node
{
    struct Node *Next;
    struct Node *Prev;
    char Value;
};

struct Node *push(struct Node *Head, char Value)
{
    // insert at end
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    NewNode->Value = Value;
    NewNode->Next = NULL;

    if (Head == NULL)
    {
        NewNode->Prev = NULL;
        Head = NewNode;
    }
    else
    {
        struct Node *Current = Head;

        while (Current->Next != NULL && Current != NULL)
        {
            Current = Current->Next;
        }

        NewNode->Prev = Current;
        Current->Next = NewNode;
    }

    SIZE++; // O of one || O(1)

    return Head;
}

struct Node *pop(struct Node *Head)
{
    // delete last node
    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return Head;
    }
    else if (Head->Next == NULL)
    {
        free(Head);
        SIZE--; // O of one || O(1)
        return NULL;
    }
    else
    {
        struct Node *Current = Head;
        while (Current->Next != NULL && Current != NULL)
        {
            Current = Current->Next;
        }

        Current->Prev->Next = NULL;

        free(Current);
    }

    SIZE--; // O of one || O(1)

    return Head;
}

struct Node *InsertAfter(struct Node *Head, char PrevValue, char Value)
{
    if (Head == NULL)
    {
        printf("\n[ Previous Cannot Be Empty ..!! ]\n");
        return NULL;
    }
    else
    {

        struct Node *PrevNode = Head;

        while (PrevNode->Value != PrevValue && PrevNode != NULL)
        {
            PrevNode = PrevNode->Next;
        }

        struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

        NewNode->Next = PrevNode->Next;
        NewNode->Value = Value;
        NewNode->Prev = PrevNode;

        if (PrevNode->Next != NULL)
        {
            PrevNode->Next->Prev = NewNode;
        }
        PrevNode->Next = NewNode;
    }

    SIZE++; // O of one || O(1)

    return Head;
}

struct Node *Reverse(struct Node *Head)
{
    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return NULL;
    }
    else if (SIZE == 1)
    {
        return Head;
    }
    else
    {
        struct Node *Current = Head;
        struct Node *Temp = NULL;

        while (Current != NULL)
        {
            Temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = Temp;
            Current = Current->Prev;
        }

        if (Temp != NULL)
        {
            Head = Temp->Prev;
        }
    }
    return Head;
}

int Size()
{
    return SIZE;
}

bool IsEmpty()
{
    return SIZE == 0;
}

struct Node *Clear(struct Node *Head)
{
    for (int i = 0; i < SIZE; i++)
    {
        Head = pop(Head);
    }
}

struct Node *GetNodeByIndex(struct Node *Head, int Index)
{
    if ((Head == NULL) || (Index >= SIZE))
    {
        return NULL;
    }
    else
    {
        struct Node *Current = Head;
        for (int i = 0; i < Index; i++)
        {
            Current = Current->Next;
        }
        return Current;
    }
}

struct Node *UpdateItem(struct Node *Head, int Index, char Value)
{
    struct Node *N1 = GetNodeByIndex(Head, Index);
    if (N1 == NULL)
    {
        return Head;
    }
    else
    {
        N1->Value = Value;
    }
    return Head;
}

char bottom(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, 0);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

char top(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, SIZE - 1);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

char peek(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, SIZE - 1);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

void print(struct Node *Head)
{
    printf("\n");
    while (Head != NULL)
    {
        printf("%c", Head->Value);
        Head = Head->Next;
    }
    printf("\n");
}

int main()
{
    system("cls");
    struct Node *Head = NULL;
    Head = push(Head, 'o');
    Head = push(Head, 'm');
    Head = push(Head, 'e');
    Head = push(Head, 'r');
    Head = push(Head, ' ');
    Head = push(Head, 'm');
    Head = push(Head, 'e');
    Head = push(Head, 'm');
    Head = push(Head, 'e');
    Head = push(Head, 's');
    Head = pop(Head);
    // Head = pop(Head);

    printf("\nSize: %d\n", Size());
    printf("\nTop: %c\n", top(Head));
    printf("\nPeek: %c\n", peek(Head));
    printf("\nBottom: %c\n", bottom(Head));

    print(Head);
}