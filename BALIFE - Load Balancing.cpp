#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
ll load_balancing(vector<int> &input , int n, ll total_sum){
    /*float x = (float(total_sum))/n;
    int equal_load = total_sum/n;
    if(x != equal_load){
        return -1;
    }*/
    if(total_sum%n != 0){
        return -1;
    }
    int equal_load = total_sum/n;
    //cout<<equal_load<<endl;
    ll ans = INT_MIN;
    ll left_sum = 0;
    ll right_sum = 0;
    for(int i = 1 ; i < n ; i++){
        left_sum += input[i-1];
        right_sum = total_sum - left_sum;
        ll required_sum_on_left = i*equal_load;
        ll required_sum_on_right = total_sum - required_sum_on_left;
        if(left_sum < required_sum_on_left){
            //borrow from right
            ans = max(ans , right_sum - required_sum_on_right);
        }
        else{
            //give lent to right
            ans = max(ans , left_sum - required_sum_on_left);
        }

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
