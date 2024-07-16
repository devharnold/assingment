#include <stdio.h>  // Standard I/O
#include <stdlib.h> // Standard library
#include <string.h> // String handling
#include <stdbool.h> // Boolean type

// Structure for library books
struct library {
    char book_title[60];   // Name of the book
    char book_author[50];  // Name of the book author
    char ISBN[20];         // Book ISBN as a string
    bool available;        // Availability status
};

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

// Global variables
struct library lib[100000]; // Limit number of books to 100000
struct user users[10000];  // Limit number of users to 10000
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

