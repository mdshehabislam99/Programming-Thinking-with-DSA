#include<bits/stdc++.h>
using namespace std;

//a1[] and a2[]
double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
    int n1 = a1.size();
    int n2 = a2.size();
    
    if(n1 > n2) {
        return findMedianSortedArrays(a2, a1);
    }
    
    int i = 0, j = 0;
    int n = n1 + n2;
    int idx2 = n/2;
    int idx1 = idx2-1;
    int cnt = 0;
    int idx1el = -1; int idx2el = -1;
    
    while(i < n1 && j < n2) {
       if(a1[i] < a2[j]) {
            if(cnt == idx1) idx1el = a1[i];
            if(cnt == idx2)  idx2el = a1[i];
            cnt++;
            i++;
        } else {
            if(cnt == idx1) idx1el = a2[j];
            if(cnt == idx2) idx2el = a2[j]; 
            cnt++;
            j++;
        }
        
    }

    while(i < n1) {
        if(cnt == idx1) idx1el = a1[i];
        if(cnt == idx2)  idx2el = a1[i];
        cnt++;
        i++;
    }

    while(j < n2) {
        if(cnt == idx1) idx1el = a2[j];
        if(cnt == idx2)  idx2el = a2[j]; 
        cnt++;
        j++;
    }
    return (idx1el + idx2el) / 2.0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double ans;
    vector<int> a1 = {1, 4,6,8,9,11};
    vector<int> a2 = {2,5,7,10,12};
    ans = findMedianSortedArrays(a1, a2);
    cout << ans << endl;
    return 0;
}
