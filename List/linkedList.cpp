template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(const T &val) : data{val}, next{nullptr}
    {
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList() : head{nullptr} {};
    ~LinkedList()
    {
        while (removeAt(0))
        {
        }
    }

    Node<T> *add(const T &data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *tmp = head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
        return newNode;
    }
    Node<T> *addFront(const T &data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        return newNode;
    }
    void insertAt(const T &data, size_t position)
    {
        Node<T> *tmp = head;
        if (position == 0)
        {
            addFront(data);
        }
        else
        {
            while (position > 1 && tmp != nullptr)
            {
                tmp = tmp->next;
                position--;
            }
            if (tmp == nullptr)
                return;
            Node<T> *newData = new Node<T>(data);
            newData->next = tmp->next;
            tmp->next = newData;
        }
    }
    bool removeAt(size_t index)
    {
        if (head == nullptr)
            return false;
        Node<T> *tmp = head;
        if (index == 0)
        {

            head = head->next;
            delete tmp;
            return true;
        }
        while (index > 1 && tmp->next != nullptr)
        {
            tmp = tmp->next;
            index--;
        }
        if (tmp == nullptr || tmp->next == nullptr)
            return false;
        Node<T> *toDelete = tmp->next;
        tmp->next = toDelete->next;
        delete toDelete;
        return true;
    }
    bool remove(const T &data)
    {
        if (head == nullptr)
            return false;
        Node<T> *prv = head;
        Node<T> *current = head->next;
        if (head->data == data)
        {
            head = current;
            delete prev;
            return true;
        }
        while (current != nullptr && current->data != data)
        {
            prv = prv->next;
            current = current->next;
        }
        if (current == nullptr)
            return false;
        prv->next = current->next;
        delete current;
        return true;
    }
    bool search(const T &data)
    {
        if (head == nullptr)
            return false;
        Node<T> *tmp = head;
        while (tmp != nullptr && tmp->data != data)
        {
            tmp = tmp->next;
        }
        if (tmp == nullptr)
            return false;
        return true;
    }
};