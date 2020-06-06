#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main(){
    int t;
    cin>>t;
    vector<int> x , y;
    while(t--){
        int r , c , n;
        cin>>r>>c>>n;
        for(int i = 0 ; i < n ; i++){
            int a , b;
            cin>>a>>b;
            x.push_back(a);
            y.push_back(b);
        }
        if(n == 0){
            cout<<r*c<<endl;
        }
        else{
            sort(x.begin() , x.end());
            sort(y.begin() , y.end());
            int prev_x = 0;
            int prev_y = 0;
            int max_delta_x = 0;
            int max_delta_y = 0;
            for(auto t : x){
                max_delta_x = max(max_delta_x , t - prev_x - 1);
                prev_x = t;
            }
            max_delta_x = max(max_delta_x , r + 1 - x[n-1] - 1 );
            for(auto t : y){
                max_delta_y = max(max_delta_y , t - prev_y - 1);
                prev_y = t;
            }
            max_delta_y =  max(max_delta_y , c + 1 - y[n-1] - 1 );
            cout<<max_delta_x*max_delta_y<<endl;
            x.clear();
            y.clear();
        }

    }
}
