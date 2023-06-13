#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Omer MEMES

struct Node
{
    struct Node *Next;
    int Value;
};

struct Node *CreateFirstNode(int Value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    NewNode->Value = Value;
    NewNode->Next = NewNode;

    return NewNode;
}

struct Node *InsertToBeginning(struct Node *Tail, int Value)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));

    NewNode->Value = Value;
    NewNode->Next = Tail->Next;
    Tail->Next = NewNode;

    return Tail;
}

void print(struct Node* Tail)
{
    struct Node *N1 = Tail->Next;
    do
    {
        printf("%d   ", N1->Value);
        N1 = N1->Next;

    } while (N1 != Tail->Next);
}

int main()
{
    struct Node* Tail;
    Tail = CreateFirstNode(1);
    Tail = InsertToBeginning(Tail, 2);
    Tail = InsertToBeginning(Tail, 3);
    Tail = InsertToBeginning(Tail, 4);
    print(Tail);
}
