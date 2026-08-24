#include <iostream>
#include <vector>
using namespace std;

class NhanVien {
private:
    string hoTen;
    int tuoi;
    double luong;
public:
    // Constructor không doi
    NhanVien() {
        hoTen = "";
        tuoi = 0;
        luong = 0;
    }

    // Constructor có doi
    NhanVien(string ht, int t, double l) {
        hoTen = ht;
        tuoi = t;
        luong = l;
    }

    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap luong: ";
        cin >> luong;
        cin.ignore(); 
    }

    void xuat() {
        cout << hoTen << "\t" << tuoi << "\t" << luong << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    cin.ignore();

    // Cách 3
    vector<NhanVien> ds;

    for (int i = 0; i < n; i++) {
        cout << "\n=== NHAP THONG TIN NHAN VIEN " << i + 1 << " ===\n";
        string ht;
        int t;
        double l;
        cout << "Ho ten: ";
        getline(cin, ht);
        cout << "Tuoi: ";
        cin >> t;
        cout << "Luong: ";
        cin >> l;
        cin.ignore();
        ds.push_back(NhanVien(ht, t, l)); 
    }

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    cout << "Ho ten\tTuoi\tLuong\n";
    for (int i = 0; i<ds.size();i++){
        ds[i].xuat();
    }

    return 0;
}

