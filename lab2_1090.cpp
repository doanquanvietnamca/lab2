#include <bits/stdc++.h>
int army,ans,tempA; 
int h[10101];
int Ih[102];
int N,K;
int main(void)
{
	while(std::cin>>N>>K){
		
		army=-1;ans=1;
		for(int i=0;i<K;i++){
			memset(h,0,sizeof(h));memset(Ih,0,sizeof(Ih));
			tempA=0;
			for(int j=0;j<N;j++){
				int temp;
				scanf("%d",&temp);
				for(int i=temp;i<temp/100*100+100;i++) tempA+=h[i];
				for(int i=temp/100+1;i<=101;i++) tempA+=Ih[i];
				h[temp]++;Ih[temp/100]++;
			}
			if(~army) {
				if(tempA>=army) army=tempA,ans=i+1;
			}
			else army=tempA,ans=i+1;
		}
		std::cout<<ans<<std::endl;
	}
return 0;
}