 /* The cosmetic company "BeautifyMe" wishes to know the alphabetic product code from the barcode. The barcode of the product is a numeric value and the alphabetic product is a string value tagged 'a-j'.
 * The alphabetic range 'a-j' represents the numeric range '0-9'. To produce the alphabetic product code, each digit in the numeric barcode is replaced by the corresponding matching letters.
 * Write an algorithm to display the alphabetic product code from the numeric barcode.
 * 
 * Input
 * The input consists of an integer - barcode, that represents the barcode of the product.
 * 
 * Output
 * Print a string representing the alphabetic product code.
 * 
 * Constraints
 * 0 <= barcode <= 10^10
 * 
 * Example
 * Input
 * 12403
 * 
 * Output
 * bcead
 * 
 * Explanation
 * The corresponding letters for the numeric barcode 12403 is 'bcead'*/

 #include <iostream>
#include <string>
using namespace std;

int main() {
    long long barcode;
    cin >> barcode;

    char alphabets[] = {'a','b','c','d','e','f','g','h','i','j'};
    string result = "";

    if (barcode == 0) {
        result = "a"; // Special case for input 0
    }

    while (barcode > 0) {
        int digit = barcode % 10;
        result = alphabets[digit] + result;
        barcode = barcode / 10;
    }

    cout << result << endl;
    return 0;
}
