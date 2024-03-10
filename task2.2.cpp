#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<double> Q1;
    queue<double> Q2;

    int queue_length;
    cout << "enter length of both queues\n";
    cin >> queue_length;

    cout << "enter numbers first queue\n";
    double tmp1;
    while(int(Q1.size()) < queue_length){
        cin >> tmp1;
        Q1.push(tmp1);
    }

    cout << "\n";

    cout << "enter numbers second queue\n";
    double tmp2;
    while(int(Q2.size()) < queue_length){
        cin >> tmp2;
        Q2.push(tmp2);
    }

    queue<double> Q3;

    for(auto num1 = Q1.front(), num2 = Q2.front(); num1!=Q1.back()+1 and num2!=Q2.back()+1; num1++,num2++ ){
        Q3.push(num1);
        Q3.push(num2);
    }

    cout << "new queue of from alternating elements of the previous two\n";
    while(!Q3.empty()){
        cout << Q3.front() << " ";
        Q3.pop();
    }

    return 0;
}
