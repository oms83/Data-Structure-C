// Omer MEMES

#include <stdio.h>
#include <stdlib.h>
void Swap(int *N1, int *N2)
{
    int Temp = *N1;
    *N1 = *N2;
    *N2 = Temp;
}

void Heapify(int Arr[], int Size, int i)
{
    int Max = i;
    int Left = 2 * i + 1;
    int Right = 2 * i + 2;

    if (Left < Size && Arr[Left] > Arr[Max])
        Max = Left;

    if (Right < Size && Arr[Right] > Arr[Max])
        Max = Right;

    if (Max != i)
    {
        Swap(&Arr[i], &Arr[Max]);

        Heapify(Arr, Size, Max);
    }
}

void Build(int Arr[], int Size)
{
    for (int i = Size / 2 - 1; i >= 0; i--)
        Heapify(Arr, Size, i);
}

void HeapSort(int Arr[], int Size)
{
    Build(Arr, Size);

    for (int i = Size - 1; i > 0; i--)
    {
        Swap(&Arr[0], &Arr[i]);

        Heapify(Arr, i, 0);
    }
}

void PrintArray(int Arr[], int Size)
{
    for (int i = 0; i < Size; ++i)
        printf("%d ", Arr[i]);
    printf("\n");
}

int main()
{
    system("cls");
    int Arr[] = {65, 66, 75, 52, 63, 69, 23, 55};
    int Size = sizeof(Arr) / sizeof(Arr[0]);

    printf("Original Array            : ");
    PrintArray(Arr, Size);

    HeapSort(Arr, Size);

    printf("Sorted By Heap Sort Array : ");
    PrintArray(Arr, Size);

    system("pause>0");
    return 0;
}
