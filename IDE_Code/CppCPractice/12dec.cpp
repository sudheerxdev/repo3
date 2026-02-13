// C++ program to convert a decimal
// number to hexadecimal number
#include <iostream>
using namespace std;

// Function to convert decimal
// to hexadecimal
void decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];

    // Counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // Temporary variable to store remainder
        int temp = 0;

        // Storing remainder in temp variable.
        temp = n % 16;

        // Check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }

    // Printing hexadecimal number
    // array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << hexaDeciNum[j];
}

// Driver code
int main()
{
    int n = 2545;
    decToHexa(n);
    return 0;
}
