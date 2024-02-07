#include <iostream>
#include <conio.h> // For _getch() and kbhit()

using namespace std;

// Structure to represent each car
struct Car {
    int position;
    int points;
    int wins;
};

// Nested structure for the racing track
struct RacingTrack {
    int trackLength;
    Car car1;
    Car car2;
};

// Function to display the racing track and cars
void displayTrack(const RacingTrack& track1, const RacingTrack track2) {
    // Display the racing track layout
    cout << "|Racing Track:" << endl;
    cout << "|______________________________|" << endl;
    cout << "| c1                 c2        |" << endl;
    cout << "+_____________________________+|" << endl;
    cout << "| Controls:                    |" << endl;
    cout << "| - Car-1: 'a' (left), 'd' (right)|" << endl;
    cout << "| - Car-2: 'j' (left), 'l' (right)|" << endl;
    cout << "| - Quit Press (q)              |" << endl;
    cout << endl;

    // Display Car 1 position on the track
    cout << "|";
    for (int i = 0; i < track1.trackLength; ++i) {
        if (i == track1.car1.position) {
            cout << '1'; // Display Car 1
        } else {
            cout << "\033[1;31m - \033[0m"; // Empty track with color
        }
    }
    cout << "|" << endl;

    // Display Car 2 position on the track
    cout << "|";
    for (int i = 0; i < track2.trackLength; ++i) {
        if (i == track2.car2.position) {
            cout << '2'; // Display Car 2
        } else {
            cout << "\033[1;34m - \033[0m"; // Empty track with color
        }
    }
    cout << "|" << endl;

    // Display positions, points, and wins for both cars
    cout << "Car 1 - Position: " << track1.car1.position << ", Points: " << track1.car1.points << endl;
    cout << "Car 2 - Position: " << track2.car2.position << ", Points: " << track2.car2.points << endl;
    cout << "Car 1 - Wins: " << track1.car1.wins << "  " << " Car 2 - Wins: " << track2.car2.wins << endl;
}

// Function to update the game state based on user input
void updateGameState(RacingTrack& track1, RacingTrack& track2, char key) {
    // Update Car 1 position
    if (key == 'a' && track1.car1.position > 0) {
        track1.car1.position--;
    } else if (key == 'd' && track1.car1.position < track1.trackLength - 1) {
        track1.car1.position++;
        track1.car1.points++;
    }

    // Update Car 2 position
    if (key == 'j' && track2.car2.position > 0) {
        track2.car2.position--;
    } else if (key == 'l' && track2.car2.position < track2.trackLength - 1) {
        track2.car2.position++;
        track2.car2.points++;
    }
}

int main() {
    RacingTrack track1, track2;
    track1.car1.wins = 0;
    track2.car2.wins = 0;

    // Initialize the racing track
    restart:
    track1.trackLength = 30;
    track2.trackLength = 30;
    track1.car1.position = 0;
    track1.car1.points = 0;
    track2.car2.position = 0;
    track2.car2.points = 0;

    char ch;
    char key;

    // Main game loop
    while (true) {
        // Display the current state of the game.
        displayTrack(track1, track2);

        // Get the keyboard input.
        key = getch();

        // Update game state based on user input
        if (key == 'q') {
            cout << "Exiting the game." << endl;
            break;
        }

        updateGameState(track1, track2, key);
        system("clear"); // Clear the console screen (Linux specific)

        // Check if either car reached the finish line
        if (track1.car1.position == 29) {
            system("clear");
            cout << "Car 1 wins ";
            track1.car1.wins++;
            cout << "If you want to play again press 'y' :";
            cin >> ch;
            if (ch == 'y') {
                goto restart;
            }
        }
        if (track2.car2.position == 29) {
            system("clear");
            cout << "Car 2 wins ";
            track2.car2.wins++;
            cout << "If you want to play again press 'y' :";
            cin >> ch;
            if (ch == 'y') {
                goto restart;
            }
        }
    }

    return 0;
}
