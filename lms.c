/**
 * C program that illustrates how a library system works
 * Allows users to borrow and return books
 * Upon success, execute with status 0, otherwise -1 with error message
 */

#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard library
#include <string.h> // String handling
#include <stdbool.h> // Boolean type

// Data Structure for books
struct Book {
	title char[100];
	author char[50];
	book_ISBN int[20];
	availability_status bool;
}

// Structure for users
struct user {
    int userID;            // User ID
    char name[50];         // Name of the user
    char borrowedISBN[20]; // ISBN of the borrowed book
};

// Function prototypes
void addBook();
void displayBook();
void borrowBook();
void returnBook();
void listBookStatus();
void addUser();

int bookCount = 0;        // Initialize book count to 0
int userCount = 0;        // Initialize user count to 0

// Function to add a new user
void addUser() {
    printf("Enter user ID: \n");
    scanf("%d", &users[userCount].userID);
    printf("Enter your name: \n");
    scanf("%s", users[userCount].name);
    strcpy(users[userCount].borrowedISBN, ""); // Initialize borrowed books to empty
    userCount++;
}

// Function to add a new book by unique book isbn
void addBook() {
    printf("Enter book title: \n");
    scanf("%s", lib[bookCount].book_title);
    printf("Enter name of book author: \n");
    scanf("%s", lib[bookCount].book_author);
    printf("Enter book ISBN: \n");
    scanf("%s", lib[bookCount].ISBN);

    lib[bookCount].available = true;
    bookCount++;
}

// Function to display all books sorted by the unique book isbn
void displayBook() {
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", lib[i].book_title);
        printf("Author: %s\n", lib[i].book_author);
        printf("ISBN: %s\n", lib[i].ISBN);
        if (lib[i].available) {
            printf("Availability: Available\n");
        } else {
            printf("Availability: Not Available\n");
        }
    }
}

// Function to borrow a book
void borrowBook() {
    int userID;
    char ISBN[20];

    printf("Enter your userID: \n");
    scanf("%d", &userID);
    printf("What is the ISBN of the book you want to borrow?: \n");
    scanf("%s", ISBN);

    for (int i = 0; i < userCount; i++) {
        if (users[i].userID == userID) {
		//compare two strings
            if (strcmp(users[i].borrowedISBN, "") != 0) {
                printf("Book already borrowed, cannot borrow this book book!\n");
                return;
            }
            for (int j = 0; j < bookCount; j++) {
		    //compare two strings
                if (strcmp(lib[j].ISBN, ISBN) == 0 && lib[j].available) {
                    lib[j].available = false;
		    //copy string
                    strcpy(users[i].borrowedISBN, ISBN);
                    printf("Success: Book borrowed successfully\n");
                    return;
                }
            }
            printf("Book not found!\n");
            return;
        }
    }
    printf("User not found!\n");
}

// Function to return a borrowed book
void returnBook() {
    int userID;
    printf("Enter your userID: \n");
    scanf("%d", &userID);

    for (int i = 0; i < userCount; i++) {
        if (users[i].userID == userID) {
		//compare two strings - users and borrowedISBN
            if (strcmp(users[i].borrowedISBN, "") == 0) {
                printf("User has not borrowed any book.\n");
                return;
            }
            for (int j = 0; j < bookCount; j++) {
                if (strcmp(lib[j].ISBN, users[i].borrowedISBN) == 0) {
                    lib[j].available = true;
                    strcpy(users[i].borrowedISBN, "");
                    printf("Thanks for returning the book!\n");
                    return;
                }
            }
        }
    }
    printf("User not found!\n");
}

// Function to list book statuses
void listBookStatus() {
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", lib[i].book_title);
        if (lib[i].available) {
            printf("Availability: Available\n");
        } else {
            printf("Availability: Not Available\n");
        }
    }
}

// Main function
int main() {
    int choice;
    while (true) {
        printf("1. Add user\n");
        printf("2. Add book\n");
        printf("3. Display book after add\n");
        printf("4. Borrow book\n");
        printf("5. Return book\n");
        printf("6. List book information\n");
        printf("7. Exit\n");
        printf("Please enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                addBook();
                break;
            case 3:
                displayBook();
                break;
            case 4:
                borrowBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                listBookStatus();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
	break;
    }
    return 0;
}
