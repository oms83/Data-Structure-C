#include<iostream>
#include<queue>
#include<stack>


using namespace std;

int main()
{
    system("cls");

    stack <int> stkA;
    stkA.push(1);
    stkA.push(2);
    stkA.push(3);
    stkA.push(4);
    stkA.push(5);
    stkA.push(6);
    stkA.pop();
    stkA.pop();
    cout << "stack top : " << stkA.top() << endl;
    
    queue <int> quA;
    quA.push(1);
    quA.push(2);
    quA.push(3);
    quA.push(4);
    quA.push(5);
    quA.push(6);
    quA.pop();
    quA.pop();
    cout << "queue front : " << quA.front() << endl;
    cout << "queue back  : " << quA.back() << endl;
    system("puase>0");
}