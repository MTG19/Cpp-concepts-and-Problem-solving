// File: A1_T1_SectionNum_20230421.cpp
// Purpose: This program works to review the basics of C++ by solving 4 problems .
// Author: Menna Talla Gamal Mahmoud
// Section: .....................
// ID: 20230421
// TA: ...................
// Date: 8 Oct 2024

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <sstream>
#include <vector>


using namespace std;


// problem 3
// Function to split a string into a vector of strings based on a delimiter
vector<string> split(string target, string delimiter) {
    vector<string> result;  // Vector to store the split strings
    if (delimiter.empty()) {
        // If delimiter is empty, return the original message as a single element
        result.push_back(target);

    }else {
        size_t pos = 0;  // Position of the delimiter in the target string
        string mes;  // Temporary string to store each split part

        // Loop through the target string, finding and processing each delimiter
        while ((pos = target.find(delimiter)) != string::npos) {
            // Extract the substring from the start to the delimiter
            mes = target.substr(0, pos);

            // If the extracted substring is not empty, add it to the result vector
            if (!mes.empty()) {
                result.push_back(mes);
            }

            // Erase the processed part (including the delimiter) from the target string
            target.erase(0, pos + delimiter.length());
        }

        // Add any remaining part of the target string (after the last delimiter)
        if (!target.empty()) {
            result.push_back(target);
        }
    }// Return the vector of split strings
    return result;

}
//________________________________________________________________
// problem 6
// a) Recursive function to print binary representation of a number
class BinaryPrinter {
public:
    static bool binaryPrint(long long n) {
        if (n < 0) {
            return false; // Return false for negative numbers
        }
        // Base case: if n is greater than 1, recursively call binaryPrint with n/2
        if (n > 1) {
            binaryPrint(n / 2);
        }
        // Print the least significant bit (n % 2)
        cout << n % 2;
        return true; // Return true for successful printing
    }
};
//________________________________________________________________
// b) Recursive function to print all binary sequences with a given prefix and k additional digits
class BinarySequencePrinter {
public:
    static void numbers(string prefix, int k) {
        // Base case: if k is 0, print the prefix and return
        if (k == 0) {
            cout << prefix << endl;
            return;
        }

        // Recursive case: add '0' and '1' to the prefix and recurse with k-1
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
};
// Function to check if the input string is a binary number
bool isBinary(const string& str) {
    for (char ch : str) {
        // Check if each character is either '0' or '1'
        if (ch != '0' && ch != '1') {
            return false; // Return false if any character is not binary
        }
    }
    return true; // All characters are binary
}
// Function to remove leading zeros from the binary string
string removeLeadingZeros(const string& str) {
    // Find the first character that is not '0'
    size_t firstNonZero = str.find_first_not_of('0');
    // If all characters are '0', return "0"
    if (firstNonZero == string::npos) {
        return "0";
    }
    // Return the substring starting from the first non-zero character
    return str.substr(firstNonZero);
}
//________________________________________________________________

// problem 9
// Recursive function to manage the teddy bear picnic game
bool teddyBearPicnic(int bears) {
    // if we have exactly 42 bears, we have reached the goal
    if (bears == 42) {
        cout << "You have reached the goal (42 teddyBears)!\n";
        return true;
    }
    // If we have fewer than 42 bears, we can't proceed to the goal
    if (bears < 42 || (bears % 5 != 0 && bears % 3 != 0 && bears % 2 != 0)) {
        return false;
    }
    // Print the current number of bears
    cout << "Now you have " << bears << " bears.\n";

    // If n is divisible by 5, give back 42 bears
    if (bears % 5 == 0) {
        cout << "Returning 42 bears (divisible by 5)\n";
        if (teddyBearPicnic(bears - 42)) {
            return true;
        }
    }
    // If n is divisible by 3 or 4, give back the product of the last two digits
    if (bears % 3 == 0 || bears % 4 == 0) {
        int lastDigit = bears % 10;
        int secondLastDigit = (bears / 10) % 10;
        int bears_to_return = lastDigit * secondLastDigit;
        if (bears_to_return==0) { //in case if bears_to_return is zero the program will go endless
            if (bears % 2 == 0) { //if divisible by 4 dont work then work with even rule
                cout << "Returning " << bears / 2 << " bears (even number)\n";
                if (teddyBearPicnic(bears - bears / 2)) {
                    return true;
                }
            }
        }else{
            cout << "Returning " << bears_to_return << " bears (divisible by 3 or 4)\n";
            if (teddyBearPicnic(bears - bears_to_return)) {
                return true;
            }
        }
    }
    // If n is even, give back n / 2 bears
    if (bears % 2 == 0) {
        cout << "Returning " << bears / 2 << " bears (even number)\n";
        if (teddyBearPicnic(bears - bears / 2)) {
            return true;
        }
    }
    return false; // Indicate failure to reach the goal
}




//____________________
// Going into the main function containing the main program
int main() {
    int programChoice;
    int problem;

    // Welcoming the user into the program
    cout << "\n___Welcome User to the Problem Solving Program___\n";
    // asking the user what he wants to do
    cout << "\nWhat would you like to do ?\n1- Solve a problem\n2- Exit\n";
    while (true) {

        cin>>programChoice;
        // Handle the user's choice
        // if the user chooses 1, then he wants to solve a problem
        if (programChoice == 1) {
            // Asking the user to choose which problem he wants to solve
            cout << "Enter the number of the problem you want to solve (3, 6, 9 or 12):" << endl;
            while (true){

                cin>>problem;

                if (problem == 3) {
                    if (problem == 3) {
                        string message, delimiter;
                        cout << "Enter your message: " << endl;
                        cin.ignore(); // Clear the newline left in the buffer
                        getline(cin, message);

                        cout << "Enter your delimiter: " << endl;
                        getline(cin, delimiter);

                        // Split the message into words
                        vector<string> words = split(message, delimiter);

                        // Print the split words
                        cout << "The split words are:" << endl;
                        for (const auto& word : words) {
                            cout << "'" << word << "' ";
                        }
                        cout << endl;
                    }
                } else if (problem == 6) {
                    char ab;
                    cout << "What do you want to do?\n a) Print the value of a number as a BINARY number. \n b) Print a sequence of binary numbers.\n Please choose (a or b)" << endl;
                    while (true) {
                        cin >> ab;
                        if (ab == 'a') {
                            long long n;
                            cout << "Enter the number:" << endl;
                            cin >> n;
                            // Print the binary representation of the number
                            cout << n << " as a BINARY number is: ";
                            if (!BinaryPrinter::binaryPrint(n)) {
                                cout << "FAIL (Cannot print binary representation of negative numbers)";
                            }
                            cout << "\n";
                            break;
                        }else if (ab == 'b') {
                            string prefix;
                            int k;
                            cout << "Enter the Binary number : ";
                            cin >> prefix;
                            cout << "Enter the number of additional digits : ";
                            cin >> k;
                            cout << "The binary sequences are:" << endl;
                            if (!isBinary(prefix)) {
                                cout << "FAIL (Invalid binary number)\n";
                                break;
                            }else {
                                BinarySequencePrinter::numbers(removeLeadingZeros(prefix), k);
                                break;
                            }
                        }else {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Please enter a valid choice (a or b): ";
                        }
                    }

                } else if (problem == 9) {
                    int bears;
                    cout << "Enter the number of teddy bears: ";
                    cin >> bears;
                    if (!teddyBearPicnic(bears)) {
                        cout << "Can not reach the goal(42) with " << bears << " bears.\n";
                    }




                }else if (problem == 12) {



                } else if (cin.fail() || (problem != 3 || problem != 6 || problem != 9 || problem != 12 )) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please select one of the available problems (3, 6, 9 or 12) !\n";
                    continue;
                }
                // asking the user what he wants to do next
                cout << "\nWhat would you like to do next?\n1- Solve another problem\n2- Exit\n";
                break;

            }
        }

        // if the user chooses 2 , then he wants to exit from the program
        else if (programChoice == 2) {
            cout << "\nThank you for using the program";
            break;
        }
            // if the user inputs an invalid input, he will be asked to re input a valid choice
        else if (cin.fail() || (problem < 1 || problem >2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid choice (1 or 2).\n";
        }
    }
    return 0;
}

