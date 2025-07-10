#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    //taking input for the number of students and the minimum participation required
    int numberOfStudents;
    int numberParticipation;
    cin >> numberOfStudents >> numberParticipation;

    // creating a variable to carry the count of students can participate
    int x = 0;

    // creating loop to take individual participation
    for(int i=0; i<numberOfStudents; i++){
        // input taking
        int timesTried; cin >> timesTried;

        // checking the value if it has minimum requirement
        // 5-numberParticipation is the number of times a student can still participate
        if( timesTried <= 5 - numberParticipation ){
            x++;
        }
    }
    // deviding the value by 3 to get the groups
    int groups = x / 3;
    //print result
    cout<< groups << endl;
}







































#include<iostream>
using namespace std;

int main() {
    // Taking input for the number of students and minimum participation required
    int numStudents, minParticipation;
    cin >> numStudents >> minParticipation;

    // Array to store the number of times each student has participated
    int attempts;
    int eligibleCount = 0;

    // Loop through each student's participation
    for (int i = 0; i < numStudents; i++) {
        cin >> attempts;

        // Check if the student can participate enough times
        if (attempts <= (5 - minParticipation)) {
            eligibleCount++;
        }
    }

    // Calculate how many full groups of 3 can be formed
    int groups = eligibleCount / 3;

    // Output the result
    cout << groups << endl;

    return 0;
}
