// File: A1_T1_SectionNum_20230421.cpp
// Purpose: .........
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
using namespace std;
//____________________
// Going into the main function containing the main program
int main() {
    int programChoice;
    int problem;
    string message, newMessage;
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
                } else if (problem == 6) {
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