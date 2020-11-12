// Converted from linked-list.cpp

/**
 * LINKEDLIST: A data structure consisting of nodes where each node points to the
 * next node
 *
 * FEATURES:
 * Efficient addition/removal of elements
 *
 * DRAWBACKS:
 * Access/lookup time is linear
 * Random access not possible
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

/**
 * Class LINKEDLIST: A class that contains only a pointer to the first node as a property.
 * All the other nodes are defined and then pointers to those are added to the
 * start node and/or its child nodes.
 */
class LinkedList {
  Node *start;

  public:
    LinkedList() {
      start = NULL;
    }

    /**
     * Display the linked list.
     */
    LinkedList display() {
      Node *t = start; // To traverse

      if (t == NULL) cout << RED_NO_UNDER << "Linked List Empty." << NC << endl;
      else {
        cout << "Current snapshot of the linked list: ";
        cout << GREEN_UNDER << t->data << NC << " ";

        while (t->next != NULL) {
          t = t->next;
          cout << ORANGE_NO_UNDER << " -> " << GREEN_UNDER << t->data << NC;
        }

        cout << endl;
      }

      return *this;
    }

    /**
     * Creates a new node and appends to the end.
     */
    LinkedList insertEnd() {
      Node *newNode = new Node, // This is the node which will be inserted.
      *t; // Used to traverse the linked list

      cout << "Enter the data: ";
      cin >> newNode->data;

      newNode->next = NULL; // Since this will be the last node

      if(start == NULL) start = newNode; // The start pointer is not initialized in the constructor
      else {
        t = start; // Temporarily store the first node pointer

        while(t->next != NULL) t = t->next; // Go to the next node till it reaches the end

        t->next = newNode; // Add pointer to newNode in the last node in the linked list
      }

      return *this;
    }

    /**
     * Inserts a new node at the beginning.
     */
    LinkedList insertBeginning() {
      Node *newNode = new Node;

      cout << "Enter the data: ";
      cin >> newNode->data;

      newNode->next = start;
      start = newNode;

      return *this;
    }

    /**
     * Inserts a node after a specified data node
     */
    LinkedList insertAfter() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        int insertAfterElem; // The value after which to insert the new node
        Node *newNode = new Node, // The new node to be inserted
        *t; // To traverse the list

        cout << "Enter the data: ";
        cin >> newNode->data;

        cout << "Enter the value after which to insert the node: ";
        cin >> insertAfterElem;

        if (start == NULL) start = newNode;
        else {
          t = start;
          while (t != NULL) {
            if (t->data == insertAfterElem) {
              newNode->next = t->next;
              t->next = newNode;
            }

            t = t->next;
          }
        }
      }

      return *this;
    }

    LinkedList insertBefore() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        Node *newNode = new Node,
        *t;
        int insertBeforeElem; // Element before which to insert the new node

        cout << "Enter the data: ";
        cin >> newNode->data;

        cout << "Enter the value before which to insert the node: ";
        cin >> insertBeforeElem;

        if (start == NULL) start = newNode;
        else {
          t = start;

          while (t != NULL) {
            if (t->next->data == insertBeforeElem) {
              newNode->next = t->next;
              t->next = newNode;
            }

            t = t->next;
          }
        }
      }

      return *this;
    }

    /**
     * Delete the first node
     */
    LinkedList deleteBeginning() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        Node *temp;

        temp = start;
        start = start->next;

        cout << "Deleted " << RED_UNDER << temp->data << NC << "." << endl;
        delete temp;
      }

      return *this;
    }

    /**
     * Delete the last node
     */
    LinkedList deleteEnd() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        Node *t = start;

        while (t->next->next != NULL) t = t->next;

        cout << "Deleted " << RED_UNDER << t->next->data << NC << "." << endl;

        delete t->next;
        t->next = NULL;
      }

      return *this;
    }

    /**
     * Delete a specific element (all matches)
     */
    LinkedList deleteElement() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        int deletedElement;

        cout << "Enter the element to be deleted: ";
        cin >> deletedElement;

        // Traversing
        Node *currentNode = start;
        Node *lastNode = new Node;
        lastNode->next = start; // Just a temporary node to take care of edge cases

        /** EXPLANATION:
         * We look at 3 nodes at once, Last Node (L), Current Node (C) and the next Node (N)
         * L -> C -> N
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Current node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Last node should point to next node
         * 2) Delete current node
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         * 2) last node = last->next
         */

        while (currentNode != NULL) {
          if (currentNode->data == deletedElement) {
            cout << "Deleted " << RED_UNDER << currentNode->data << NC << "." << endl;

            lastNode->next = currentNode->next;
            delete currentNode;
          }

          Node *temp = lastNode->next;

          currentNode = lastNode->next->next;
          lastNode = temp;
        }
      }

      return *this;
    }

    /**
     * Delete the node before a given element
     */
    LinkedList deleteBefore() {
      if (start == NULL || start->next == NULL) cout << RED_FLASH << "Linked list has less than two nodes." << NC << endl;
      else {
        int deleteBeforeElement;

        cout << "Enter the element, the node before which is to be deleted: ";
        cin >> deleteBeforeElement;

        // Traversing
        Node *currentNode = start;
        Node *lastNode = new Node;
        lastNode->next = start;

        /** EXPLANATION:
         * We look at 3 nodes at once, Last Node (L), Current Node (C) and the next Node (N)
         * L -> C -> N
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Next node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Last node should point to next node
         * 2) Delete current node
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         * 2) last node = last->next
         */

        while (currentNode->next != NULL) {
          if (currentNode->next->data == deleteBeforeElement) {
            cout << "Deleted " << RED_UNDER << currentNode->data << NC << "." << endl;

            lastNode->next = currentNode->next;
            delete currentNode;
          }

          Node *temp = lastNode->next;

          currentNode = lastNode->next->next;
          lastNode = temp;
        }
      }

      return *this;
    }

    /**
     * Delete the node after a given element
     */
    LinkedList deleteAfter() {
      if (start == NULL || start->next == NULL) cout << RED_FLASH << "Linked list has less than two nodes." << NC << endl;
      else {
        int deleteAfterElement;

        cout << "Enter the element, the node after which is to be deleted: ";
        cin >> deleteAfterElement;

        // Traversing
        Node *currentNode = start->next;
        Node *lastNode = start;

        /** EXPLANATION:
         * We look at 3 nodes at once, Last Node (L), Current Node (C) and the next Node (N)
         * L -> C -> N
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Last node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Last node should point to next node
         * 2) Delete current node
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         * 2) last node = last->next
         */

        while (currentNode != NULL) {
          if (lastNode->data == deleteAfterElement) {
            cout << "Deleted " << RED_UNDER << currentNode->data << NC << "." << endl;

            lastNode->next = currentNode->next;
            delete currentNode;
          }

          Node *temp = lastNode->next;

          currentNode = lastNode->next->next;
          lastNode = temp;
        }
      }

      return *this;
    }

    /**
     * Reverses the list nodes
     */
    LinkedList reverse() {
      Node* last = start;
      Node* current = start->next;
      Node* next;

      /**
       * IMPLEMENTATION: We look at 3 nodes and continue recursively.
       * L -> C -> N (L is last; C is current; N is next)
       *
       * STEPS:
       * 1) C->next = L;
       * now: L <- C -> N
       * 2) L = C
       * 3) C = N
       * 4) IF (we are at the end of the list): exit condition (see code below)
       *    ELSE: N = C->N
       * 5) Recursively continue for the new values of L C and N
       */

      if (last != NULL && current != NULL) {
        next = current->next;
        last->next = NULL; // First node becomes last node so it should point to null.

        while (current != NULL) {
          current->next = last;
          last = current;
          current = next;


          if (current != NULL) next = current->next; // If we are NOT at the end of the list
          else start = last; // At the END (but now end becomes start)
        }
      }

      return *this;
    }
};
