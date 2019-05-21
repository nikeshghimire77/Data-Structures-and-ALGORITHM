#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include "ArgumentManager.h"

using namespace std;

bool isDouble(const string &s) {
    int dot = 0;
    int operators = 0;
    int i = 0;
    for (; i < s.length(); i++) {
        if (s[i] == '.')
            dot++;
        else if (s[i] == '+' || s[i] == '-') {
            operators++;
        } else if (!isdigit(s[i]))
            return false;
    }
    return (dot <= 1 && operators <= 1);
}

int main(int argc, char *argv[]) {
    // Incorrect Usage
    if (argc < 2) {
        cout << "Usage: densemultiple \"A=<file>;B=<file>;C=<file>\"" << endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    
    string input1 = am.get("A");
    string input2 = am.get("B");
    string output = am.get("C");
    
    // Open File Streams
    ifstream file1(input1.c_str()), file2(input2.c_str());
    ofstream file3(output.c_str());
    
    if (!file1 || !file2 || !file3) {
        file3 << "error";
        return -1;
    }
    
    double arr1[20][20], arr2[20][20];
    
    int r1, c1, r2, c2;
    string row;
    int colcnt1 = 0, rowcnt1 = 0;
    // Read from file 1
    while (getline(file1, row)) {
        
        if (row[row.length() - 1] == '\r' || row[row.length() - 1] == '\n') {
            row = row.substr(0, row.length() - 1);
        }
        if (row.length() == 0) {
            continue;
        }
        istringstream iss(row);
        string value;
        int tcolcnt = 0;
        while (getline(iss, value, ' ')) {
            if (value.length() == 0) {
                continue;
            }
            if (!isDouble(value)) {
                file3 << "error";
                return -1;
            }
            try {
                arr1[rowcnt1][tcolcnt] = strtod(value.c_str(), NULL);
                tcolcnt++;
            }
            catch (int e) {
                file3 << "error";
                return -1;
            }
        }
        
        if (tcolcnt == 0) {
            continue;
        }
        
        if (rowcnt1 == 0)
            colcnt1 = tcolcnt;
        else if (tcolcnt != colcnt1) {
            file3 << "error";
            return -1;
        }
        rowcnt1++;
    }
    
    int colcnt2 = 0, rowcnt2 = 0;
    // Read from file 2
    while (getline(file2, row)) {
        if (row[row.length() - 1] == '\r' || row[row.length() - 1] == '\n') {
            row = row.substr(0, row.length() - 1);
        }
        if (row.length() == 0) {
            continue;
        }
        istringstream iss(row);
        string value;
        int tcolcnt = 0;
        while (getline(iss, value, ' ')) {
            if (value.length() == 0) {
                continue;
            }
            if (!isDouble(value)) {
                file3 << "error";
                return -1;
            }
            try {
                arr2[rowcnt2][tcolcnt] = strtod(value.c_str(), NULL);
                tcolcnt++;
            }
            catch (int e) {
                file3 << "error";
                return -1;
            }
        }
        
        if (tcolcnt == 0) {
            continue;
        }
        
        if (rowcnt2 == 0)
            colcnt2 = tcolcnt;
        else if (tcolcnt != colcnt2) {
            file3 << "error";
            return -1;
        }
        rowcnt2++;
    }
    if (colcnt1 != rowcnt2) {
        file3 << "error";
        return -1;
    }
    if (rowcnt1 == 0 && rowcnt2 == 0) {
        file3 << "error";
        return -1;
    }
    // Multiply matrices and store in file 3
    for (int i = 0; i < rowcnt1; i++) {
        for (int j = 0; j < colcnt2; j++) {
            double sum = 0;
            for (int k = 0; k < rowcnt2; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            file3 << fixed << setprecision(2) << sum << " ";
        }
        file3 << endl;
    }
}

