// Ring Buffer Template
class MyCircularQueue {
private:
    vector<int> buf_;
    int rear;
    int front;
    int capacity;
public:
    MyCircularQueue(int k) {
        buf_ = vector<int>(k+1);
        capacity = k;
        front = 0;
        rear = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
            buf_[rear] = value;
            rear = (rear+1) % (capacity+1);
            return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front+1) % (capacity+1);
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return buf_[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        if (!rear) {
            return buf_.back();
        }
        return buf_[rear-1];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear+1) % (capacity+1) == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
