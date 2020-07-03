#include <iostream>
#include <stack>
using namespace std;
bool IsStringBalanced(char *a){
    stack <char> s;
    for(int i=0;a[i]!='\0';i++){
        char ch = a[i];
        switch(ch){
            case '(':
            case '{':
            case '[': s.push(ch);
                      break;
            case ')': if(s.top()=='('&& !s.empty()){
                            s.pop();
                            break;
                         }
                       else{
                        return false;
                       }
            case ']': if(s.top()=='['&& !s.empty()){
                            s.pop();
                            break;
                         }
                       else{
                        return false;
                       }
            case '}': if(s.top()=='{'&& !s.empty()){
                            s.pop();
                            break;
                         }
                       else{
                        return false;
                       }
        }
    }

    return s.empty();
}

int main()
{   char a[] = "){}";
    bool b = IsStringBalanced(a);
    if(b){
        cout<<"yes the string is balanced";
    }
    else{
        cout<<"string is inbalnced";
    }
    return 0;
}
