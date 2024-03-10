#include <iostream>
#include <forward_list>

using namespace std;

int main(){

    forward_list<int> MyList;

    int list_lenght;
    cout << "enter list length\n";
    cin >> list_lenght;

    cout << "enter numbers\n";
    for(int i=0;i<list_lenght;i++){
        int tmp;
        cin >> tmp;
        MyList.push_front(tmp);
    }

    double average;
    int sum_elem = 0;
    int count_elem = 0;

    for(auto i: MyList){
        if (i%4==0){
            sum_elem+=i;
            count_elem++;
        }
    }
    average = sum_elem/double(count_elem);

    cout << "Average number multiple of 4: "<< average;

    return 0;
}

