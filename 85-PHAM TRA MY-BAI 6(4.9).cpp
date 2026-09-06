#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];
public:
    void nhap();
    void xuat();
    float tinhDiemTB();
    bool coMonThiLai();
};

void SinhVien::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    for (int i = 0; i < 5; i++) {
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
    for (int i = 0; i < 5; i++) tong += diem[i];
    return tong / 5;
}

bool SinhVien::coMonThiLai() {
    for (int i = 0; i < 5; i++)
        if (diem[i] < 5) return true;
    return false;
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    SinhVien sv[n];
    for (int i = 0; i < n; i++) sv[i].nhap();

    cout << "\nDanh sach sinh vien phai thi lai:\n";
    for (int i = 0; i < n; i++)
        if (sv[i].coMonThiLai()) sv[i].xuat();
    return 0;
}

