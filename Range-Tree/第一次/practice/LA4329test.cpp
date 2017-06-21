#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ans=0;
    for(int i=1;i<=19998;++i){
        ans+=(i*(20000-i-1));
    }
    //3:3,7,3   �ⶥΪ3+2:5 (4
    //4:4,6,6,4 �ⶥΪ4+2:6 (2
    //5:5,8,9,8,5     7 (3 1
    //6:6,10,12,12,10,6  8 (4 2
    cout<<ans<<endl;
    return 0;
}
