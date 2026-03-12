// job structure
struct Job {
    int id;
    int deadline;
    int profit;
};

// sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs) {

    // Step 1: sort jobs by profit
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();

    // find maximum deadline
    int maxDeadline = 0;
    for(auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // slot array to track free time slots
    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;

    // Step 2: schedule jobs
    for(int i = 0; i < n; i++) {

        // try to schedule job at latest possible slot
        for(int j = jobs[i].deadline; j > 0; j--) {

            if(slot[j] == -1) { // slot is free

                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";

    for(int i = 1; i <= maxDeadline; i++) {
        if(slot[i] != -1) {
            cout << slot[i] << " ";
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}
