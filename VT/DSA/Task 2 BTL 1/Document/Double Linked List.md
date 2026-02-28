# Double Linked List (Danh sách liên kết đôi)

## 1. Khái niệm

**Double Linked List** (danh sách liên kết đôi) là cấu trúc dữ liệu tuyến tính, trong đó mỗi node chứa:

* `data`: dữ liệu lưu trữ
* `next`: con trỏ trỏ tới node kế tiếp
* `prev`: con trỏ trỏ tới node trước đó

So với Single Linked List, Double Linked List cho phép **duyệt 2 chiều**: từ đầu → cuối và từ cuối → đầu.

![](https://prepbytes-misc-images.s3.ap-south-1.amazonaws.com/assets/1663789836593-37_Artboard%203.png)

---

## 2. Cấu trúc Node

Một node cơ bản trong Double Linked List:

```cpp
template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};
```

---

## 3. Thành phần của BotkifyDoubleLinkedList

Danh sách liên kết đôi thường quản lý bởi:

* `head`: trỏ tới node đầu tiên
* `tail`: trỏ tới node cuối cùng
* `count`: số lượng phần tử

```cpp
Node* head;
Node* tail;
int count;
```

---

## 4. Các thao tác cơ bản

### 4.1. Thêm phần tử vào cuối (add)

* Tạo node mới
* Nếu danh sách rỗng:

  * `head = tail = node`
* Nếu không:

  * `tail->next = node`
  * `node->prev = tail`
  * Cập nhật `tail = node`

**Độ phức tạp:** O(1)

---

### 4.2. Thêm phần tử tại vị trí bất kỳ (add(index, value))

* Kiểm tra chỉ số hợp lệ
* Nếu `index == 0`:

  * Chèn vào đầu, cập nhật `head`
* Nếu `index == count`:

  * Chèn vào cuối, giống hàm `add(value)`
* Ngược lại:

  * Duyệt tới node tại vị trí `index`
  * Nối node mới vào giữa hai node

**Độ phức tạp:** O(n)
*(có thể tối ưu bằng cách duyệt từ `tail` nếu index gần cuối)*

---

### 4.3. Truy cập phần tử (get)

* Kiểm tra chỉ số hợp lệ
* Nếu `index <= count / 2` → duyệt từ `head`
* Nếu `index > count / 2` → duyệt từ `tail` ngược về

**Độ phức tạp:** O(n)
*(trung bình nhanh hơn Single Linked List)*

---

### 4.4. Xóa phần tử tại vị trí (removeAt)

* Kiểm tra chỉ số hợp lệ
* Nếu xóa đầu:

  * Cập nhật `head = head->next`
  * `head->prev = nullptr`
* Nếu xóa cuối:

  * Cập nhật `tail = tail->prev`
  * `tail->next = nullptr`
* Ngược lại:

  * Nối `prev->next` với `next->prev`

**Độ phức tạp:** O(n)

---

### 4.5. Xóa phần tử theo giá trị (removeItem)

* Duyệt danh sách
* Khi tìm thấy node có `data == item`:

  * Nếu là đầu → cập nhật `head`
  * Nếu là cuối → cập nhật `tail`
  * Nếu ở giữa → nối hai node kề nhau
* Giảm `count`

**Độ phức tạp:** O(n)

---

### 4.6. Xóa toàn bộ danh sách (clear)

* Duyệt từ `head`
* Giải phóng từng node
* Đặt `head = tail = nullptr`, `count = 0`

**Độ phức tạp:** O(n)

---

### 4.7. Chuyển danh sách sang chuỗi (toString)

* Duyệt từ `head` đến `tail`
* Ghép `data` thành chuỗi, ngăn cách bằng `", "`

---

## 5. Ưu và nhược điểm

### ✅ Ưu điểm

* Duyệt được 2 chiều (forward & backward)
* Xóa node bất kỳ dễ hơn Single Linked List
* Truy cập cuối danh sách nhanh (O(1))
* Tối ưu duyệt khi index gần cuối

### ❌ Nhược điểm

* Tốn bộ nhớ hơn (thêm con trỏ `prev`)
* Cài đặt phức tạp hơn Single Linked List
* Nhiều thao tác gán con trỏ → dễ bug nếu sai

---

## 6. So sánh với Single Linked List

| Tiêu chí            | Single     | Double             |
| ------------------- | ---------- | ------------------ |
| Số con trỏ / node   | 1 (`next`) | 2 (`next`, `prev`) |
| Duyệt ngược         | ❌          | ✅                  |
| Xóa node giữa       | Khó hơn    | Dễ hơn             |
| Bộ nhớ              | Ít hơn     | Tốn hơn            |
| Độ phức tạp cài đặt | Dễ         | Trung bình         |

---
