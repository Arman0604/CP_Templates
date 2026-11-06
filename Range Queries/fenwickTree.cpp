
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

// ============================================================
// FENWICK TREE (BINARY INDEXED TREE / BIT)
// ============================================================
// Operations:
// 1. Point Update: Add val to arr[i].
// 2. Prefix Sum: Find sum from index 0 to i.
// 3. Range Sum: Find sum in range [l, r].
//
// Time Complexity:
// Build         : O(N log N)
// Point Update  : O(log N)
// Prefix Query  : O(log N)
// Range Query   : O(log N)
//
// Space Complexity: O(N)
//
// External indexing = 0-based.
// Internal BIT indexing = 1-based.
// ============================================================

class FenwickTree{
    vector<long long> bit;
    int n;

public:

    // Constructor: Initialize BIT with n elements.
    FenwickTree(int n){
        this->n = n;
        bit.resize(n+1, 0);
    }

    // Add val to element at index i.
    void update(int i, long long val){

        // Convert 0-based index to 1-based index.
        i++;

        while(i <= n){

            // Add val to current BIT node.
            bit[i] += val;

            // Move to the next responsible node.
            // i & -i gives the lowest set bit.
            i += (i & -i);
        }
    }

    // Find prefix sum from index 0 to i.
    long long query(int i){

        // Convert 0-based index to 1-based index.
        i++;

        long long sum = 0;

        while(i > 0){

            // Add contribution of current BIT node.
            sum += bit[i];

            // Move to the parent node.
            i -= (i & -i);
        }

        return sum;
    }

    // Find sum of elements in range [l, r].
    long long rangeQuery(int l, int r){

        // Sum [l, r] = Prefix Sum [0, r] - Prefix Sum [0, l-1].
        long long right = query(r);
        long long left = 0;

        if(l > 0){
            left = query(l-1);
        }

        return right - left;
    }
};


// ============================================================
// MAIN FUNCTION - HOW TO USE FENWICK TREE
// ============================================================

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    // Create Fenwick Tree of size n.
    FenwickTree ft(n);

    // Build Fenwick Tree by inserting all array elements.
    for(int i=0; i<n; i++){
        ft.update(i, v[i]);
    }

    // --------------------------------------------------------
    // 1. PREFIX SUM QUERY
    // --------------------------------------------------------
    // Find sum of elements from index 0 to 3.
    long long prefix = ft.query(3);

    cout << prefix << endl;


    // --------------------------------------------------------
    // 2. RANGE SUM QUERY
    // --------------------------------------------------------
    // Find sum of elements from index 1 to 4.
    long long range = ft.rangeQuery(1, 4);

    cout << range << endl;


    // --------------------------------------------------------
    // 3. POINT UPDATE (ADDITION)
    // --------------------------------------------------------
    // Add 10 to element at index 2.
    ft.update(2, 10);

    // Check updated range sum.
    cout << ft.rangeQuery(1, 4) << endl;


    // --------------------------------------------------------
    // 4. POINT ASSIGNMENT (CHANGE VALUE)
    // --------------------------------------------------------
    // Change element at index 2 to 100.
    // Fenwick update performs addition, not assignment.
    long long newval = 100;
    long long diff = newval - v[2];

    v[2] = newval;
    ft.update(2, diff);

    cout << ft.rangeQuery(1, 4) << endl;

    return 0;
}
