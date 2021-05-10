#include <iostream>
#include <chrono>
#define MAX_LIST_SIZE 100000

using namespace std;

inline void error(const char* str) {
    std::cerr << str << "\n";
    exit(1);
};

class ArrayList {
    private:
        int data[MAX_LIST_SIZE];
        size_t length;
        // size_t == unsigned int
        // 32��Ʈ OS���� uint32_t
        // 64��Ʈ OS���� uint64_t

    public:
        ArrayList() {
            length = 0;
        }
        ~ArrayList(){}

        void insert(int pos, int e) {
            if (!isFull() && pos >= 0 && pos <= length) {
                for (int i = length; i > pos; i--) {
                    data[i] = data[i - 1];
                }
                data[pos] = e;
                length++;
            }
            else {
                error("��ȭ���� ���� �Ǵ� ���� ��ġ ����\n");
            }
        }

        void remove(int pos) {
            if (!isEmpty() && pos >= 0 && pos < length) {
                for (int i = pos + 1; i < length; i++) {
                    data[i - 1] = data[i];
                }
                length--;
            }
            else {
                error("������� ���� �Ǵ� ���� ��ġ ����\n");
            }
        }

        int getEntry(int pos) {
            return data[pos];
        }

        bool isEmpty() {
            return length == 0;
        }

        bool isFull() {
            return length == MAX_LIST_SIZE;
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
            if (!isEmpty() && pos >= 0 && pos < length) {
                data[pos] = 0;
            }
            else {
                error("������� ���� �Ǵ� ġȯ ��ġ ����\n");
            }
        }

        int size() {
            return length;
        }

        void display() {
            cout << "Array List�� �� �׸� ��: " << length;
            for (int i = 0; i < length; i++) {
                cout << " [" << data[i] << "]";
            }
            cout << endl;
        }


        void clear() {
            length = 0;
        }
};


int main() {
    ArrayList list;

    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(1, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, 90);
    list.display();

    list.clear();
    list.display();


    
    ArrayList list2;
    cout << "list2!!" << endl;

    auto end = std::chrono::steady_clock::now();
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < 10000; i++) {
        list2.insert(0, 0);

        if (i % 1000 == 999) {
            end = std::chrono::steady_clock::now();
            std::cout << i << "��° ����: ";
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns \n";
            start = std::chrono::steady_clock::now();
        }
    }

    start = std::chrono::steady_clock::now();

    for (int i = 0; i < 10000; i++) {
        list2.remove(0);

        if (i % 1000 == 999) {
            end = std::chrono::steady_clock::now();
            std::cout << i << "��° ����: ";
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns \n";
            start = std::chrono::steady_clock::now();
        }
    }

    return 0;
}