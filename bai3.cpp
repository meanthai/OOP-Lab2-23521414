#include <iostream>
#include <cmath>
using namespace std;

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

// Lớp đa giác
class DaGiac {
private:
    int n;        // Số đỉnh của đa giác
    Diem* Dinh;   // Mảng các đỉnh của đa giác

public:
    DaGiac(int soDinh = 3) { // tạo đa giác, mặc định sẽ là 3 đỉnh
        n = soDinh;
        Dinh = new Diem[n];  // Cấp phát bộ nhớ cho các đỉnh
    }

    void Nhap() {
        cout << "Nhap so dinh cua da giac: ";
        cin >> n;

        // Làm rỗng tập đỉnh trước khi nhập lại tập đỉnh mới
        delete[] Dinh;
        Dinh = new Diem[n];

        for (int i = 0; i < n; ++i) {
            cout << "Nhap toa do dinh thu " << i + 1 << ":\n";
            Dinh[i].Nhap();
        }
    }

    void Xuat() const {
        for (int i = 0; i < n; ++i) {
            cout << "Dinh thu " << i + 1 << ": ";
            Dinh[i].Xuat();
            cout << endl;
        }
    }

    void TinhTien(int dHoanh, int dTung) { // TỊnh tiến cộng thêm dHoang dTung tương ứng
        for (int i = 0; i < n; ++i) {
            Dinh[i].TinhTien(dHoanh, dTung);
        }
    }

    void PhongTo(float ratio) { // Phóng to nhân tỉ lệ
        for (int i = 0; i < n; ++i) {
            Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * ratio);
            Dinh[i].SetTungDo(Dinh[i].GetTungDo() * ratio);
        }
    }

    void ThuNho(float ratio) { // Thu nhỏ thực chất là phóng to với tỉ lệ nghịch
        PhongTo(1 / ratio);  
    }

    void Quay(float goc) {
        float rad = goc * M_PI / 180.0; //Quay điểm theo góc

        for (int i = 0; i < n; ++i) {
            int x = Dinh[i].GetHoanhDo();
            int y = Dinh[i].GetTungDo();

            int xMoi = x * cos(rad) - y * sin(rad);
            int yMoi = x * sin(rad) + y * cos(rad);

            Dinh[i].SetHoanhDo(xMoi);
            Dinh[i].SetTungDo(yMoi);
        }
    }
};

int main() {
    DaGiac dg;

    dg.Nhap();

    cout << "\nToa do da giac ban dau:\n";
    dg.Xuat();

    dg.TinhTien(2, 3);
    cout << "\nToa do da giac sau khi tinh tien (2, 3):\n";
    dg.Xuat();

    dg.PhongTo(2);
    cout << "\nToa do da giac sau khi phong to voi ti le 2:\n";
    dg.Xuat();

    dg.ThuNho(2);
    cout << "\nToa do da giac sau khi thu nho voi ti le 2:\n";
    dg.Xuat();

    dg.Quay(90);
    cout << "\nToa do da giac sau khi quay 90 do:\n";
    dg.Xuat();

    return 0;
}
