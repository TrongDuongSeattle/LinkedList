//
// Created by T D  on 10/9/23.
//
#include "Node.cpp"
template <class T>
class LinkedList
{
public:
    /**
     * 0 parameter constructor
     */
    LinkedList()
    {
        m_head = 0;
        m_tail = 0;
        m_size = 0;
    }
    ~LinkedList()
    {
        delete m_head;
    }
    /**
     * Inserts given data at end of linked list
     * @param data
     */
    void add(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (m_head == 0)
        {
            m_head = m_tail = newNode;
            m_size++;
        }
        else
        {
            m_tail->setNext(newNode);
            m_tail = m_tail->getNext();
            m_size++;
        }
    }
    /**
     *
     * @param index the position of the desired node
     * @return pointer to node at given index.
     */
    Node<T>* findNodeByIndex(int index)
    {
        Node<T>* currentNode = m_head;
        for (int i = 0; i < index; ++i)
        {
            if (currentNode->getNext() != 0)
            {
                currentNode = currentNode->getNext();
            }
        }
        return currentNode;
    }
    /**
     * Searches linked list for given value
     * @param value
     * @return pointer to node with desired value
     */
    Node<T>* findNodeByValue(T value)
    {
        Node<T>* currentNode = m_head;
        for (int i = 0; i < m_size; ++i)
        {
            if (currentNode->getNext() != 0)
            {
                currentNode = currentNode->getNext();
            }
        }
        return currentNode;
    }
    T getByIndex(int index)
    {
        return findNodeByIndex(index)->getData();
    }
    /**
     * Deletes node at given index
     * @param index of node to be deleted
     */
    void deleteByIndex(int index)
    {
        Node<T>* precedingNode = findNodeByIndex(index - 1);
        if (index == m_size)
        {
            precedingNode->setNext(0);
            m_tail = precedingNode;
        }
        else if (index > 0)
        {
            precedingNode->setNext(precedingNode->getNext()->getNext());
        }
        else
        {
            m_head = m_head->getNext();
        }
        m_size--;
    }
    void deleteByValue(T value)
    {
        delete
    }
    int getSize()
    {
        return m_size;
    }
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    int m_size;
};
