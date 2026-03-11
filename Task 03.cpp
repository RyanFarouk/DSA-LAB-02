#include <iostream>
using namespace std;

class Publication {
public:
    virtual void display() = 0;
};

class Book : public Publication {
private:
    string title;
    string author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() {
        cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

class Newspaper : public Publication {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }
};

class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newspaperCount = 0;

public:
    void addBook(Book b) {
        books[bookCount++] = b;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount++] = n;
    }

    void displayCollection() {
        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++)
            books[i].display();

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++)
            newspapers[i].display();
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = i + 1; j < bookCount; j++) {
                if (books[i].getPages() > books[j].getPages()) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[i].getEdition() > newspapers[j].getEdition()) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title)
                return &books[i];
        }
        return NULL;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getName() == name)
                return &newspapers[i];
        }
        return NULL;
    }
};