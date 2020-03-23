
#include <string>
#include <iostream>
using namespace std;
 
void Cipher()
{
	string s;
	cin>>s;
	int c = 1;
	string rs;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (rs.empty() || rs.back() != s[i])
		{
			if (c % 2 == 0) rs.pop_back();			
			if (!rs.empty() && rs.back() == s[i]) c = 2;
			else
			{
				rs.push_back(s[i]);
				c = 1;
			}
		}
		else c++;
	}
	if (c % 2 == 0 && !rs.empty()) rs.pop_back();
	cout<<rs;
}
 
int main()
{
	Cipher();
	return 0;
}