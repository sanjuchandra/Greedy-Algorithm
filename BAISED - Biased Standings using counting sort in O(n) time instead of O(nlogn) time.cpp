#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


#define ll long long
ll badness(vector<int> &standing , int n){  
    int *arr = new int[n+10]();
    for(auto x : standing){
        arr[x]++;
    }
    ll ans  = 0;
    int j = 1;
    for(int i = 1 ; i <= n ; i++){
        while(j < n and arr[j] == 0){
            j++;
        }
        ans += abs(i - j);
        //cout<<ans<<"-->"<<j<<endl;
        arr[j]--;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<int> standing;
    while(t--){
        cin.get(); //to consume whitespace
        int n;
        cin>>n;
        for(int i = 0 ; i  < n ; i++){
            string s;
            int x;
            cin>>s;
            cin>>x;
            standing.push_back(x);
        }
        cout<<badness(standing , n)<<endl;
        standing.clear();
    }
}
