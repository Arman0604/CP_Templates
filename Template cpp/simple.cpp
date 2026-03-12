#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }
        // Your logic here
        t--;
    }
    return 0;
}
