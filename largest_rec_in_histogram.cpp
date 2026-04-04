#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nsL(vector<int> heights){
    int n = heights.size();
    stack<int> st;
    vector<int> nsL(n, -1);
    nsL[0] = -1;
    st.push(0);
    for(int i=1; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]  ){
            st.pop();
        }

    if(st.empty()) nsL[i] = -1;
    else nsL[i] = st.top();
    st.push(i);
    }
    return nsL;
}

vector<int> nsR(vector<int> heights){
    int n = heights.size();
    stack<int> st;
    vector<int> nsR(n, -1);
    nsR[n-1] = n;
    st.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!st.empty() && heights[i] <= heights[st.top()]){
            st.pop();
        }

    if(st.empty()) nsR[i] = n;
    else nsR[i] = st.top();
    st.push(i);
    }
    return nsR;
}


int largestRectangleArea(vector<int>& heights) {
    vector<int> nsL1 = nsL(heights);
    vector<int> nsR1 = nsR(heights);
    int maxArea = 0;
    for(int i=0; i<heights.size(); i++){
        int area = heights[i] * (nsR1[i] - nsL1[i] - 1);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = largestRectangleArea(heights);
    cout<<ans<<endl;
}
