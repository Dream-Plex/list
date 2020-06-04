#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
public:

    List();

    ~List();

    void push_back(T data);

    unsigned length();

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
unsigned List<T>::length ()
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
