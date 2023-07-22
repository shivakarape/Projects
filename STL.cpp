///////////////////////////////////////////////////////////////////////////////////////////
//    Customised Template Library - (for Primitive data types)
//    
//      contains functions + classes
//    - 4 Linked Lists, Stack, Queue
//    - Array Algorithms : Searching , Sorting ,Arithmetic operations
//
///////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Class of SuperClass

///////////////////////////////////////////////////////////////////////////////////////////


class SuperClass
{
    public:
        int iCount;

        SuperClass()
        {
            iCount = 0;
        }

        int Count()
        {
            return iCount;
        }
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for Singly linear and Singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
	T data;
	struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for Doubly linear and Doubly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
	T data;
	struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL : public  SuperClass
{
	public:
		struct NodeS<T> *first;

    SinglyLL();
    ~SinglyLL();
    void Display();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
}

template <class T>
SinglyLL<T>::~SinglyLL()
{
    NodeS<T> * temp = first;

    for(int i = 1; i <= iCount ; i++)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}
 
template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int ipos)
{
    if(ipos < 0 || ipos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }   
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if(ipos < 0 || ipos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *tempX = NULL;

        for(int i = 1 ; i < ipos -1 ; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL : public SuperClass
{
	public:
		struct NodeS<T> *first;
        struct NodeS<T> *last;

    SinglyCL();
    ~SinglyCL();
    void Display();
     

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
}

template <class T>
SinglyCL<T>:: ~SinglyCL()
{
    NodeS<T> * temp = first;
    for(int i = 1; i <= iCount; i++)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of Singly Circular Linked list are : "<<"\n";
    NodeS<T> * temp = first;
    for(int i = 1; i <= iCount ; i++)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    if(ipos < 0 || ipos > iCount+1)
    {
        cout<<"Invalid position\n";
        return ;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> * temp = first;
        
        while(temp->next != last)
        {
            temp = temp -> next;
        }
        delete last;
        last = temp;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if(ipos < 0 || ipos > iCount)
    {
        cout<<"Invalid position\n";
        return ;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *tempX = NULL;

        for(int i = 0; i < ipos-1 ; i++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL : public  SuperClass
{
	public:
		struct NodeD<T> *first;

    DoublyLL();
    ~DoublyLL();
    void Display();
     

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyLL<T>:: DoublyLL()
{
    first = NULL;
}

template <class T>
DoublyLL<T>:: ~DoublyLL()
{
    NodeD<T> * temp = NULL;

    for(int i = 1; i <= iCount ; i++)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>:: Display()
{
    NodeD<T> * temp = first;

    cout<<"Elements of Doubly Linear Linked list are : "<<"\n";

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> * temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>:: InsertAtPos(T no, int ipos)
{
    if(ipos < 0 || ipos > iCount+1)
    {
        cout<<"Invalid position\n";
        return ;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;
        NodeD<T> * newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < ipos-1 ; i++)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        
        iCount++;
    }
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> * temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>:: DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>    
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    if(ipos < 0 || ipos > iCount)
    {
        cout<<"Invalid position\n";
        return ;
    }
    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly circular linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL : public  SuperClass
{
	public:
		struct NodeD<T> *first;
        struct NodeD<T> *last;

    DoublyCL();
    ~DoublyCL();
    void Display();
     

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
}

template <class T>
DoublyCL<T>:: ~DoublyCL()
{
    NodeD<T> * temp = NULL;

    for(int i = 1; i <= iCount ; i++)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements of Doubly Circular Linked list are : "<<"\n";

    NodeD<T> * temp = first;

    cout<<"NULL <=>";
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn; 
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}
 
template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn; 
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int ipos)
{
    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }   
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new  NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(ipos < (iCount/2))
        for(int i = 1; i < ipos-1 ; i++)
        {
            temp = temp->next;
        }
        else
        {
            temp = last;
            for(int i = iCount; i > ipos-1 ; i--)
            {
                temp = temp->prev;
            }
        }
        
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {   
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        
        first->prev = last;
        last->next = first;
    }
    
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else
    {
        last = last->prev;
        delete first->prev;
    }
    first->prev = last;
    last->next = first;
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }   
    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {   
        NodeD<T> *temp = first;
        
        if(ipos < (iCount/2))
        for(int i = 1; i < ipos-1 ; i++)
        {
            temp = temp->next;
        }
        else
        {
            temp = last;
            for(int i = iCount; i > ipos-1 ; i--)
            {
                temp = temp->prev;
            }
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack : public  SuperClass
{
    private:
        struct NodeS<T> * first;

    public:
        Stack();
        void Push(T no);      // InsertLast
        T Pop();              // DleteLast
        void Display();
         
};

template <class T>
Stack<T>:: Stack()
{
    first = NULL;
}

template <class T>
void Stack<T>::Push(T no)        // InsertFirst : Last in
{
    NodeS<T> * newn = new NodeS(no);

    newn->data = no;
    newn->next = NULL;    

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
} 

template <class T>
T Stack<T>::Pop()        // DeleteFirst : First Out
{
    T Value;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        Value = first->data;
        first = first->next;
    
        delete temp;
    }

    iCount--;

    return Value;
}              

template <class T>
void Stack<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Stack is empty\n";
        return;
    }
    
    cout<<"Elements of stack are : \n";

    NodeS<T> * temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue : public  SuperClass
{
    private:
        struct NodeS<T> * first;
        struct NodeS<T> * last;

    public:
        Queue();
        void Enqueue(int no);      // InsertLast
        int Dequeue();              // DleteFirst
        void Display();
};

template <class T>
Queue<T>:: Queue()
{
    first = NULL;
    last = NULL;
}

template <class T>
void Queue<T>::Enqueue(int no)        // InsertLast
{
    NodeS<T> * newn = new NodeS<T>(no);

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        last->next = newn;
    }
    iCount++;
} 

template <class T>
int Queue<T>::Dequeue()        // DeleteFirst
{
    int Value = 0;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }
    else
    {
        Value = first -> data;
        NodeS<T> * temp = first;
        first = first -> next;
        delete temp;
    }

    iCount--;

    return Value;
}              

template <class T>
void Queue<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    NodeS<T> * temp = first;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of generic data type Array

///////////////////////////////////////////////////////////////////////////////////////////

template <class T> 
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        T Maximum();
        T Minimum();
        T Summation();
        T Average();
        int Frequency(T);
        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
        bool CheckSorted();
        void BubbleSort(bool);
        void BubbleSortEfficient(bool);
        void SelectionSort(bool);  
        void InsertionSort(bool);  
};

///////////////////////////////////////////////////////////////////////////////////////////
// ArrayX constructor
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

///////////////////////////////////////////////////////////////////////////////////////////
// ArrayX distructor
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
ArrayX<T>:: ~ArrayX()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Accepting elements from user to store in an Array object
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>:: Accept()
{
    cout<<"Enter the elements: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// Display each element of Array object on terminal
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>:: Display()
{
    cout<<"Elements of array are : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   Maximum
//  Input           :   T
//  Ouput           :   T
//  Description     :   Returns the element of maximum value from an array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T ArrayX<T>:: Maximum()
{
    T Max = Arr[0];
    int iCnt = 0;
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > Max)
        {
            Max = Arr[iCnt];
        }
    }
    return Max;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   Minimum
//  Input           :   T
//  Ouput           :   T
//  Description     :   Returns the element of Minimum value from an array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T ArrayX<T>:: Minimum()
{
    T Min = Arr[0];
    int iCnt = 0;
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] < Min)
        {
            Min = Arr[iCnt];
        }
    }
    return Min;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   Summation
//  Input           :   T
//  Ouput           :   T
//  Description     :   Returns the Sum of all elements in an array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T ArrayX<T>:: Summation()
{
    const char *ch = typeid(Arr[0]).name();
    if(*ch == 'c')
    {
        cout<<"Summation of characters is not permitted";
        return '\0';
    }

    T Sum = 0;
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        Sum = Sum + Arr[iCnt];
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   Average
//  Input           :   T
//  Ouput           :   T
//  Description     :   Returns the average of all elements in an array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T ArrayX<T>:: Average()
{
    const char *ch = typeid(Arr[0]).name();
    if(*ch == 'c')
    {
        cout<<"Summation of characters is not permitted";
        return '\0';
    }

    T Sum = 0;
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        Sum = Sum + Arr[iCnt];
    }
    return (Sum/iSize);
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   Frequency
//  Input           :   T
//  Ouput           :   Integer
//  Description     :   Returns the number total occurences of data in an Array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int ArrayX<T>:: Frequency(T Value)
{
    int iCount = 0;
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == Value)
        {
            iCount++;
        }
    }
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   LinearSearch
//  Input           :   T
//  Ouput           :   Boolean
//  Description     :   Returns the status of data availability in an Array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>:: LinearSearch(T No)
{
    bool flag = false;

    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   BidirectionalSearch
//  Input           :   Primitive data type
//  Ouput           :   Boolean
//  Description     :   Returns the status of data availability in an Array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(N/2)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>:: BidirectionalSearch(T No)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   BinarySearch
//  Input           :   Primitive data type
//  Ouput           :   Boolean
//  Description     :   Returns the status of data availability in an Array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case time complexity :   O(log N)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>:: BinarySearch(T No) // Array must be sorted
{
    bool flag = false;
    int iStart = 0, iEnd = 0, iMid = 0;
    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart)/2;
        if((Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid -1;
        }
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   CheckSorted
//  Input           :   void
//  Ouput           :   Boolean
//  Description     :   Returns the Sort status of an Array
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Time complexity :   O(N-1)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>:: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(int iCnt = 0; iCnt  < iSize-1; iCnt++)
    {
        if (Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   BubbleSort
//  Input           :   Boolean
//  Ouput           :   void
//  Description     :   Sorts the Array increasing or decreasing order as per input parameter
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Time complexity :   O((N-1)^2)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>:: BubbleSort(bool order)
{
    T temp;

    if(order == true)
    for(int i = 0; i < iSize-1; i++)
    {
        for(int j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }

    else
    for(int i = 0; i < iSize-1; i++)
    {
        for(int j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name    :   BubbleSortEfficient
//  Input           :   Boolean
//  Ouput           :   void
//  Description     :   Sorts the Array increasing or decreasing order as per input parameter
//  Author          :   Shivanand Aabasaheb Karape
//  Date            :   20/07/2023
//  Update Date     :   
//  Worst case Time complexity :   O((N-1)^2)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>:: BubbleSortEfficient(bool order)
{
    T temp;
    bool flag = false;

    if(order == true)
    for(int i = 0; i < iSize-1; i++)
    {
        flag = false;

        for(int j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }

    else
    for(int i = 0; i < iSize-1; i++)
    {
        flag = false;

        for(int j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name:   SelectionSort
//  Input       :   Boolean
//  Ouput       :   void
//  Description :   Sorts the Array increasing or decreasing order as per input parameter
//  Author      :   Shivanand Aabasaheb Karape
//  Date        :   20/07/2023
//  Update Date :   
//  Worst case Time complexity :   O(((N-1)^2)/2)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>:: SelectionSort(bool order)
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    if(order == true)
    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;              
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }

    else
    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;              
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//  Funtion Name:   InsertionSort
//  Input       :   Boolean
//  Ouput       :   void
//  Description :   Sorts the Array increasing or decreasing order as per input parameter
//  Author      :   Shivanand Aabasaheb Karape
//  Date        :   20/07/2023
//  Update Date :   
//  Worst case Time complexity :   O(((N-1)^2)/2)
//
///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T>:: InsertionSort(bool order)
{
    int i = 0, j = 0;
    T selected;

    if(order == true)
    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; ((j >= 0) && (Arr[j] > selected));j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }

    else
    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; ((j >= 0) && (Arr[j] < selected));j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point Function
///////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////

/*
    Scope of improvement
    1. 	we can convert linked list into Array of structure
    2.	Doubly LLL can have last node pointer for back traversal.
    3.	Doubly CLL can hanve middle node pointer instead of last node pointer.
    
    4.  inset string processing functions.

*/

