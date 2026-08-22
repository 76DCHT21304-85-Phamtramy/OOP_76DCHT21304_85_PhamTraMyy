#include<iostream>
#include<string>
using namespace std;

struct NhanVien {
	string maNV;
	string tenNV;
	float luongcoban;
	float heso;
};

void nhap(NhanVien &nv){
	cout <<"Nhap ma nv: ";
	cin >>nv.maNV;
	
	cin.ignore();
	cout <<"nhap ten nv: ";
	getline(cin, nv.tenNV);
	
	cout <<"Nhap luong cb:";
	cin >>nv.luongcoban;
	
	cout <<"Nhap he so:";
	cin >>nv.heso;
}

void xuat(NhanVien nv){
	cout << "Ma nv:" << nv.maNV << endl;
	cout << "Ten nv:" << nv.tenNV << endl;
	cout << "Luong cb:" << nv.luongcoban << endl;
	cout << "He so:" << nv.heso << endl;
	cout << "Luong:" << nv.luongcoban * nv.heso << endl;
	}
	
	int main(){
		int n;
		
		cout << "Nhap so luong nv:";
		cin >> n;
		
		NhanVien nv[100];
		
		for(int i=0; i<n; i++){
			cout << "\n NHAP NHAN VIEN" << i+1 <<endl;
			nhap(nv[i]);
		}
		
		cout << "\n DANH SACH NHAN VIEN" << endl;
		
		for (int i=0;i<n;i++){
			cout << "\n NHAN VIEN" << i+1 <<endl;
			xuat(nv[i]);
		}
		return 0;
	}
