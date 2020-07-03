#include <iostream>

using namespace std;
template <typename T>
class Vector{
    T *arr;
    int curr;
    int maxm;
public:
    Vector(int default_size = 4){
        maxm = default_size;
        curr = 0;
        arr = new T[maxm];
    }
    void Push_back(T n){
        if(curr==maxm){
            T *oldarr = arr;
            arr = new T[2*maxm];
            maxm = 2*maxm;
            for(int i=0;i<curr;i++){
                arr[i]= oldarr[i];
            }
            delete [] oldarr;
        }
        arr[curr]=n;
        curr++;
    }
    void pop_back(){
        if(curr!=0){
        curr--;}
    }
    void print(){
        for(int i=0;i<curr;i++){
            cout<<arr[i]<<" ";
        }
    }
    T IthTerm(int i){
        return arr[i];
    }
    T& operator[](int i){
        return arr[i];
    }
    int CurrentSize(){
        return curr;
    }
    int MaxSize(){
        return maxm;
    }
    void Add(Vector &X){
        for(int i=0;i<X.CurrentSize();i++){
            if(curr==maxm){
                T *oldarr = arr;
                arr = new T[2*maxm];
                maxm = 2*maxm;
                for(int i=0;i<curr;i++){
                    arr[i]= oldarr[i];
                }
                delete [] oldarr;
            }
            arr[curr]=X.arr[i];
            curr++;
        }
    }

};

ostream& operator<<(ostream& io,Vector<char> X){
    X.print();
    return io;
}

int main()
{   Vector <char> v(8);
    v.Push_back('a');
    v.Push_back('b');
    v.Push_back('q');
    Vector<char> v1(8);
    v1.Push_back('y');
    v1.Push_back('u');
    v1.Push_back('r');
    v1.Push_back('s');
    v1.pop_back();
    v1.print();
    v[2]= 'c';
    cout<<v[2]<<endl;;
    v.Add(v1);
    return 0;
}
