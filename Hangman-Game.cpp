#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to display the current state of the word
// Reveals correctly guessed letters and hides the rest with underscores
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.size(); i++) {
        // If the letter is guessed, display it; otherwise, display an underscore
        cout << (guessed[i] ? word[i] : '_') << " ";
    }
    cout << endl; // Add a new line for better formatting
}

int main() {
    // List of possible words for the game
    vector<string> words = {
        "apple", "banana", "carpet", "table", "window", "book", "computer", "tree", "mountain", "sun",
"ocean", "river", "bird", "plane", "rocket", "keyboard", "television", "phone", "camera", "mouse",
"city", "country", "beach", "forest", "desert", "cloud", "star", "planet", "moon", "earth",
"guitar", "drums", "piano", "violin", "flute", "harp", "soccer", "basketball", "tennis", "hockey",
"ice", "fire", "earthquake", "hurricane", "snow", "rain", "storm", "wind", "sunshine", "rainbow",
"friend", "enemy", "love", "hate", "happy", "sad", "angry", "peace", "war", "death",
"life", "morning", "night", "afternoon", "evening", "weekend", "holiday", "birthday", "party", "event",
"car", "bus", "train", "bicycle", "motorcycle", "boat", "rocket", "airplane", "submarine", "helicopter",
"house", "apartment", "condo", "building", "cabin", "villa", "mansion", "hotel", "park", "garden",
"flower", "treehouse", "fireplace", "lighthouse", "skyscraper", "bridge", "castle", "chapel", "dome", "pyramid",
"cloud", "fog", "mist", "drizzle", "thunderstorm", "hail", "blizzard", "breeze", "gust", "tornado",
"galaxy", "nebula", "universe", "asteroid", "comet", "satellite", "orbit", "eclipse", "meteor", "constellation",
"butterfly", "beetle", "spider", "ant", "bee", "grasshopper", "ladybug", "dragonfly", "firefly", "moth",
"dog", "cat", "rabbit", "hamster", "mouse", "rat", "guinea pig", "ferret", "parrot", "canary",
"zebra", "giraffe", "elephant", "lion", "tiger", "bear", "wolf", "fox", "panda", "kangaroo",
"shark", "dolphin", "whale", "octopus", "jellyfish", "seahorse", "crab", "lobster", "stingray", "starfish",
"cake", "pie", "cookie", "brownie", "muffin", "cupcake", "pancake", "waffle", "toast", "bagel",
"pizza", "burger", "sandwich", "hotdog", "taco", "burrito", "salad", "soup", "steak", "chicken",
"chess", "checkers", "puzzle", "crossword", "sudoku", "cards", "dominoes", "dice", "board game", "video game",
"pen", "pencil", "eraser", "ruler", "marker", "highlighter", "crayon", "paintbrush", "canvas", "notebook",
"clock", "watch", "calendar", "alarm", "bell", "lamp", "lantern", "candle", "flashlight", "mirror",
"shoes", "boots", "sandals", "sneakers", "heels", "socks", "scarf", "gloves", "hat", "umbrella"

    };

    // Seed the random number generator using the current time
    srand(time(0));

    // Randomly select a word from the list
    string word = words[rand() % words.size()];

    // Vector to track guessed letters (true = guessed, false = not guessed)
    vector<bool> guessed(word.size(), false);

    // Variables for gameplay
    int attempts; // Tracks remaining attempts
    string name;  // Player's name
    string response; // Start game response
    string mode; // Difficulty level

    // Game welcome message
    cout << "Welcome to Hangman!" << endl << endl;

    // Get player's name
    cout << "Enter your Name: ";
    getline(cin, name);
    cout << endl;

    // Greet the player
    cout << "Hello " << name << endl << endl;

    // Ask the player to start the game
    cout << "Press 1 to start the game! ";
    cin >> response;


    // Prompt the player to select a difficulty mode
    cout << "Choose from the following difficulty modes: " << endl;
    cout << "1. Easy (For Beginners!)" << endl;
    cout << "2. Medium (Looking for a Challenge!)" << endl;
    cout << "3. Hard (YOU AIN'T GONNA WIN!)" << endl;
    cout << "Mode: ";
    cin >> mode;

    // Set the number of attempts based on the chosen difficulty level
    if (mode == "1") {
        cout << "You have 6 attempts to get the word right!" << endl;
        attempts = 6;
    }
    else if (mode == "2") {
        cout << "You have 4 attempts to get the word right!" << endl;
        attempts = 4;
    }
    else if (mode == "3") {
        cout << "You have 3 attempts to get the word right!" << endl;
        attempts = 3;
    }
    else {
        cout << "Shifting to default and going with the Easy mode ! ";
        attempts = 6;

    }

    // Main game loop
    while (attempts > 0 && response == "1") {
        // Display the current state of the word
        cout << "Word: " << endl;
        displayWord(word, guessed);

        // Show the number of attempts left
        cout << "Attempts left: " << attempts << endl;

        // Prompt the player to guess a letter
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        // Check if the guessed letter is in the word
        bool correct = false; // Flag to track if the guess is correct
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                cout << "You got it right! " << endl;
                guessed[i] = true; // Mark the letter as guessed
                correct = true; // Update the correct flag
            }
        }

        // If the guess was incorrect, decrement the attempts
        if (!correct) {
            attempts--;
            cout << "Oh no! You guessed it wrong." << endl;
        }

        // Check if the player has guessed all the letters correctly
        bool allGuessed = true;
        for (bool b : guessed) {
            if (!b) {
                allGuessed = false; // If any letter is not guessed, update the flag
                break;
            }
        }

        // If the player has guessed the entire word, end the game
        if (allGuessed) {
            cout << endl;
            cout << "Congratulations! You guessed the word: " << word << endl;
            return 0; // Exit the program
        }
    }

    // If the player runs out of attempts, reveal the word
    cout << endl;
    cout << "You ran out of attempts! The word was: " << word << endl;
    return 0; // Exit the program
}
