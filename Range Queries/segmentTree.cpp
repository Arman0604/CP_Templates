
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

// ============================================================
// 1. SEGMENT TREE WITH LAZY PROPAGATION
// ============================================================
// Operations:
// 1. Range Update: Add val to every element in [l, r].
// 2. Range Query: Find sum of elements in [l, r].
//
// Time Complexity:
// Build  : O(N)
// Update : O(log N)
// Query  : O(log N)
//
// Note: This implementation supports range addition,
// NOT range assignment.
// ============================================================

class SGTreeL{
    vector<long long> seg, lazy;

public:

    SGTreeL(int n){
        seg.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    // Build the segment tree.
    void built(int low, int hi, int idx, vector<int>& arr){

        if(low == hi){
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (hi-low)/2;

        // Left child = 2*idx+1
        built(low, mid, 2*idx+1, arr);

        // Right child = 2*idx+2
        built(mid+1, hi, 2*idx+2, arr);

        // Parent stores sum of both children.
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    // Push pending lazy update to the current node
    // and postpone it for its children.
    void push(int low, int hi, int idx){

        if(lazy[idx] != 0){

            // Every element in this segment increases by lazy[idx].
            // Therefore, segment sum increases by length * lazy[idx].
            seg[idx] += (hi-low+1) * lazy[idx];

            if(low != hi){

                // Pass pending addition to both children.
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }

            // Current node's pending update is processed.
            lazy[idx] = 0;
        }
    }

    // Add val to every element in range [l, r].
    void update(int low, int hi, int idx, int l, int r, long long val){

        // First process any pending update.
        push(low, hi, idx);

        // Case 1: No overlap.
        if(hi < l || low > r){
            return;
        }

        // Case 2: Complete overlap.
        if(low >= l && hi <= r){

            // Update current segment.
            seg[idx] += (hi-low+1) * val;

            // Postpone update for children.
            if(low != hi){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }

            return;
        }

        // Case 3: Partial overlap.
        int mid = low + (hi-low)/2;

        update(low, mid, 2*idx+1, l, r, val);
        update(mid+1, hi, 2*idx+2, l, r, val);

        // Recalculate parent after updating children.
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    // Find sum of elements in range [l, r].
    long long query(int low, int hi, int idx, int l, int r){

        // First process any pending update.
        push(low, hi, idx);

        // Case 1: No overlap.
        if(hi < l || low > r){
            return 0;
        }

        // Case 2: Complete overlap.
        if(low >= l && hi <= r){
            return seg[idx];
        }

        // Case 3: Partial overlap.
        int mid = low + (hi-low)/2;

        long long left = query(low, mid, 2*idx+1, l, r);
        long long right = query(mid+1, hi, 2*idx+2, l, r);

        return left + right;
    }
};


// ============================================================
// 2. NORMAL SEGMENT TREE
// ============================================================
// Operations:
// 1. Point Update: Change arr[i] to val.
// 2. Range Query: Find minimum element in [l, r].
//
// Time Complexity:
// Build  : O(N)
// Update : O(log N)
// Query  : O(log N)
//
// To change this into a Sum/Max/GCD segment tree,
// modify the merging operation and the no-overlap value.
// ============================================================

class SGTree{
    vector<int> seg;

public:

    SGTree(int n){
        seg.resize(4*n, INT_MAX);
    }

    // Build the segment tree.
    void built(int low, int hi, int idx, vector<int>& arr){

        if(low == hi){
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (hi-low)/2;

        // Build left and right subtrees.
        built(low, mid, 2*idx+1, arr);
        built(mid+1, hi, 2*idx+2, arr);

        // Parent stores minimum of both children.
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }

    // Find minimum element in range [l, r].
    int query(int low, int hi, int l, int r, int idx){

        // Case 1: No overlap.
        // INT_MAX does not affect the minimum operation.
        if(l > hi || r < low){
            return INT_MAX;
        }

        // Case 2: Complete overlap.
        if(low >= l && hi <= r){
            return seg[idx];
        }

        // Case 3: Partial overlap.
        int mid = low + (hi-low)/2;

        int left = query(low, mid, l, r, 2*idx+1);
        int right = query(mid+1, hi, l, r, 2*idx+2);

        return min(left, right);
    }

    // Change the value at index i to val.
    void update(int low, int hi, int idx, int i, int val){

        // Reached the required index.
        if(low == hi){
            seg[idx] = val;
            return;
        }

        int mid = low + (hi-low)/2;

        // Find which subtree contains index i.
        if(i <= mid){
            update(low, mid, 2*idx+1, i, val);
        }
        else{
            update(mid+1, hi, 2*idx+2, i, val);
        }

        // Recalculate minimum while returning from recursion.
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }
};


// ============================================================
// 3. MAIN FUNCTION - USAGE EXAMPLES
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

    // --------------------------------------------------------
    // NORMAL SEGMENT TREE
    // --------------------------------------------------------

    SGTree sgt(n);

    // Build: low=0, hi=n-1, root index=0.
    sgt.built(0, n-1, 0, v);

    // Range Minimum Query [l, r].
    int ans = sgt.query(0, n-1, 2, 5, 0);

    // Point Update: arr[2] = 100.
    sgt.update(0, n-1, 0, 2, 100);


    // --------------------------------------------------------
    // LAZY PROPAGATION
    // --------------------------------------------------------

    SGTreeL sgtl(n);

    // Build the lazy segment tree.
    sgtl.built(0, n-1, 0, v);

    // Range Update: Add 10 to every element in [1, 4].
    sgtl.update(0, n-1, 0, 1, 4, 10);

    // Range Sum Query [1, 4].
    long long sum = sgtl.query(0, n-1, 0, 1, 4);

    cout << ans << endl;
    cout << sum << endl;

    return 0;
}
