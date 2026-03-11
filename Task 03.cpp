#include <iostream>
using namespace std;

class Publication {
public:
    virtual void display() = 0;
};

class Book : public Publication {
    string title, author;
    int pages;

public:
    Book() {}
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() { return title; }
    int getPages() { return pages; }

    void display() {
        cout << "Book: " << title << " | Author: " << author << " | Pages: " << pages << endl;
    }
};

class Newspaper : public Publication {
    string name, date, edition;

public:
    Newspaper() {}
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() { return name; }
    string getEdition() { return edition; }

    void display() {
        cout << "Newspaper: " << name << " | Date: " << date << " | Edition: " << edition << endl;
    }
};

template <class T>
void sortItems(T arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i].getPages() > arr[j].getPages()) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

template <class T>
T* searchItem(T arr[], int n, string key) {
    for (int i = 0; i < n; i++)
        if (arr[i].getTitle() == key)
            return &arr[i];
    return NULL;
}

class Library {
    Book books[10];
    Newspaper newspapers[10];
    int bCount = 0, nCount = 0;

public:
    void addBook(Book b) { books[bCount++] = b; }
    void addNewspaper(Newspaper n) { newspapers[nCount++] = n; }

    void displayCollection() {
        cout << "\nBooks:\n";
        for (int i = 0;i < bCount;i++) books[i].display();

        cout << "\nNewspapers:\n";
        for (int i = 0;i < nCount;i++) newspapers[i].display();
    }

    void sortBooksByPages() {
        sortItems(books, bCount);
    }

    void sortNewspapersByEdition() {
        for (int i = 0;i < nCount - 1;i++)
            for (int j = i + 1;j < nCount;j++)
                if (newspapers[i].getEdition() > newspapers[j].getEdition()) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
    }

    Book* searchBookByTitle(string title) {
        return searchItem(books, bCount, title);
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0;i < nCount;i++)
            if (newspapers[i].getName() == name)
                return &newspapers[i];
        return NULL;
    }
};
int main() {
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    // Create newspaper objects
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
    // Create a library object
    Library library;
    // Add books and newspapers to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);
    // Display the entire collection
    cout << "Before Sorting:\n";
    library.displayCollection();
    // Sort books by pages and newspapers by edition
    library.sortBooksByPages();
    library.sortNewspapersByEdition();
    cout << "\nAfter Sorting:\n";
    library.displayCollection();
    // Search for a book by title
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }
    // Search for a newspaper by name
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }
    return 0;
}
