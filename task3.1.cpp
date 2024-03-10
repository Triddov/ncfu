#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<double> Q1;
    queue<double> Q2;

    int q1_length;
    int q2_length;
    cout << "enter length of first queues\n";
    cin >> q1_length;
    cout << "enter length of second queues\n";
    cin >> q2_length;


    cout << "enter ascending numbers first queue\n";
    double tmp1;
    while(int(Q1.size()) < q1_length){
        cin >> tmp1;
        Q1.push(tmp1);
    }

    cout << "enter ascending numbers second queue\n";
    double tmp2;
    while(int(Q2.size()) < q2_length){
        cin >> tmp2;
        Q2.push(tmp2);
    }

    queue<double> Q3;

    auto num1 = Q1.front();
    auto num2 = Q2.front();

    double beginer = min(num1,num2);

    while(num1!=Q1.back()+1){
        while(num2!=Q2.back()+1){
            beginer = min(num1,num2);

            if(num1>=num2){
                Q3.push(num2);
                cout << 1;
            }else{
                Q3.push(num1);
                cout << 2;
            }

            if (beginer==num1) num1++;
            if (beginer==num2) num2++;
        }
    }

    cout << "new sorted queue\n";
    while(!Q3.empty()){
        cout << Q3.front() << " ";
        Q3.pop();
    }

    return 0;
}
