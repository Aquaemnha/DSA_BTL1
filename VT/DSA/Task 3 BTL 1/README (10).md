# TASK 3 - FULL BTL1

## Bước 1 chạy docker giống task 1

## Bước 2 Code vào `BotkifyLinkedList.h` bằng Circular Doubly Linked List và Hiện thực `Playlist.cpp`

## Bước 3 Build và Run

```sh
# Build không memory
g++ -std=c++17 -I. -Isrc main.cpp src/Playlist.cpp tests/*.cpp -o main

# Build check memory
g++ -std=c++17 -fsanitize=address -fno-omit-frame-pointer -g -O0 -Wall -Wextra -I. -Isrc main.cpp src/Playlist.cpp tests/*.cpp -o main

# Chạy toàn bộ test
./main

# Chạy 1 test
./main --test-case=Playlist_002
```

## Bước 4 Debug nếu cần

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