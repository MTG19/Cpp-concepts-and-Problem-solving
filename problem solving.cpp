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

    // Return the vector of split strings
    return result;
}

// problem 6
// a) Recursive function to print binary representation of a number
// Class for binary number operations
class BinaryPrinter {
public:
    static void binaryPrint(int n) {
        // Base case: if n is greater than 1, recursively call binaryPrint with n/2
        if (n > 1) {
            binaryPrint(n / 2);
        }
        // Print the least significant bit (n % 2)
        // This builds the binary representation from right to left
        cout << n % 2;
    }
};
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

// problem 9




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
                    string message, delimiter;
                    cout << "Enter your message:" << endl;
                    cin.ignore(); // Clear the newline left in the buffer
                    getline(cin, message);

                    cout << "Enter your delimiter:" << endl;
                    getline(cin, delimiter);

                    // Split the message into words
                    vector<string> words = split(message, delimiter);

                    // Print the split words
                    cout << "The split words are:" << endl;
                    for (const auto& word : words) {
                        cout << word << endl;
                    }


                } else if (problem == 6) {
                    char ab;
                    cout << "What do you want to do?\n a) Print the value of a number as a BINARY number. \n b) Print a sequence of binary numbers.\n Please choose (a or b)" << endl;
                    while (true) {
                        cin >> ab;
                        if (ab == 'a') {
                            int n;
                            cout << "Enter the number:" << endl;
                            cin >> n;
                            // Print the binary representation of the number
                            cout<< n <<" as a BINARY number is : ";
                            BinaryPrinter::binaryPrint(n);
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
                            BinarySequencePrinter::numbers(prefix, k);
                            break;

                        }else {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Please enter a valid choice (a or b): ";
                        }
                    }




                } else if (problem == 9) {




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

