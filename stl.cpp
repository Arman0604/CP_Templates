#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------------------- PAIR --------------------
    pair<int, int> p = {10, 20};          // stores two values
    cout << p.first << " " << p.second << "\n";

    pair<int, string> p2 = {1, "hello"};

    // -------------------- VECTOR --------------------
    vector<int> v = {5, 2, 9, 1};

    v.push_back(7);                       // add at end
    v.pop_back();                         // remove last
    cout << v.size() << "\n";             // number of elements
    cout << v.empty() << "\n";            // true if empty
    cout << v[0] << "\n";                 // access element (no bounds check)
    cout << v.at(0) << "\n";              // access element (bounds checked)
    v.clear();                            // remove all elements

    // -------------------- 2D VECTOR --------------------
    vector<vector<int>> mat(3, vector<int>(4, 0)); // 3x4 matrix

    // -------------------- STRING --------------------
    string s = "competitive";
    cout << s.size() << "\n";             // length of string
    s += " programming";                  // append string
    s.push_back('!');                     // add character at end
    reverse(s.begin(), s.end());          // reverse string
    cout << s << "\n";

    string t = "hello world";
    int pos = t.find("world");            // first occurrence of substring
    if (pos != string::npos) {            // npos means not found
        cout << pos << "\n";
    }
    int pos2 = t.find('o');               // first occurrence of character
    if (pos2 != string::npos) {
        cout << pos2 << "\n";
    }
    int last = t.rfind("l");              // last occurrence
    if (last != string::npos) {
        cout << last << "\n";
    }

    // -------------------- ARRAY --------------------
    array<int, 5> a = {4, 1, 3, 2, 5};    // fixed-size array

    // -------------------- STACK --------------------
    stack<int> st;
    st.push(10);                          // insert on top
    st.push(20);
    cout << st.top() << "\n";             // top element
    st.pop();                             // remove top
    cout << st.empty() << "\n";           // check empty

    // -------------------- QUEUE --------------------
    queue<int> q;
    q.push(1);                            // insert at back
    q.push(2);
    cout << q.front() << "\n";            // front element
    q.pop();                              // remove front
    cout << q.back() << "\n";             // back element

    // -------------------- DEQUE --------------------
    deque<int> d;
    d.push_back(10);                      // insert at back
    d.push_front(5);                      // insert at front
    d.pop_back();                         // remove from back
    d.pop_front();                        // remove from front

    // -------------------- PRIORITY QUEUE --------------------
    priority_queue<int> pq;               // max heap
    pq.push(3);
    pq.push(10);
    pq.push(5);
    cout << pq.top() << "\n";             // largest element
    pq.pop();                             // remove largest

    priority_queue<int, vector<int>, greater<int>> minpq; // min heap
    minpq.push(3);
    minpq.push(10);
    minpq.push(5);
    cout << minpq.top() << "\n";          // smallest element

    // -------------------- SET --------------------
    set<int> stt;
    stt.insert(3);                        // insert element
    stt.insert(1);
    stt.insert(2);
    stt.erase(2);                         // erase by value
    cout << stt.count(1) << "\n";         // 1 if present else 0
    cout << *stt.begin() << "\n";         // smallest element
    cout << *stt.rbegin() << "\n";        // largest element
    auto sit = stt.lower_bound(2);        // first element >= 2
    auto su = stt.upper_bound(2);         // first element > 2

    // -------------------- MULTISET --------------------
    multiset<int> ms;
    ms.insert(5);                         // duplicates allowed
    ms.insert(5);
    ms.insert(1);
    ms.insert(3);

    ms.erase(ms.find(5));                 // erase only one occurrence of 5
    // ms.erase(5);                       // erase all occurrences of 5

    cout << ms.count(5) << "\n";         // number of occurrences

    auto ml = ms.lower_bound(5);         // first element >= 5
    auto mu = ms.upper_bound(5);         // first element > 5
    auto mr = ms.equal_range(5);         // [lower_bound, upper_bound)

    if (ml != ms.end()) cout << *ml << "\n";
    if (mu != ms.end()) cout << *mu << "\n";

    // -------------------- UNORDERED SET --------------------
    unordered_set<int> us;
    us.insert(100);
    us.insert(20);
    us.erase(20);
    cout << us.count(100) << "\n";       // average O(1)

    // -------------------- MAP --------------------
    map<int, string> mp;
    mp[2] = "two";                        // insert/update
    mp[1] = "one";
    mp.insert({3, "three"});
    cout << mp[1] << "\n";                // access by key
    mp.erase(2);                          // remove key
    cout << mp.count(3) << "\n";          // 1 if key exists else 0

    // -------------------- UNORDERED MAP --------------------
    unordered_map<int, int> ump;
    ump[10] = 100;
    ump[20] = 200;
    cout << ump[10] << "\n";              // average O(1)

    // -------------------- LIST --------------------
    list<int> li;
    li.push_back(10);
    li.push_front(5);
    li.pop_back();
    li.pop_front();

    // -------------------- ITERATORS --------------------
    vector<int> vec = {10, 20, 30, 40};

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";               // forward iterator
    }
    cout << "\n";

    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";               // reverse iterator
    }
    cout << "\n";

    for (int x : vec) {
        cout << x << " ";                 // range-based loop
    }
    cout << "\n";

    // -------------------- ALGORITHMS --------------------
    vector<int> arr = {5, 1, 8, 3, 2};

    sort(arr.begin(), arr.end());                 // ascending sort
    sort(arr.begin(), arr.end(), greater<int>()); // descending sort
    reverse(arr.begin(), arr.end());              // reverse range

    int mx = *max_element(arr.begin(), arr.end()); // maximum element
    int mn = *min_element(arr.begin(), arr.end()); // minimum element

    int c = count(arr.begin(), arr.end(), 3);      // count occurrences
    cout << c << "\n";

    auto fit = find(arr.begin(), arr.end(), 8);    // find first occurrence
    if (fit != arr.end()) cout << "found\n";

    bool ok = binary_search(arr.begin(), arr.end(), 5); // search in sorted range
    cout << ok << "\n";

    auto lb = lower_bound(arr.begin(), arr.end(), 3);   // first >= 3
    auto ub = upper_bound(arr.begin(), arr.end(), 3);   // first > 3

    next_permutation(arr.begin(), arr.end());      // next lexicographic permutation
    prev_permutation(arr.begin(), arr.end());      // previous lexicographic permutation

    vector<int> pref = {1, 2, 3, 4};
    int sum = accumulate(pref.begin(), pref.end(), 0);  // sum of all elements
    cout << sum << "\n";

    vector<int> b = {1, 1, 2, 2, 2, 3};
    b.erase(unique(b.begin(), b.end()), b.end());  // remove consecutive duplicates

    // -------------------- NUMERIC FUNCTIONS --------------------
    cout << gcd(12, 18) << "\n";          // greatest common divisor
    cout << lcm(12, 18) << "\n";          // least common multiple

    // -------------------- SWAP --------------------
    int x = 5, y = 10;
    swap(x, y);                           // swap two variables

    // -------------------- VECTOR OF PAIRS --------------------
    vector<pair<int, int>> vp = {{2, 3}, {1, 5}, {2, 1}};
    sort(vp.begin(), vp.end());           // sorts by first, then second

    // Custom comparator
    sort(vp.begin(), vp.end(), [](auto &a, auto &b) {
        return a.second < b.second;       // sort by second value
    });

    return 0;
}
