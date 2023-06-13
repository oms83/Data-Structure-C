// Omer MEMES


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int SIZE = 0;

struct Node
{
    struct Node *Next;
    struct Node *Prev;
    int Value;
};

struct Node *push(struct Node *Head, int Value)
{
    // insert at beginning
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    NewNode->Prev = NULL;
    NewNode->Value = Value;
    NewNode->Next = Head;

    if (Head != NULL)
    {
        Head->Prev = NewNode;
    }

    SIZE++; // O of one || O(1)

    Head = NewNode;
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

    SIZE++;

    return NULL;
}

struct Node *InsertAfter(struct Node *Head, int PrevValue, int Value)
{
    if (Head == NULL)
    {
        printf("\n[ Node Is NULL ..!! ]\n");
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

void print(struct Node *Head)
{

    printf("\n");
    while (Head != NULL)
    {
        printf(" %-*d ", 5, Head->Value);
        Head = Head->Next;
    }
    printf("\n");
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

struct Node *Reverse(struct Node *Head)
{
    if (Head == NULL)
    {
        printf("\n[ Node NULL ..!! ]\n");
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

struct Node *GetNodeByIndex(struct Node *Head, int Index)
{
    if ((Head == NULL) || (Index >= SIZE))
    {
        return NULL;
    }
    else
    {
        struct Node *Current = Head;
        int Counter = 0;
        while (Current != NULL && Counter < Index)
        {
            Counter++;
            Current = Current->Next;
        }
        return Current;
    }
}

struct Node *UpdateItem(struct Node *Head, int Index, int Value)
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

int Back(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, 0);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

int Front(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, SIZE - 1);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

int main()
{
    system("cls");
    struct Node *Head = NULL;
    Head = push(Head, 1);
    Head = push(Head, 2);
    Head = push(Head, 3);
    Head = push(Head, 4);
    Head = push(Head, 5);
    Head = push(Head, 6);
    Head = pop(Head);
    Head = pop(Head);
    print(Head);

    printf("\nSize: %d\n", Size());
    printf("\nFront: %d\n", Front(Head));
    printf("\nBack: %d\n", Back(Head));
}