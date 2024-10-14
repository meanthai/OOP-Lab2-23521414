#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define ii pair<int, int>
#define iii pair<ll, pair<int, int>>
#define MASK(c) (1LL << (c))
const ll N =  1e6 + 30;
const ll inf = 1e9 + 7;
const ll base = 7013;
using namespace std;

/*
     /\_/\
    (  ._.)
    / >() \>()
*/

class Diem {
private:
    int iHoanh; // Tọa độ hoành độ (x)
    int iTung;  // Tọa độ tung độ (y)

public:
    Diem() : iHoanh(0), iTung(0) {} // Em sẽ mặc định điểm có tọa độ (0, 0) nếu không truyền biến vào

    Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

    void Nhap() { // Nhập điểm
        cout << "+)Nhap hoanh do: ";
        cin >> iHoanh;
        cout << "+)Nhap tung do: ";
        cin >> iTung;
    }

    void Xuat() {
        cout << "(" << iHoanh << ", " << iTung << ")"; // In điểm
    }

    void TinhTien(int dHoanh, int dTung) { // Tịnh tiến điểm bằng cách cộng thêm dHoanh và dTung
        iHoanh += dHoanh;
        iTung += dTung;
    }

    int GetHoanhDo() 
    { return iHoanh; } // Lấy giá trị hoành độ

    int GetTungDo() 
    { return iTung; } // Lấy giá trị tung độ

    void SetHoanhDo(int Hoanh)
    { iHoanh = Hoanh; } // Gán giá trị hoành độ

    void SetTungDo(int Tung)
    { iTung = Tung; } // Gán gias trị tung độ
};

// Lớp tam giác
class TamGiac {
private:
    Diem A, B, C;

public:
    TamGiac() {}

    TamGiac(Diem a, Diem b, Diem c) : A(a), B(b), C(c) {}

    void Nhap() { // Nhập 3 điểm A, B, C
        cout << "Nhap toa do dinh A:\n";
        A.Nhap();
        cout << "Nhap toa do dinh B:\n";
        B.Nhap();
        cout << "Nhap toa do dinh C:\n";
        C.Nhap();
    }

    void Xuat(){
        cout << "Toa do dinh A: "; 
        A.Xuat(); cout << endl;
        cout << "Toa do dinh B: "; 
        B.Xuat(); cout << endl;
        cout << "Toa do dinh C: "; 
        C.Xuat(); cout << endl;
    }

    void TinhTien(int dHoanh, int dTung) { // Tịnh tiến
        A.TinhTien(dHoanh, dTung);
        B.TinhTien(dHoanh, dTung);
        C.TinhTien(dHoanh, dTung);
    }

    void PhongTo(float ratio) { // Phóng to bằng cách nhân thêm với giá trị ratio
        A.SetHoanhDo(A.GetHoanhDo() * ratio);
        A.SetTungDo(A.GetTungDo() * ratio);

        B.SetHoanhDo(B.GetHoanhDo() * ratio);
        B.SetTungDo(B.GetTungDo() * ratio);

        C.SetHoanhDo(C.GetHoanhDo() * ratio);
        C.SetTungDo(C.GetTungDo() * ratio);
    }

    void ThuNho(float ratio) { // Thu nhỏ thực chất là phóng to với tỉ lệ nghịch đảo 
        PhongTo(1 / ratio); 
    }

    void Quay(float goc) { //Quay điểm theo góc
        float rad = goc * M_PI / 180.0;
        QuayDiem(A, rad);
        QuayDiem(B, rad);
        QuayDiem(C, rad);
    }

private:
    void QuayDiem(Diem &d, float rad) { // Hàm tính điểm quay theo góc dùng sin, cos
        int x = d.GetHoanhDo();
        int y = d.GetTungDo();

        int xMoi = x * cos(rad) - y * sin(rad);
        int yMoi = x * sin(rad) + y * cos(rad);

        d.SetHoanhDo(xMoi);
        d.SetTungDo(yMoi);
    }
};

int main() {
    TamGiac tg;
    tg.Nhap();

    cout << "\nToa do tam giac ban dau:\n";
    tg.Xuat();

    tg.TinhTien(2, 3);
    cout << "\nToa do tam giac sau khi tinh tien (2, 3):\n";
    tg.Xuat();

    tg.PhongTo(2);
    cout << "\nToa do tam giac sau khi phong to voi ti le 2:\n";
    tg.Xuat();

    tg.ThuNho(2);
    cout << "\nToa do tam giac sau khi thu nho voi ti le 2:\n";
    tg.Xuat();

    tg.Quay(90);
    cout << "\nToa do tam giac sau khi quay 90 do:\n";
    tg.Xuat();

    return 0;
}