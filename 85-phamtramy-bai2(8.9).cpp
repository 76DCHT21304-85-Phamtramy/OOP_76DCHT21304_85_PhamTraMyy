#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    // Hàm tao không doi
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    // Hàm tao có doi
    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
        if (mau == 0) this->mau = 1;
    }

    // Hàm huy
    ~PhanSo() {}

    // Rút gon
    void rutGon() {
        int gcd = __gcd(tu, mau);
        tu /= gcd;
        mau /= gcd;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    // Nap chông toán tu nhap
    friend istream& operator>>(istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.tu;
        cout << "Nhap mau so: ";
        in >> ps.mau;
        if (ps.mau == 0) {
            cout << "Mau so khong hop le! Gan mau = 1\n";
            ps.mau = 1;
        }
        return in;
    }

    // Nap chong toán tu xuat
    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        out << ps.tu << "/" << ps.mau;
        return out;
    }

    // Toán tu cong
    PhanSo operator+(PhanSo b) {
        PhanSo kq(tu * b.mau + mau * b.tu, mau * b.mau);
        kq.rutGon();
        return kq;
    }

    // Toán tu tru
    PhanSo operator-(PhanSo b) {
        PhanSo kq(tu * b.mau - mau * b.tu, mau * b.mau);
        kq.rutGon();
        return kq;
    }

    // Toán tu nhân
    PhanSo operator*(PhanSo b) {
        PhanSo kq(tu * b.tu, mau * b.mau);
        kq.rutGon();
        return kq;
    }

    // Toán tu chia
    PhanSo operator/(PhanSo b) {
        PhanSo kq(tu * b.mau, mau * b.tu);
        kq.rutGon();
        return kq;
    }
};

int main() {
    PhanSo a, b;

    cout << "Nhap phan so thu nhat:\n";
    cin >> a;

    cout << "Nhap phan so thu hai:\n";
    cin >> b;

    cout << "\nKet qua:\n";

    cout << "Cong: " << (a + b) << endl;
    cout << "Tru: " << (a - b) << endl;
    cout << "Nhan: " << (a * b) << endl;
    cout << "Chia: " << (a / b) << endl;

    return 0;
}

