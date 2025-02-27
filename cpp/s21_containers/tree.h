
#ifndef S21_CONTAINARS_TREE_H
#define S21_CONTAINARS_TREE_H

#include <iostream>

enum { RED, BLACK };

template <typename Key, typename T>
class RBtree
{
protected:
    struct Node;

public:
    class RBtreeIteratorBase{
        protected:
            Node* current;

        public:      
            friend class RBtree<Key, T>;

            RBtreeIteratorBase() : current(nullptr) {}
            RBtreeIteratorBase(Node* node) : current(node) {}

            void next() {
                if(current->ibnYamina != nil){
                    current = current->ibnYamina;
                    if(current->ibnShimala != nil){
                    current = getmin(current);
                    }
                }  
                else {
                    Node* ubi = current->ubi;
                    Node* node = current;
                    while (ubi != nil && ubi->ibnYamina == node)
                    {
                        node = ubi;
                        ubi = ubi->ubi;
                    }
                    if(ubi != nil){
                        current = node;
                    }
                }
            }
            void prev(){
                if(current->ibnShimala != nil){
                    current = current->ibnShimala;
                    if(current->ibnYamina != nil){
                        current = getmax(current);
                    }
                }
                else{
                    Node* ubi = current->ubi;
                    Node* node = current;
                    while (ubi != nil && ubi->ibnShimala == node)
                    {   
                        node = ubi;
                        ubi = ubi->ubi;
                    }
                    if(node != nil){
                        current = node;
                    }
                }
            }

    };

    class RBTreeIterator : public RBtreeIteratorBase{
        public:
            using RBtreeIteratorBase::RBtreeIteratorBase;
            using RBtreeIteratorBase::current;

            std::pair<Key, T> operator*() { return value_type(current->key, current->value); }
            std::pair<Key, T>* operator->() { return &(operator*()); }

            RBTreeIterator operator++() {
                this->next();
                return *this;
            }
            RBTreeIterator operator++(int) {
                RBTreeIterator temp = *this;
                this->next();
                return temp;
            }
            RBTreeIterator operator--() {
                this->prev();
                return *this;
            }
            RBTreeIterator operator--(int) {
                RBTreeIterator temp = *this;
                this->prev();
                return temp;
            }
            
            bool operator!=(const RBTreeIterator& other) { return current != other.current; }

    };

    class RBTreeConstIterator : public RBtreeIteratorBase{
        public:
            using RBtreeIteratorBase::RBtreeIteratorBase;
            using RBtreeIteratorBase::current;

            RBTreeIterator operator++() {
                this->next();
                return *this;
            }
            RBTreeIterator operator++(int) {
                RBTreeIterator temp = *this;
                this->next();
                return temp;
            }
            RBTreeIterator operator--() {
                this->prev();
                return *this;
            }
            RBTreeIterator operator--(int) {
                RBTreeIterator temp = *this;
                this->prev();
                return temp;
            }

    };
    
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using refernce = value_type&;
    using const_reference = const value_type&;
    using size_type = size_t;
    using iterator = RBTreeIterator;
    using const_iterator = RBTreeConstIterator;



    RBtree();
    ~RBtree();

    void clear();
    iterator begin();
    iterator end();
    std::pair<iterator, bool> insert(const value_type& value);

protected:
    struct Node{
        key_type key = 0;
        mapped_type value;
        Node* ubi = nullptr; // отец
        Node* ibnShimala = nullptr; // левый сын
        Node* ibnYamina = nullptr; // правый сын
        int color = BLACK;
        int Bheigth = 0;

        Node() {}
        Node(key_type x, mapped_type y) : key(x), value(y), color(RED) { };
        Node(key_type x, mapped_type y, Node* ub) : key(x), value(y), ubi(ub), color(RED) { };
        Node(key_type x, mapped_type y, Node *ibnl, Node *ibnr, Node* ub) : key(x), value(y), ibnShimala(ibnl), ibnYamina(ibnr), ubi(ub), color(RED) { };
    };

    iterator find(const key_type k);
    Node* getmax(Node* node);
    Node* getmin(Node* node);
    void DeleteNode(Node* node, key_type k);
    void DeleteTree(Node* node);
    Node* insert_node(Node* node, key_type k, mapped_type val);

    Node* root;
    Node* nil;
    size_type size = 0;

};

#endif
