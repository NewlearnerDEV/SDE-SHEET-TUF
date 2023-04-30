class Stack {
    int arr[];
    int tp = -1;
    int cp;

public:
  
    Stack(int capacity) {
        // Write your code here.
        cp=capacity;
        arr=new int[capacity];
        
    }

    void push(int num) {
        tp=tp+1;
        arr[tp]=num;
    }

    int pop() {
        // Write your code here.
        int x=arr[tp];
        tp=tp-1;
        return x;
    }
    
    int top() {
        // Write your code here.
        int x=arr[tp];
        return x;
    }
    
    int isEmpty() {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    int isFull() {
        // Write your code here.
        if(tp==cp-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    