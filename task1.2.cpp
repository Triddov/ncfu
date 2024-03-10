#include<iostream>
#include<stack>

using namespace std;

struct Monitor{
    int diagonal; // >0
    double price; // >0
};

int main(){

    stack<Monitor> MyStack;

    int stack_length;
    cout << "enter quantity monitors\n";
    cin >> stack_length;
    cout << "\n";

    while(int(MyStack.size())<stack_length){
        Monitor new_monitor;

        cout << "enter monitor diagonal\n";
        cin >> new_monitor.diagonal;
        cout << "enter monitor price\n";
        cin >> new_monitor.price;
        cout << "\n";

        MyStack.push(new_monitor);
    }

    int monitors_over_20inch = 0;
    double sum_price_over_20inch = 0;

    while(!MyStack.empty()){
        Monitor new_monitor = MyStack.top();
        if (new_monitor.diagonal>20){
            monitors_over_20inch++;
            sum_price_over_20inch+=new_monitor.price;
        }
        MyStack.pop();
    }

    cout << "quantity monitors over 20 inch: " << monitors_over_20inch << "\n";
    cout << "summary price monitors over 20 inch: " << sum_price_over_20inch << "\n";

    return 0;
}
