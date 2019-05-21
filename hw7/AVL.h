/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVL.h
 * Author: oracle
 *
 * Created on November 7, 2018, 9:20 PM
 */

#ifndef AVL_H
#define AVL_H

#include <fstream>
using namespace std;

class Node {
public:

    Node() : key(0), left(nullptr), right(nullptr), height(1) {
    }

    ~Node() {
    }
    int key;
    Node *left;
    Node *right;
    int height;

};

class AVL {
public:

    AVL();
    AVL(const AVL& orig);
    virtual ~AVL();
    void insert(int key);
    bool elementExists(int key);
    void inorderTraversal(fstream& outfile);
    void preorderTraversal(fstream& outfile);
    void postorderTraversal(fstream& outfile);
    void printGivenLevel(int level, fstream& outfile);



private:
    int totalNodes;
    Node *root;
    Node* newNode(int key);
    Node* insert(Node* node, int key);
    void printLevelElements(Node* node, int n, fstream& outfile);
    Node* find(Node* node, int key);
    void inOrder(Node *node, fstream& outfile);
    void preOrder(Node *node, fstream& outfile);
    void postOrder(Node *node, fstream& outfile);
    int max(int a, int b);
    Node* rightRotate(Node *y);
    Node* leftRotate(Node *x);
    int getBalance(Node *N);
    int getHeight(Node *N);
    void printGivenLevel(Node* node, int level, fstream& outfile);

};
#endif 