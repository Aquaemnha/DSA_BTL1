# Single Linked List (Danh sách liên kết đơn)

## 1. Khái niệm

**Single Linked List** (danh sách liên kết đơn) là một cấu trúc dữ liệu tuyến tính, trong đó mỗi phần tử (node) gồm:

* `data`: dữ liệu được lưu trữ
* `next`: con trỏ trỏ tới node kế tiếp trong danh sách

Khác với mảng (array), các phần tử trong linked list **không nằm liên tiếp trong bộ nhớ** mà được liên kết thông qua các con trỏ.

![](https://images.viblo.asia/9230ca44-0288-47b3-8dd9-4f390a10223f.png)

---

## 2. Cấu trúc Node

Một node cơ bản trong Single Linked List:

```cpp
template <class T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};
```

---

## 3. Thành phần của Single Linked List

Một danh sách liên kết đơn thường quản lý bởi:

* `head`: con trỏ trỏ tới node đầu tiên
* `tail`: con trỏ trỏ tới node cuối cùng
* `count`: số lượng phần tử trong danh sách

```cpp
Node* head;
Node* tail;
int count;
```

---

## 4. Các thao tác cơ bản

### 4.1. Thêm phần tử vào cuối (add)

* Tạo node mới
* Nếu danh sách rỗng → `head = tail = node`
* Nếu không → `tail->next = node`, cập nhật `tail`

**Độ phức tạp:** O(1)

---

### 4.2. Thêm phần tử tại vị trí bất kỳ (add(index, value))

* Kiểm tra chỉ số hợp lệ
* Nếu `index == 0` → thêm vào đầu
* Nếu `index == count` → thêm vào cuối
* Ngược lại → duyệt tới node trước vị trí cần chèn

**Độ phức tạp:** O(n)

---

### 4.3. Truy cập phần tử (get)

* Kiểm tra chỉ số hợp lệ
* Duyệt từ `head` tới vị trí `index`

**Độ phức tạp:** O(n)

---

### 4.4. Xóa phần tử tại vị trí (removeAt)

* Kiểm tra chỉ số hợp lệ
* Nếu xóa đầu danh sách → cập nhật `head`
* Nếu xóa giữa/cuối → nối node trước với node sau
* Nếu xóa phần tử cuối → cập nhật `tail`

**Độ phức tạp:** O(n)

---

### 4.5. Xóa phần tử theo giá trị (removeItem)

* Duyệt danh sách
* Khi tìm thấy phần tử cần xóa:

  * Nếu là node đầu → cập nhật `head`
  * Nếu là node giữa/cuối → cập nhật liên kết
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

* Duyệt từng node
* Ghép dữ liệu vào chuỗi, phân tách bằng `", "`

---

## 5. Ưu và nhược điểm

### ✅ Ưu điểm

* Kích thước linh hoạt (không cần cấp phát sẵn như mảng)
* Thêm/xóa đầu danh sách nhanh O(1)
* Không lãng phí bộ nhớ do mảng dư thừa

### ❌ Nhược điểm

* Truy cập ngẫu nhiên chậm (O(n))
* Tốn thêm bộ nhớ cho con trỏ `next`
* Không duyệt ngược được danh sách

---

## 6. So sánh với cấu trúc khác

| Cấu trúc           | Truy cập | Thêm/Xóa đầu | Thêm/Xóa giữa | Bộ nhớ  |
| ------------------ | -------- | ------------ | ------------- | ------- |
| Array              | O(1)     | O(n)         | O(n)          | Ít      |
| Single Linked List | O(n)     | O(1)         | O(n)          | Tốn hơn |

---