#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> maxleft;
    priority_queue<int,vector<int>,greater<int> > minright;
    int data;
    cin>>data;
    int num;
    cin>>num;
    while(num!=0){
        if(num == -1){
            cout<<data<<endl;
            if(maxleft.size()==minright.size()){
                int temp = maxleft.top();
                maxleft.pop();
                data = temp;
            }
            else{
                int temp = minright.top();
                minright.pop();
                data = temp;
            }
        }
        else{
            if(num<=data){
                maxleft.push(num);
            }
            else{
                minright.push(num);
            }
            if((maxleft.size()-minright.size())==1){
                int temp = maxleft.top();
                maxleft.pop();
                minright.push(data);
                data = temp;
                }
            if((minright.size()-maxleft.size())>1){
                int temp = minright.top();
                minright.pop();
                maxleft.push(data);
                data = temp;
            }
        }
        cin>>num;
    }
    return 0;
}
