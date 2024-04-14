#include<bits/stdc++.h>

#include<thread>
using namespace std;

void tasksA(int x){
    for (int i = x; i < x+5; i++)
    {
        cout<<i<<endl;
        sleep(1);
    }
}
void tasksB(int y){
    for (int j = y; j < y+5; j++)
    {
        cout<<j<<endl;
        sleep(1);
    }
    
}
int main(){
    thread t1(tasksA,9);
    thread t2(tasksB,12);

    t1.join();
    t2.join();
}