// 用数组模拟双端队列 保证同时存储数的个数不大于 N

class MyCircularDeque 
{
public:
    int l=0 , r=0 , size=0 , limit=0;
    int deque[N];
public:
    MyCircularDeque(int k) 
    {
        limit = k;
        size=0;
        l=0 , r=0;
    }
    
    bool insertFront(int value) 
    {
        if(isFull())
        {
            return false;
        }

        if(size==0)
        {
            // 当 size == 0 时 l和r 会错开 不能直接加数
            // 要保证的是 当 size == 1 时 l == r
            deque[l] = value;
            r = l;
        }
        else
        {
            l = l==0 ? (limit-1) : (l-1);
            deque[l] = value;
        }

        size++;
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
        {
            return false;
        }

        if(size==0)
        {
            // 当 size == 0 时 l和r 会错开 不能直接加数
            // 要保证的是 当 size == 1 时 l == r
            deque[l]=value;
            r = l;
        }
        else
        {
            r = r==(limit-1) ? 0 : r+1;
            deque[r] = value;
        }

        size++;
        return true;
    }
    
    bool deleteFront() 
    {
        if(isEmpty())
        {
            return false;
        }

        l = l==(limit-1) ? 0 : l+1;
        size--;
        return true;
    }
    
    bool deleteLast() 
    {   
        if(isEmpty())
        {
            return false;
        }

        r = r==0 ? (limit-1) : (r-1);
        size--;
        return true;
    }
    
    int getFront() 
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return deque[l];
        }
    }
    
    int getRear() 
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return deque[r];
        }
    }
    
    bool isEmpty() 
    {
        return size==0;
    }
    
    bool isFull() 
    {
        return size==limit;
    }
};