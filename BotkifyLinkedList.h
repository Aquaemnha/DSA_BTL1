#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

template <class T>
class BotkifyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* extra;

        Node();
        Node(const T& data, Node* next = nullptr, Node* extra = nullptr) : data(data), next(next), extra(extra){}
    };

    Node* head;
    Node* tail;
    int count;
    Node* curr; //Phục vụ cho việc nắm được vị trí hiện tại của bài hát

public:
    BotkifyLinkedList(Node* head = nullptr, Node* tail = nullptr, int count = 0, Node* curr =  nullptr) : head(head), tail(tail), count(count), curr(curr){}
    BotkifyLinkedList(const BotkifyLinkedList& other) { //Deep copy
        head = nullptr;
        tail = nullptr;
        curr = nullptr;
        count = 0;
    
        Node* temp = other.head;
        while (temp != nullptr) {
            this->add(temp->data); // Dùng hàm add có sẵn để tạo node mới
            temp = temp->next;
        }
        // Thiết lập curr cho bản sao (có thể trỏ về đầu hoặc vị trí tương ứng)
        this->curr = this->head; 
    }
    ~BotkifyLinkedList(){ //O(n)
        clear();
    }

    void add(T e){//Cuối ds //O(1)
        if(empty()){
            head = new Node(e);
            tail = head;
            curr = head;
            count++;
            return;
        }
        Node* tmp = tail;
        tail -> next = new Node(e);
        tail = tail -> next;
        tail -> extra = tmp;
        count++;
    }
    void addHead(T e){//Đầu ds //O(1)
        if(empty()){ 
            head = new Node(e);
            tail = head;
            curr = head;
            count++;
            return;
        }
        Node* tmp = new Node(e);
        tmp -> next = head;
        head -> extra = tmp;
        head = tmp;
        count++;

    }
    void add(int index, T e){//At index //O(n)
        if(index < 0 || index > count){
            throw out_of_range("Index is invalid!");
        }
        if(empty()){
            head = new Node(e);
            tail = head;
            curr = head;
            count++;
            return;
        }
        if (index == 0){
            addHead(e);
            return;
        }
        if (index == count){
            add(e);
            return;
        }
        Node* trc = nullptr;
        Node* sau = head;
        Node* tmp = new Node(e);
        for(int i = 0; i < index; i++){
            trc = sau;
            sau = sau -> next;
        }
        tmp -> next = sau;
        trc -> next = tmp;
        tmp -> extra = trc;
        sau -> extra = tmp;
        count++;
    }

    T removeHead(){//Xóa đầu //O(1)
        if(empty()) throw out_of_range("Index is invalid!");
        T result;
        if (curr == head) {
            if (count == 1) curr = nullptr;
            else curr = head->next;
        }
        Node* tmp = head;
        if (count == 1){
            result = head -> data;
            delete head;
            curr = nullptr;
            head = nullptr;
            tail = nullptr;
            count = 0;
            return result;
        }
        head = head -> next;
        head -> extra = nullptr;
        result = tmp -> data;
        delete tmp;
        count--;
        return result;
    }
    T removeTail(){// Xóa cuối //O(1)
        if(empty()) throw out_of_range("Index is invalid!");
        T result;
        if (curr == tail) {
            if (count == 1) curr = nullptr;
            else curr = head;
        }
        Node* tmp = tail;
        if(count == 1){
            result = tail -> data;
            delete tail;
            curr = nullptr;
            tail = nullptr;
            head = nullptr;
            count = 0;
            return result;
        }
        result = tail -> data;
        tail = tail -> extra;
        tail -> next = nullptr;
        delete tmp;
        count--;
        return result;        
    }
    T removeAt(int index){//O(n)
        if(index < 0 || index >= count){
            throw out_of_range("Index is invalid!");
        }
        if(empty()) throw out_of_range("Index is invalid!");
        if(index == 0) return removeHead();
        if(index == count - 1) return removeTail();
        T result;
        Node* trc = head;
        Node* sau = head;
        Node* tmp = head;
        for(int i = 0; i < index; i++){
            tmp = tmp -> next;
        }
        if (curr == tmp) {
            curr = tmp->next;
        }
        trc = tmp -> extra;
        sau = tmp -> next;
        trc -> next = sau;
        sau -> extra = trc;
        result = tmp -> data;
        delete tmp;
        count--;
        return result;
    }
    bool removeItem(T item){//O(n)
        if(empty()) return 0;
        int pos = 0;
        Node* tmp = head;
        while(tmp != nullptr && tmp -> data != item){
            tmp = tmp -> next;
            pos++;
        }
        if(pos < 0 || pos >= count){
            return 0;
        }
        removeAt(pos);
        return 1;       
    }

    bool empty() const{ //O(1)
        if (head == nullptr) return 1;
        return 0;
    }
    int size() const{ //O(1)
        return count;
    }
    void clear(){ //O(n)
        while(head != nullptr){
            Node* tmp = head;
            head = head -> next;
            delete tmp;
        }
        curr = nullptr;
        tail = nullptr;
        count = 0;        
    }

    T* getDataArray(){ //Phục vụ độ phức tạp O(n) //Xài xong nhớ xóa
        Node* tmp = head;
        T* arrayData = new T[count];
        for (int i = 0; tmp != nullptr; i++){
            arrayData[i] = tmp -> data;
            tmp = tmp -> next;
        }
        return arrayData;
    }

    T& get(int index) const{ //O(n)
        if(index < 0 || index >= count){
            throw out_of_range("Index is invalid!");
        }
        if(empty()) throw out_of_range("Index is invalid!");
        if(index == 0) return head -> data;
        if (index == count - 1) return tail -> data;
        Node* tmp = head;
        for (int i = 0; i < index; i++){
            tmp = tmp -> next;
        }
        return tmp -> data;
    } 

    void moveCurr(int code){
        if (head == nullptr) throw out_of_range("Index is invalid!");
        // Nếu chưa có bài nào đang phát
        if (curr == nullptr) {
            if (code == 1) curr = head;
                else if (code == 0) curr = tail;
            return;
        }
        if (code == 1){ //Lên 1 bước
            if (curr -> next == nullptr){
                curr = head;
                return;
            }
            curr = curr -> next;
        }
        if (code == 0){ //Lùi 1 bước
            if (curr -> extra == nullptr){
                curr = tail;
                return;
            }
            curr = curr -> extra;
        }
    }

    T& getCurr(){
        if (head == nullptr || curr == nullptr) throw out_of_range("Index is invalid!"); 
        return curr -> data;
    }

    string toString() const{ //O(n)
        stringstream result;
        if(empty()) return result.str();
        Node* tmp = head;
        while (tmp != nullptr){
            result << tmp -> data;
            if(tmp -> next != nullptr) result << ",";
            tmp = tmp -> next;
        }
        return result.str();
    }
};
#endif // BOTKIFY_LINKED_LIST_H
