
// Omer MEMES

#include <stdio.h>
#include <stdlib.h>

int Counter = 0;

struct BST
{
    struct BST *Left;
    struct BST *Right;
    int Value;
};

struct BST *Create(int Value)
{
    struct BST *NewNode = (struct BST *)malloc(sizeof(struct BST));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Value = Value;
    ++Counter;
    return NewNode;
}

struct BST *Insert(struct BST *Root, int Value)
{
    if (Root == NULL)
    {
        Root = Create(Value);
    }
    else
    {
        if (Value <= Root->Value)
        {
            Root->Left = Insert(Root->Left, Value);
        }
        else
        {
            Root->Right = Insert(Root->Right, Value);
        }
    }

    return Root;
}

void PreOrder(struct BST *Root)
{
    // Root -> Left -> Right
    if (Root != NULL)
    {
        printf("%d\t", Root->Value);
        PreOrder(Root->Left);
        PreOrder(Root->Right);
    }
}

void InOrder(struct BST *Root)
{
    // Left -> Root -> Right
    if (Root != NULL)
    {
        PreOrder(Root->Left);
        printf("%d\t", Root->Value);
        PreOrder(Root->Right);
    }
}

void PostOrder(struct BST *Root)
{
    // Left -> Right -> Root
    if (Root != NULL)
    {
        PreOrder(Root->Left);
        PreOrder(Root->Right);
        printf("%d\t", Root->Value);
    }
}

struct BST *Search(struct BST *Root, int Value)
{
    if (Root == NULL || Root->Value == Value)
    {
        return Root;
    }
    else
    {
        if (Value < Root->Value)
        {
            return Search(Root->Left, Value);
        }
        else
        {
            return Search(Root->Right, Value);
        }
    } 
}

int Count()
{
    // return countNodes(root->left) + countNodes(root->right) + 1; ---> O(n)
    return Counter; // ---> O(1)
}

void FreeBT(struct BST *Root)
{
    if (Root != NULL)
    {
        FreeBT(Root->Left);
        FreeBT(Root->Right);
        free(Root);
    }
}

struct BST *Min(struct BST *Root)
{
    if (Root == NULL || Root->Left == NULL)
    {
        return Root;
    }

    return Min(Root->Left);
}

struct BST *Max(struct BST *Root)
{
    if (Root == NULL || Root->Right == NULL)
    {
        return Root;
    }

    return Max(Root->Right);
}

struct BST *Del(struct BST *Root, int Value)
{
    if (Root == NULL)
    {
        return NULL;
    }
    if (Value < Root->Value)
    {
        Root->Left = Del(Root->Left, Value);
    }
    else if (Value > Root->Value)
    {
        Root->Right = Del(Root->Right, Value);
    }
    else
    {
        if (Root->Left == NULL && Root->Right == NULL)
        {
            Root = NULL;
        }
        else if (Root->Right == NULL && Root->Left != NULL)
        {
            Root->Value = Root->Left->Value;
            free(Root->Left);
        }
        else if (Root->Left == NULL && Root->Right != NULL)
        {
            Root->Value = Root->Right->Value;
            free(Root->Right);
        }
        else
        {
            struct BST *MAXNode = Max(Root->Left);
            Root->Value = MAXNode->Value;
            Root->Left = Del(Root->Left, MAXNode->Value);
        }
    }

    return Root;
}

struct BST* Delete(struct BST* Root, int Value)
{
    struct BST* ROOT = Del(Root, Value);

    if(ROOT!=NULL)
    {
        Counter--;
    }

    return ROOT;
    
}

int main()
{
    system("cls");

    struct BST *Root = NULL;
    Root = Insert(Root, 5);
    Root = Insert(Root, 3);
    Root = Insert(Root, 663);
    Root = Insert(Root, 321);
    Root = Insert(Root, 654);
    Root = Insert(Root, 96);
    Root = Insert(Root, 65);
    Root = Delete(Root, 654);

    PostOrder(Root);

    struct BST *Node1 = Search(Root, 3);
    struct BST *Node2 = Min(Root);
    struct BST *Node3 = Max(Root);

    printf("\nSearch: %d: ", Node1->Value);
    printf("\nMin: %d", Node2->Value);
    printf("\nMax: %d", Node3->Value);

    printf("\nCounter: %d", Count());

    system("pause>0");
    return 0;
    
}