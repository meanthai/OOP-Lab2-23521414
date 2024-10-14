#include <bits/stdc++.h>
using namespace std;

// Lớp List quản lý một mảng động
class List {
private:
    double* arr;       // Con trỏ quản lý mảng
    unsigned int size; // Kích thước của list

public:
    // Constructor khởi tạo list rỗng
    List() {
        arr = nullptr;
        size = 0;
    }

    // Destructor để giải phóng bộ nhớ
    ~List() {
        delete[] arr;
    }

    // Phương thức thêm phần tử vào list
    void add(double x) {
        double* temp = new double[size + 1];
        for (unsigned int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        temp[size] = x;
        delete[] arr;
        arr = temp;
        size++;
    }

    // Phương thức xóa phần tử đầu tiên có giá trị x
    void remove_first(double x) {
        bool found = false;
        for (unsigned int i = 0; i < size; i++) {
            if (arr[i] == x) {
                found = true;
                double* temp = new double[size - 1];
                for (unsigned int j = 0, k = 0; j < size; j++) {
                    if (j != i) {
                        temp[k++] = arr[j];
                    }
                }
                delete[] arr;
                arr = temp;
                size--;
                break;
            }
        }
        if (!found) {
            cout << "Phan tu " << x << " khong ton tai trong list.\n";
        }
    }

    // Phương thức xóa tất cả các phần tử có giá trị x
    void remove_all(double x) {
        unsigned int count = 0;
        for (unsigned int i = 0; i < size; i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        if (count == 0) {
            cout << "Khong co phan tu nao bang " << x << " trong list.\n";
            return;
        }

        double* temp = new double[size - count];
        for (unsigned int i = 0, j = 0; i < size; i++) {
            if (arr[i] != x) {
                temp[j++] = arr[i];
            }
        }
        delete[] arr;
        arr = temp;
        size -= count;
    }

    // Phương thức thay đổi phần tử thứ x bằng giá trị y
    void replace(unsigned int idx, double y) {
        if (idx >= size) {
            cout << "Vi tri khong hop le.\n";
            return;
        }
        arr[idx] = y;
    }

    // Phương thức in list hiện tại
    void print() {
        cout << "[";
        for (unsigned int i = 0; i < size; i++) {
            cout << arr[i];
            if (i < size - 1) cout << ",";
        }
        cout << "]\n";
    }
};

int main() {
    List myList;
    int n;

    while (true) {
        cout << "Nhap chi thi (0: them, 1: xoa phan tu dau tien, 2: xoa tat ca, 3: thay the, -1: ket thuc): ";
        cin >> n;

        if (n == -1) {
            // B3: In ra danh sách và thoát chương trình
            myList.print();
            break;
        }

        if (n == 0) {
            // Thêm phần tử vào list
            double x;
            cout << "Nhap gia tri can them: ";
            cin >> x;
            myList.add(x);
        } else if (n == 1) {
            // Xóa phần tử đầu tiên có giá trị x
            double x;
            cout << "Nhap gia tri can xoa: ";
            cin >> x;
            myList.remove_first(x);
        } else if (n == 2) {
            // Xóa tất cả các phần tử có giá trị x
            double x;
            cout << "Nhap gia tri can xoa: ";
            cin >> x;
            myList.remove_all(x);
        } else if (n == 3) {
            // Thay đổi phần tử thứ x bằng y
            unsigned int idx;
            double y;
            cout << "Nhap vi tri can thay the: ";
            cin >> idx;
            cout << "Nhap gia tri moi: ";
            cin >> y;
            myList.replace(idx, y);
        } else {
            cout << "Chi thi khong hop le.\n";
        }
    }

    return 0;
}
