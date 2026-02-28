# Circular Doubly Linked List (Danh sách liên kết đôi vòng)

## 1. Khái niệm

**Circular Doubly Linked List** là biến thể của Double Linked List, trong đó:

* Node cuối (`tail`) **trỏ về node đầu (`head`)**
* Node đầu (`head`) có con trỏ `prev` **trỏ về node cuối (`tail`)**

👉 Danh sách tạo thành **vòng tròn khép kín**, không có `nullptr` ở hai đầu.

![](https://www.alphacodingskills.com/imgfiles/circular-doubly-linked-list.PNG)

---

## 2. Cấu trúc Node

Mỗi node chứa 3 thành phần:

```cpp
template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(this), prev(this) {}
};
```

> Khi khởi tạo node đơn lẻ, `next` và `prev` đều trỏ về chính nó.

---

## 3. Thành phần của BotkifyCycleDoubleLinkedList

Danh sách được quản lý bởi:

* `head`: trỏ tới node đầu tiên
* `tail`: trỏ tới node cuối cùng
* `count`: số lượng phần tử

```cpp
Node* head;
Node* tail;
int count;
```

**Invariant quan trọng:**

```cpp
tail->next == head
head->prev == tail
```

---

## 4. Các thao tác cơ bản

### 4.1. Thêm phần tử vào cuối (add)

Các bước:

1. Tạo node mới
2. Nếu danh sách rỗng:

   * `head = tail = node`
   * `node->next = node`
   * `node->prev = node`
3. Nếu không rỗng:

   * `node->prev = tail`
   * `node->next = head`
   * `tail->next = node`
   * `head->prev = node`
   * Cập nhật `tail = node`

**Độ phức tạp:** O(1)

---

### 4.2. Thêm phần tử tại vị trí bất kỳ (add(index, value))

1. Kiểm tra chỉ số hợp lệ
2. Nếu `index == 0` (chèn đầu):

   * Nối node mới trước `head`
   * Cập nhật `head`
3. Nếu `index == count` (chèn cuối):

   * Gọi lại `add(value)`
4. Ngược lại:

   * Duyệt tới node tại vị trí `index`
   * Nối node mới giữa hai node kề nhau

**Độ phức tạp:** O(n)

---

### 4.3. Truy cập phần tử (get)

* Kiểm tra chỉ số hợp lệ
* Nếu `index <= count / 2` → duyệt xuôi từ `head`
* Nếu `index > count / 2` → duyệt ngược từ `tail`

**Độ phức tạp:** O(n)
*(trung bình nhanh hơn Single Linked List)*

---

### 4.4. Xóa phần tử tại vị trí (removeAt)

1. Kiểm tra chỉ số hợp lệ
2. Nếu danh sách có **1 phần tử**:

   * Xóa node đó
   * `head = tail = nullptr`
3. Nếu xóa đầu (`index == 0`):

   * `head = head->next`
   * `head->prev = tail`
   * `tail->next = head`
4. Nếu xóa cuối (`index == count - 1`):

   * `tail = tail->prev`
   * `tail->next = head`
   * `head->prev = tail`
5. Nếu xóa giữa:

   * Nối `prev->next` với `next->prev`

**Độ phức tạp:** O(n)

---

### 4.5. Xóa phần tử theo giá trị (removeItem)

* Duyệt danh sách từ `head`
* Khi tìm thấy node có `data == item`:

  * Nếu là node duy nhất → reset danh sách
  * Nếu là `head` → cập nhật `head`
  * Nếu là `tail` → cập nhật `tail`
  * Nếu ở giữa → nối hai node kề nhau
* Giảm `count`

**Độ phức tạp:** O(n)

---

### 4.6. Xóa toàn bộ danh sách (clear)

* Nếu rỗng → return
* Duyệt vòng từ `head`
* Xóa từng node cho đến quay lại `head`
* Đặt `head = tail = nullptr`, `count = 0`

**Độ phức tạp:** O(n)

---

### 4.7. Chuyển danh sách sang chuỗi (toString)

* Nếu rỗng → trả về chuỗi rỗng
* Duyệt từ `head`
* In từng phần tử
* Dừng khi quay lại `head`

Ví dụ:

```text
10, 20, 30, 40
```

---

## 5. Ưu và nhược điểm

### ✅ Ưu điểm

* Duyệt **liên tục không cần null check**
* Phù hợp cho bài toán **xoay vòng (round-robin)**
* Duyệt được 2 chiều
* Truy cập đầu/cuối nhanh O(1)
* Không bị “đứt” danh sách khi ở hai đầu

---

### ❌ Nhược điểm

* Cài đặt **phức tạp nhất** trong 3 loại
* Dễ bug vòng lặp vô hạn nếu sai điều kiện dừng
* Debug khó hơn do không có `nullptr`
* Tốn bộ nhớ hơn Single Linked List

---

## 6. So sánh 3 loại Linked List

| Tiêu chí            | Single | Double     | Cycle Double         |
| ------------------- | ------ | ---------- | -------------------- |
| next                | ✅      | ✅          | ✅                    |
| prev                | ❌      | ✅          | ✅                    |
| Vòng tròn           | ❌      | ❌          | ✅                    |
| Duyệt ngược         | ❌      | ✅          | ✅                    |
| Null ở đầu/cuối     | ✅      | ✅          | ❌                    |
| Độ phức tạp cài đặt | Dễ     | Trung bình | Khó                  |
| Ứng dụng            | Cơ bản | Undo/Redo  | Scheduler, Game loop |

---
