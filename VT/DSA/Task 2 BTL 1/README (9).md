# TASK 2 - Tìm danh sách liên kết phù hợp nhất và hiện thực

| Mô tả                         | Link                                                                     |
| --------------------------- | ------------------------------------------------------------------------ |
| Single Linked List          | [Single Linked List.md](Document/Single%20Linked%20List.md)                     |
| Double Linked List          | [Double Linked List.md](Document/Double%20Linked%20List.md)                     |
| Circular Doubly Linked List | [Circular Doubly Linked List.md](Document/Circular%20Doubly%20Linked%20List.md) |


**🧪 Run test**

```sh
# Build không memory
g++ -std=c++17 -I. -Isrc main.cpp tests/*.cpp -o main

# Build check memory
g++ -std=c++17 -fsanitize=address -fno-omit-frame-pointer -g -O0 -Wall -Wextra -I. -Isrc main.cpp tests/*.cpp -o main

# Chạy toàn bộ test
./main

# Chạy 1 test
./main --test-case=BotkifyCycleDoubleLinkedList_002
```

**📊 So sánh các cấu trúc danh sách**

| Tiêu chí              | Array                             | Single Linked List | Double Linked List | Circular Linked List | Circular Doubly Linked List |
| --------------------- | --------------------------------- | ------------------ | ------------------ | -------------------- | --------------------------- |
| Cấp phát bộ nhớ       | Liên tục                          | Rời rạc            | Rời rạc            | Rời rạc              | Rời rạc                     |
| Kích thước            | Cố định (hoặc dynamic với vector) | Linh hoạt          | Linh hoạt          | Linh hoạt            | Linh hoạt                   |
| Truy cập theo index   | O(1)                              | O(n)               | O(n)               | O(n)                 | O(n)                        |
| Thêm/xóa ở đầu        | O(n)                              | O(1)               | O(1)               | O(1)                 | O(1)                        |
| Thêm/xóa ở cuối       | O(1)                             | O(n) / O(1)      | O(1)               | O(n) / O(1)        | O(1)                        |
| Thêm/xóa ở giữa       | O(n)                              | O(n)               | O(n)               | O(n)                 | O(n)                        |
| Duyệt xuôi            | ✅                                 | ✅                  | ✅                  | ✅                    | ✅                           |
| Duyệt ngược           | ❌                                 | ❌                  | ✅                  | ❌                    | ✅                           |
| Vòng tròn             | ❌                                 | ❌                  | ❌                  | ✅                    | ✅                           |
| Con trỏ mỗi node      | 0                                 | 1 (`next`)         | 2 (`next`, `prev`) | 1 (`next`)           | 2 (`next`, `prev`)          |
| Bộ nhớ phụ            | Thấp                              | Trung bình         | Cao                | Trung bình           | Cao                         |
| Dễ cài đặt            | Rất dễ                            | Dễ                 | Trung bình         | Trung bình           | Khó                         |
| Dễ debug              | Rất dễ                            | Dễ                 | Trung bình         | Khó                  | Khó                         |
| Nguy cơ loop vô hạn   | ❌                                 | ❌                  | ❌                  | ⚠️                   | ⚠️                          |
| Tối ưu duyệt gần cuối | ❌                                 | ❌                  | ✅                  | ❌                    | ✅                           |

---
<p align="center">
  <a href="https://www.facebook.com/Shiba.Vo.Tien">
    <img src="https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook"/>
  </a>
  <a href="https://www.tiktok.com/@votien_shiba">
    <img src="https://img.shields.io/badge/TikTok-000000?style=for-the-badge&logo=tiktok&logoColor=white" alt="TikTok"/>
  </a>
  <a href="https://www.facebook.com/groups/khmt.ktmt.cse.bku?locale=vi_VN">
    <img src="https://img.shields.io/badge/Facebook%20Group-4267B2?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook Group"/>
  </a>
  <a href="https://www.facebook.com/CODE.MT.BK">
    <img src="https://img.shields.io/badge/Page%20CODE.MT.BK-0057FF?style=for-the-badge&logo=facebook&logoColor=white" alt="Facebook Page"/>
  </a>
  <a href="https://github.com/VoTienBKU">
    <img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub"/>
  </a>
</p>