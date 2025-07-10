#include<iostream>
#include<algorithm>
using namespace std;

// creating structure for holding two data together
struct event {
    int start;
    int end;
};

// creating compare function
bool comp(event first, event second) {
    return first.end < second.end;
}

int main(){
    // number of times
    int x; cin>>x;
    // loop for each time
    for(int i = 0; i < x; i++) {
        // taking events input
        int n; cin>>n;
        event events[n];

        // loop for taking event input
        for(int j = 0; j < n; j++) {
            // input start and end time
            cin>>events[j].start>>events[j].end;
        }

        //sort the events
        sort(events, events + n, comp);
        // selected activities count variable
        int numberOfEvents = 1;
        // taking first events ent time as default endtime for comparing
        int defaultEndTime = events[0].end;

        // checking other event with default end time
        int j = 1;
        while(j<n )
        {
            if(events[j].start >= defaultEndTime) {
                numberOfEvents++;
                // changing the default end time
                defaultEndTime = events[j].end;
            }
            j++;
        }

        cout << numberOfEvents << endl;

    }
    return 0;
}








































#include<iostream>
#include<algorithm>
using namespace std;

// Creating a structure to hold event start and end times
struct Activity {
    int startTime;
    int endTime;
};

// Comparison function to sort activities by their end times
bool compareActivities(Activity a, Activity b) {
    return a.endTime < b.endTime;
}

int main() {
    int testCases; // Variable for number of test cases
    cin >> testCases;

    while (testCases--) {
        int numEvents; // Number of events for the current test case
        cin >> numEvents;

        // Array to hold the start and end times of events
        Activity events[numEvents];

        // Input start and end times of the events
        for (int i = 0; i < numEvents; i++) {
            cin >> events[i].startTime >> events[i].endTime;
        }

        // Sort events based on their end time
        sort(events, events + numEvents, compareActivities);

        // Variable to count the maximum number of events we can attend
        int count = 1;  // We can always attend the first event
        int lastEndTime = events[0].endTime; // Store the end time of the first event

        // Check other events
        for (int i = 1; i < numEvents; i++) {
            if (events[i].startTime >= lastEndTime) { // If the start time is after the last event's end time
                count++;  // Increment the count of events we can attend
                lastEndTime = events[i].endTime; // Update the last end time
            }
        }

        // Output the result for the current test case
        cout << count << endl;
    }

    return 0;
}
