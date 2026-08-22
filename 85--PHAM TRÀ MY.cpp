#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien {
private:
    string hoten;
    int tuoi;
    string diachi;

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();

        cout << "Nhap dia chi: ";
        getline(cin, diachi);
    }

    void xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Dia chi: " << diachi << endl;
    }
};

int main() {

    cout << "\n================ CACH 1: MANG TINH =================\n";
    NhanVien dsnv1[10];

    for (int i = 0; i < 10; i++) {
        cout << "\n=== NHAP THONG TIN NHAN VIEN " << i+1 << " ===\n";
        dsnv1[i].nhap();
    }

    cout << "\n----- XUAT DANH SACH NHAN VIEN (MANG TINH) -----\n";
    for (int i = 0; i < 10; i++) {
        cout << "\nNhan vien " << i+1 << ":\n";
        dsnv1[i].xuat();
    }


    cout << "\n================ CACH 2: MANG DONG =================\n";
    NhanVien *dsnv2 = new NhanVien[10];

    for (int i = 0; i < 10; i++) {
        cout << "\n=== NHAP THONG TIN NHAN VIEN " << i+1 << " ===\n";
        dsnv2[i].nhap();
    }

    cout << "\n----- XUAT DANH SACH NHAN VIEN (MANG DONG) -----\n";
    for (int i = 0; i < 10; i++) {
        cout << "\nNhan vien " << i+1 << ":\n";
        dsnv2[i].xuat();
    }

    delete[] dsnv2;


    cout << "\n================ CACH 3: VECTOR =================\n";
    vector<NhanVien> ds;

    for (int i = 0; i < 10; i++) {
        NhanVien nv;
        cout << "\n=== NHAP THONG TIN NHAN VIEN " << i+1 << " ===\n";
        nv.nhap();
        ds.push_back(nv);
    }

    cout << "\n----- XUAT DANH SACH NHAN VIEN (VECTOR) -----\n";
    for (int i = 0; i < ds.size(); i++) {
        cout << "\nNhan vien " << i+1 << ":\n";
        ds[i].xuat();
    }


    cout << "\n\n================ SO SANH 3 CACH LUU TRU =================\n";

    cout << "\n1. MANG TINH (NhanVien dsnv[10])\n";
    cout << "- Kich thuoc co dinh, khong thay doi duoc.\n";
    cout << "- Don gian, de dung.\n";
    cout << "- Phu hop khi biet truoc so luong nhan vien.\n\n";

    cout << "2. MANG DONG (new NhanVien[10])\n";
    cout << "- Co the thay doi kich thuoc khi cap phat.\n";
    cout << "- Phai tu giai phong bo nho (delete[]).\n";
    cout << "- De gay loi neu quen giai phong.\n\n";

    cout << "3. VECTOR (vector<NhanVien>)\n";
    cout << "- Linh hoat nhat, tu dong mo rong kich thuoc.\n";
    cout << "- Khong can quan ly bo nho.\n";
    cout << "- Nhieu ham ho tro manh me (push_back, erase...).\n";
    cout << "- Duoc khuyen dung trong C++ hien dai.\n\n";

    cout << "=> Ket luan: VECTOR la lua chon tot nhat trong thuc te.\n";

    return 0;
}

