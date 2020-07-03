#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
class cordinates{
public:
    int x;
    int y;

    cordinates(int x,int y){
        this->x = x;
        this->y = y;
    }
};
class mycompare{
public:
    bool operator()(cordinates a, cordinates b){
        int xa = sqrt((a.x*a.x)-(a.y*a.y));
        int xb = sqrt((b.x*b.x)-(b.y*b.y));
        return xa>xb;
    }
};
int main()
{
    priority_queue<cordinates,vector<cordinates>,mycompare> car;
    for(int i=0;i<5;i++){
        int x,y;
        cin>>x>>y;
        cordinates c(x,y);
        car.push(c);
    }
    while(!car.empty()){
        cout<<car.top().x<<" "<<car.top().y<<endl;
        car.pop();
    }

    return 0;
}
