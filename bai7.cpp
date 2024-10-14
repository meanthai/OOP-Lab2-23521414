#include <bits/stdc++.h>
using namespace std;

// Lớp Diem đại diện cho một điểm trên mặt phẳng
class Diem {
public:
    double x, y; // Hoành độ và tung độ của điểm

    Diem() : x(0), y(0) {} // Điểm mặc định không tham số sẽ ở tọa độ (0, 0)
    Diem(double hoanh, double tung) : x(hoanh), y(tung) {} // Khai báo điểm có tham số tại tọa độ (x, y)
};

// Lớp Polygon đại diện cho một đa giác
class Polygon {
private:
    vector<Diem> dinh; // Mảng chứa các điểm của đa giác
    int n; // Số lượng điểm của đa giác

public:
    // Nhập tọa độ các đỉnh của đa giác
    void Nhap() {
        cout << "Nhap so dinh cua da giac (n > 2): ";
        cin >> n;

        // Kiểm tra nếu số đỉnh nhỏ hơn 3 thì không hợp lệ
        if (n <= 2) {
            cout << "khong hop le" << endl;
            return;
        }

        // Nhập tọa độ các đỉnh
        dinh.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
            cin >> dinh[i].x >> dinh[i].y;
        }
    }

    // Tính diện tích đa giác theo công thức 
    double TinhDienTich() {
        double dien_tich = 0;

        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n; // Lấy đỉnh tiếp theo, quay lại đỉnh đầu nếu là đỉnh cuối
            dien_tich += (dinh[i].x * dinh[j].y) - (dinh[j].x * dinh[i].y);
        }

        return abs(dien_tich) / 2.0;
    }

    // Phương thức xuất diện tích của đa giác
    void XuatDienTich() {
        if (n <= 2) {
            cout << "Da giac khong hop le de tinh dien tich vi so dinh <= 2." << endl;
        } else {
            cout << "Dien tich da giac la: " << TinhDienTich() << endl;
        }
    }
};

int main() {
    Polygon polygon; // Khởi tạo đối tượng đa giác

    polygon.Nhap();  // Nhập tọa độ các đỉnh
    polygon.XuatDienTich(); // Tính và xuất diện tích của đa giác

    return 0;
}
