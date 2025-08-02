#include<stdio.h>
int main(){
	int row,col;
	
	printf("Enter the row and column of first matrix:");
	scanf("%d%d",&row,&col);
	
	int m1[row][col];
	
	printf("Enter the elements for first matrix:");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&m1[i][j]);
		}
	}
	printf("\nThe first matrix:\n");	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",m1[i][j]);
		}
		printf("\n");
	}
	
	
	int m2[row][col];
	
	printf("Enter the elements for second matrix:");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&m2[i][j]);
		}
	}
	printf("\nThe second matrix:\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",m2[i][j]);
		}
		printf("\n");
	}
	
	//Adding two matrix
	
	int add[row][col];
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			add[i][j]=m1[i][j]+m2[i][j];
		}
	}
	printf("The added matrix:\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",add[i][j]);
		}
		printf("\n");
	}
	
	//transposing matrix
	
	printf("The Transposed matrix:\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d\t",add[j][i]);
		}
		printf("\n");
	}
	
	//non zero elements
	int count=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(add[i][j]!=0){
				count++;
			}
		}
	}
	
	printf("the no of non-zero elements: %d",count);	
	
return 0;
}	
