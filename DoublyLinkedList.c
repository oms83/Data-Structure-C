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

struct Node *InsertAtBeginning(struct Node *Head, int Value)
{
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

struct Node *InsertAtEnd(struct Node *Head, int Value)
{

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
        printf("\n[ Node Cannot Be Empty ..!! ]\n");
        return NULL;
    }
    else
    {

        struct Node *PrevNode = Head;
        int Counter = 0;
        while (PrevNode->Value != PrevValue && PrevNode != NULL)
        {
            Counter++;
            PrevNode = PrevNode->Next;

            if (Counter == SIZE)
            {
                printf("\n[ Value Not Founded ..!! ]\n");
                return Head;
            }
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

struct Node *InsertBefor(struct Node *Head, int NextValue, int Value)
{
    if (Head == NULL)
    {
        printf("\n[ Node Cannot Be Empty ..!! ]\n");
        return NULL;
    }
    else
    {
        struct Node *NextNode = Head;

        if (NextNode->Value == NextValue)
        {
            SIZE++;
            return InsertAtBeginning(Head, Value);
        }

        int Counter = 0;
        while (NextNode->Value != NextValue && NextNode != NULL)
        {
            NextNode = NextNode->Next;

            if (Counter == SIZE)
            {
                printf("\n[ Value Not Founded ..!! ]\n");
                return Head;
            }
        }

        struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

        NewNode->Prev = NextNode->Prev;
        NewNode->Next = NextNode;
        NewNode->Value = Value;

        if (NextNode->Prev != NULL)
        {
            NextNode->Prev->Next = NewNode;
        }

        NextNode->Prev = NewNode;
    }

    SIZE++; // O of one || O(1)

    return Head;
}

struct Node *DeleteFirstNode(struct Node *Head)
{

    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return NULL;
    }
    struct Node *Current = Head;
    if (Head->Next == NULL)
    {
        free(Head);
        SIZE--; // O of one || O(1)
        return NULL;
    }
    else
    {
        Head = Current->Next;

        if (Head != NULL)
        {
            Head->Prev = NULL;
        }

        free(Current);

        SIZE--; // O of one || O(1)
    }

    return Head;
}

struct Node *DeleteLastNode(struct Node *Head)
{
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

struct Node *Delete(struct Node *Head, int Value)
{
    struct Node *Current = Head;

    if (Head == NULL)
    {
        printf("\n[ Node Empty ..!! ]\n");
        return NULL;
    }
    else if (Current->Value == Value)
    {
        Current->Prev = NULL;
        Head = Current->Next;
        free(Current);

        SIZE--; // O of one || O(1)

        return NULL;
    }
    else
    {

        while (Current->Next != NULL && Current != NULL)
        {
            Current = Current->Next;
        }

        Current->Prev->Next = Current->Next;

        if (Current->Next != NULL)
        {
            Current->Next->Prev = Current->Prev;
        }

        free(Current);
    }

    SIZE--;

    return Head;
}

void PrintList(struct Node *Head)
{

    printf("NULL <-->");
    while (Head != NULL)
    {
        printf(" %d <--> ", Head->Value);
        Head = Head->Next;
    }
    printf(" NULL");
}

void PrintNodeDetails(struct Node *Head)
{
    if (Head->Prev != NULL)
        printf("%-*d", 4, Head->Prev->Value);
    else
        printf("NULL");

    printf(" <--> %-*d <--> ", 4, Head->Value);

    if (Head->Next != NULL)
        printf("%-*d", 4, Head->Next->Value);
    else
        printf("NULL");
}

void PrintListDetails(struct Node *Head)
{
    while (Head != NULL)
    {
        PrintNodeDetails(Head);
        printf("\n");
        Head = Head->Next;
    }
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
        Head = DeleteFirstNode(Head);
    }
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

int GetFirstItem(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, 0);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

int GetLastItem(struct Node *Head)
{
    struct Node *N1 = GetNodeByIndex(Head, SIZE - 1);
    if (N1 != NULL)
    {
        return N1->Value;
    }

    printf("\nNode Not Found :-( ");
    return 0;
}

struct Node* InsertAccordingTo(struct Node* Head, int Standard, int Value)
{
    if(Standard >= Value)
        return InsertBefor(Head, Standard, Value);

    else
        return InsertAfter(Head, Standard, Value);
}

int main()
{
    system("cls");
    struct Node *Head = NULL;

    // Head = InsertAtBeginning(Head, 1);
    // Head = InsertAtBeginning(Head, 3);
    // Head = InsertAtBeginning(Head, 4);
    // Head = InsertAtBeginning(Head, 2);
    // Head = InsertAfter(Head, 9, 1);
    // Head = InsertBefor(Head, 4, 500);
    // Head = InsertBefor(Head, 2, 600);
    // Head = InsertAfter(Head, 4, 500);
    // PrintList(Head);
    // PrintListDetails(Head);

    Head = InsertAtBeginning(Head, 7);
    Head = InsertAccordingTo(Head, 7, 1);
    Head = InsertAccordingTo(Head, 7, 10);
    Head = InsertAccordingTo(Head, 7, 13);
    Head = InsertAccordingTo(Head, 7, 4);
    Head = InsertAccordingTo(Head, 7, 96);
    Head = InsertAccordingTo(Head, 7, 3);
    
    PrintListDetails(Head);
    // Head = InsertAtBeginning(Head, 1);
    // Head = InsertAtBeginning(Head, 2);
    // Head = InsertAtBeginning(Head, 3);

    // Head = InsertAtEnd(Head, 4);
    // Head = InsertAtEnd(Head, 5);
    // Head = InsertAtEnd(Head, 6);

    // struct Node *N1 = Find(Head, 5);
    // Head = InsertAfter(Head, 6, 7);

    // // Head = Delete(Head, 7);
    // // Head = DeleteFirstNode(Head);
    // // Head = DeleteFirstNode(Head);
    // // Head = DeleteLastNode(Head);
    // // Head = DeleteLastNode(Head);
    // // Head = Clear(Head);

    // // printf("\n\nSize:  %d \n", Size());

    // // PrintListDetails(Head);

    // // Head = Reverse(Head);
    // // printf("\n\nSize:  %d \n\n", Size());

    // // struct Node *N2 = GetNodeByIndex(Head, 0);
    // // printf("\nNode by index: %d\n", N2->Value);

    // Head = UpdateItem(Head, 1, 6050);

    // printf("\nFirst Item: %d\n", GetFirstItem(Head));
    // printf("\nLast Item: %d\n", GetLastItem(Head));

    // PrintListDetails(Head);
}