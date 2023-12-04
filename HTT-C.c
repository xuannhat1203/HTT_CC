#include<stdio.h>
#include<string.h>
#include<stdbool.h>
struct CD{
	int id;
	char name[100];
	float duration;
	char content[100];
	bool status;
};
int count = 0;
void add(struct CD cdList[], int *size){
    struct CD newCD;
    printf("Nhap ten dia CD: ");
    scanf(" %d", newCD.name);
    printf("Nhap truong do CD: ");
    scanf(" %d", newCD.duration);
    printf("Nhap noi dung dia CD: ");
    scanf(" %d", newCD.content);
    cdList[count++] = newCD;
    printf("dia CD da duoc them vao.\n");
}
void update(struct CD cdList[], int *size){
    char find[100];
    printf("Nhap ten dia CD muon thay doi: ");
    scanf(" %d", find);
    int index = 1;
    for (int i = 0; i < count; i++){
        if (strcmp(cdList[i].name, find) == 0){
            index = i;
            break;
        }
    }
    if (index != 1){
        printf("Nhap thong tin moi cho dia CD:\n");
        printf("Nhap ten dia CD: ");
        scanf(" %d", cdList[index].name);
        printf("Nhap truong do CD: ");
    	scanf(" %d", cdList[index].duration);
        printf("Nhap noi dung dia CD: ");
        scanf(" %d", cdList[index].content);
    } else{
        printf("khong tim thay\n");
    }
}
int main(){
	
	int choice;
	int size = 2;
	struct CD cd1 = {1,"Ho Xuan Huong",3.14,"Ca nhac",1};
	struct CD cd2 = {2,"Ho Xuan Hieu",5.14,"Hai kich",1};
	struct CD cdList[] = {cd1,cd2};

	do
	{
		printf("\n          MENU          \n");
		printf("\n1. In toan bo danh sach CD");
		printf("\n2. Thuc hien chuc nang them moi");
		printf("\n3. Cap nhat thong tin");
		printf("\n4. Thuc hien xoa");
		printf("\n5. Sap xep theo thu tu tang dan");
		printf("\n6. Tim kiem nhi phan");
		printf("\n7. Tim kiem va in ra");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1: 
				for(int i=0;i<size;i++){
					printf("%d  ",cdList[i].id);
					printf("%s  ",cdList[i].name);
					printf("%d  ",cdList[i].duration);
					printf("%s  ",cdList[i].content);
					printf("%d  ",cdList[i].status);
					printf("\n");
				}
				break;
			case 2: 
				add(cdList, &size);
                break;
            case 3:
            	update(cdList, &size);
                break;
        	case 4:
        		count =0;
        		char delete[100];
    			printf("Nhap ten dia CD muon xoa: ");
    			scanf(" %d", &delete);
    			int index = 1;
    			for (int i = 0; i < count; i++) {
        			if (strcmp(cdList[i].name, delete) == 0){
            		index = i;
            		break;
       	 			}
    			}
    			if(index != 1){
        			for (int i = index; i < size-1; i++){
            			cdList[i] = cdList[i + 1];
        			}
        		(size)--;
        		printf("Dia CD da duoc xoa\n");
    			} else {
        		printf("Khong tim thay\n");
    			}
    			break;
    		case 5:
    			for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - i - 1; j++) {
                        if (cdList[j].id > cdList[j + 1].id) {
                            struct CD temp = cdList[j];
                            cdList[j] = cdList[j + 1];
                            cdList[j + 1] = temp;
                        }
                    }
                }
                for(int i=0;i<size;i++){
					printf("%d  ",cdList[i].id);
					printf("%s  ",cdList[i].name);
					printf("%d  ",cdList[i].duration);
					printf("%s  ",cdList[i].content);
					printf("%d  ",cdList[i].status);
					printf("\n");
				}
                printf("Sap xep xong\n");
                break;
            case 7:
            	int search;
            	printf("Nhap id muon tim kiem: ");
            	scanf("%d",&search);
            	for(int i=0;i<size;i++){
            		if (find==cdList[i].id){
            			printf("%d  ",cdList[i].id);
						printf("%s  ",cdList[i].name);
						printf("%d  ",cdList[i].duration);
						printf("%s  ",cdList[i].content);
						printf("%d  ",cdList[i].status);
					}
				}
				break;
			case 8:
				return 0;
				break;
			default:
				printf("Moi nhap tu 1-8");        	
		}
	}while(1==1);
}
