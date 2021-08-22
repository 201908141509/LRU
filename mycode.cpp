struct Node{
        int key,value;
        Node *pre,*next;
        Node(int a,int b):key(a),value(b),pre(nullptr),next(nullptr){}
        Node():key(0),value(0),pre(nullptr),next(nullptr){}
    };
class LRUCache {
private:
    unordered_map<int,Node*> hash;
    Node *head,*tail;
    int max_size;
    int size;
public:
    LRUCache(int capacity) {
        max_size=capacity;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->pre=head;
        size=0;
    }
    
    int get(int key) {
        if(hash.count(key)==0)
        {
            return -1;
        }
        Node *node=hash[key];
        move_to_head(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!hash.count(key))
        {
            Node *node=new Node(key,value);
            hash[key]=node;
            add_to_head(node);
            size++;
            if(size>max_size)
            {
                size--;
                hash.erase(tail->pre->value);
                remove_node(tail->pre);
            }
        }
        else
        {
            Node *node=hash[key];
            move_to_head(node);
            hash[key]->value=value;
        }
    }
    void add_to_head(Node *node)
    {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
    void move_to_head(Node *node)
    {
        remove_node(node);
        head->next->pre=node;
        node->next=head->next;
        head->next=node;
        node->pre=head;
    }
    void remove_node(Node *node)
    {
        node->pre->next=node->next;
        node->next->pre=node->pre;
        delete node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */