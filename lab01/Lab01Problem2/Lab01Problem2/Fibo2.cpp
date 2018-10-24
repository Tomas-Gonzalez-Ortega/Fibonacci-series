/**
 * Name: Tomas Gonzalez ID: 100266942.
 * Assignment #1 lab01 Problem 2
 * Description: a functions based program with the following capabilities :
 * 1. Generating the Fibonacci number Fn (only one number).
 * 2. Generating F0 to Fn of the Fibonacci sequence.
 * 3. Generating Fm to Fn of the Fibonacci sequence, where m ≤ n
 * Copyright © 2017-09-14 All rights reserved.
 */

#include <iostream>
using namespace std;
void announce();
void instruction();
int getTerms();
int getMeFm();
void option1(int);
void option2(int);
void option3(int, int);
int option, terms, Fm, F0 = 0, F1 = 1, followingTerm = 0;

// Greets the user
void announce() {
    cout << "Welcome to Fibonacci sequence maker - CPSC1160 Lab 1" << endl;
}

// Provides instructions
void instruction() {
    cout << "Please choose one of the following options, type 1, 2 or 3: " << endl;
    cout << "1. Generating the Fibonacci number Fn (only one number)" << endl;
    cout << "2. Generating F0 to Fn of the Fibonacci sequence" << endl;
    cout << "3. Generating Fm to Fn of the Fibonacci sequence, where m ≤ n" << endl;
}

// Gets option value after checking if option has a valid input value
void check() {
    do {
        cout << "Please choose one of the following options, type 1, 2 or 3: " << endl;
        cin >> option;
    }
    while ((option != 1) && (option != 2) && (option != 3));
}

// Retreives the number of terms of the Fibonacci sequence
int getTerms() {
    cout << "Please choose number of terms this Fibonacci serie will reach: ";
    cin >> terms;
    return terms;
}

// Retreives the number of the terms in which this Fibonacci sequence will focus
int getMeFm() {
    cout << "Please choose the term number in which this Fibonacci sequence will start: ";
    cin >> Fm;
    return Fm;
}

// Generates the Fibonacci number Fn
void option1(int terms) {
    for (int i = 2; i <= terms; ++i) {
        followingTerm = F0 + F1;
        F0 = F1;
        F1 = followingTerm;
    }
    cout << followingTerm << endl;
}

// Generates F0 to Fn of the Fibonacci sequence
void option2(int terms) {
    cout << F0 << " " << F1 << " ";
    for (int i = 2; i <= terms; ++i) {
        followingTerm = F0 + F1;
        F0 = F1;
        F1 = followingTerm;
        cout << followingTerm << " ";
    }
    cout << endl;
}

// Generates Fm to Fn of the Fibonacci sequence, where m ≤ n
void option3(int terms, int Fm) {
    for (int i = 2; i <= terms; ++i) {
        followingTerm = F0 + F1;
        F0 = F1;
        F1 = followingTerm;
        if (F1 >= Fm - F0) {
            cout << followingTerm << " ";
        }
    }
    cout << endl;
}

int main() {
    announce();
    instruction();
    check();
    // Option 1 generates the Fibonacci number Fn
    if (option == 1) {
        getTerms();
        option1(terms);
    }
    // Option 2 generates F0 to Fn of the Fibonacci sequence
    else if (option == 2) {
        getTerms();
        option2(terms);
    }
    // Option 3 generates Fm to Fn of the Fibonacci sequence, where m ≤ n
    else if (option == 3) {
        getMeFm();
        getTerms();
        while (Fm > terms) {
            cout <<  "Invalid inputs remember the starting point has to be smaller or equal than the end point ";
            getMeFm();
            getTerms();
        }
        if (Fm == 0) {
            cout << F0 << " " << F1 << " ";
        }
        else if (Fm == 1) {
            cout << F1 << " ";
        }
        option3(terms, Fm);
    }
    return 0;
}
