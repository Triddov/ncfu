#include<iostream>
#include<list>
// ??






using namespace std;

int main(){

    list<int> Stack;

    int list_length;
    cout << "enter list length\n";
    cin >> list_length;

    cout << "enter numbers\n";
    int tmp;

    while(int(Stack.size())<list_length){
        cin >> tmp;
        Stack.push_back(tmp);

    }


    return 0;
}
