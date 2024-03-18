#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> MyStack;

    int stack_length;
    cout << "enter stack length\n";
    cin >> stack_length;

    cout << "enter numbers\n";
    int tmp;
    while(int(MyStack.size())<stack_length){
        cin >> tmp;
        MyStack.push(tmp);
    }

    int mult_odds = 1;

    while(!MyStack.empty()){
        if (MyStack.top()%2!=0){
            mult_odds*=MyStack.top();
        }
        MyStack.pop();
    }

    cout << "multiplication of all odd numbers\n" << mult_odds;


    return 0;
}
