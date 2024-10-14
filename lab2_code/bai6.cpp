#include <bits/stdc++.h>

using namespace std;

const double soPi = 3.14;

class Diem {
public:
    double x, y;

    Diem() : x(0), y(0) {} // Điểm mặc định không tham số sẽ ở tọa độ (0, 0)
    Diem(double hoanh, double tung) : x(hoanh), y(tung) {} // Khai báo điểm có tham số tại tọa độ (x, y)

    // Tịnh tiến điểm theo góc và độ dài tịnh tiến
    void TinhTien(double goc, double do_dai) {
        // Đổi góc từ độ sang radian
        double radian = goc * soPi / 180;
        x += do_dai * cos(radian); // Tịnh tiến theo trục x
        y += do_dai * sin(radian); // Tịnh tiến theo trục y
    }

    // Xuất tọa độ điểm
    void Xuat() {
        cout << "(" << x << ", " << y << ")";
    }
};

class TamGiac {
public:
    Diem A, B, C;

    // Nhập 3 điểm của tam giác
    void Nhap() {
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    }

    // In ra tọa độ 3 điểm của tam giác
    void Xuat() {
        cout << "Toa do 3 dinh tam giac: ";
        A.Xuat();
        cout << ", ";
        B.Xuat();
        cout << ", ";
        C.Xuat();
        cout << std::endl;
    }

    // Phương thức tịnh tiến tam giác theo hướng và độ dài tịnh tiến
    void TinhTien(double goc, double do_dai) {
        A.TinhTien(goc, do_dai);
        B.TinhTien(goc, do_dai);
        C.TinhTien(goc, do_dai);
    }
};

int main() {
    TamGiac tg;
    double goc, do_dai;

    cout << "Nhap toa do 3 dinh tam giac (x1 y1 x2 y2 x3 y3): ";
    tg.Nhap();

    cout << "Nhap goc tịnh tien (tinh bang do): ";
    cin >> goc;

    cout << "Nhap do dai tịnh tien: ";
    cin >> do_dai;

    tg.TinhTien(goc, do_dai);

    cout << "Toa do tam giac sau khi tịnh tien: ";
    tg.Xuat();

    return 0;
}
