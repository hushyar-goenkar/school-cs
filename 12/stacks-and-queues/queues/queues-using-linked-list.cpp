#include "../../linked-list/linked-list.hpp"

class Queue: private LinkedList {
  public:
    Queue enqueue() {
      LinkedList::insertEnd();

      return *this;
    }

    Queue dequeue() {
      LinkedList::deleteBeginning();

      return *this;
    }

    Queue display() {
      LinkedList::display();

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

        q.enqueue();
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
