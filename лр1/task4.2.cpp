#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

int main(){

    forward_list<string> MyList;

    int list_lenght;
    cout << "enter list length\n";
    cin >> list_lenght;

    string tmp;

    cout << "enter strings\n";
    for(int i=0;i<list_lenght;i++){
        cin >> tmp;
        MyList.push_front(tmp);
    }

    string minString = "  ";

    for(auto i: MyList){
        minString = minString.length()<i.length()? minString : i;
    }

    MyList.remove(minString);

    cout << "list of strings without string minimum length:\n";
    for(auto i: MyList){
        cout << i << " ";
    }

    return 0;
}

