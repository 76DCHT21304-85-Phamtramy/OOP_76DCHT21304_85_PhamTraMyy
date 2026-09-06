#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];
public:
    void nhap();
    void xuat();
    float tinhDiemTB();
    bool duDieuKienTotNghiep();
};

void SinhVien::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    for (int i = 0; i < 4; i++) {
        cout << "Nhap diem mon " << i + 1 << ": ";
        cin >> diem[i];
    }
    cin.ignore();
}

void SinhVien::xuat() {
    cout << "Ho ten: " << hoTen << ", Nam sinh: " << namSinh << endl;
    cout << "Diem trung binh: " << tinhDiemTB() << endl;
}

float SinhVien::tinhDiemTB() {
    float tong = 0;
    for (int i = 0; i < 4; i++) tong += diem[i];
    return tong / 4;
}

bool SinhVien::duDieuKienTotNghiep() {
    if (tinhDiemTB() < 7) return false;
    for (int i = 0; i < 4; i++)
        if (diem[i] < 5) return false;
    return true;
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    SinhVien sv[n];
    for (int i = 0; i < n; i++) sv[i].nhap();

    cout << "\nDanh sach sinh vien du dieu kien tot nghiep:\n";
    for (int i = 0; i < n; i++)
        if (sv[i].duDieuKienTotNghiep()) sv[i].xuat();
    return 0;
}

