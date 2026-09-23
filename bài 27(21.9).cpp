//lop PS1:tuso,mauso khac 0,nhap,xuat,rut gon;
//lop PS2 : ke thua PS 1 them nap chong gan(=),>
//nhap toi da 10 ps,sap xep giam dan
#include<iostream>
#include<math.h>
using namespace std;
class PS1{
	protected :
		int tuso;
		int mauso;
	public:
		void nhap()
		{
			cout<<"nhap tu so:";
			cin>>tuso;
			do
			{
				cout<<"nhap mau so :";
				cin>>mauso;
			}
			while(mauso==0);
		}
		void xuat()
		{
			toigian();
			if(mauso<0)
			{
				tuso=-tuso;
				mauso=-mauso;
			}
			cout<<tuso<<"/"<<mauso<<endl;
		}
		//toi gian
		void toigian()
		{
			//tim ucln ts va ms
			int a=abs(tuso),b=abs(mauso);
			while(b!=0)
			{
				int r=a%b;
				a=b;
				b=r;
			}
			int ucln=a;
			tuso=tuso/ucln;
			mauso=mauso/ucln;
		}
		
};
class PS2 :public PS1{
	public:
		void nhap()
		{
			PS1::nhap();
		}
		void xuat()
		{
			PS1::xuat();
		}
		bool operator =(PS2 c)
		{
			//this=a
			tuso=c.tuso;
			mauso=c.mauso;
			return true;
		}
		//nap chong toan tu > ,ktra this>a: ts/ms > a.ts/a.ms;
		bool operator >(PS2 c)
		{
			return tuso*c.mauso > c.tuso*mauso;
		}
};
int main()
{
	PS2 x,y;
	x.nhap();
	x.xuat();
	y.nhap();
	y.xuat();
	if(x>y)
	 cout<<"dung x>y";
	
	return 0;
}

