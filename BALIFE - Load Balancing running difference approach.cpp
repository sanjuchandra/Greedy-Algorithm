#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
ll load_balancing(vector<int> &input , int n, ll total_sum){
    if(total_sum%n != 0){
        return -1;
    }
    int equal_load = total_sum/n;
    ll ans = INT_MIN;
    ll running_diff = 0;
    for(int i = 1 ; i < n ; i++){
        running_diff += (input[i-1] - equal_load);
        ans = max(ans , abs(running_diff));
    }
    return ans;
}

int main(){
    vector<int> input;
    while(1){
        int n;
        cin>>n;
        if(n == -1){
            //break;
            return 0;
        }
        int total_sum = 0;
        for(int i = 0 ; i < n ; i++){
            int d;
            cin>>d;
            input.push_back(d);
            total_sum += d;
        }
        cout<<load_balancing(input , n , total_sum)<<endl;
        input.clear();
    }
    return 0;
}
