class Queue
{
    int arr[];
    int fr;
    int rear;
    int size;

public:
 
    Queue()
    {
        // Implement the Constructor
        size = 101;
        arr = new int[size];
        fr = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (fr == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear != size)
        {
            arr[rear] = data;
            rear++;
        }
        else
        {
            cout << "Queue overflow" << endl;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (rear == fr)
        {
            return -1;
        }
        else
        {
            int x = arr[fr];
            fr++;
            return x;
        }
    }

    int front()
    {
        // Implement the front() function
        if (rear == fr)
        {
            return -1;
        }
        else
        {
            return arr[fr];
        }
    }
};