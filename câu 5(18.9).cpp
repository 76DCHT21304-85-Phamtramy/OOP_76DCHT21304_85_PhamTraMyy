#include<iostream>
#include<string>
using namespace std;

// Lop nguoi
class nguoi
{
	protected:
		string hoten;
		int namsinh;
		
	public:
		void nhap()
		{
			cout << "Nhap ho ten: ";
			getline(cin, hoten);
			
			cout << "Nhap nam sinh: ";
			cin >> namsinh;
			cin.ignore();
		}
		void xuat()
		{
			cout << "Ho ten: " << hoten << endl;
			cout << "Nam sinh: " << namsinh << endl;
		}
};
// Lop sinh vien ke thua lop nguoi
class sinhvien : public nguoi
{
	private:
		string msv;
		float dtb;
		
	public:
		void nhap()
		{
			nguoi::nhap();
			cout << "Nhap msv: ";
			getline(cin, msv);
			cout << "Nhap dtb: ";
			cin >> dtb;
			cin.ignore();
		}
		void xuat()
		{
			nguoi::xuat();
			cout << "MSV: " << msv << endl;
			cout << "DTB: " << dtb << endl;
		}
		int tk_ma(string ma)
		{
			if(msv == ma)
			{
				return 1;
			}
			return 0;
		}
		int tk_hoten(string ten)
		{
			if(hoten == ten)
			{
				return 1;
			}
			return 0;
		}
};


int main()
{
	int n;
	cout << "Nhap n = ";
	cin >> n;
	cin.ignore();
	sinhvien ds[50];
	// Nhap danh sach sinh vien
	cout <<"***** NHAP THONG TIN SINH VIEN"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i + 1 << ":" << endl;
		ds[i].nhap();
	}
	// Chon cach tim kiem
	int luachon;
	cout << "*****CHON CACH TIM KIEM"<<endl;
	cout << "1. Tim kiem ma sinh vien" << endl;
	cout << "2. Tim kiem ho ten" << endl;
	cout << "Nhap lua chon: ";
	cin >> luachon;
	cin.ignore();
	// Tim theo ma sinh vien
	if(luachon == 1)
	{
		string ma;
		int timthay = 0;
		cout << "Nhap ma sinh vien can tim: ";
		getline(cin, ma);
		for(int i = 0; i < n; i++)
		{
			if(ds[i].tk_ma(ma) == 1)
			{
				cout << "\n***** SINH VIEN TIM THAY *****\n";
				ds[i].xuat();
				timthay = 1;
			}
		}
		
		if(timthay == 0)
		{
			cout << "Khong tim thay thong tin";
		}
	}
	
	// Tim theo ho ten
	else if(luachon == 2)
	{
		string ten;
		int timthay = 0;
		cout << "Nhap ho ten sinh vien can tim: ";
		getline(cin, ten);
		
		for(int i = 0; i < n; i++)
		{
			if(ds[i].tk_hoten(ten) == 1)
			{
				cout << "\n***** SINH VIEN TIM THAY *****\n";
				ds[i].xuat();
				timthay = 1;
			}
		}
		
		if(timthay == 0)
		{
			cout << "Khong tim thay thong tin";
		}
	}
	return 0;
}
