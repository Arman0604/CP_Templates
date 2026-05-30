#include <bits/stdc++.h>
using namespace std;

int maximumOverlappingIntervals(vector<pair<int,int>>& intervals) {
    vector<int> start, end;

    for (auto &it : intervals) {
        start.push_back(it.first);
        end.push_back(it.second);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int curr = 0, ans = 0;
    int n = intervals.size();

    while (i < n && j < n) {
        if (start[i] <= end[j]) {
            curr++;
            ans = max(ans, curr);
            i++;
        } else {
            curr--;
            j++;
        }
    }

    return ans;
}

int main() {
    vector<pair<int,int>> intervals = {
        {1, 4}, {2, 5}, {7, 9}, {3, 6}
    };

    cout << maximumOverlappingIntervals(intervals) << endl;
    return 0;
}
