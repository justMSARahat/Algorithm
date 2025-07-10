#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; //taking t variable as a test case
    cin>>t; //taking user input of t
    //loop to run for each test case
     while(t>0)
     {
         string s; //variable to store strings
         cin>>s; //user input of the string to read
         string totalnumber = ""; //variable to store final compressed result
          int count = 1; //count is 1 to start from the first character

          for(int i =1 ; i<s.length(); i++) //this loop to go through each string
          {
              if(s[i] == s[i-1]) //if current string is same as the previous string
              {
                  count++; //increase the number of count

              }
              else
              {
                  totalnumber += to_string(count); //to convert count into string
                  totalnumber += s[i-1];  // to add the the character itself
                  count = 1; // for reset for new character
              }

          }
          totalnumber += to_string(count); //to add the count of the last characters to the result
          totalnumber += s[s.length() - 1]; // to add the character itself
          cout<<totalnumber<<endl; //for the compressed output
t—;
     }
     return 0;
}