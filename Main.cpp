#include "MyQueue.h"

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    MyQueue<int> queue(size);

    int choice, value;
    bool running = true;

    while (running)
    {
        cout << endl << "Queue Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Enqueue
            cout << "Enter a value to enqueue: ";
            cin >> value;
            queue.enQueue(value);
            break;

        case 2: // Dequeue
            value = queue.deQueue();
            if (value != 0 || !queue.isEmpty()) // Check if the queue was not empty
                cout << "Dequeued value: " << value << endl;
            break;

        case 3: // Display Queue
            queue.display();
            break;

        case 4: // Exit
            running = false;
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}