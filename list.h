#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
public:

    List();
    ~List();

    void push_back(T data);  
    void push_front(T data);

    void pop_front();
    void pop_back();

    void insert(T data, unsigned index);
    void removeAt(unsigned index);

    void clear();
    unsigned len();

    T& operator[](const int index);

private:

// Node
    template<typename U>
    class Node
    {
    public:
        Node *next;
        U data;
        Node(U data = U(), Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };



// field
    Node<T> *head;
    unsigned size;
};

template<typename T>
List<T>::List()
{
    this->size = 0;
    this->head = nullptr;
}

template<typename T>
List<T>::~List()
{
    this->clear ();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while(current->next != nullptr)
            current = current->next;

        current->next = new Node<T>(data);
    }
    this->size++;
}

template<typename T>
void List<T>::push_front(T data)
{
    this->head = new Node<T>(data, this->head);
    this->size++;
}

template<typename T>
void List<T>::pop_front()
{
    if (this->head != nullptr)
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->size--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    this->removeAt (this->size - 1);
}

template<typename T>
void List<T>::insert(T data, unsigned index)
{
    if (!index)
    {
        this->push_front (data);
    }
    else
    {
        Node<T> *previous = this->head;
        for (unsigned i = 0; i != index - 1; i++)
            previous = previous->next;

        Node<T> *inserted = new Node<T>(data, previous->next);
        previous->next = inserted;
        this->size++;
    }
}

template<typename T>
void List<T>::removeAt(unsigned index)
{
    if (!index)
    {
        this->pop_front ();
    }
    else
    {
        Node<T>*previous = this->head;
        for (unsigned i = 0; i != index - 1; i++)
            previous = previous->next;

        Node<T> *removable = previous->next;
        previous->next = removable->next;
        delete removable;
        this->size--;
    }
}

template<typename T>
void List<T>::clear()
{
    while (this->size)
        this->pop_front ();
}

template<typename T>
unsigned List<T>::len ()
{
    return this->size;
}

template<typename T>
T &List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;

    while (current != nullptr)
    {
        if (counter == index)
            return current->data;

        current = current->next;
        counter++;
    }
}

#endif // LIST_H
