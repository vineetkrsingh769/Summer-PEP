
// A company is transmitting its data to another server. To secure the data against malicious activity, they plan to reverse the data before 
// transmitting it. They want to know the number of data characters that do not change position even after the data stream is reversed. 
// The network administrator has been tasked with ensuring the smooth transmission of the data. Write an algorithm for the network administrator to 
// help him find the number of data characters that do not change position even after the data stream is reversed.

// Note 
// The input string data stream is case-sensitive and made up of English letters only. Uppercase characters and lowercase characters are counted 
// as different.

// Example 

// Input
// alphxxdida

// Output
// 4

// Explanation
// The reversed data stream is "adidxxhpla". 
// The characters that do not change position after the data stream is reversed are the characters 'a' at the start and end position and the 
// characters 'x' in the middle positions.

// Input format
// The input consists of a string dataStream, representing the data to be transmitted through the network (N).

// Output format
// Print an integer representing the number of data characters that do not change position even after the data stream is reversed. If no such 
// character is found or the input string is empty then print 0


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string n;
    cin>>n;

    string r=n;
    reverse(r.begin(),r.end());
    
    cout<<r<<endl;    //---> to check the reversed string

    // Count the number of characters that remain in the same position after reversing by comparing the original string with the reversed string
    int c=0;
    for (int i=0;i<n.length();i++){
        if(n[i]==r[i]){
            c++;
        }
    } 
    cout<<c<<endl;
    return 0;
}