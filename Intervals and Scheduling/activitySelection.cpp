// structure to store activity
struct Activity {
    int start;
    int finish;
};

// comparator to sort by finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {

    // Step 1: sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";

    // select the first activity (finishes earlier)
    int lastFinish = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    // Step 2: check remaining activities
    for(int i = 1; i < activities.size(); i++) {

        // if activity start time >= last selected finish time
        if(activities[i].start >= lastFinish) {

            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";

            // update finish time
            lastFinish = activities[i].finish;
        }
    }
}
