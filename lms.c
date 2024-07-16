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
