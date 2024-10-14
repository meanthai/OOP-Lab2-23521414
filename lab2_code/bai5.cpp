#include <iostream>
using namespace std;

class Diem {
private:
    double hoanhDo;
    double tungDo;

public:
    // Constructor
    Diem(double x = 0, double y = 0) : hoanhDo(x), tungDo(y) {}

    // Hàm nhân đôi tung độ và hoành độ 
    void NhanDoi() {
        hoanhDo *= 2;
        tungDo *= 2;
    }

    // Hàm gán điểm về gốc tọa độ
    void GanGocToaDo() {
        hoanhDo = 0;
        tungDo = 0;
    }

    // Hàm tịnh tiến điểm
    void TinhTien(int k, double d) {
        if (k == 0)  hoanhDo += d; // Tịnh tiến theo trục x
         else { // Tịnh tiến theo trục y
            tungDo += d;
        }
    }

    // Hàm xuất tọa độ điểm
    void Xuat() const {
        cout << "(" << hoanhDo << "," << tungDo << ")" << endl;
    }
};

double x, y;
int n;

int main() {
    

    // Nhập tọa độ ban đầu
    cout << "Nhap hoanh do va tung do cua diem: ";
    cin >> x >> y;

    Diem diem(x, y);

    // Nhập số lượng yêu cầu theo bài
    cout << "Nhap so luong yeu cau - n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int yeucau;
        cout << "Nhap yeu cau x - (1, 2, 3): ";
        cin >> yeucau;

        if (yeucau == 1) {
            diem.NhanDoi(); // Nhân đôi hoành độ và tung độ
        } else if (yeucau == 2) {
            diem.GanGocToaDo(); // Gán về gốc tọa độ
        } else if (yeucau == 3) {
            int k;
            double d;
            cout << "Nhap huong tinh tien k (0: theo truc x, 1: theo truc y): ";
            cin >> k;
            cout << "Nhap do tinh tien d: ";
            cin >> d;
            diem.TinhTien(k, d); // Tịnh tiến điểm
        }
    }

    // Xuất tọa độ điểm cuối cùng
    cout << "Toa do diem sau khi thuc hien chi thi: ";
    diem.Xuat();

    return 0;
}
