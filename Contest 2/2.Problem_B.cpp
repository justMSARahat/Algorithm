#include<iostream>
using namespace std;

// Creating fuction called fanction that takes a string as input.
string fanction(const string& input){
    // taking another sttring variable to store number and output
    string output = "";
    // Using length function to get the length of the input string
    int length = input.length();
    // Looping through the input string
    for(int i = 0; i < length; i++){
        // taking input for counting
        int x = 1;
        // loop for counting the number of times a character appears
        for(int j=i+1; j<length; j++){ // starting from the second character cuz first one will compare with second one
            // condition to check if the character is same
            if(input[i] == input[j]){
                // incrementing the count
                x++;
                i++;
            }
            // Printing the character and its count
        }
        output += to_string(x) + input[i];
    }
    return output;
}

int main(){
    // test case
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        // taking input for test case
        string input; cin>>input;
        cout<<fanction(input) << endl;
    }
}
