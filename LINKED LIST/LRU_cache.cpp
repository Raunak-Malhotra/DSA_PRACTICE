// LEETCODE 146 - LRU CACHE

#include <iostream>
#include <unordered_map>

using namespace std;

// Doubly Linked List Node
class Node {

public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v) {

        key = k;
        value = v;

        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {

private:

    int capacity;

    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

public:

    LRUCache(int cap) {

        capacity = cap;

        // Dummy nodes
        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove node from DLL
    void removeNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node right after head
    void insertAfterHead(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if(cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];

        // Move to front (Most Recently Used)
        removeNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if(cache.find(key) != cache.end()) {

            Node* existing = cache[key];

            existing->value = value;

            removeNode(existing);
            insertAfterHead(existing);

            return;
        }

        // Capacity full
        if(cache.size() == capacity) {

            Node* lru = tail->prev;

            removeNode(lru);

            cache.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key,value);

        cache[key] = newNode;

        insertAfterHead(newNode);
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1,10);
    cache.put(2,20);

    cout << cache.get(1) << endl;

    cache.put(3,30);

    cout << cache.get(2) << endl; // -1

    cache.put(4,40);

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 30
    cout << cache.get(4) << endl; // 40

    return 0;
}