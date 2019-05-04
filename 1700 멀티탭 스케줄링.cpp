#include<stdio.h>
int main(){
	int N,K;
	int use_cnt=0,cnt=0;
	int min_k=0;
	int use[101]={0}; // ²ÅÇôÀÖ´Â ¾Ö 
	int plug[101]={0}; // »ç¿ë È½¼ö 
	int sequence[101]={0}; // »ç¿ë ¼ø¼­ 
	scanf("%d %d",&N,&K);
	for(int i = 0 ; i < K ; i++){
		scanf("%d",&sequence[i]);
		plug[sequence[i]]++;
	}

	for(int i = 0 ; i < K ; i++){
		if(use[sequence[i]]==1){
		//	printf("1\n");
			plug[sequence[i]]--;
			continue;
		}
		if(use_cnt < N){
	//		printf("2\n");
			use[sequence[i]]=1;
			plug[sequence[i]]--;
			use_cnt++;
		}
		else if(use_cnt == N){
	//		printf("3\n");
			cnt++;
			int min = 987654321;
			int idx=i,val=0;
			int l;
			for(int j = 1 ; j <= K ; j++){
				if(use[j]){
					for(l = i ; l < K ; l++){
						if(sequence[l]==j){
							if(l>idx){
								idx = l;
								val = sequence[l];
								printf("idx = %d\n",idx);
								printf("val = %d\n",val);
							}
						}
					if(l==K)
						val = j;
					}
				}
			}
			if(val==0){
				for(int j = 1 ; j <= K ; j++){
					if(use[j]){
						val = j;
						break;
					}
				}
			}
			printf("%d¹ø plug »ÌÈû\n",val);
			use[val]=0;
			plug[sequence[i]]--;
			use[sequence[i]]=1;
		}
		
	}
	for(int i = 1 ; i <= K; i++)
		printf("%d ",plug[i]);
	printf("\n%d\n",cnt);
}
