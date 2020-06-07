#include <iostream>
#include <algorithm>
using namespace std;

//#define ll long long

int main(){
    int n , d;
    int arr[100007] = {0};
    cin>>n>>d;
    for(int  i = 1 ; i < n ; i++){
        cin>>arr[i];
    }
    sort(arr , arr+n);
    int cnt = 0;
    for(int i = 1 ; i < n ;){
        if(arr[i] - arr[i-1] <= d){
            i = i+2;
            cnt++;
            continue;
        }
        i++;
    }
    cout<<cnt<<endl;
}
