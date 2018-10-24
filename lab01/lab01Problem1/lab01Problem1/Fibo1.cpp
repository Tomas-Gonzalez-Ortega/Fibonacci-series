/**
* Name: Tomas Gonzalez ID: 100266942.
* Assignment #1 lab01 Problem 1
* Description: a program with the following capabilities:
* 1. Generating the Fibonacci number Fn (only one number).
* 2. Generating F0 to Fn of the Fibonacci sequence.
* 3. Generating Fm to Fn of the Fibonacci sequence, where m ≤ n
* Copyright © 2017-09-14 All rights reserved.
*/

#include <iostream>
using namespace std;

int main() {
    int option, Fm, F0 = 0, F1 = 1, followingTerm = 0;
    cout << "Please choose one of the following options, type 1, 2 or 3: " << endl;
    cout << "1. Generating the Fibonacci number Fn (only one number)" << endl;
    cout << "2. Generating F0 to Fn of the Fibonacci sequence" << endl;
    cout << "3. Generating Fm to Fn of the Fibonacci sequence, where m ≤ n" << endl;
    do {
        cout << "Please choose one of the following options, type 1, 2 or 3: " << endl;
        cin >> option;
    }
    while ((option != 1) && (option != 2) && (option != 3));
    //Option 1 generates the Fibonacci number Fn
    if (option == 1) {
        int terms;
        cout << "Please choose number of terms this Fibonacci serie will reach: ";
        cin >> terms;
        for (int i = 2; i <= terms; ++i) {
            followingTerm = F0 + F1;
            F0 = F1;
            F1 = followingTerm;
        }
        cout << followingTerm << endl;
    }
    //Option 2 generates F0 to Fn of the Fibonacci sequence
    else if (option == 2) {
        int terms;
        cout << "Please choose number of terms this Fibonacci serie will reach: ";
        cin >> terms;
        cout << F0 << " " << F1 << " ";
        for (int i = 2; i <= terms; ++i) {
            followingTerm = F0 + F1;
            F0 = F1;
            F1 = followingTerm;
            cout << followingTerm << " ";
        }
        cout << endl;
    }
    //Option 3 generates Fm to Fn of the Fibonacci sequence, where m ≤ n
    else if (option == 3) {
        int terms;
        cout << "Enter the value from where this serie will start: ";
        cin >> Fm;
        cout << "Please choose number of terms this Fibonacci serie will reach: ";
        cin >> terms;
        while (Fm > terms) {
            cout << "Enter a valid value from where this serie will start: ";
            cin >> Fm;
            cout << "Please choose a valid number of terms this Fibonacci serie will reach: ";
            cin >> terms;
        }
        if (Fm == 0) {
            cout << F0 << " " << F1 << " ";
        }
        else if (Fm == 1) {
            cout << F1 << " ";
        }
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
    return 0;
}

/*
 Please ignore this, I was writing this as part of the notes I took over the lecture
 Where?
 Pass by value is used only for small amount of inputs. To making sure the data won't be changed, but less efficient since we need to copy from 1 stack frame to another stack frame or activation record
 Pass by reference outputs and large amount of inputs/outputs. Always more efficient than by value. We can use the key word const to make it final so the code is not changed by mistake

 FUNCTION PROTOTYPE
 Name (parameters) and the type of the input and the output. Doesn't have any implementation.
 */
