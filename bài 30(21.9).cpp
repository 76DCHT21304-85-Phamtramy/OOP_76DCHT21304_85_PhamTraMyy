//lop SP1:phan thuc,phan ao||xd tao,nhap,in,tinh moudle sp
//lopSP2 : ke thua,nap chong =,>
// tao ds toi da 10 ptu,sx giam dan moudul
#include<iostream> 
#include<math.h>
using namespace std;
class SP1{
	protected:
		float phanthuc;
		float phanao;
	public:
		//ham tao khong doi
		SP1()
		{
			phanthuc=0;
			phanao=0;
		}
		//ham tao co doi
		SP1(float phanthuc,float phanao)
		{
			this->phanthuc=phanthuc;
			this->phanao=phanao;
		}
		void nhap()
		{
			cout<<"nhap phan thuc :";
			cin>>phanthuc;
			cout<<"nhap phan ao:";
			cin>>phanao;
		}
		void xuat()
		{
			cout<<phanthuc;
			if(phanao>0)
			cout<<"+"<<phanao<<"i"<<endl;
			else
			cout<<"-"<<-phanao<<"i";
			cout<<"    |x|="<<moudle()<<endl;
		}
		//tinhs moudle la tinh do dai so phuc |z|=can(a*a+b*b)
		float moudle()
		{
			return sqrt(phanthuc*phanthuc+phanao*phanao);
		}
		
		
};
class SP2 : public SP1{
	public:
		void nhap()
		{
			SP1::nhap();
		}
		void xuat()
		{
			SP1::xuat();
		}
		//nap chong toan tu gan
		bool operator =(SP2 c)
		{
			phanthuc=c.phanthuc;
			phanao=c.phanao;
			return true;
		}
		//nap chong > moudle
		bool operator >(SP2 c)
		{
			return moudle()>c.moudle();
		}
		
};
int main()
{
	//goi ham tao SP1
	// SP1 a(4,5);
	SP2 ds[10];
	int n;
	cout<<"nhap so luong so phuc:";
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cout<<"so phuc thu "<<i+1<<":"<<endl;
		ds[i].nhap();
	}
	//sx giam dan moudle
	cout<<"**** DS MOUDLE GIAM DAN :"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ds[j]>ds[i])
			{
				SP2 temp=ds[j];
				ds[j]=ds[i];
				ds[i]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		ds[i].xuat();
	}
	return 0;
	
}
