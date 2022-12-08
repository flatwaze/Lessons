#ifndef List_H
#define List_H

template <class T>
class List
{
public:
    List();
    List(int size);
    void clear();
    bool empty();
    int size();
    virtual ~List();
    void push_front(T elem);
    void pop_front();
    void push_back(T elem);
    void pop_back();
    int insert(int it, T elem);
    int erase(int it);
    int begin();
    int end();
    T& front();
    T& back();
    T& operator[](int i);
private:
    int length;
    int maxSize;
    int start;
    int stop;
    T *array;
    int *arrayLink;
    int *arrayLink2;
    
    int emptyIndex;
    
};

#endif // List_H

template <class T>
List<T> :: List()
{
    array = new T[100];
    arrayLink = new int[100];
    arrayLink2 = new int[100];
    this->maxSize = 100;  
    clear();
} 

template <class T>
List<T> :: List (int size)
{
    array = new T[size];
    arrayLink = new int[size];
    arrayLink2 = new int[size];
    this->maxSize = size;
    clear();
}

template <class T>
List<T> :: ~List()
{
    delete [] array;
    delete [] arrayLink;
    delete [] arrayLink2;
}

template <class T>
int List<T> :: size(){
    return length;
}

template <class T>
void List<T> :: clear(){
    length = 0;
    emptyIndex = 0;
    start = 0;
    stop = 0;
}

template <class T>
bool List<T> :: empty(){
    return (length == 0);
}


template <class T>
void List<T> :: push_front(T elem){
    if(length == 0){
        arrayLink[emptyIndex] = maxSize - 1;
        arrayLink[maxSize - 1] = emptyIndex;
        
        arrayLink2[emptyIndex] = maxSize - 1;
        arrayLink2[maxSize - 1] = emptyIndex;
    }

    array[emptyIndex] = elem;

    arrayLink2[emptyIndex] = maxSize - 1;
    arrayLink2[arrayLink[maxSize - 1]] = emptyIndex;
    
    arrayLink[emptyIndex] = arrayLink[maxSize - 1];
    arrayLink[maxSize - 1] = emptyIndex;
    
    emptyIndex++;
    length++;
}

template <class T>
void List<T> :: pop_front(){
    arrayLink2[arrayLink[maxSize - 1]] = maxSize - 1;
    arrayLink[maxSize - 1] = arrayLink[arrayLink[maxSize - 1]];

    length--;
}

template <class T>
T& List<T> :: front(){
    return array[arrayLink[maxSize - 1]];
}

template <class T>
T& List<T> :: back(){
    return array[arrayLink2[maxSize - 1]];
}

template <class T>
void List<T> :: push_back(T elem){
    if(length == 0){
        arrayLink[emptyIndex] = maxSize - 1;
        arrayLink[maxSize - 1] = emptyIndex;
        
        arrayLink2[emptyIndex] = maxSize - 1;
        arrayLink2[maxSize - 1] = emptyIndex;
    }

    array[emptyIndex] = elem;

    arrayLink[emptyIndex] = maxSize - 1;
    arrayLink[arrayLink2[maxSize - 1]] = emptyIndex;
    
    arrayLink2[emptyIndex] = arrayLink2[maxSize - 1];
    arrayLink2[maxSize - 1] = emptyIndex;
    
    emptyIndex++;
    length++;
}

template <class T>
void List<T> :: pop_back(){
    arrayLink[arrayLink2[maxSize - 1]] = maxSize - 1;
    arrayLink2[maxSize - 1] = arrayLink2[arrayLink2[maxSize - 1]];

    length--;
}

template <class T>
int List<T> :: insert(int it, T elem){
    int index = maxSize - 1;
    array[emptyIndex] = elem;

    int i = 0;
    while(i < it){
        index = arrayLink[index];
        i++;
    }

    arrayLink2[emptyIndex] = index;
    arrayLink2[arrayLink[index]] = emptyIndex;
    
    arrayLink[emptyIndex] = arrayLink[index];
    arrayLink[index] = emptyIndex;
    
    emptyIndex++;
    length++;

    return it + 1;
}

template <class T>
int List<T> :: erase(int it){
    int index = maxSize - 1;

    int i = 0;

    while(i < it + 1){
        index = arrayLink[index];
        i++;
    }

    arrayLink[arrayLink2[index]] = arrayLink[index];
    arrayLink2[arrayLink[index]] = arrayLink2[index];

    length--;

    return it;
}

template <class T>
int List<T> :: begin(){
    return 0;
}

template <class T>
int List<T> :: end(){
    return length;
}

template <class T>
T& List<T> :: operator[](int it){
    int index = maxSize - 1;
    int i = 0;

    while(i < it + 1){
        index = arrayLink[index];
        i++;
    }

    return array[arrayLink[index]];
}
