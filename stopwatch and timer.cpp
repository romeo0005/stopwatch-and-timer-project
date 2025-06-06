#include <iostream> //allow the use of input and output stream
#include <chrono> //gh-resolution clocks and timeities
#include <thread> // Enables the use of multiding and sleep functions


using namespace std; // Simplifies the code by allowing direct use of standard library objects and functions
// Function to start the stopwatch

void startStopwatch() {
     // Inform the user that the stopwatch has started and how to stop it// Record the starting time using high-resolution clock for accurate timing
    cout << "Stopwatch started. Press Enter to stop...\n";
// Record the starting time using high-resolution clock for accurate timing
    auto start = chrono::high_resolution_clock::now(); // Wait for the user to press Enter, effectively letting time pass
    cin.ignore();  // Wait for Enter key press
    auto end = chrono::high_resolution_clock::now();
  // Calculate the duration in seconds
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
     // Display the elapsed time
    cout << "Stopwatch stopped. Elapsed time: " << duration.count() << " seconds.\n";
}
// Function to start a countdown timer for a specified number of seconds
void startTimer(int seconds) {
    cout << "Timer set for " << seconds << " seconds.\n";
  // Loop to count down each second
    for (int i = seconds; i > 0; --i) {
        cout << "Time remaining: " << i << " seconds\r" << flush;
        this_thread::sleep_for(chrono::seconds(1));// Wait for 1 second
    }

    cout << "\nTime's up!\n";
}
`
int main() {
    int choice;
        // Display the menu options to the 

    do {
        cout << "\nSreen for Stopwatch and Timer:\n";
        cout << "1. Start Stopwatch\n";
        cout << "2. Start Timer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
// Handle the user's menu choice
        switch (choice) {
        case 1:
            cin.ignore();  // Clear input buffer
            startStopwatch();
            break;
        case 2: 
            int seconds;
            cout << "Enter timer duration in seconds: ";
            cin >> seconds;
            startTimer(seconds);
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);// Continue until the user chooses to exit

    return 0;
}
