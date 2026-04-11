// Time: O(nlog n)
// Space: O(n)

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


bool compare2(pair<double,int> p1, pair<double,int> p2){
    return p1.first > p2.first;
}
double fractionalKnapsack(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    vector<pair<double, int>> ratio(n, make_pair(0,0));
    for(int i=0; i<n; i++){
        double r = (wt[i] == 0) ? 0 : val[i]/(double)wt[i];
        ratio[i] = make_pair(r, i);
    }
    sort(ratio.begin(), ratio.end(), compare2);

    double ans = 0.0;
    for(int i=0; i<n; i++){
        int idx = ratio[i].second;
        if(wt[idx] <= W){
            ans += val[idx];
            W -= wt[idx];
        }
        else {
            ans += ratio[i].first * W;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};

    cout<<fractionalKnapsack(value, weight, 50)<<endl;
}