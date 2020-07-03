#include <iostream>
#include <algorithm>
using namespace std;

int main()
{   int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int w,h,n;
        cin>>w>>h>>n;
        int arrw[n+1],arrh[n+1];
        for(int i=0;i<n;i++){
            cin>>arrw[i]>>arrh[i];
        }
        arrw[n]=w;
        arrh[n]=h;
        sort(arrw,arrw+n);
        sort(arrh,arrh+n);
        int curr=0;
        int maxw=0;
        int maxh=0;
        int initialh  =0;
        int initialw = 0;

        for(int i=0;i<=n;i++){
                curr = (arrh[i]-initialh-1);
                initialh = arrh[i];
                maxh = max(maxh,curr);
            }
        for(int i=0;i<=n;i++){
                curr = (arrw[i]-initialw-1);
                initialw = arrw[i];
                maxw = max(maxw,curr);
            }

        cout<<(maxw*maxh);
    }
    return 0;
}
