/*The apparel company "FeelGood" has collected a list of the sales values of the N highest selling brands of products during the festive season. Each brand is identified by a unique ID numbered 0 - (N-1) in the list.
 * From this list the company wishes to determine the Kth largest sales value for a given day.
 * 
 * Write a C++ program by using function to help the company determine the sales value of the Kth largest selling product.
 * 
 * Input
 * The first line of input consists of two integers- numBrands and largestSale where the first integer represents the total number of brands selected by  the company (N) and the second integer represents the Kth value.
 * The next line consists of N space separated integers - salesValue[0], salesValue[1],.... salesValue[N-1]
 * representing the sales value of the N brands.
 * 
 * Output
 * Print an integer representing the Kth largest sales value in the list for the given day.
 * 
 * Constraint
 * 0 < numBrands < 10^6
 * 0 < largestSale <= numBrands
 * 0 < salesValue[i] <= 10^6
 * 0 <= i < numBrands
 * 
 * Example
 * Input
 * 5 3
 * 45 32 67 21 12
 * 
 * Output
 * 32
 * 
 * Explanation
 * The 3rd largest value in the given list is 32.
 * Hence the output is 32.*/



// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int main() {
//     int numBrands, largestSale;
//     cin >> numBrands >> largestSale;

//     priority_queue<int, vector<int>, greater<int>> minHeap;

//     for (int i = 0; i < numBrands; ++i) {
//         int sale;
//         cin >> sale;
//         minHeap.push(sale);
//         if (minHeap.size() > largestSale) {
//             minHeap.pop(); 
//         }
//     }

//     // The top of the heap is the Kth largest
//     cout << minHeap.top() << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int brand,largest;
    cin >> brand >> largest;

    vector<int> sales(brand);
    for(int i = 0; i < brand; i++){
        cin >> sales[i];
    }
    nth_element(sales.begin(), sales.begin() + largest - 1, sales.end(), greater<int>());
    cout << sales[largest - 1] << endl;
    return 0;

}