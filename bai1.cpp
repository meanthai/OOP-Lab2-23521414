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
    // Khai báo điểm không chứa tham số
    Diem() {
        iHoanh = 0;
        iTung = 0;
    }

    // khai báo điểm có tham số
    Diem(int Hoanh, int Tung) {
        iHoanh = Hoanh;
        iTung = Tung;
    }

    // sao chép điểm
    Diem(const Diem &x) {
        iHoanh = x.iHoanh;
        iTung = x.iTung;
    }

    // Phương thức xuất thông tin điểm
    void Xuat() {
        cout << "Diem(" << iHoanh << ", " << iTung << ")" << endl;
    }

    // lấy gtri tung độ
    int GetTungDo() {
        return iTung;
    }

    // lấy gtri hoành độ
    int GetHoanhDo() {
        return iHoanh;
    }

    // lấy gtri tung độ
    void SetTungDo(int Tung) {
        iTung = Tung;
    }

    // lấy gtri hoành độ
    void SetHoanhDo(int Hoanh) {
        iHoanh = Hoanh;
    }

    // Tịnh tiến bằng cách cộng thêm giá trị dHoanh dTung tương ứng
    void TinhTien(int dHoanh, int dTung) {
        iHoanh += dHoanh;
        iTung += dTung;
    }
};


int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Diem p1;
    p1.Xuat();

    // Tạo điểm p2 với tọa độ (3, 4)
    Diem p2(3, 4);
    p2.Xuat();

    // Tạo điểm p3 sao chép từ p2
    Diem p3(p2);
    p3.Xuat();

    // Sử dụng setter để thay đổi tung độ và hoành độ
    p3.SetHoanhDo(5);
    p3.SetTungDo(7);
    p3.Xuat();

    // Tịnh tiến điểm p3
    p3.TinhTien(2, 3);
    p3.Xuat();
    return 0;
}