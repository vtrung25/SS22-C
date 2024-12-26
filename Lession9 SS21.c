#include<stdio.h>
struct book{
	int id;
	char name[25];
	char author[25];
	float price;
	char type[25];
	
};

void menu();
void addInput(struct book *Sach, int *n);
void saveToFile(struct book *Sach, int n);
void getIn4(struct book *Sach, int *n);
void showIn4(struct book *Sach, int n);
int main(){
	int choice;
	int n;
	struct book Sach[100];
	do{
		menu();
		printf("Nhap lua chon cua ban ");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
			addInput(Sach,&n);
			break;
			case 2:
				saveToFile(Sach,n);
				break;
				case 3:
					getIn4(Sach,&n);
					break;
					case 4:
						showIn4(Sach,n);
						break;
						case 5:
							printf("BYE!!!");
						default:
							printf("Lua chon khong hop le");
		}
		printf("\n");
	}while(choice!=5);
	return 0;
}
void menu(){
	printf("          MENU      \n");
	printf("1.Nhap so luong va thong tin sach\n");
	printf("2.Luu thong tin sach vao file\n");
	printf("3.Lay thong tin sach tu file\n");
	printf("4.Hien thi thong tin sach\n");
	printf("5.Thoat\n\n");
}
void addInput(struct book *Sach, int *n){
	
	printf("Nhap so luong sach: ");
	scanf("%d", n);
	
	for(int i = 0; i<*n; i++){
		printf("Nhap thong tin sach thu %d: \n", i+1);
		printf("ID: ");
		scanf("%d", &Sach[i].id);
		getchar();
		printf("Ten sach: ");
		fgets(Sach[i].name,sizeof(Sach[i].name), stdin);
		printf("Ten tac gia: ");
		fgets(Sach[i].author,sizeof(Sach[i].author),stdin);
		printf("Gia: ");
		scanf("%f", &Sach[i].price);
		getchar();
		printf("The loai: ");
		fgets(Sach[i].type,sizeof(Sach[i].type),stdin);
		printf("\n");
	}
}
void saveToFile(struct book *Sach, int n){
	FILE *fptr;
	fptr = fopen("book.bin","wb");
	
		fwrite(&n,sizeof(int),1,fptr);
		fwrite(Sach,sizeof(struct book),n,fptr);
	}
	fclose(fptr);
	void getIn4(struct book *Sach, int *n){
		FILE *fptr;
		fptr = fopen("book.bin","rb");
		fread(n,sizeof(int),1,fptr);
		fread(Sach,sizeof(struct book),*n,fptr);
		fclose(fptr);
		
	}
	void showIn4(struct book *Sach, int n){
		for(int i = 0; i<n;i++){
			printf("Thong tin sach thu %d\n",i+1);
			printf("ID: %d\n", Sach[i].id);
			printf("Ten sach: %s\n",Sach[i].name);
			printf("Ten tac gia: %s\n",Sach[i].author);
			printf("Gia sach: %f\n",Sach[i].price);
			printf("The loai: %s\n",Sach[i].type);
			printf("\n");
		}
	}
	
	
