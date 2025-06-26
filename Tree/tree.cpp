#include <iostream>
#include <queue>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *right;
    Node<T> *left;
    Node(const T &value) : data{value}, right{nullptr}, left{nullptr} {}
};

template <typename T>
class Tree
{
private:
    Node<T> *root;
    void dfsHelper(Node<T> *node)
    {
        if (node)
        {
            std::cout << node->data << ' ';
            dfsHelper(node->left);
            dfsHelper(node->right);
        }
    }
    void bfsHelper(Node<T> *node)
    {
        int counter = 0;
        int nextLevelCounter = counter * 2 + 1;
        std::queue<Node<T> *> q;
        if (!node)
            return;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *node = q.front();
            q.pop();
            counter++;
            std::cout << node->data;
            if (counter == nextLevelCounter)
            {
                std::cout << '\n';
                nextLevelCounter = nextLevelCounter * 2 + 1;
            }
            else
            {
                std::cout << ' ';
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    Node<T> *&insertHelper()
    {
        std::queue<Node<T> *> q;
        if (!root)
            return root;
        q.push(root);
        while (!q.empty())
        {
            Node<T> *front = q.front();
            q.pop();
            if (front->left)
                q.push(front->left);
            else
                return front->left;
            if (front->right)
                q.push(front->right);
            else
                return front->right;
        }
    }

    Node<T> *searchHelper(const T &data, Node<T> *node)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data == data)
            return node;
        Node<T> *leftNode = searchHelper(data, node->left);
        if (leftNode)
            return leftNode;
        else
            return searchHelper(data, node->right);
    }
    size_t sizeHelper(Node<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }
    int heightHelper(Node<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }

public:
    Tree() : root{nullptr}
    {
    }
    void dfs()
    {
        dfsHelper(root);
    }
    void bfs()
    {
        bfsHelper(root);
    }
    void insert(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        insertHelper() = newNode;
    }
    Node<T> *search(const T &data)
    {
        return searchHelper(data, root);
    }
    size_t size()
    {
        return sizeHelper(root);
    }
    int height()
    {
        return heightHelper(root);
    }
};

int main()
{
    Tree<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.dfs();
    tree.bfs();
    std::cout << '\n'
              << tree.size() << '\n';
}