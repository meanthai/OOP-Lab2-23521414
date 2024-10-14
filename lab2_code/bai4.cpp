#include <iostream>
#include <string>
using namespace std;

// Lớp Thí Sinh
class ThiSinh {
private:
    string Ten;       // Tên thí sinh
    string MSSV;      // Mã số sinh viên
    int iNgay, iThang, iNam;  // Ngày, tháng, năm sinh
    float fToan, fVan, fAnh;  // Điểm Toán, Văn, Anh

public:
    // Phương thức nhập thông tin thí sinh
    void Nhap() {
        cin.ignore();
        cout << "Nhap ten: ";
        getline(cin, Ten);
        cout << "Nhap MSSV: ";
        getline(cin, MSSV);
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> iNgay >> iThang >> iNam;
        cout << "Nhap diem Toan: ";
        cin >> fToan;
        cout << "Nhap diem Van: ";
        cin >> fVan;
        cout << "Nhap diem Anh: ";
        cin >> fAnh;
        cin.ignore();  // Bỏ qua ký tự newline sau khi nhập số
    }

    // Phương thức xuất thông tin thí sinh
    void Xuat() {
        cout << "Ten: " << Ten << endl;
        cout << "MSSV: " << MSSV << endl;
        cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
        cout << "Diem Toan: " << fToan << ", Diem Van: " << fVan << ", Diem Anh: " << fAnh << endl;
        cout << "Tong diem: " << Tong() << endl;
    }

    // Tính tổng điểm
    float Tong() const {
        return fToan + fVan + fAnh;
    }

    // Lấy MSSV
    string GetMSSV() const {
        return MSSV;
    }
};

// Hàm main
int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    cin.ignore();  // Bỏ qua ký tự newline sau khi nhập số

    ThiSinh* thiSinhArray = new ThiSinh[n];  // Cấp phát bộ nhớ cho mảng thí sinh

    // Nhập thông tin cho các thí sinh
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        thiSinhArray[i].Nhap();
    }

    // In ra thông tin thí sinh có tổng điểm lớn hơn 15
    cout << "\nDanh sach thi sinh co tong diem lon hon 15:\n";
    for (int i = 0; i < n; ++i) {
        if (thiSinhArray[i].Tong() > 15) {
            thiSinhArray[i].Xuat();
            cout << endl;
        }
    }

    // Tìm thí sinh có tổng điểm cao nhất
    float maxTongDiem = thiSinhArray[0].Tong();
    int viTriMax = 0;
    for (int i = 1; i < n; ++i) {
        if (thiSinhArray[i].Tong() > maxTongDiem) {
            maxTongDiem = thiSinhArray[i].Tong();
            viTriMax = i;
        }
    }

    // In ra thông tin thí sinh có điểm cao nhất
    cout << "\nThong tin thi sinh co tong diem cao nhat (MSSV: " << thiSinhArray[viTriMax].GetMSSV() << "):\n";
    thiSinhArray[viTriMax].Xuat();

    // Giải phóng bộ nhớ
    delete[] thiSinhArray;

    return 0;
}
