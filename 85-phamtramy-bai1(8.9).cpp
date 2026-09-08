#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    // Hàm t?o không d?i
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    // Hàm t?o có d?i
    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
        if (mau == 0) this->mau = 1;
    }

    // Hàm h?y
    ~PhanSo() {}

    // Nh?p phân s?
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tu;
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0) {
            cout << "Mau so khong hop le! Gan mau = 1\n";
            mau = 1;
        }
    }

    // Xu?t phân s?
    void xuat() {
        cout << tu << "/" << mau;
    }

    // Rút g?n
    void rutGon() {
        int gcd = __gcd(tu, mau);
        tu /= gcd;
        mau /= gcd;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // C?ng
    PhanSo cong(PhanSo b) {
        PhanSo kq(tu * b.mau + mau * b.tu, mau * b.mau);
        kq.rutGon();
        return kq;
    }

    // Tr?
    PhanSo tru(PhanSo b) {
        PhanSo kq(tu * b.mau - mau * b.tu, mau * b.mau);
        kq.rutGon();
        return kq;
    }

    // Nhân
    PhanSo nhan(PhanSo b) {
        PhanSo kq(tu * b.tu, mau * b.mau);
        kq.rutGon();
        return kq;
    }

    // Chia
    PhanSo chia(PhanSo b) {
        PhanSo kq(tu * b.mau, mau * b.tu);
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo a, b;

    cout << "Nhap phan so thu nhat:\n";
    a.nhap();

    cout << "Nhap phan so thu hai:\n";
    b.nhap();

    cout << "\nKet qua:\n";

    cout << "Cong: ";
    a.cong(b).xuat();
    cout << endl;

    cout << "Tru: ";
    a.tru(b).xuat();
    cout << endl;

    cout << "Nhan: ";
    a.nhan(b).xuat();
    cout << endl;

    cout << "Chia: ";
    a.chia(b).xuat();
    cout << endl;

    return 0;
}

