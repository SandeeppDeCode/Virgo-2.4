/*
Pascal Triangle - 
1. Given a row and column find the elment at that place
2. Print any Nth row of the pascal Triangle
3. Given N print the entire Triangle  
*/

//1. Given row and column find the elemnet at that place;
/*
    using nCr = r-1Cc-1;
    Eg = 10C3 = (10 * 9 * 8) / (1 * 2 * 3)

Takigng advatnge of symmntry
C(10,7)=C(10,10−7)=C(10,3)

*/





#include <iostream>
using namespace std;

/*
Pascal Triangle - 
1. Given a row and column, find the element at that place.
2. Print any N-th row of the Pascal Triangle.
3. Given N, print the entire Triangle.
*/

// Function to calculate nCr using an optimized approach

//row = N and col = r;
long long nCr(int r, int c) {
    if (c > r) return 0; // Invalid case
    if (c == 0 || c == r) return 1; // Base cases

    // Since C(n, k) = C(n, n-k)
    if (c > r - c) {
        c = r - c; // Take advantage of symmetry
    }

    long long result = 1;
    for (int i = 0; i < c; i++) {
        result *= (r - i);
        result /= (i + 1);
    }
    return result;
}

// Function to get the element at position (r, c) in Pascal's Triangle
long long pascalTriangleElement(int r, int c) {
    return nCr(r, c);
}

// Function to print the N-th row of Pascal's Triangle
void printNthRow(int n) {
    for (int i = 0; i <= n; i++) {
        cout << nCr(n, i) << " ";
    }
    cout << endl;
}

// Function to print Pascal's Triangle up to the N-th row
void printPascalTriangle(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << nCr(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    
    cout << "Choose an option:\n";
    cout << "1. Find element at position (r, c)\n";
    cout << "2. Print N-th row of Pascal's Triangle\n";
    cout << "3. Print entire Pascal's Triangle up to N-th row\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            int r, c;
            cout << "Enter row number (r): ";
            cin >> r;
            cout << "Enter column number (c): ";
            cin >> c;

            long long element = pascalTriangleElement(r, c);
            
            if (element != 0) {
                cout << "Element at position (" << r << ", " << c << ") in Pascal's Triangle is: " << element << endl;
            } else {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        case 2: {
            int n;
            cout << "Enter row number (n): ";
            cin >> n;
            cout << "The " << n << "-th row of Pascal's Triangle is: ";
            printNthRow(n);
            break;
        }
        case 3: {
            int n;
            cout << "Enter number of rows (N): ";
            cin >> n;
            cout << "Pascal's Triangle up to " << n << "-th row:\n";
            printPascalTriangle(n);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
