//instances generator for sorting algorithms
#include "gen.hpp"
using namespace std;
int main() 
{
	int p, s, ile;
	unsigned int VerNum, EdgeQt, Adds, v[3] ;
	float Sat;
	std::set <set <int> > Used;
	std::set <int> act;
	std::set <int> bct;
	std::set <int> cct;
	std::string pl;
	std::cout<<"Podaj nazwê pliku"<<std::endl;
	std::cin>>pl;
	std::cout<<"Podaj Liczbê wierzcho³ków"<<std::endl;
	std::cin>>VerNum;
	std::cout<<"Podaj nasycenie grafu"<<std::endl;
	std::cin>>Sat;	
	srand(time(NULL));
	std::vector <int> InGraf;
	std::vector <int>::iterator I;
	std::set <int>::iterator S;
	std::set <int> OutGraf;
	for (int i = 0; i < VerNum; i++) OutGraf.insert(i);
	EdgeQt = ((VerNum*(VerNum-1))/2) * Sat;
	int* DegList = new int [VerNum];
	for(int abc =0;abc<VerNum;abc++)
		{
			DegList[abc]=0;
		}	
	bool** Graf = new bool* [VerNum];
	for (int i = 0; i<VerNum; i++)
	{
		Graf[i] = new bool[EdgeQt];
		for(int j = 0 ; j < EdgeQt; j++)
			Graf[i][j] = 0;
	}
	for (int i = 0; i < EdgeQt/3; i++)
	{
		if (InGraf.size() == 0 || InGraf.size() == VerNum)
		{
			do
			{
				act.clear();
				bct.clear();
				cct.clear();
				v[0] = std::rand()%VerNum;
				do
				{
					v[1] = std::rand()%VerNum;
				}while (v[1] == v[0]);
				do
				{
					v[2] = std::rand()%VerNum;
				}while (v[2] == v[0] || v[2] ==v[1]);
				act.insert(v[1]);
				act.insert(v[2]);
				bct.insert(v[2]);
				bct.insert(v[0]);
				cct.insert(v[0]);
				cct.insert(v[1]);
			}while (Used.count(act) != 0 || Used.count(bct) != 0 || Used.count(cct)!= 0);
			Used.insert(act);
			Used.insert(bct);
			Used.insert(cct);	
//			for(set<set<int> >::iterator it = Used.begin(); it!=Used.end();it++)
//			{
//				cout<<"(";
//				for(set<int>::iterator itt = it->begin(); itt != it->end();itt++) cout<<*itt<<", ";
//				cout<<")";
//			}
//			cout<<e	
			for(int j=0;j<3;j++)
			{
				s=3*i+j;				
				for (int k=0; k<VerNum; k++)
				{
					if (k==v[j] || k == v[(j+1)%3])
					{
						Graf[k][s] = 1; 
						DegList[k] += 1;
					}
					else
					{
						Graf[k][s] = 0;
					}
				}
				if (InGraf.size() <3)
				{
					InGraf.push_back(v[j]);
					OutGraf.erase(v[j]);
				}
			}
		}
		else
		{
			do
			{
				act.clear();
				bct.clear();
				cct.clear();
				p= VerNum - InGraf.size();
				s = InGraf[std::rand()%InGraf.size()];
				v[0] = s;
				do
				{
					if (p < 2)
					{
						s = InGraf[std::rand()%InGraf.size()];
						v[1] = s;	
					}
					else
					{		
						s = std::rand() % OutGraf.size();
						S = OutGraf.begin();
						for (int a = 0; a<s;a++) S++;						
						v[1] = * S;
					}
				}while (v[1] == v[0]);
				do
				{		
					s = std::rand() % OutGraf.size();
					S = OutGraf.begin();
					for (int a = 0; a<s;a++) S++;					
					v[2] = * S;
				}while (v[2] == v[0] || v[2]==v[1]);
				act.insert(v[1]);
				act.insert(v[2]);
				bct.insert(v[2]);
				bct.insert(v[0]);
				cct.insert(v[0]);
				cct.insert(v[1]);
			}while (Used.count(act) != 0 || Used.count(bct) != 0 || Used.count(cct)!=0);
			Used.insert(act);
			Used.insert(bct);
			Used.insert(cct);
			for (int j=0;j<3;j++)
			{
				s=3*i+j;				
				for (int k=0; k<VerNum; k++)
				{
					if (k==v[j] || k == v[(j+1)%3])
					{
						Graf[k][s] = 1; 
						DegList[k] += 1;
					}
					else
					{
						Graf[k][s] = 0;
					}
					if (OutGraf.count(v[j]))
					{
					InGraf.push_back(v[j]);
					OutGraf.erase(v[j]);
					}
				}
			}		
		}
	}
	
	std::fstream plik;
	plik.open( pl.c_str(), std::ios::app );
	plik<<VerNum<<" "<<Sat<<std::endl;
	for(int i = 0; i<VerNum; i++)
	{
		for (int j = 0; j<EdgeQt;j++)
		{
			plik<<Graf[i][j]<<" ";
		}
		plik<<std::endl;
	} 
	void close(void);
	return 0;
}
