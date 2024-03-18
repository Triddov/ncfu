#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

int main(){

    forward_list<double> MyList;

    int list_lenght;
    cout << "enter list length\n";
    cin >> list_lenght;

    cout << "enter numbers\n";
    for(int i=0;i<list_lenght;i++){
        int tmp;
        cin >> tmp;
        MyList.push_front(tmp);
    }

    vector<double> copyMyList;
    for(auto i: MyList){
        copyMyList.push_back(i);
    }

    for(int i=0;i<copyMyList.size();i++){
        if (copyMyList[i]==55){
            MyList.remove(copyMyList[i+1]);
        }
    }

    cout << "list with element removed:\n";
    for(auto i: MyList){
        cout << i << " ";
    }

    return 0;
}
