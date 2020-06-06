#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


#define ll long long
typedef pair<string , int> p;

bool cmp(const p x , const p y){
    return x.second <= y.second;
}

ll badness(vector<int> &standing , int n){
    sort(standing.begin() , standing.end());
    ll ans = 0;
    for(int i = 0 ; i <n ; i++){
        ans += abs(standing[i] - (i + 1));
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
