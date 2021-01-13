// Converted from linked-list.cpp

/**
 * LINKEDLIST: A data structure consisting of nodes where each node points to the
 * next node
 *
 * CIRCULAR: Last node points to the first node.
 */

/**
 * IMPLEMENTATION:
 */

#include <iostream>
#include "../util/COLORS!.hpp"
using namespace std;

/**
 * Struct NODE: A structure with (int)data and a pointer which points to the next node.
 * Properties:
 * next: A pointer to another node
 * data: An integer value as the data of the current node
 */
struct Node {
  struct Node *next = NULL;
  int data;
};

class CircularLinkedList {
  Node *start;

  public:
    CircularLinkedList() {
      cout << "Enter the data for the first node: ";
      cin >> start->data;
      start->next = start;
    }

    /**
     * Display the linked list.
     */
    CircularLinkedList display() {
      Node *t = start; // To traverse

      cout << "Current snapshot of the linked list: ";
      cout << GREEN_UNDER << t->data << NC;

      while (t->next != start) {
        t = t->next;
        cout << ORANGE_NO_UNDER << " -> " << GREEN_UNDER << t->data << NC;
      }

      cout << ORANGE_NO_UNDER << " -> " << ORANGE_UNDER << "↩" << NC << endl;

      return *this;
    }

    /**
     * Inserts a node after a specified data node.
     */
    CircularLinkedList insertAfter() {
      int insertAfterElem; // The value after which to insert the new node
      Node *newNode = new Node, // The new node to be inserted
      *t = start; // To traverse the list

      cout << "Enter the data: ";
      cin >> newNode->data;

      cout << "Enter the value after which to insert the new node: ";
      cin >> insertAfterElem;

      do {
        if (t->data == insertAfterElem) {
          newNode->next = t->next;
          t->next = newNode;
          break;
        }

        t = t->next;
      }
      while (t != start);

      return *this;
    }

    CircularLinkedList insertBefore() {
      int insertAfterElem; // The value after which to insert the new node
      Node *newNode = new Node, // The new node to be inserted
      *t = start; // To traverse the list

      cout << "Enter the data: ";
      cin >> newNode->data;

      cout << "Enter the value before which to insert the new node: ";
      cin >> insertAfterElem;

      do {
        if (t->next->data == insertAfterElem) {
          newNode->next = t->next;
          t->next = newNode;
          break;
        }

        t = t->next;
      }
      while (t != start);

      return *this;
    }

    /**
     * Delete a specific element (all matches)
     */
    CircularLinkedList deleteElement() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else if (start->next == start) cout << RED_FLASH << "You cannot delete the last element." << NC << endl;
      else {
        int deletedElement;

        cout << "Enter the element to be deleted: ";
        cin >> deletedElement;

        // Traversing
        Node *currentNode = start->next;
        Node *previousNode = start;

        /** EXPLANATION:
         * We look at 3 nodes at once, Previous Node (P), Current Node (C) and the Next Node (N)
         * P -> C -> N
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always le (t->next != start) {
          t = t->next;
          cout << ORANGE_NO_UNDER << " -> " << GREEN_UNDER << t->data << NC;
        } node
         *
         * DELETE:
         * 1) Previous node should point to next node
         * 2) Delete current node
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         * 2) previous node = previous->next
         */

        do {
          if (currentNode->data == deletedElement) {
            cout << "Deleted " << RED_UNDER << currentNode->data << NC << "." << endl;

            previousNode->next = currentNode->next;
            if (start == currentNode) start = previousNode->next;
            else delete currentNode;
            break;
          }

          Node *temp = previousNode->next;

          currentNode = previousNode->next->next;
          previousNode = temp;
        }
        while (previousNode != start);
      }

      return *this;
    }

    /**
     * Delete the node before a given element
     */
    CircularLinkedList deleteBefore() {
      if (start == NULL || start->next == start) cout << RED_FLASH << "Linked list has less than two nodes." << NC << endl;
      else {
        int deleteBeforeElement;

        cout << "Enter the element, the node before which is to be deleted: ";
        cin >> deleteBeforeElement;

        // Traversing
        Node *currentNode = start->next;
        Node *previousNode = start;

        /** EXPLANATION:
         * We look at 3 nodes at once, Previous Node (P), Current Node (C) and the Next Node (N)
         * P -> C -> N
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Next node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Previous node should point to next node
         * 2) Delete current node
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         * 2) previous node = previous->next
         */

        do {
          if (currentNode->next->data == deleteBeforeElement) {
            cout << "Deleted " << RED_UNDER << currentNode->data << NC << "." << endl;

            previousNode->next = currentNode->next;
            if (start == currentNode) start = previousNode->next;
            else delete currentNode;
            break;
          }

          Node *temp = previousNode->next;

          currentNode = previousNode->next->next;
          previousNode = temp;
        }
        while (previousNode != start);
      }

      return *this;
    }

    /**
     * Delete the node after a given element
     */
    CircularLinkedList deleteAfter() {
      if (start == NULL || start->next == start) cout << RED_FLASH << "Linked list has less than two nodes." << NC << endl;
      else {
        int deleteAfterElement;

        cout << "Enter the element, the node after which is to be deleted: ";
        cin >> deleteAfterElement;

        // Traversing
        Node *currentNode = start->next;
        Node *previousNode = start;

        /** EXPLANATION:
         * We look at 3 nodes at once, Previous Node (L), Current Node (C) and the Next Node (N)
         * L -> C -> N
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Previous node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Previous node should point to next node
         * 2) Delete current node
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         * 2) previous node = previous->next
         */

        do {
          if (previousNode->data == deleteAfterElement) {
            cout << "Deleted " << RED_UNDER << currentNode->data << NC << "." << endl;

            previousNode->next = currentNode->next;
            if (start == currentNode) start = previousNode->next;
            else delete currentNode;
            break;
          }
          Node *temp = previousNode->next;

          currentNode = previousNode->next->next;
          previousNode = temp;
        }
        while (previousNode != start) ;
      }

      return *this;
    }
};
