#include<stdio.h>
struct student{
	int id;
	char name[25];
	int age;
};
void display(struct student *sv, int n);
void add(struct student *sv, int *n);
void edit(struct student *sv, int n);
void Delete(struct student *sv, int *n);
void search(struct student *sv, int n);
void sort(struct student *sv, int n);
void loadFromFile(struct student *sv, int *n);
void saveToFile(struct student *sv, int *n);
void menu();

int main(){
	int choice;
	struct student sv[100];
	int n = 0;
	loadFromFile(sv,&n);
	do{
		
		menu();
		printf("Nhap lua chon cua ban ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: 
			display(sv,n);
			printf("\n");
			break;
			case 2:
				add(sv, &n);
				printf("\n");
				break;
				case 3:
					edit(sv,n);
					printf("\n");
					break;
					case 4:
						Delete(sv,&n);
						printf("\n");
						break;
						case 5:
							search(sv,n);
							printf("\n");
							break;
							case 6:
								sort(sv,n);
								printf("\n");
								break;
								case 7:
								saveToFile(sv,&n);
									printf("BYE!!!");
									break;
									default :
										printf("Lua chon khong hop le");
		}
	}while(choice!=7);
	return 0;
}
void display(struct student *sv, int n){
	if(n==0){
		printf("Mang dang khong co sinh vien\n");
		return;
	}
	for(int i = 0; i<n; i++){
		printf("Thong tin sinh vien thu %d: \n",i+1);
		printf("ID: %d\n",sv[i].id);
		printf("Ten sinh vien: %s\n",sv[i].name);
		printf("Tuoi: %d\n",sv[i].age);
		printf("\n");
	}
}
	void add(struct student *sv, int *n){
		if(*n>100){
			printf("Danh sach sinh vien da day\n");
			return;
		}
		printf("Nhap id sinh vien: ");
		scanf("%d", &sv[*n].id);
		getchar();
		printf("Nhap ten sinh vien: ");
		fgets(sv[*n].name,sizeof(sv[*n].name),stdin);
		
		printf("Nhap tuoi sinh vien: ");
		scanf("%d",&sv[*n].age);
		getchar();
		(*n)++;
}
void edit(struct student *sv, int n){
	int id, found;
	printf("Nhap id sinh vien can chinh sua: ");
	scanf("%d", &id);
	getchar();
	for(int i = 0;i<n;i++){
		found = 1;
		if(sv[i].id==id){
			printf("Nhap ten moi: ");
			fgets(sv[i].name,sizeof(sv[i].name),stdin);
			printf("Nhap tuoi: ");
			scanf("%d", &sv[i].age);
		}
	}
	if(found!=1){
		printf("Khong tim thay sinh vien can chinh sua");
		return;
	}
}
void Delete(struct student *sv, int *n){
	int id, found;
	printf("Nhap id sinh vien can xoa: ");
	scanf("%d", &id);
	for(int i = 0; i<*n; i++){
		if(sv[i].id==id){
			found = 1;
			for(int j = i; j<*n-1; j++){
				sv[j]=sv[j+1];
			}
			(*n)--;
			break;
		}
	}
	if(found!=1){
		printf("Khong tim thay sinh vien can xoa");
		return;
}
}
void search(struct student *sv, int n){
	int id, found;
	printf("Nhap id sinh vien can tim kiem: ");
	scanf("%d", &id);
	for(int i = 0; i<n;i++){
		if(sv[i].id==id){
			found=1;
			printf("Ten sinh vien: %s\n", sv[i].name);
			printf("Tuoi sinh vien: %d", sv[i].age);
			break;
		}
	}
	if(found!=1){
		printf("Khong tim thay sinh vien can tim");
		return;
}
}
void sort(struct student *sv, int n){
	struct student temp;
	for(int i =0;i<n-1;i++){
		for(int j =i+1;j<n;j++){
			if(sv[i].id>sv[j].id){
			
			sv[i]=temp;
			sv[i]=sv[j];
			sv[j]=temp;
		}
		}
	}
}
void loadFromFile(struct student *sv, int *n){
	FILE *fptr;
	fptr=fopen("sinhvien.bin","rb");

	fread(n,sizeof(int),1,fptr);
	fread(sv,sizeof(struct student),*n,fptr);
	fclose(fptr);
}
void saveToFile(struct student *sv, int *n){
	FILE *fptr;
	fptr = fopen("sinhvien.bin","wb");
	if(fptr==NULL){
		printf("Loi mo file");
		return;
	}
	fwrite(n,sizeof(int),1,fptr);
	fwrite(sv,sizeof(struct student),*n,fptr);
	fclose(fptr);
}
void menu(){
	printf("           MENU     \n");
	printf("1.In danh sach sinh vien\n");
	printf("2.Them sinh vien\n");
	printf("3.Sua thong tin sinh vien\n");
	printf("4.Xoa sinh vien\n");
	printf("5.Tim kiem sinh vien\n");
	printf("6.Sap xep danh sach sinh vien\n");
	printf("7.Thoat\n");
}





