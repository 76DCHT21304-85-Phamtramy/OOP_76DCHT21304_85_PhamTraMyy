//mon hoc:ten ,diem cc,diem kt,diem thi
//sinh vien: ke thua mon hoc,hoten ,lop ,msv
//nhap,xuat,tinhdiem hocphan,cam thi(cc<5 va diem Kt=0)
#include<iostream>
#include<string>
using namespace std;
class monhoc{
	protected:
		string tenmon;
		float cc;
		float kt;
		float dt;
	void nhap()
	{
		cout<<"nhap ten mon hoc:";
		getline(cin,tenmon);
		cout<<"nhap diem chuyen can:";
		cin>>cc;
		cout<<"nhap diem kiem tra:";
		cin>>kt;
		cout<<"nhap diem thi:";
		cin>>dt;
		cin.ignore();
	}
	void xuat()
	{
		cout<<"ten mon hoc:"<<tenmon<<endl;
		cout<<"diem chuyen can:"<<cc<<endl;
		cout<<"diem kiem tra:"<<kt<<endl;
		cout<<"diem thi:"<<dt<<endl;
	}
};
class sinhvien :public monhoc{
	private:
		string hoten;
		string lop;
		string msv;
	public:
		void nhap()
		{
			monhoc::nhap();
			cout<<"nhap ho ten:";
			getline(cin,hoten);
			cout<<"nhap lop:";
			getline(cin,lop);
			cout<<"nhap msv:";
			getline(cin,msv);
			cin.ignore();
		}
		void xuat()
		{
			monhoc::xuat();
			cout<<"ho ten:"<<hoten<<endl;
			cout<<"lop hoc:"<<lop<<endl;
			cout<<"msv:"<<msv<<endl;
			cout<<"diem hoc phan:"<<diem_hp()<<endl;
		}
		float diem_hp()
		{
			return dt*0.5+kt*0.3+cc*0.2;
		}
		float get_cc()
		{
			return cc;
		}
		float get_kt()
		{
			return kt;
		}
		
};
int main()
{
	int n;
	cout<<"nhap so sinh vien :";
	cin>>n;
	cin.ignore();
	sinhvien ds[50];
	cout<<"*******NHAP DS SINH VIEN:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"sinh vien thu "<<i+1<<":"<<endl;
		ds[i].nhap();
	}
	//xay dung cam thi
	cout<<"*******DS SINH VIEN BI CAM THI:"<<endl;
	for(int i=0;i<n;i++)
	{
		if(ds[i].get_cc() <5 || ds[i].get_kt()==0)
		ds[i].xuat();
	}
	return 0;
	
}
