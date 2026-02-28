#include "Playlist.h"

// =======================
// Song implementation
// =======================

Song::Song(int id,
           string title,
           string artist,
           string album,
           int duration,
           int score,
           string url)
{
    // TODO: Student implementation
    this -> id = id;
    this -> title = title;
    this -> artist = artist;
    this -> album = album;
    this -> duration = duration;
    this -> score = score;
    this -> url = url;
}

int Song::getID() const //O(1)
{
    // TODO: Student implementation
    return id;
}

int Song::getDuration() const //O(1)
{
    // TODO: Student implementation
    return duration;
}

int Song::getScore() const //O(1)
{
    // TODO: Student implementation
    return score;
}

string Song::toString() const //O(1)
{
    // TODO: Student implementation
    return title + "-" + artist;
}

// =======================
// Playlist implementation
// =======================

Playlist::Playlist(string name) //O(1)
{
    // TODO: Student implementation
    this -> name = name;
    this -> size = 0;
}
Playlist::Playlist(const Playlist& other) : lstSong(other.lstSong) {
    this->name = other.name;
    this->size = other.size;
    // Khi gọi lstSong(other.lstSong), nó sẽ tự động gọi Copy Constructor 
    // của BotkifyLinkedList mà chúng ta vừa viết ở trên.
}

int Playlist::getSize() const //O(1)
{ 
    // TODO: Student implementation
    return lstSong.size();
}

bool Playlist::empty() const //O(1)
{
    // TODO: Student implementation
    if (lstSong.empty()) return true;
    return false;
}

void Playlist::clear() //O(n)
{
    // TODO: Student implementation
    lstSong.clear();
    this -> size = 0;
}

void Playlist::addSong(Song* s) //O(n)
{
    // TODO: Student implementation
    lstSong.add(s);
    this -> size = lstSong.size();
}

void Playlist::removeSong(int index) //O(n)
{
    // TODO: Student implementation
    if(index < 0 || index >= lstSong.size()){
        throw out_of_range("Index is invalid!");
    }
    if(empty()) throw out_of_range("Index is invalid!");
    lstSong.removeAt(index);
    this -> size = lstSong.size();
}

Song* Playlist::getSong(int index) const //O(n)
{
    // TODO: Student implementation
    if(index < 0 || index >= lstSong.size()){
        throw out_of_range("Index is invalid!");
    }
    if(empty()) throw out_of_range("Index is invalid!");
    return lstSong.get(index);
}

BotkifyLinkedList<Song*> Playlist::getlstSong(){ //O(1)
    return lstSong;
}
// =======================
// Playing control
// =======================

Song* Playlist::playNext() //O(1)
{
    // TODO: Student implementation
    if (lstSong.size() == 0) throw out_of_range("Index is invalid!");
    lstSong.moveCurr(1);
    return lstSong.getCurr();
}

Song* Playlist::playPrevious() //O(1)
{
    // TODO: Student implementation
    if (lstSong.size() == 0) throw out_of_range("Index is invalid!");
    lstSong.moveCurr(0);
    return lstSong.getCurr();
}

// =======================
// Score-related
// =======================

int Playlist::getTotalScore() //O(n)
{
    // TODO: Student implementation
    //Motonic stack tìm vùng
    if(lstSong.empty()) return 0;
    long long sum = 0;
    int top = -1;
    Song** arrayData = lstSong.getDataArray();
    long long* arraySum = new long long[lstSong.size()]; //Tổng 1 mảng con bất kỳ từ node đầu tiên đến r
    long long* subArraySum = new long long[lstSong.size()]; //Tổng nhiều mảng con bất kỳ từ 1 tới r (dựa trên mảng arraySum)
    int* left = new int[lstSong.size()]; //Mảng lưu phạm vi bên trái của mỗi node
    int* right = new int[lstSong.size()]; //Mảng lưu phạm vi bên phải của mỗi node
    int* stack = new int[lstSong.size()]; //Dùng để lưu node nhỏ nhất đến lớn dần
    long long* songScore = new long long[lstSong.size()];
    for (int i = 0; i < lstSong.size(); i++){ //Score
        songScore[i] = arrayData[i]->getScore(); //O(n)
    }
    for (int i = 0; i < lstSong.size(); i++){ //Left //O(n)
        if(top == -1){//Phần tử duy nhất của stack
            stack[++top] = i;
            left[i] = -1;
            continue;
        }
        if(songScore[i] > songScore[stack[top]]){//Nếu bên trái nhỏ bên phải
            left[i] = stack[top];
            stack[++top] = i;
            continue;
        }
        else{//Ngược lại
            top--;
            i--;
            if(i < 0) break;
            continue;
        }
    }
    top = lstSong.size();
    delete [] stack;
    stack = new int[lstSong.size()];
    for (int i = lstSong.size() - 1; i >= 0; i--){ //Right //O(n)
        if(top == lstSong.size()){//Phần tử duy nhất của stack
            stack[--top] = i;
            right[i] = lstSong.size();
            continue;
        }
        if(songScore[i] >= songScore[stack[top]]){//Nếu bên phải nhỏ hơn bên trái
            right[i] = stack[top];
            stack[--top] = i;
            continue;
        }
        else{ //Ngược lại
            top++;
            i++;
            if(i >= lstSong.size()) break;
            continue;
        }
    }
    for(int i = 0; i < lstSong.size(); i++){ //arraySum //O(n)
        if(i == 0){
            arraySum[i] = songScore[i];
            continue;
        }
        arraySum[i] = songScore[i] + arraySum[i - 1];
    }
    for(int i = 0; i < lstSong.size(); i++){ //subArraySum //O(n)
        if(i == 0){
            subArraySum[i] = arraySum[i];
            continue;
        }
        subArraySum[i] = arraySum[i] + subArraySum[i - 1];        
    }
    for(int i = 0; i < lstSong.size(); i++){ //O(n)
        int countRight = right[i] - i;
        int countLeft = i - left[i];
        long long A, B, C, D;
        if (right[i] - 1 < 0) A = 0;
        else A = subArraySum[right[i] - 1];
        if(i - 1 < 0) B = 0;
        else B = subArraySum[i - 1];
        if (left[i] == - 1 || left[i] - 1 < 0) D = 0;
        else D = subArraySum[left[i] - 1];
        sum += songScore[i] * (countLeft * (A - B) - countRight * (B - D));
        //sum += countLeft * (subArraySum[righti - 1] - subArraySum[i - 1]) - countRight * (subArraySum[i - 1] - subArraySum[lefti - 1]);
    }
    delete[] arrayData; // BotkifyLinkedList cấp phát cái này
    delete[] arraySum;
    delete[] subArraySum;
    delete[] left;
    delete[] right;
    delete[] stack;
    delete[] songScore;
    return (int)sum;
}

bool Playlist::compareTo(Playlist p, int numSong) //O(n)
{
    // TODO: Student implementation
    //Motonic Dequeue - sliding window
    if(numSong > lstSong.size() || numSong > p.getSize() || numSong <= 0) return false;
    double pointA = 0;
    double pointB = 0;
    int stepA = lstSong.size() - numSong + 1;
    int stepB = p.getSize() - numSong + 1;
    long long* dequeueA = new long long[lstSong.size()]; //dequeue này lưu index
    long long* dequeueB = new long long[p.getSize()]; //dequeue này lưu index
    long long* songScoreA = new long long[lstSong.size()];
    long long* songScoreB = new long long[p.getSize()];
    Song** arrayDataA = lstSong.getDataArray();
    Song** arrayDataB = p.getlstSong().getDataArray();
    for (int i = 0; i < lstSong.size(); i++){ //ScoreA
        songScoreA[i] = arrayDataA[i]->getScore(); //O(n)
    }
    for (int i = 0; i < p.getSize(); i++){ //ScoreB
        songScoreB[i] = arrayDataB[i]->getScore(); //O(n)
    }
    int head = 0;
    int tail = -1;
    for (int i = 0; i < lstSong.size(); i++){ //Xử lý mảng A //O(n*numSong)
        while(tail - head >= 0 && songScoreA[i] > songScoreA[dequeueA[tail]]){ //Phần tử kế tiếp lớn hơn top queue;
            tail--;
        }        
        if(tail - head >= 0 && songScoreA[i] <= songScoreA[dequeueA[tail]]){
            dequeueA[++tail] = i;
        }
        if(tail - head < 0){ //DS rỗng
            dequeueA[head] = i;
            tail = head;
        }        
        if(i >= numSong - 1){//Lấy max liên tục khi cửa sổ đủ lần đầu và bắt đầu trượt
            if(dequeueA[head] <= i - numSong) head++; //Slide
            pointA += songScoreA[dequeueA[head]];
            continue;
        }
    }
    head = 0;
    tail = -1;    
    for (int i = 0; i < p.getSize(); i++){ //Xử lý mảng B //O(n*numSong)
        while(tail - head >= 0 && songScoreB[i] > songScoreB[dequeueB[tail]]){ //Phần tử kế tiếp lớn hơn top queue;
            tail--;
        }        
        if(tail - head >= 0 && songScoreB[i] <= songScoreB[dequeueB[tail]]){
            dequeueB[++tail] = i;
        }
        if(tail - head < 0){ //DS rỗng
            dequeueB[head] = i;
            tail = head;
        }        
        if(i >= numSong - 1){//Lấy max liên tục khi cửa sổ đủ lần đầu và bắt đầu trượt
            if(dequeueB[head] <= i - numSong) head++; //Slide
            pointB += songScoreB[dequeueB[head]];
            continue;
        }
    }   
    pointA = pointA / stepA;
    pointB = pointB / stepB;
    delete[] arrayDataA;
    delete[] arrayDataB;
    delete[] dequeueA;
    delete[] dequeueB;
    delete[] songScoreA;
    delete[] songScoreB;
    if(pointA >= pointB) return true;    
    return false;
}

// =======================
// Advanced playing modes
// =======================

void Playlist::playRandom(int index)
{
    // TODO: Student implementation
    // Motonic stack tìm vùng
    //Trải mảng *2 để nó thành vòng tròn
    if (lstSong.empty() || index < 0 || index >= lstSong.size()) {
        return;
    }
    if(lstSong.empty()) return;
    int top = -1;
    Song** arrayData = lstSong.getDataArray();
    int* left = new int[lstSong.size()]; //Mảng lưu phạm vi bên trái của mỗi node
    int* right = new int[lstSong.size()]; //Mảng lưu phạm vi bên phải của mỗi node
    int* stack = new int[lstSong.size()]; //Dùng để lưu node nhỏ nhất đến lớn dần
    long long* songDuration = new long long[lstSong.size()];
    Song** result = new Song*[lstSong.size()]; //Lưu các bài hát được phát
    for (int i = 0; i < lstSong.size(); i++){ //Score
        songDuration[i] = arrayData[i]->getDuration(); //O(n)
    }
    for (int i = 0; i < lstSong.size(); i++){ //Left //O(n)
        if(top == -1){//Phần tử đầu tiên
            stack[++top] = i;
            left[i] = -1;
            continue;
        }
        if(songDuration[i] < songDuration[stack[top]]){//Nếu bên phải nhỏ hơn bên trái
            left[i] = stack[top];
            stack[++top] = i;
            continue;
        }
        else{ //Ngược lại
            top--;
            i--;
            if(i < 0) break;
            continue;
        }
    }
    top = lstSong.size();
    for (int i = lstSong.size() - 1; i >= 0; i--){ //Right //O(n)
        if(top == lstSong.size()){//Phần tử đầu tiên
            stack[--top] = i;
            right[i] = lstSong.size();
            continue;
        }
        if(songDuration[i] < songDuration[stack[top]]){//Nếu bên trái nhỏ hơn/ bằng bên phải
            right[i] = stack[top];
            stack[--top] = i;
            continue;
        }
        else{ //Ngược lại
            top++;
            i++;
            if(i > lstSong.size()) break;
            continue;
        }
    }
    int curr = index;
    int count = 0;
    for (int i = 0; i < lstSong.size(); i++){
        result[i] = arrayData[curr];
        count++;
        if(left[curr] == -1 && right[curr] == lstSong.size()) break;
        if(left[curr] == -1){
            curr = right[curr];
            continue;
        }
        else if(right[curr] == lstSong.size()){
            curr = left[curr];
            continue;
        }
        if((curr) - left[curr] < right[curr] - curr) curr = left[curr];
        else curr = right[curr];
    }
    for (int i = 0; i < count; i++){
        cout << result[i]->toString();
        if (i < count - 1) {
            cout << ","; // Chỉ in dấu phẩy nếu chưa phải bài cuối cùng
        }
    }
    delete [] arrayData;
    delete[] left;
    delete[] right;
    delete[] stack;
    delete[] songDuration;
    delete[] result;
}

int Playlist::playApproximate(int step) //O(N ∗step).
{
    // TODO: Student implementation
    //Dynamic Programming
    if(lstSong.empty()) return 0;
    int result;
    Song** arrayData = lstSong.getDataArray();
    long long* songDuration = new long long[lstSong.size()];
    for (int i = 0; i < lstSong.size(); i++){ //Score
        songDuration[i] = arrayData[i]->getDuration(); //O(n)
    }
    long long* bestPath = new long long[lstSong.size()];
    for (int i = 0; i < lstSong.size(); i++){ //ĐI nhưng không thử, mỗi bestPath[i] sẽ được lựa chọn từ step + 1 cách hoặc ít hơn trước đó rồi lựa ra cái phù hợp nhất đưa vào bestPath[i]
        if (i == 0){
            bestPath[i] = 0;
            continue;
        }
        int j;
        int k = i - 1 - step; //Nhằm phục vụ việc so sánh mà cập nhật min lần đầu
        long long min;
        if (k < 0){
            j = 0;
            k = 0;
        }
        else j = k;
        for (j; j < i; j++){
            long long tmp = bestPath[j] + abs(songDuration[i] - songDuration[j]);
            if (j == k){
                min = tmp;
                continue;
            }
            if (min > tmp) min = tmp;
        }
        bestPath[i] = min;
    }
    result = (int)bestPath[lstSong.size() - 1];
    delete [] arrayData;
    delete[] songDuration;
    delete [] bestPath;
    return result;
}
