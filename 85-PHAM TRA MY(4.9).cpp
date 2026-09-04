#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoten;
    int namsinh;
    float diem[5];   // di?m 5 môn h?c

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap nam sinh: ";
        cin >> namsinh;

        cout << "Nhap diem 5 mon:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Mon " << i + 1 << ": ";
            cin >> diem[i];
        }
        cin.ignore(); // tránh l?i khi nh?p chu?i ti?p theo
    }

    void xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Nam sinh: " << namsinh << endl;
        cout << "Diem cac mon: ";
        for (int i = 0; i < 5; i++) {
            cout << diem[i] << " ";
        }
        cout << endl;
        cout << "Diem trung binh: " << tinhDTB() << endl;
    }

    float tinhDTB() {
        float sum = 0;
        for (int i = 0; i < 5; i++) sum += diem[i];
        return sum / 5.0;
    }

    void monThiLai() {
        bool coThiLai = false;
        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                if (!coThiLai) {
                    cout << "Sinh vien " << hoten << " phai thi lai:\n";
                    coThiLai = true;
                }
                cout << "  - Mon " << i + 1 << " (diem: " << diem[i] << ")\n";
            }
        }
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    SinhVien sv[n];

    cout << "\n=== Nhap danh sach sinh vien ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien thu " << i + 1 << ":\n";
        sv[i].nhap();
    }

    cout << "\n=== Danh sach sinh vien phai thi lai ===\n";
    for (int i = 0; i < n; i++) {
        sv[i].monThiLai();
    }

    return 0;
}

