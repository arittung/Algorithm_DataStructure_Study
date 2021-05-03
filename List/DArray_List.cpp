#include <iostream>
#include <chrono>
using namespace std;


inline void error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
};

class DArrayList {
    private:
        int* data;
        size_t length;  // 현재 리스트 길이
        size_t current_size;    // 현재 할당된 크기
        size_t resize_unit;     // 할당 크기 변화 기준
    public:
        DArrayList(size_t init_size = 10) {
            cout << "\n<Initialize to: " << init_size << "> ";
            data = new int[init_size];
            current_size = init_size;
            resize_unit = init_size;
            length = 0;
        }

        ~DArrayList() {
            delete[] data;
        }

        void resize(size_t newsize) {
            int* temparray = new int[newsize];
            cout << "\n<Resize to: " << newsize << "> ";

            for (int i = 0; i < length; i++) {
                temparray[i] = data[i];
            }

            delete[] data;
            current_size = newsize;
            data = temparray;

        }

        void insert(int pos, int e) {
            if (pos >= 0 && pos <= length) {
                if (isFull()) {
                    resize(current_size + resize_unit);
                }
                for (int i = length; i > pos; i--) {
                    data[i] = data[i - 1];
                }
                data[pos] = e;
                length++;
            }
            else {
                cout << "포화상태 오류 또는 삽입 위치 오류" << endl;
            }
        }

        void remove(int pos) {
            if (!isEmpty() && 0 <= pos && pos < length){
                if (current_size > resize_unit + length) {
                    // array 공간 여유가 resize_unit보다 클 때
                    resize(current_size - resize_unit);
                }
                for (int i = pos + 1; i < length; i++) {
                    data[i - 1] = data[i];
                }
                length--;
            }
        }

        int getEntry(int pos) {
            return data[pos];
        }

        bool isEmpty() {
            return length == 0;
        }

        bool isFull() {
            return length == current_size;
        }

        bool find(int item) {
            for (int i = 0; i < length; i++) {
                if (data[i] == item) {
                    return true;
                }
            }
            return false;
        }

        void replace(int pos, int e) {
            if (!isEmpty() && 0 <= pos && pos < length) {
                data[pos] = e;
            }
            else {
                cout << "공백상태 오류 또는 치환 유지 오류" << endl;
            }
        }

        int size() {
            return length;
        }

        void display() {
            cout << "Array List의 총 항목 수: " << length;
            for (int i = 0; i < length; i++) {
                cout << " [" << data[i] << "]";
            }
            cout << endl;
        }

        void clear() {
            length = 0;
            resize(resize_unit);
        }

        
};


int main() {
    DArrayList list(10);
    for (int i = 0; i < 20; i++) {
        list.insert(list.size(), i);
        if (i % 10 == 9) {
            list.display();
        }
    }

    for (int i = 0; i < 20; i++) {
        list.remove(list.size() - 1);
        if (i % 10 == 9) {
            list.display();
        }
    }
    list.display();

    for (int i = 0; i < 100; i++) {
        auto start = std::chrono::steady_clock::now();
        list.insert(list.size(), i);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns ";
    }
    std::cout << "\n";



    for (int i = 0; i < 100; i++) {
        auto start = std::chrono::steady_clock::now();
        list.remove(list.size() - 1);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns ";
    }

    list.clear();
    list.display();

    return 0;
}