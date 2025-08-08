#include<stdio.h>
int main(){
	int row1,col1,row2,col2;
	
	printf("Enter the row and column of first matrix:");
	scanf("%d%d",&row1,&col1);
	
	int m1[row1][col1];
	
	printf("Enter the elements for first matrix:\n");
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			scanf("%d",&m1[i][j]);
		}
	}
	printf("\nThe first matrix:\n");	
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			printf("%d\t",m1[i][j]);
		}
		printf("\n");
	}
	printf("Enter the row and column of first matrix:");
	scanf("%d%d",&row2,&col2);
	
	int m2[row2][col2];
	
	printf("Enter the elements for second matrix:\n");
	for(int i=0;i<row2;i++){
		for(int j=0;j<col2;j++){
			scanf("%d",&m2[i][j]);
		}
	}
	printf("\nThe second matrix:\n");
	for(int i=0;i<row2;i++){
		for(int j=0;j<col2;j++){
			printf("%d\t",m2[i][j]);
		}
		printf("\n");
	}
	
	//Adding two matrix
	
	int add[row1][col1];
	
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			add[i][j]=m1[i][j]+m2[i][j];
		}
	}
	printf("\nThe added matrix:\n");
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			printf("%d\t",add[i][j]);
		}
		printf("\n");
	}
	
	//non zero elements
	int count=0;
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			if(add[i][j]!=0){
				count++;
			}
		}
	}
	//transposing  matrix
	int trans[col1][row1];
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			trans[i][j]=add[j][i];
		}
	}
	printf("\nTranspose of added matrix is:\n");
	for(int i=0;i<col1;i++){
		for(int j=0;j<row1;j++){
			printf("%d\t",trans[i][j]);
		}
		printf("\n");
	}
	
	//compact matrix
	int compact[count+1][3];
	compact[0][0]=row1;
	compact[0][1]=col1;
	compact[0][2]=count;
	
	int d=1;
	
	for(int i=0;i<row1;i++){
		for(int j=0;j<col1;j++){
			if(trans[i][j]!=0){
				
				compact[d][0]=i;
				compact[d][1]=j;
				compact[d][2]=trans[i][j];
				d++;
			}
		}
	}
	printf("\nCompact matrix\nrow\tcolumn\tvalue\n");
	for(int i=0;i<=count;i++){
		printf("%d\t%d\t%d\n",compact[i][0],compact[i][1],compact[i][2]);
	}
	
return 0;
}	
