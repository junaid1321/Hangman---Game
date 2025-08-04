#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    int id;
    string title;
    string author;
    bool isBorrowed;

public:
    Item() {
        id = -1;
        title = "Unknown";
        author = "Unknown";
        isBorrowed = false;
    }

    Item(int i, string t, string a) {
        setID(i);
        title = t;
        author = a;
        isBorrowed = false;
    }

    void setTitle(string t) {
        title = t;
    }

    string getTitle() {
        return title;
    }

    void setID(int i) {
        if (i >= 0) {
            id = i;
        }
        else {
            cout << "Invalid ID! Must be non-negative.\n";
        }
    }

    int getID() {
        return id;
    }

    void setAuthor(string a) {
        author = a;
    }

    string getAuthor() {
        return author;
    }

    void set_isBorrowed(bool b) {
        isBorrowed = b;
    }

    bool get_isBorrowed() {
        return isBorrowed;
    }

    ~Item() {

    }
};

class Book : public Item {
protected:
    string genre;

public:
    Book() {
        id = -1;
        title = "Unknown";
        author = "Unknown";
        isBorrowed = false;
        genre = "Unknown";
    }

    Book(int i, string t, string a, string g) {
        title = t;
        setID(i);
        author = a;
        isBorrowed = false;
        genre = g;
    }

    void addBook(Book books[], int count) {
        string t, a, g;
        int i;

        cout << "Enter Book Details: " << endl;

        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, t);
        if (t.empty()) {
            do {
                cout << "Error ! Enter Input.\n";
                cout << "Enter Book Title: ";
                getline(cin, t);
            } while (t.empty());
        }

        cout << endl;

        bool duplicateFound = false;
        do {
            cout << "Enter ID: ";
            cin >> i;
            duplicateFound = false;

            for (int j = 0; j < count; j++) {
                if (books[j].getID() == i) {
                    cout << "ID already exists. Please enter a unique ID.\n";
                    duplicateFound = true;
                    break;
                }
            }
        } while (i < 0 || duplicateFound);

        cout << endl;

        cout << "Enter Book Author: ";
        cin.ignore();
        getline(cin, a);
        if (a.empty()) {
            do {
                cout << "Error ! Enter Input.\n";
                cout << "Enter Book Author: ";
                getline(cin, a);
            } while (a.empty());
        }

        cout << endl;

        cout << "Enter Genre of the Book: ";
        getline(cin, g);
        if (g.empty()) {
            do {
                cout << "Error ! Enter Input.\n";
                cout << "Enter Genre of the Book: ";
                getline(cin, g);
            } while (g.empty());
        }

        cout << endl;

        setID(i);
        title = t;
        author = a;
        genre = g;
        isBorrowed = false;
    }

    void displayBook() {
        cout << "Book Details: " << endl;
        cout << "Title: " << title << endl;
        cout << "ID: " << id << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        if (!isBorrowed) {
            cout << "Status: Available" << endl;
        }
        else {
            cout << "Status: Not Available" << endl;
        }
    }
};


class Magazine : public Item {
protected:
    string issueMonth;

public:
    string validMonths[36] = {
        "January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December",
        "Jan", "Feb", "Mar", "Apr", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
        "january", "february", "march", "april", "may", "june", "july", "august",
        "september", "october", "november", "december"
    };

    Magazine() {
        id = -1;
        title = "Unknown";
        author = "Unknown";
        isBorrowed = false;
        issueMonth = "Unknown";
    }

    Magazine(int i, string t, string a, string m) {
        title = t;
        id = i;
        author = a;
        isBorrowed = false;
        issueMonth = m;
    }

    void addMagazine(Magazine magazines[], int count) {
        string t, a, m;
        int i;

        cout << "Enter Magazine Details: " << endl;

        cout << "Enter Magazine Title: ";
        cin.ignore();
        getline(cin, t);
        if (t.empty()) {
            do {
                cout << "Error ! Enter Input.\n";
                cout << "Enter Magazine Title: ";
                getline(cin, t);
            } while (t.empty());
        }

        cout << endl;

        bool duplicateFound = false;
        do {
            cout << "Enter Magazine ID: ";
            cin >> i;
            duplicateFound = false;

            for (int j = 0; j < count; j++) {
                if (magazines[j].getID() == i) {
                    cout << "ID already exists. Please enter a unique ID.\n";
                    duplicateFound = true;
                    break;
                }
            }
        } while (i < 0 || duplicateFound);

        cout << endl;

        cout << "Enter Magazine Author: ";
        cin.ignore();
        getline(cin, a);
        if (a.empty()) {
            do {
                cout << "Error ! Enter Input.\n";
                cout << "Enter Magazine Author: ";
                getline(cin, a);
            } while (a.empty());
        }

        cout << endl;

        bool valid_month = false;
        do {
            cout << "Enter the Month the Magazine was Issued: ";
            getline(cin, m);
            if (m.empty()) {
                do {
                    cout << "Error ! Enter Input.\n";
                    cout << "Enter the Month the Magazine was Issued: ";
                    getline(cin, m);
                } while (m.empty());
            }
            for (int i = 0; i < 36; i++) {
                if (m == validMonths[i]) {
                    issueMonth = m;
                    valid_month = true;
                }
            }
        } while (!valid_month);

        cout << endl;

        title = t;
        id = i;
        author = a;
        isBorrowed = false;
    }

    void displayMagazine() {
        cout << "Magazine Detail: " << endl;
        cout << "Title: " << title << endl;
        cout << "ID: " << id << endl;
        cout << "Month Issued: " << issueMonth << endl;
        if (!isBorrowed) {
            cout << "Status: Available" << endl;
        }
        else {
            cout << "Status: Not Available" << endl;
        }
    }
};



class Review {
    int bookID;
    string reviewText;

public:
    int getbookID() {
        return bookID;
    }
    Review() {
        bookID = -1;
        reviewText = "";
    }
    void AddReview(int id) {
        bookID = id;
        cin.ignore();
        cout << "Enter a review: ";
        getline(cin, reviewText);
    }
    void DisplayReview() {
        cout << "Book ID: " << bookID << endl;
        cout << "Review: " << reviewText << endl;
    }
    void EditReview() {
        cin.ignore();
        cout << "Enter new review: ";
        getline(cin, reviewText);
    }
    bool isValidBookID(Book books[], int book_count, int id) {
        for (int i = 0; i < book_count; i++) {
            if (books[i].getID() == id) {
                return true;
            }
        }
        return false;
    }
};




class BorrowManager {
public:
    BorrowManager() {}

    void BorrowBook(Book books[], int book_count) {
        string title;
        cout << "Enter book title for borrow: ";
        cin.ignore();
        getline(cin, title);

        int foundIndex = -1;
        for (int i = 0; i < book_count; i++) {
            if (books[i].getTitle() == title) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            cout << "Book not found!" << endl;
        }
        else {
            if (books[foundIndex].get_isBorrowed()) {
                cout << "Book is already Borrowed!" << endl;
            }
            else {
                books[foundIndex].set_isBorrowed(true);
                cout << "Book Borrowed Successfully!" << endl;
            }
        }
    }

    void returnBook(Book books[], int book_count) {
        string title;
        cout << "Enter Book Title To Return: ";
        cin.ignore();
        getline(cin, title);

        int foundIndex = -1;
        for (int i = 0; i < book_count; i++) {
            if (books[i].getTitle() == title) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            cout << "Book not found!" << endl;
        }
        else {
            if (!books[foundIndex].get_isBorrowed()) {
                cout << "Book is already available" << endl;
            }
            else {
                books[foundIndex].set_isBorrowed(false);
                cout << "Book returned successfully!" << endl;
            }
        }
    }

    void borrowMagazine(Magazine magazines[], int magazine_count) {
        string title;
        cout << "Enter Magazine title for borrow: ";
        cin.ignore();
        getline(cin, title);

        int foundIndex = -1;
        for (int i = 0; i < magazine_count; i++) {
            if (magazines[i].getTitle() == title) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            cout << "Magazine not found!" << endl;
        }
        else {
            if (magazines[foundIndex].get_isBorrowed()) {
                cout << "Magazine is already Borrowed!" << endl;
            }
            else {
                magazines[foundIndex].set_isBorrowed(true);
                cout << "Magazine Borrowed Successfully!" << endl;
            }
        }
    }

    void returnMagazine(Magazine magazines[], int magazine_count) {
        string title;
        cout << "Enter Magazine Title To Return: ";
        cin.ignore();
        getline(cin, title);

        int foundIndex = -1;
        for (int i = 0; i < magazine_count; i++) {
            if (magazines[i].getTitle() == title) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex == -1) {
            cout << "Magazine not found!" << endl;
        }
        else {
            if (!magazines[foundIndex].get_isBorrowed()) {
                cout << "Magazine is already available" << endl;
            }
            else {
                magazines[foundIndex].set_isBorrowed(false);
                cout << "Magazine returned successfully!" << endl;
            }
        }
    }
};

class SearchUtility {
public:
    SearchUtility() {}

    void searchBookByTitle(Book books[], int book_count, string title) {
        cout << "Enter Book Title To Be Searched: ";
        cin.ignore();
        getline(cin, title);

        int found_index = -1;
        for (int i = 0; i < book_count; i++) {
            if (books[i].getTitle() == title) {
                found_index = i;
                break;
            }
        }
        if (found_index == -1) {
            cout << "Book not found !" << endl;
        }
        else {
            cout << "Book found !" << endl;
            books[found_index].displayBook();
        }
    }

    void searchMagazineByTitle(Magazine magazines[], int magazine_count, string title) {
        cout << "Enter Magazine Title To Be Searched: ";
        cin.ignore();
        getline(cin, title);

        int found_index = -1;
        for (int i = 0; i < magazine_count; i++) {
            if (magazines[i].getTitle() == title) {
                found_index = i;
                break;
            }
        }
        if (found_index == -1) {
            cout << "Magazine not found !" << endl;
        }
        else {
            cout << "Magazine found !" << endl;
            magazines[found_index].displayMagazine();
        }
    }
};

int main() {
    Book books[100];
    int book_count = 0;

    Magazine magazines[100];
    int magazine_count = 0;

    Review reviews[100];
    int reviewCount = 0;

    BorrowManager borrowManager;
    SearchUtility searchUtility;

    int choice;
    int start;

    cout << "\n====== Welcome to PagePal ======\n";
    cout << "Press 1 to Enter: ";
    cin >> start;

    if (start == 1) {
        do {
            cout << "\n====== PagePal Menu ======\n";
            cout << "1. Book\n";
            cout << "2. Magazine\n";
            cout << "3. Search Item by Title\n";
            cout << "4. Borrow Item\n";
            cout << "5. Return Item\n";
            cout << "6. Add Review\n";
            cout << "7. View Reviews\n";
            cout << "8. Edit Reviews\n";
            cout << "9. Delete Reviews\n";
            cout << "0. Exit\n";
            cout << "==========================\n";
            cout << "Enter Choice (0-9): ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int choice2;
                do {
                    cout << "\n====== Book Menu ======\n";
                    cout << "1. Add Book.\n";
                    cout << "2. Display Book.\n";
                    cout << "0. Exit\n";
                    cout << "==========================\n";
                    cout << "Enter Choice (0-2): ";
                    cin >> choice2;

                    switch (choice2) {
                    case 1: {
                        if (book_count < 100) {
                            books[book_count].addBook(books, book_count);
                            book_count++;
                            cout << "Book Added Successfully.\n";
                        }
                        else {
                            cout << "Books Limit Reached! Cannot add more books.\n";
                        }
                        break;
                    }

                    case 2: {
                        if (book_count == 0) {
                            cout << "No Books available to display.\n";
                        }
                        else {
                            for (int i = 0; i < book_count; i++) {
                                cout << "Book " << i + 1 << ":\n";
                                books[i].displayBook();
                                cout << endl;
                            }
                        }
                        break;
                    }

                    case 0: {
                        cout << "Exiting Book Menu........\n";
                        break;
                    }

                    default: {
                        cout << "Error! Invalid Option.\n";
                        break;
                    }
                    }
                } while (choice2 != 0);
                break;
            }
            case 2: {
                int choice3;
                do {
                    cout << "\n====== Magazine Menu ======\n";
                    cout << "1. Add Magazine.\n";
                    cout << "2. Display Magazines.\n";
                    cout << "0. Exit\n";
                    cout << "==========================\n";
                    cout << "Enter Choice (0-2): ";
                    cin >> choice3;

                    switch (choice3) {
                    case 1: {
                        if (magazine_count < 100) {
                            magazines[magazine_count].addMagazine(magazines, magazine_count);
                            magazine_count++;
                            cout << "Magazine Added Successfully.\n";
                        }
                        else {
                            cout << "Magazine Limit Reached! Cannot add more magazines.\n";
                        }
                        break;
                    }

                    case 2: {
                        if (magazine_count == 0) {
                            cout << "No Magazines available to display.\n";
                        }
                        else {
                            for (int i = 0; i < magazine_count; i++) {
                                cout << "Magazine " << i + 1 << ":\n";
                                magazines[i].displayMagazine();
                                cout << endl;
                            }
                        }
                        break;
                    }

                    case 0: {
                        cout << "Exiting Magazine Menu........\n";
                        break;
                    }

                    default: {
                        cout << "Error! Invalid Option.\n";
                        break;
                    }
                    }
                } while (choice3 != 0);
                break;
            }
            case 3: {
                string dummy;
                int opt;
                cout << "\n====== Search Menu ======\n";
                cout << "1. Search Book\n2. Search Magazine\n";
                cout << "==========================\n";
                cout << "Enter Choice: ";
                cin >> opt;
                if (opt == 1)
                    searchUtility.searchBookByTitle(books, book_count, dummy);
                else if (opt == 2)
                    searchUtility.searchMagazineByTitle(magazines, magazine_count, dummy);
                break;
            }
            case 4: {
                int opt;
                cout << "\n====== Borrow Menu ======\n";
                cout << "1. Borrow Book\n2. Borrow Magazine\n";
                cout << "==========================\n";
                cout << "Enter Choice: ";
                cin >> opt;
                if (opt == 1)
                    borrowManager.BorrowBook(books, book_count);
                else if (opt == 2)
                    borrowManager.borrowMagazine(magazines, magazine_count);
                break;
            }
            case 5: {
                int opt;
                cout << "\n====== Return Menu ======\n";
                cout << "1. Return Book\n2. Return Magazine\n";
                cout << "==========================\n";
                cout << "Enter Choice: ";
                cin >> opt;
                if (opt == 1)
                    borrowManager.returnBook(books, book_count);
                else if (opt == 2)
                    borrowManager.returnMagazine(magazines, magazine_count);
                break;
            }
            case 6: {
                if (reviewCount >= 100) {
                    cout << "Review limit reached!" << endl << endl;
                    break;
                }

                cout << "\n--- Available Books ---\n";
                for (int i = 0; i < book_count; i++) {
                    cout << "Book " << i + 1 << ":\n";
                    books[i].displayBook();
                    cout << "------------------------\n";
                }

                int id;
                bool validID = false;
                do {
                    cout << "Enter Book ID to review: ";
                    cin >> id;
                    if (reviews[reviewCount].isValidBookID(books, book_count, id)) {
                        validID = true;
                    }
                    else {
                        cout << "Invalid Book ID! Please try again." << endl;
                    }
                } while (!validID);

                reviews[reviewCount].AddReview(id);
                reviewCount++;
                cout << "Review added successfully!" << endl << endl;
                break;
            }
            case 7: {
                int id;
                bool found = false;
                cout << "Enter Book ID to view reviews: ";
                cin >> id;
                for (int i = 0; i < reviewCount; i++) {
                    if (reviews[i].getbookID() == id) {
                        reviews[i].DisplayReview();
                        found = true;
                    }
                }
                if (!found)
                    cout << "No reviews found.\n";
                break;
            }
            case 8: {
                if (reviewCount == 0) {
                    cout << "No reviews available to edit.\n";
                    break;
                }

                cout << "\n--- Available Books ---\n";
                for (int i = 0; i < book_count; i++) {
                    cout << "Book " << i + 1 << ":\n";
                    books[i].displayBook();
                    cout << "------------------------\n";
                }

                int id;
                bool found = false;
                cout << "Enter Book ID to edit review: ";
                cin >> id;

                for (int i = 0; i < reviewCount; i++) {
                    if (reviews[i].getbookID() == id) {
                        reviews[i].EditReview();
                        cout << "Review updated successfully!" << endl << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "No review found for this Book ID." << endl << endl;
                }
                break;
            }

            case 9: {
                if (reviewCount == 0) {
                    cout << "No reviews available to delete.\n";
                    break;
                }
                cout << "\n--- Available Books ---\n";
                for (int i = 0; i < book_count; i++) {
                    cout << "Book " << i + 1 << ":\n";
                    books[i].displayBook();
                    cout << "------------------------\n";
                }

                int id;
                bool validID = false;
                do {
                    cout << "Enter Book ID to delete review: ";
                    cin >> id;
                    if (reviews[0].isValidBookID(books, book_count, id)) {
                        validID = true;
                    }
                    else {
                        cout << "Invalid Book ID! Please try again." << endl;
                    }
                } while (!validID);

                bool found = false;
                for (int i = 0; i < reviewCount; i++) {
                    if (reviews[i].getbookID() == id) {
                        for (int j = i; j < reviewCount - 1; j++) {
                            reviews[j] = reviews[j + 1];
                        }
                        reviewCount--;
                        cout << "Review deleted successfully!" << endl << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "No review found for this Book ID." << endl << endl;
                }
                break;
            }
            case 0: {
                cout << "Exiting PagePal.........\n";
                return 0;
            }

            default: {
                cout << "Error! Invalid Option.\n";
                break;
            }
            }
        } while (choice != 0);
    }
    else {
        cout << "\nEnding the Program.\n";
        return 0;
    }
}