// Converted from queues(needs conversion).cpp

/**
 * QUEUES:
 * The first element is removed and new elemts are added behind just like a normal queue.
 * Enqueue - Adding a new element to the back of the queue
 * Dequeue - Adding a new element to the end of the queue
 */

#include <iostream>
#include "../../util/COLORS!.hpp"
using namespace std;

#define size 20
class Queue {
  int a[size],
  rear; // Last index that is filled

  public:
    Queue() {
      rear = -1; // Initially all are empty so -1 ie before 0
    }

    Queue enqueue(int x) {
      if (rear == size - 1) cout << RED_FLASH << "Queue is full." << NC << endl;
      else a[++rear] = x;

      return *this;
    }

    Queue dequeue() {
      if (rear == -1) cout << RED_FLASH << "Queue is empty." << NC << endl;

      for (int i = 0; i < rear; i++) a[i] = a[i + 1]; // Shift all elements by 1, overwrite first element
      rear --;

      return *this;
    }

    Queue display() {
      if (rear == -1) cout << RED_FLASH << "Queue is empty." << NC << endl;
      for (int i = rear; i >= 0; i--) cout << ORANGE_NO_FLASH << a[i] <<  NC << " ";

      cout << endl;

      return *this;
    }
};

int main() {
  int choice, ele;
  Queue q;

  while (true) {
    cout << "Enter " <<
    ORANGE_UNDER << 1 << NC
    << " to enqueue, " <<
    ORANGE_UNDER << 2 << NC
    << " to dequeue and "
    << ORANGE_UNDER << 3 << NC
    << " to display: " << ORANGE_NO_FLASH;

    cin >> choice;
    cout << NC;

    switch(choice) {
      case 1:
        cout << "Enter element: " << ORANGE_NO_FLASH;
        cin >> ele;
        cout << NC;

        q.enqueue(ele);
        break;

      case 2:
        q.dequeue();
        break;

      case 3:
        q.display();
        break;

      default:
        return 0;
    }
  }
}
