/*In a gaming hub, N number of players were playing the same type of game. All players got stuck at the pillar level in the game, each with a different score. 
The owner of the gaming hub announced that players can pass that level if they can break two pillar. 
The trick is to break the pillar at a time that if the player's current score is multiplied up to a certain point the should be equal to the pillars health. 
The same trick is to be used for the other pillar. 
If there is no number that can be multiplied with the player's score to make the score equal to the pillar health, than that player loses.
 A player can only break one pillar at a time and if the player is not able to break both the pillars then they will not be able to clear the level. 
 Write a C++ program to find the total number of players who will clear that level game. 
 Sample Input 1:
  5 
  15 5 3 7 9 
  135 90 
  Sample Output 1:
  4 
 Sample Input 2:
 8 11
 15 19 27 29 34 19 32 
 23 25 
 Sample Output 2: 
 0  */




 
#include <iostream>
using namespace std;

int main() {
    int n; // Number of players
    cin >> n;

    int scores[n]; // Array to store scores of all players

    // Reading scores of all players
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int pillar1, pillar2;
    cin >> pillar1 >> pillar2; // Reading health of both pillars

    int count = 0; // Counter to count how many players can break both pillars

    // Loop through each player's score
    for (int i = 0; i < n; i++) {
        // Check if the player's score is a factor of both pillar1 and pillar2
        // This means some multiplier of score equals pillar health
        if (pillar1 % scores[i] == 0 && pillar2 % scores[i] == 0) {
            count++; // Player can break both pillars, increase the count
        }
    }

    // Output the number of players who can clear the level
    cout << count << endl;

    return 0;
}

