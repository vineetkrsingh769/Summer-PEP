/*An oil factory has N number of containers and each has a different capacity.
 * During renovation, the manager decided to make some changes with the containers. He wishes to make different pairs for the containers in such a way that in the the first pair, the container of maximum capacity is paired with the container of minimum capacity, and so on for the rest of the containers,
 * to maintain balance throughout all the pairs of containers.
 * 
 * Write an algorithm to make different pairs of containers in such a way that the first container in the pair is of maximum capacity and second container in the pair is of minimum capacity. 
 * 
 * Input
 * The first line of the input consists of an integer - numContainers, representing the number of containers (N).
 * The next line consists of N space-separated integers - cont1, cont2,....contN, representing container capacity.
 * 
 * Output
 * Print K lines consisting of two space-separated integers representing the pairs that will be formed to maintain the balance by pairing the container of maximum capacity with the container of minimum capacity and so on.
 * 
 * Constraints
 * 1 <= numContainers <= 10^3
 * 1 <= conti <= 10^3
 * 1 <= i <= numContainers
 * 
 * Note
 * If only one container is left and no pair is possible then print the capacity of that container and the second value will be '0'
 * 
 * Example
 * Example 1:
 * Input:
 * 6
 * 100 560 23 19 53 20
 * Output:
 * 560 19
 * 100 20
 * 53 23
 * Explanation: We have 6 containers with the capacity (100, 560, 23, 19, 53, 20), so we can form the following pairs of containers - (560,19),(100,20),(53,23)
 */

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int main() {
    int n;
    cin >> n; // Number of containers

    vector<int> arr(n); // Container to hold capacities

    // Read the container capacities
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the capacities in ascending order
    sort(arr.begin(), arr.end());

    // Form pairs: smallest with largest
    for (int i = 0; i < n / 2; i++) {
        cout << arr[n - i - 1] << " " << arr[i] << endl;
    }

    // If there's an odd number of containers, print the middle one with 0
    if (n % 2 != 0) {
        cout << arr[n / 2] << " 0" << endl;
    }

    return 0;
}
