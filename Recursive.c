#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//                                                                              Ömer Memes 
int ReadAPositiveNumber(char *Message)
{
    int Number;
    do
    {
        printf("\n%s", Message);
        scanf("%d", &Number);

    } while (Number < 0);

    return Number;
}

char *TextNumber(int Number)
{
    char *Numbers[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *Tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *result = (char *)malloc(1000 * sizeof(char));
    strcpy(result, "");

    if (Number < 20)
        sprintf(result, "%s%s ", result, Numbers[Number]);
    else if (Number < 100)
        sprintf(result, "%s%s %s ", result, Tens[Number / 10], Numbers[Number % 10]);
    else if (Number < 1000)
        sprintf(result, "%s%s hundred %s ", result, TextNumber(Number / 100), TextNumber(Number % 100));
    else if (Number < 1000000)
        sprintf(result, "%s%s thousand %s ", result, TextNumber(Number / 1000), TextNumber(Number % 1000));
    else if (Number < 1000000000)
        sprintf(result, "%s%s million %s ", result, TextNumber(Number / 1000000), TextNumber(Number % 1000000));
    else if (Number < 1000000000000)
        sprintf(result, "%s%s billion %s ", result, TextNumber(Number / 1000000000), TextNumber(Number % 1000000000));

    return result;
}

void Fibonacci(int Number, int Prev1, int Prev2)
{
    int FibNumber = 0;

    if (Number > 0)
    {
        FibNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FibNumber;
        printf("%d\t", FibNumber);
        return Fibonacci(Number - 1, Prev1, Prev2);
    }
}

void Fibo(int Number)
{
    int Prev1 = 1;
    int Prev2 = 0;

    printf("%d\t", Prev1);

    int FibNumber = 0;
    for (int i = 0; i < Number; i++)
    {
        FibNumber = Prev1 + Prev2;
        printf("%d\t", FibNumber);
        Prev2 = Prev1;
        Prev1 = FibNumber;
    }
}

int NPowM(int N, int M)
{
    if (M == 0)
    {
        return 1;
    }
    return N * NPowM(N, M - 1);
}

int Pow()
{
    int N = ReadAPositiveNumber("Tabani gir: ");
    int M = ReadAPositiveNumber("Usu gir: ");
    int Result = 1;
    for (int i = 0; i < M; i++)
    {
        Result *= N;
    }

    return Result;
}

int NCarpiM(int N, int M)
{
    if (N == 0)
    {
        return 0;
    }

    return M + NCarpiM(N - 1, M);
}

int Carpi(int N, int M)
{
    int Result = 0;
    for (int i = 0; i < N; i++)
    {
        Result += M;
    }

    return Result;
}

int main()
{
    system("clear");

    printf("\n3^4: %d ", NPowM(3, 4));
    // printf("\nPow: %d ", Pow());

    // printf("\n3*4: %d ", NCarpiM(4, 3));

    // printf("\nFibonacci Sersisi: ");
    // Fibo(4);

    // printf("\nFibonacci Sersisi: ");
    // Fibonacci(6, 0, 1);

    // int Number = ReadAPositiveNumber("Enter a positive number: ");
    // printf("%s", TextNumber(Number));

    system("pause>0");
    return 0;
}