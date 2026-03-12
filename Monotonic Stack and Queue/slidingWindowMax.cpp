
vector<int> slidingWindowMaximum(vector<int>& nums, int k) {

    deque<int> dq;          // will store indices of useful elements
    vector<int> result;     // stores maximum of each window

    for(int i = 0; i < nums.size(); i++) {

        // Step 1: Remove indices that are outside the current window
        // Window range = [i-k+1 , i]
        if(!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Step 2: Maintain decreasing order in deque
        // Remove all smaller elements from the back
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Step 3: Add current index
        dq.push_back(i);

        // Step 4: Start storing answers once first window is complete
        if(i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}
