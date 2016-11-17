#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

template<typename T>
class Node {
public:
    explicit Node (T t)
        : value(t), parent(NULL) {}
    explicit Node (T t, Node<T> * p)
        : value(t), parent(p) {}
    virtual ~Node(){}
    
    //setter
    void setParent(Node<T> * p) { parent = p; }
    void setValue(T t) { value = t; }

    //getter
    Node<T>* getParent() const { return parent; }
    const T& getValue() const { return value; }
private:
    T value;
    Node<T> * parent;
};

template<typename T>
class disjoint_set {
public:
    static Node<T>* Find(Node<T>* p)
    {
        if (p == NULL) throw;
        if (p->getParent() == NULL)
            return p;
        else
            return Find(p->getParent());
    }
    static Node<T>* make_set(T val)
    {
        Node<T>* p = new Node<T>(val);
        return p;
    }
    static void merge(Node<T>* n1, Node<T>* n2)
    {
        Node<T>* root1 = Find(n1);
        Node<T>* root2 = Find(n2);
        root2->setParent(root1);
    }
    static void clear_node(Node<T>* p)
    {
        if (p)
            delete p;
    }
};

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        int people, num_of_stat;
        cin >> people >> num_of_stat;
        vector<Node<int> *> members(people, NULL);
        vector<pair<int, int> > disinfo;
        for (int i = 0; i < num_of_stat; ++i)
        {
            string info;
            int index1, index2;
            cin >> info >> index1 >> index2;
            Node<int>* dset1 = NULL;
            Node<int>* dset2 = NULL;
            if (members[index1])
                dset1 = members[index1];
            else
            {
                dset1 = disjoint_set<int>::make_set(index1);
                members[index1] = dset1;
            }
            if (members[index2])
                dset2 = members[index2];
            else
            {
                dset2 = disjoint_set<int>::make_set(index2);
                members[index2] = dset2;
            }
            Node<int>* root1 = disjoint_set<int>::Find(dset1);
            Node<int>* root2 = disjoint_set<int>::Find(dset2);
            if (info.compare("ACK") == 0)
            {
                if (root1 != root2)
                {
                    // check CONTRADICTION before merge
                    disjoint_set<int>::merge(root1, root2);
                }
            }
            else
            {
                if (root1 == root2)
                    cout << "CONTRADICTION AT " << i+1 << endl;
                disinfo.push_back(make_pair(index1, index2));
            }
        }
        for (int i = 0; i < people; i++)
            disjoint_set<int>::clear_node(members[i]);
    }
}
