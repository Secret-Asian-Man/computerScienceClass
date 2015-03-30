#ifndef LINKEDLISTFUNCTIONS_H
#define LINKEDLISTFUNCTIONS_H
#include "nodes/node.h"

void print(node* head);
node* walker(node* head, int distance);
node* search(node* head, ITEM_TYPE key);
node* findPrevious(node* head, node*position);
void printAll(node* head);
void deleteNode(node*& head, node* position);
void deleteNode(node*& head, ITEM_TYPE type);
void insertHead(node*& head, ITEM_TYPE number);
void insertAfter(node *&head, node* position, ITEM_TYPE input);
void insertBefore(node*& head, node* position, ITEM_TYPE input);
int nodeCount(node* head);
void insertSort(node*& head, ITEM_TYPE input);
void swap(node*& A, node*& B);
ITEM_TYPE at(node *head, int pos);
void reverse(node*& head);
void deleteRepeat(node*& head);
//void shuffle(node*& head);
void copy(node *source, node*& destination);//need to run eraseAll in here
void eraseAll(node *&head);
node* uniqueMerge(node*& A,  node*& B);











#endif // LINKEDLISTFUNCTIONS_H
