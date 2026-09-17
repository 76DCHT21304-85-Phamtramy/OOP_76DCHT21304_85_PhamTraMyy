// lop nguoi: ho ten, nam sinh
//lop sv:msv,dtb
#include<iostream>
#include<string> 
#include<iomanip>
using namespace std;
class nguoi{
	protected:
		string hoten;
		int namsinh;
	//ham tao khong doi
	nguoi()
	{
		hoten="";
		namsinh=0;
	}
	//ham tao co doi
	nguoi(string hoten,int namsinh)
	{
		this->hoten=hoten;
		this->namsinh=namsinh;
	}	
		void nhap()
		{
			cout<<"nhap hoten :";getline(cin,hoten);
			cout<<"nhap nam sinh: ";cin>>namsinh;
			cin.ignore();
		}
		void xuat()
		{
			cout<<"hoten:"<<hoten<<endl;
			cout<<"namsinh:"<<namsinh<<endl;		
		}
	
};
class sinhvien:public nguoi{
	private:
		string msv;
		float dtb;
	public:
		//lop con sinh vien khong duoc ke thua ham tao ma phai goi lai
		//goi lai ham tao khong doi cua nguoi
		sinhvien():nguoi(){
			msv="";
			dtb=0;
		}
		//goi lai ham tao co doi cua nguoi
		sinhvien(string hoten,int namsinh,string msv,float dtb):nguoi(hoten,namsinh){
			this->msv=msv;
			this->dtb=dtb;
		}
		void nhap(){
			nguoi::nhap();//goi nhap cua nguoi vi tinh ke thua
			cout<<"nhap msv: ";getline(cin,msv);
			cout<<"nhap dtb: ";cin>>dtb;
			cin.ignore();
		}
		void xuat(){
			nguoi::xuat();
			cout<<" msv: "<<msv<<endl;
			cout<<" dtb: "<<dtb<<endl;
		}
		float getdtb()
		{
			return dtb;
		}
};
int main()
{
	sinhvien minh("minh",2000,"mn1",8.5);
	minh.xuat();
	int n;
	cout<<"nhap n=";
	cin>>n;
	cin.ignore();
	sinhvien ds[100];
	for(int i = 0; i < n; i++)
	{
		cout << "--- Sinh vien thu " << i + 1<< endl;
		ds[i].nhap();
	}
	// Sap xep diem trung binh giam dan
	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(ds[i].getdtb() < ds[j].getdtb())
			{
				sinhvien temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
	cout << "---danh sach sinh vien co dtb giam dan:"<< endl;
	
	for(int i = 0; i < n; i++)
	{
		ds[i].xuat();
	}
	
	return 0;
}
