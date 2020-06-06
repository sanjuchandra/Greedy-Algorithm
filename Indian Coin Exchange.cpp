#include <iostream>
#include <algorithm>
using namespace std;


int no_of_coins(int coins[] , int n , int rupee){
    if(rupee <= 0){
        return 0;
    }
    int x = upper_bound(coins , coins + n , rupee) - coins - 1;
    return 1 + no_of_coins(coins , n , rupee - coins[x]);
}

int main(){
    int coins[] = {1 , 2, 5 , 10 , 20 , 50 , 100 , 200 , 500 , 2000};
    int n = sizeof(coins)/sizeof(int);
    int m;
    cin>>m;
    for(int i = 0 ; i < m ; i++){
        int rupee;
        cin>>rupee;
        cout<<no_of_coins(coins , n , rupee)<<endl;
    }
    return 0;
}
