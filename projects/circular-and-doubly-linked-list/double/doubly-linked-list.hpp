// Converted from linked-list.cpp

/**
 * DoublyLinkedList: A data structure consisting of nodes where each node points to the
 * next node
 *
 * DOUBLE: Each node is connected to the next AND the previous node.
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
  struct Node *previous = NULL;
  int data;
};


class DoublyLinkedList {
  Node *start;

  public:
    DoublyLinkedList() {
      start = NULL;
    }

    /**
     * Display the linked list.
     */
    DoublyLinkedList display() {
      Node *t = start; // To traverse

      if (t == NULL) cout << RED_NO_UNDER << "Linked List Empty." << NC << endl;
      else {
        cout << "Current snapshot of the linked list: ";
        cout << GREEN_UNDER << t->data << NC;

        while (t->next != NULL) {
          t = t->next;
          cout << ORANGE_NO_UNDER << " ⇋ " << GREEN_UNDER << t->data << NC;
        }

        cout << endl;
      }

      return *this;
    }

    /**
     * Creates a new node and appends to the end.
     */
    DoublyLinkedList insertEnd() {
      Node *newNode = new Node, // This is the node which will be inserted.
      *t; // Used to traverse the linked list

      cout << "Enter the data: ";
      cin >> newNode->data;

      newNode->next = NULL; // Since this will be the last node

      if(start == NULL) {
        start = newNode; // The start pointer is not initialized in the constructor
        newNode->previous = NULL; // Since this will also be the first node
      }
      else {
        t = start; // Temporarily store the first node pointer

        while(t->next != NULL) t = t->next; // Go to the next node till it reaches the end

        t->next = newNode; // Add pointer to newNode in the last node in the linked list
        newNode->previous = t;
      }

      return *this;
    }

    /**
     * Inserts a new node at the beginning.
     */
    DoublyLinkedList insertBeginning() {
      Node *newNode = new Node;
      newNode->previous = NULL; // Since this will be the first node

      cout << "Enter the data: ";
      cin >> newNode->data;

      newNode->next = start;
      newNode->next->previous = newNode;

      start = newNode;

      return *this;
    }

    /**
     * Inserts a node after a specified data node
     */
    DoublyLinkedList insertAfter() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        int insertAfterElem; // The value after which to insert the new node
        Node *newNode = new Node, // The new node to be inserted
        *t = start; // To traverse the list

        cout << "Enter the data: ";
        cin >> newNode->data;

        cout << "Enter the value after which to insert the node: ";
        cin >> insertAfterElem;

        while (t != NULL) {
          if (t->data == insertAfterElem) {
            newNode->next = t->next;
            if (newNode->next != NULL) newNode->next->previous = newNode;

            t->next = newNode;
            t->next->previous = t;
            break;
          }

          t = t->next;
        }
      }

      return *this;
    }

    DoublyLinkedList insertBefore() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        Node *newNode = new Node,
        *t = start;
        int insertBeforeElem; // Element before which to insert the new node

        cout << "Enter the data: ";
        cin >> newNode->data;

        cout << "Enter the value before which to insert the node: ";
        cin >> insertBeforeElem;

        while (t != NULL) {
          if (t->next->data == insertBeforeElem) {
            newNode->next = t->next;
            newNode->next->previous = newNode;

            t->next = newNode;
            t->next->previous = t;
            break;
          }

          t = t->next;
        }
      }

      return *this;
    }

    /**
     * Delete the first node
     */
    DoublyLinkedList deleteBeginning() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        Node *temp;

        temp = start;
        start = start->next;
        start->previous = NULL;

        cout << "Deleted " << RED_UNDER << temp->data << NC << "." << endl;
        delete temp;
      }

      return *this;
    }

    /**
     * Delete the last node
     */
    DoublyLinkedList deleteEnd() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else if (start->next == NULL) {
        delete start;
        start = NULL;
      }
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
    DoublyLinkedList deleteElement() {
      if (start == NULL) cout << RED_FLASH << "Linked list is empty." << NC << endl;
      else {
        int deletedElement;

        cout << "Enter the element to be deleted: ";
        cin >> deletedElement;

        // Traversing
        Node *t = start;

        /** EXPLANATION:
         * We look at only 1 node at once.
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Current node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Previous node(ie currentNode->previous) should point to next node
         * 2) Next node should point to previous node.
         * 2) Delete current node.
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         */

        while (t != NULL) {
          if (t->data == deletedElement) {
            cout << "Deleted " << RED_UNDER << t->data << NC << "." << endl;

            if (t->previous != NULL) t->previous->next = t->next;
            if (t->next != NULL) t->next->previous = t->previous;

            if (t == start) start = t->next;

            delete t;
            break;
          }

          t = t->next;
        }
      }

      return *this;
    }

    /**
     * Delete the node before a given element
     */
    DoublyLinkedList deleteBefore() {
      if (start == NULL || start->next == NULL) cout << RED_FLASH << "Linked list has less than 2 elements." << NC << endl;
      else {
        int deletedElement;

        cout << "Enter the element, the node before which is to be deleted: ";
        cin >> deletedElement;

        // Traversing
        Node *t = start;

        /** EXPLANATION:
         * We look at only 1 node at once.
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Next node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Previous node(ie currentNode->previous) should point to next node
         * 2) Next node should point to previous node.
         * 2) Delete current node.
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         */

        while (t != NULL) {
          if (t->next != NULL && t->next->data == deletedElement) {
            cout << "Deleted " << RED_UNDER << t->data << NC << "." << endl;

            if (t->previous != NULL) t->previous->next = t->next;
            if (t->next != NULL) t->next->previous = t->previous;

            if (t == start) start = t->next;

            delete t;
            break;
          }

          t = t->next;
        }
      }

      return *this;
    }

    /**
     * Delete the node after a given element
     */
    DoublyLinkedList deleteAfter() {
      if (start == NULL || start->next == NULL) cout << RED_FLASH << "Linked list has less than 2 elements." << NC << endl;
      else {
        int deletedElement;

        cout << "Enter the element, the node after which is to be deleted: ";
        cin >> deletedElement;

        // Traversing
        Node *t = start;

        /** EXPLANATION:
         * We look at only 1 node at once.
         * Now we can check the condition, based on which we can either delete or not delete
         * the CURRENT NODE. (always delete current node)
         *
         * CONDITION: Previous node == Given element
         * If yes: Delete the current node
         *
         * DELETE:
         * 1) Previous node(ie currentNode->previous) should point to next node
         * 2) Next node should point to previous node.
         * 2) Delete current node.
         *
         * TRAVERSE: Traverse unconditionally, whether deleted or not.
         * 1) current node = next node
         */

        while (t != NULL) {
          if (t->previous != NULL && t->previous->data == deletedElement) {
            cout << "Deleted " << RED_UNDER << t->data << NC << "." << endl;

            if (t->previous != NULL) t->previous->next = t->next;
            if (t->next != NULL) t->next->previous = t->previous;

            if (t == start) start = t->next;

            delete t;
            break;
          }

          t = t->next;
        }
      }

      return *this;
    }

    /**
     * Reverses the list nodes
     */
    DoublyLinkedList reverse() {
      Node* t = start;

      /**
       * IMPLEMENTATION: We look at one node only. We just reverse the previous and next pointers. At the end, change the starting node.
       */

      while (t != NULL) {
        Node* temp = t->next; // temporary
        t->next = t->previous;
        t->previous = temp;

        if (t->previous == NULL) start = t;

        t = t->previous; // Go one step ahead. ->previous since the direction is reversed.
      }

      return *this;
    }
};
