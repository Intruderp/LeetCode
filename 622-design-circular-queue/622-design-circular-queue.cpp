class MyCircularQueue {
public:
    list<int> l;
    int sz=0,mx=0;
    MyCircularQueue(int k) {
        mx=k;
    }
    
    bool enQueue(int value) {
        if(sz<mx)
        {
            l.push_back(value);
            sz++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(sz>0)
        {
            l.pop_front();
            sz--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(sz>0)
            return l.front();
        return -1;
    }
    
    int Rear() {
        if(sz>0)
            return l.back();
        return -1;
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==mx;
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