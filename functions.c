#include <ctype.h>
#include <stdio.h>
#include "functions.h"
#include <string.h>

void menuStart(){
	
    printf("\n***He thong Quan ly Sinh vien su dung ngon ngu lap trinh C***\n");
    printf("\n");
    printf("\t  CHON VAI TRO CUA BAN\n");
    printf("\t=====================\n");
    printf("\t[1] Admin.\n");
    printf("\t[2] Student.\n");
    printf("\t[3] Teacher. \n");
    printf("\t[0] Thoat chuong trinh.\n");
    printf("\t=====================\n");
}
void menuAdmin(){

    printf("\n***He thong Quan ly Sinh vien Su dung C***\n");
    printf("\n");
    printf("\t         MENU\n");
    printf("\t==========================\n");
    printf("\t[1] Quan ly sinh vien.\n");
    printf("\t[2] Quan ly lop hoc. \n");
    printf("\t[3] Quan ly giao vien.\n");
    printf("\t[4] Huong dan nguoi dung.\n");
    printf("\t[0] Back.\n");
    printf("\t==========================\n");
}
void menuStudents(){
	
    printf("\n***He thong quan ly sinh vien su dung C***\n");
    printf("\n");
    printf("\t    STUDENT MENU\n");
    printf("\t======================\n");
    printf("\t[1] Them sinh vien moi.\n");
    printf("\t[2] Hien thi danh sach sinh vien.\n");
    printf("\t[3] Xoa mot sinh vien.\n");
    printf("\t[4] Chinh sua thong tin mot sinh vien.\n");
    printf("\t[5] Tim kiem mot sinh vien\n");
    printf("\t[6] Sap xep sinh vien.\n");
    printf("\t[0] Thoat.\n");
    printf("\t======================\n");
}
void addStudent(int *length, struct Student sv[]) {
    // dinh nghia cac ham kiem tra ben trong addStudent
    int isValidPhoneNumber(char* phone) {
    	int i;
        for (i = 0; phone[i] != '\0'; i++) {
            if (!isdigit(phone[i])) {
                return 0;  // khong hop le neu co ki tu khong phai chu so
            }
        }
        return 1; //hop le neu cac ki tu la chu so
    }

    int isValidEmail(char* email) {
        if (strchr(email, '@') != NULL) {
            return 1;  // Hop le neu co dau '@'
        }
        return 0;
    }

    int isValidPassword(char* password) {
        if (strlen(password) >= 6) {
            return 1;  // hop le neu mat khau tu 6 ki tu tro len
        }
        return 0;
    }

    printf("\n\t***Them mot sinh vien***\n");
    int newStudents;
    printf("\nThem so luong hoc sinh: ");
    scanf("%d", &newStudents);
    getchar();
    
    int i;
    for (i = *length; i < *length + newStudents; i++) {
        printf("\n       Student %d\n", i + 1);
        
        // Nhap thong tin sinh vien
        printf("Nhap Id sinh vien: ");
        fgets(sv[i].studentId, 10, stdin);
        sv[i].studentId[strcspn(sv[i].studentId, "\n")] = '\0';
        
        printf("Nhap ten sinh vien: ");
        fgets(sv[i].fullName, 30, stdin);
        sv[i].fullName[strcspn(sv[i].fullName, "\n")] = '\0';
        
        // Kiem tra ngay thang nam sinh
        printf("Nhap ngay sinh cho sinh vien (dd / mm / yyyy): \n");
        
        do {
            printf("   Nhap ngay sinh: ");
            scanf("%d", &sv[i].dateOfBrith.day);
            if (sv[i].dateOfBrith.day < 1 || sv[i].dateOfBrith.day > 31) {
                printf("Ngay khong hop le! Vui long nhap lai.\n");
            }
        } while (sv[i].dateOfBrith.day < 1 || sv[i].dateOfBrith.day > 31);
        
        do {
            printf("   Nhap thang sinh: ");
            scanf("%d", &sv[i].dateOfBrith.month);
            if (sv[i].dateOfBrith.month < 1 || sv[i].dateOfBrith.month > 12) {
                printf("Thang khong hop le! Vui long nhap lai.\n");
            }
        } while (sv[i].dateOfBrith.month < 1 || sv[i].dateOfBrith.month > 12);
        
        do {
            printf("   Nhap nam sinh: ");
            scanf("%d", &sv[i].dateOfBrith.year);
            if (sv[i].dateOfBrith.year < 1 || sv[i].dateOfBrith.year > 2024) {
                printf("Nam khong hop le! Vui long nhap lai.\n");
            }
        } while (sv[i].dateOfBrith.year < 1 || sv[i].dateOfBrith.year > 2024);
        
        // Kiem tra gioi tinh
        do {
            printf("Nhap gioi tinh cho sinh vien(1 for Male, 0 for Female): ");
            scanf("%d", &sv[i].gender);
            if (sv[i].gender != 1 && sv[i].gender != 0) {
                printf("Gioi tinh khong hop le! Vui long nhap lai.\n");
            }
        } while (sv[i].gender != 1 && sv[i].gender != 0);
        
        getchar();
        
        // Nhap lop hoc
        printf("Nhap lop cho sinh vien: ");
        fgets(sv[i].classroomId, 10, stdin);
        sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
        
        // Nhap email va kiem tra xem email co hop le hay khong
        do {
            printf("Nhap email cho sinh vien: ");
            fgets(sv[i].email, 30, stdin);
            sv[i].email[strcspn(sv[i].email, "\n")] = '\0';
            if (!isValidEmail(sv[i].email)) {
                printf("Email khong hop le! Vui long nhap lai.\n");
            }
        } while (!isValidEmail(sv[i].email));
        
        // Nhap so dien thoai va kiem tra xem co hop le hay khong
        do {
            printf("Nhap so dien thoai cho sinh vien: ");
            fgets(sv[i].phone, 20, stdin);
            sv[i].phone[strcspn(sv[i].phone, "\n")] = '\0';
            if (!isValidPhoneNumber(sv[i].phone)) {
                printf("So dien thoai khong hop le! Vui long nhap lai.\n");
            }
        } while (!isValidPhoneNumber(sv[i].phone));
        
        // Nhap mat khau va kiem tra tinh hop le hay khong
        do {
            printf("Nhap mat khau cho sinh vien: ");
            fgets(sv[i].password, 20, stdin);
            sv[i].password[strcspn(sv[i].password, "\n")] = '\0';
            if (!isValidPassword(sv[i].password)) {
                printf("Mat khau phai co it nhat 6 ky tu. Vui long nhap lai.\n");
            }
        } while (!isValidPassword(sv[i].password));
    }
    
    *length += newStudents;
    printf("\nThem sinh vien thanh cong.\n");
}
void printHeader(){
	
	printf("\n\t  ***All Student***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|\n");
}
void printStudent(int length, struct Student sv[]){
	
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s|\n",
            sv[i].studentId,
            sv[i].classroomId,
            sv[i].fullName,
            sv[i].dateOfBrith.day,
            sv[i].dateOfBrith.month,
            sv[i].dateOfBrith.year,
            sv[i].gender ? "Male" : "Female",
            sv[i].email,
            sv[i].phone);
            printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|\n");
    }
}
void saveStudentToFile(int length, struct Student sv[]){
	
    FILE *fptr = fopen("studentsData.dat", "wb");
    if (fptr == NULL) {
        printf("Khong the mo tep\n");
        return;
    }
    fwrite(sv, sizeof(struct Student), 50, fptr);
    printf("Du lieu sinh vien duoc luu thanh cong\n");
    fclose(fptr);
}
void loadStudentFromFile(int *length, struct Student sv[]){
	
    FILE *fptr = fopen("studentsData.dat", "rb");
    if (fptr == NULL) {
        printf("Khong tim thay du lieu.\n");
        return;
    }
    *length = fread(sv, sizeof(struct Student), 50, fptr);
    fclose(fptr);
}
void deleteStudent(int *length, struct Student sv[]) {	system("cls");
    printf("\n\t***Xoa mot sinh vien***\n");
    getchar();
	char id[10];
    printf("\nNhap ma sinh vien de xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(sv[i].studentId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nKhong tim thay sinh vien voi Id %s.\n", id);
    }else {
        printf("\nMot sinh vien da duoc tim thay voi Id: %s\n", id);
        printf("  Thong tin sinh vien:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",sv[findIndex].classroomId);
        printf("FullName: %s\n",sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",sv[findIndex].dateOfBrith.day,sv[findIndex].dateOfBrith.month,sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",sv[findIndex].email);
        printf("Phone: %s\n",sv[findIndex].phone);
        printf("Password: %s\n",sv[findIndex].password);
        for(i=findIndex;i<*length-1; i++){
            sv[i]=sv[i+1];
        }
        (*length)--;
        printf("\n\t***Cap nhat thong tin sinh vien moi ***\n");
        printHeader();
        printStudent(*length, sv);
        printf("\nDa xoa sinh vien thanh cong.\n");
    }
}
void editStudent(int length, struct Student sv[]) {
    system("cls");
    printf("\n\t***Chinh sua thong tin sinh vien***\n");

    char id[10];
    printf("\nNhap Id sinh vien can sua: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int findIndex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(sv[i].studentId, id) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("\nKhong tim thay sinh vien voi Id %s.\n", id);
    } else {
        printf("\nCo mot sinh vien voi Id: %s\n", id);
        printf("  Thong tin sinh vien:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);

       
        printf("\nNhap ten moi: ");
        fgets(sv[findIndex].fullName, 30, stdin);
        sv[findIndex].fullName[strcspn(sv[findIndex].fullName, "\n")] = '\0';

        
        do {
            printf("Nhap vao ngay, thang, nam sinh moi (dd / mm / yyyy):\n");
            printf("   Nhap vao ngay sinh: ");
            scanf("%d", &sv[findIndex].dateOfBrith.day);
            if (sv[findIndex].dateOfBrith.day < 1 || sv[findIndex].dateOfBrith.day > 31) {
                printf("%d ngay ban nhap khong hop le, vui long nhap lai.\n", sv[findIndex].dateOfBrith.day);
            }
        } while (sv[findIndex].dateOfBrith.day < 1 || sv[findIndex].dateOfBrith.day > 31);

        do {
            printf("   Nhap vao thang sinh: ");
            scanf("%d", &sv[findIndex].dateOfBrith.month);
            if (sv[findIndex].dateOfBrith.month < 1 || sv[findIndex].dateOfBrith.month > 12) {
                printf("%d thang ban nhap khong hop le, vui long nhap lai.\n", sv[findIndex].dateOfBrith.month);
            }
        } while (sv[findIndex].dateOfBrith.month < 1 || sv[findIndex].dateOfBrith.month > 12);

        do {
            printf("   Nhap vao nam sinh: ");
            scanf("%d", &sv[findIndex].dateOfBrith.year);
            if (sv[findIndex].dateOfBrith.year < 1 || sv[findIndex].dateOfBrith.year > 2024) {
                printf("%d nam ban nhap khong hop le, vui long nhap lai.\n", sv[findIndex].dateOfBrith.year);
            }
        } while (sv[findIndex].dateOfBrith.year < 1 || sv[findIndex].dateOfBrith.year > 2024);

       
        do {
            printf("Nhap gioi tinh (1 for Male, 0 for Female): ");
            scanf("%d", &sv[findIndex].gender);
            if (sv[findIndex].gender != 1 && sv[findIndex].gender != 0) {
                printf("Gioi tinh ban nhap khong hop le, vui long nhap lai.\n");
            }
        } while (sv[findIndex].gender != 1 && sv[findIndex].gender != 0);

        getchar(); 

        
        printf("Nhap lop hoc moi: ");
        fgets(sv[findIndex].classroomId, 10, stdin);
        sv[findIndex].classroomId[strcspn(sv[findIndex].classroomId, "\n")] = '\0';

        
        int emailValid;
        do {
            printf("Nhap email moi: ");
            fgets(sv[findIndex].email, 30, stdin);
            sv[findIndex].email[strcspn(sv[findIndex].email, "\n")] = '\0';
           
            emailValid = (strchr(sv[findIndex].email, '@') != NULL);
            if (!emailValid) {
                printf("Email khong hop le, vui long nhap lai.\n");
            }
        } while (!emailValid);

       
        int phoneValid;
        do {
            printf("Nhap so dien thoai moi (chi nhap ky tu la chu so): ");
            fgets(sv[findIndex].phone, 20, stdin);
            sv[findIndex].phone[strcspn(sv[findIndex].phone, "\n")] = '\0';

           
            phoneValid = 1; 
            int j;
            for (j = 0; sv[findIndex].phone[j] != '\0'; j++) {
                if (!isdigit(sv[findIndex].phone[j])) {
                    phoneValid = 0; 
                    break;
                }
            }

            if (!phoneValid) {
                printf("So dien thoai khong hop le, vui long nhap lai.\n");
            }
        } while (!phoneValid);

        
        int passwordValid;
        do {
            printf("Nhap mat khau moi (toi thieu 6 ky tu): ");
            fgets(sv[findIndex].password, 20, stdin);
            sv[findIndex].password[strcspn(sv[findIndex].password, "\n")] = '\0';

            
            passwordValid = (strlen(sv[findIndex].password) >= 6);
            if (!passwordValid) {
                printf("Mat khau phai co it nhat 6 ky tu. Vui long nhap lai.\n");
            }
        } while (!passwordValid);

        // Hien thi lai sau khi cap nhat
        printf("\n\t***Cap nhat sinh vien moi***\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);

        printf("\nSinh vien da chinh sua thanh cong.\n");
    }
}
void searchStudent(int length, struct Student sv[]){
	
    printf("\n\t***Tim kiem mot sinh vien***\n");
    getchar();
	char name[30];
    printf("\Nhap ten de tim kiem sinh vien: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(sv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nKhong tim thay sinh vien nao voi ten %s.\n",name);
    }else{
        printf("\nSinh vien duoc tim thay voi ten %s.\n",name);
        printf("Da tim thay sinh vien thanh cong.\n\n");
	}
}
void sortStudentsByName(int length, struct Student sv[]){
	
    int choice4;
	do{
		printf("\n\t***Sap xep mot sinh vien***\n");
	    printf("\n");
	    printf("\t  Sap xep sinh vien\n");
	    printf("\t=====================\n");
	    printf("\t[1] Sap xep tang dan.\n");
	    printf("\t[2] Sap xep giam dan.\n");
	    printf("\t[0] Thoat.\n");
	    printf("\t=====================\n");
		printf("\tNhap vao lua chon cua ban: ");
	    scanf("%d", &choice4);
		switch(choice4){
			struct Student temp;
			int i,j;
			case 1:
			    printf("\n\t  Sap xep tang dan\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)>0){
			                temp = sv[i];
			                sv[i] = sv[j];
			                sv[j] = temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nHoc sinh duoc sap xep thanh cong.\n");
				break;
			case 2:
				printf("\n\t  Sap xep giam dan\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(sv[i].fullName, sv[j].fullName)<0){
			                temp=sv[i];
			                sv[i]=sv[j];
			                sv[j]=temp;
			            }
			        }
			    }
			    printHeader();
		        printStudent(length,sv);
			    printf("\nHoc sinh duoc sap xep thanh cong.\n");
				break;
			case 0:
				break;
			default:
				printf("\tLoi: moi ban nhap lai.\n");
	    }
	}while(choice4!=0);
}
void menuTeacher(){
	
    printf("\n***Quan ly giao vien bang ngon ngu C***\n");
    printf("\n");
    printf("\t    TEACHER MENU\n");
    printf("\t======================\n");
    printf("\t[1] Them mot giao vien moi.\n");
    printf("\t[2] Hien thi danh sach giao vien.\n");
    printf("\t[3] Xoa mot giao vien.\n");
    printf("\t[4] Chinh sua thong tin mot giao vien.\n");
    printf("\t[5] Tim kiem mot giao vien.\n");
    printf("\t[6] Sap xep giao vien.\n");
    printf("\t[7] Them giao vien vao lop hoc.\n");
    printf("\t[0] Thoat.\n");
    printf("\t======================\n");
}	
void addTeacher(int *length, struct Teacher tv[]) {
    printf("\n\t***Them mot giao vien moi***\n");

    int newTeacher;
    printf("\nThem so luong giao vien: ");
    scanf("%d", &newTeacher);
    getchar(); 
    
    int i;
    for (i = *length; i < *length + newTeacher; i++) {
        printf("\n       Giao vien %d\n", i + 1);

        
        printf("Nhap ID: ");
        fgets(tv[i].teacherId, 10, stdin);
        tv[i].teacherId[strcspn(tv[i].teacherId, "\n")] = '\0'; 

       
        printf("Nhap ten: ");
        fgets(tv[i].fullName, 30, stdin);
        tv[i].fullName[strcspn(tv[i].fullName, "\n")] = '\0';

       
        do {
            printf("Nhap ngay sinh: ");
            scanf("%d", &tv[i].dateOfBrith.day);
            if (tv[i].dateOfBrith.day < 1 || tv[i].dateOfBrith.day > 31) {
                printf("%d ngay ban nhap khong hop le. Vui long nhap lai.\n", tv[i].dateOfBrith.day);
            }
        } while (tv[i].dateOfBrith.day < 1 || tv[i].dateOfBrith.day > 31);

        do {
            printf("Nhap thang sinh: ");
            scanf("%d", &tv[i].dateOfBrith.month);
            if (tv[i].dateOfBrith.month < 1 || tv[i].dateOfBrith.month > 12) {
                printf("%d thang ban nhap khong hop le. Vui long nhap lai.\n", tv[i].dateOfBrith.month);
            }
        } while (tv[i].dateOfBrith.month < 1 || tv[i].dateOfBrith.month > 12);

        
        do {
            printf("Nhap nam sinh: ");
            scanf("%d", &tv[i].dateOfBrith.year);
            if (tv[i].dateOfBrith.year < 1 || tv[i].dateOfBrith.year > 2024) {
                printf("%d nam ban nhap khong hop le. Vui long nhap lai.\n", tv[i].dateOfBrith.year);
            }
        } while (tv[i].dateOfBrith.year < 1 || tv[i].dateOfBrith.year > 2024);

        
        do {
            printf("Nhap gioi tinh(1 for Male, 0 for Female): ");
            scanf("%d", &tv[i].gender);
            if (tv[i].gender != 1 && tv[i].gender != 0) {
                printf("Gioi tinh ban nhap khong hop le. Vui long nhap lai.\n");
            }
        } while (tv[i].gender != 1 && tv[i].gender != 0);

        getchar();  

        printf("Nhap lop: ");
        fgets(tv[i].classroomId, 10, stdin);
        tv[i].classroomId[strcspn(tv[i].classroomId, "\n")] = '\0';

       
        int emailValid;
        do {
            printf("Nhap email: ");
            fgets(tv[i].email, 30, stdin);
            tv[i].email[strcspn(tv[i].email, "\n")] = '\0';

            emailValid = (strchr(tv[i].email, '@') != NULL);
            if (!emailValid) {
                printf("Email khong hop le. Vui long nhap lai.\n");
            }
        } while (!emailValid);

        
        int phoneValid;
        do {
            printf("Nhap so dien thoai (chi nhap ky tu la chu so): ");
            fgets(tv[i].phone, 20, stdin);
            tv[i].phone[strcspn(tv[i].phone, "\n")] = '\0';

           
            phoneValid = 1;
            int j;
            for (j = 0; tv[i].phone[j] != '\0'; j++) {
                if (!isdigit(tv[i].phone[j])) {
                    phoneValid = 0;
                    break;
                }
            }

            if (!phoneValid) {
                printf("So dien thoai khong hop le. Vui long nhap lai.\n");
            }
        } while (!phoneValid);

       
        int passwordValid;
        do {
            printf("Nhap mat khau: ");
            fgets(tv[i].password, 20, stdin);
            tv[i].password[strcspn(tv[i].password, "\n")] = '\0';

            
            passwordValid = (strlen(tv[i].password) >= 6);
            if (!passwordValid) {
                printf("Mat khau phai co it nhat 6 ky tu. Vui long nhap lai.\n");
            }
        } while (!passwordValid);
    }

    *length += newTeacher;  
    printf("\nThem giao vien thanh cong.\n");
}
void printHeader2(){
	
	printf("\n\t  ***All Teacher***\n");
    printf("|============|=============|=========================|=======================|============|============================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               |\n");
    printf("|============|=============|=========================|=======================|============|============================|=====================|\n");
}		
void printTeacher(int length, struct Teacher tv[]){
	
    int i;
    for(i=0;i<length;i++){
    printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s|\n",
            tv[i].teacherId,
            tv[i].classroomId,
            tv[i].fullName,
            tv[i].dateOfBrith.day,
            tv[i].dateOfBrith.month,
            tv[i].dateOfBrith.year,
            tv[i].gender ? "Male" : "Female",
            tv[i].email,
            tv[i].phone);
            printf("|------------|-------------|-------------------------|-----------------------|------------|----------------------------|---------------------|\n");
    }
}
void saveTeacherToFile(int length, struct Teacher tv[]){
	
    FILE *fptr = fopen("teachersData.dat", "wb");
    if (fptr == NULL) {
        printf("Khong the mo file \n");
        return;
    }
    fwrite(tv, sizeof(struct Teacher), 50, fptr);
    printf("Du lieu giao vien duoc luu thanh cong\n");
    fclose(fptr);
}
void loadTeacherFromFile(int *length, struct Teacher tv[]){
	
    FILE *fptr = fopen("teachersData.dat", "rb");
    if (fptr == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    *length = fread(tv, sizeof(struct Teacher), 50, fptr);
    fclose(fptr);
}
void deleteTeacher(int *length, struct Teacher tv[]) {
;
    printf("\n\t***Xoa mot giao vien***\n");
    getchar();
	char id[10];
    printf("\nNhap Id giao vien de xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex= -1;
    int i;
    for(i=0;i<*length; i++) {
        if(strcmp(tv[i].teacherId, id) == 0) {
            findIndex= i;
            break;
        }
    }
    if(findIndex==-1) {
        printf("\nKhong co giao vien nao duco tim thay voi Id.\n", id);
    }else {
        printf("\nCo mot giao vien voi Id: %s\n", id);
        printf("  Thong tin giao vien:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n",tv[findIndex].classroomId);
        printf("FullName: %s\n",tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n",tv[findIndex].dateOfBrith.day,tv[findIndex].dateOfBrith.month,tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n",tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n",tv[findIndex].email);
        printf("Phone: %s\n",tv[findIndex].phone);
        printf("Password: %s\n",tv[findIndex].password);
        for(i=findIndex;i<*length-1; i++){
            tv[i]=tv[i+1];
        }
        (*length)--;
        printf("\n\t***Cap nhat giao vien moi ***\n");
        printHeader2();
        printTeacher(*length, tv);
        printf("\nGiao vien da xoa thanh cong.\n");
    }
}
void editTeacher(int length, struct Teacher tv[]) {
   
    int isValidEmail(char* email) {
        if (strchr(email, '@') != NULL) {
            return 1;  
        }
        return 0;
    }

   
    int isValidPhoneNumber(char* phone) {
    	int i;
        for (i = 0; phone[i] != '\0'; i++) {
            if (!isdigit(phone[i])) {
                return 0;  
            }
        }
        return 1;
    }

    
    int isValidPassword(char* password) {
        if (strlen(password) >= 6) {
            return 1; 
        }
        return 0;
    }

    printf("\n\t***Chinh sua thong tin mot giao vien***\n");
    getchar(); 
    char id[10];
    printf("\nNhap Id giao vien de chinh sua: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; 
    int findIndex = -1;
    
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(tv[i].teacherId, id) == 0) {
            findIndex = i;
            break;
        }
    }

    if (findIndex == -1) {
        printf("\nKhong co giao vien nao voi Id %s.\n", id);
    } else {
        printf("\nMot giao vien duoc tim thay voi Id: %s\n", id);
        printf("  Thong tin giao vien:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", tv[findIndex].classroomId);
        printf("FullName: %s\n", tv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", tv[findIndex].dateOfBrith.day, tv[findIndex].dateOfBrith.month, tv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", tv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", tv[findIndex].email);
        printf("Phone: %s\n", tv[findIndex].phone);
        printf("Password: %s\n", tv[findIndex].password);
        
      
        printf("\nNhap ten moi: ");
        fgets(tv[findIndex].fullName, 30, stdin);
        tv[findIndex].fullName[strcspn(tv[findIndex].fullName, "\n")] = '\0';

      
        printf("Nhap vao ngay, thang, nam sinh (dd / mm / yyyy):\n");
        do {
            printf("   Nhap ngay sinh: ");
            scanf("%d", &tv[findIndex].dateOfBrith.day);
            if (tv[findIndex].dateOfBrith.day < 1 || tv[findIndex].dateOfBrith.day > 31) {
                printf("%d ngay ban nhap khong hop le. Vui long nhap lai.\n", tv[findIndex].dateOfBrith.day);
            }
        } while (tv[findIndex].dateOfBrith.day < 1 || tv[findIndex].dateOfBrith.day > 31);

        do {
            printf("   Nhap thang sinh: ");
            scanf("%d", &tv[findIndex].dateOfBrith.month);
            if (tv[findIndex].dateOfBrith.month < 1 || tv[findIndex].dateOfBrith.month > 12) {
                printf("%d thang ban nhap khong hop le. Vui long nhap lai.\n", tv[findIndex].dateOfBrith.month);
            }
        } while (tv[findIndex].dateOfBrith.month < 1 || tv[findIndex].dateOfBrith.month > 12);

        do {
            printf("   Nhap nam sinh: ");
            scanf("%d", &tv[findIndex].dateOfBrith.year);
            if (tv[findIndex].dateOfBrith.year < 1 || tv[findIndex].dateOfBrith.year > 2024) {
                printf("%d nam ban nhap khong hop le. Vui long nhap lai.\n", tv[findIndex].dateOfBrith.year);
            }
        } while (tv[findIndex].dateOfBrith.year < 1 || tv[findIndex].dateOfBrith.year > 2024);

    
        do {
            printf("Nhap gioi tinh (1 for Male, 0 for Female): ");
            scanf("%d", &tv[findIndex].gender);
            if (tv[findIndex].gender != 1 && tv[findIndex].gender != 0) {
                printf("Gioi tinh ban nhap khong hop le. Vui long nhap lai.\n");
            }
        } while (tv[findIndex].gender != 1 && tv[findIndex].gender != 0);

        getchar();  
       
        printf("Nhap vao lop moi: ");
        fgets(tv[findIndex].classroomId, 10, stdin);
        tv[findIndex].classroomId[strcspn(tv[findIndex].classroomId, "\n")] = '\0';

        do {
            printf("Nhap vao email moi: ");
            fgets(tv[findIndex].email, 30, stdin);
            tv[findIndex].email[strcspn(tv[findIndex].email, "\n")] = '\0';
            if (!isValidEmail(tv[findIndex].email)) {
                printf("Email khong hop le. Vui long nhap lai.\n");
            }
        } while (!isValidEmail(tv[findIndex].email));

        
        do {
            printf("Nhap so dien thoai: ");
            fgets(tv[findIndex].phone, 20, stdin);
            tv[findIndex].phone[strcspn(tv[findIndex].phone, "\n")] = '\0';
            if (!isValidPhoneNumber(tv[findIndex].phone)) {
                printf("So dien thoai khong hop le. Vui long nhap lai.\n");
            }
        } while (!isValidPhoneNumber(tv[findIndex].phone));

        
        do {
            printf("Nhap mat khau: ");
            fgets(tv[findIndex].password, 20, stdin);
            tv[findIndex].password[strcspn(tv[findIndex].password, "\n")] = '\0';
            if (!isValidPassword(tv[findIndex].password)) {
                printf("Mat khau khong hop le (toi thiieu 6 ky tu). Vui long nhap lai.\n");
            }
        } while (!isValidPassword(tv[findIndex].password));

       
        printf("\n\t***Cap nhat giao vien moi***\n");
        
        printHeader2();
        printTeacher(length, tv);
        printf("\nGiao vien da chinh sua thanh cong.\n");
    }
}
void searchTeacher(int length, struct Teacher tv[]){
	
    printf("\n\t***Tim kiem mot giao vien***\n");
    getchar();
	char name[30];
    printf("\nNhap ten giao vien de tim kiem: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int i;
    int findIndex=-1;
	for(i=0;i<length; i++) {
        if (strcmp(tv[i].fullName,name)==0){
            findIndex=i;
            break;
        }
    }
    if (findIndex==-1){
        printf("\nKhong tim thay giao vien nao voi ten %s.\n",name);
    }else{
        printf("\nGiao vien da duoc tim thay voi ten %s.\n",name);
        printf("Giao vien da duoc tim thay thanh cong.\n\n");
	}
}
void sortTeachersByName(int length, struct Teacher tv[]){
	
    int choice6;
	do{
		printf("\n\t***Sap xep mot giao vien***\n");
	    printf("\n");
	    printf("\t  Sap xep giao vien\n");
	    printf("\t=====================\n");
	    printf("\t[1] Tang dan.\n");
	    printf("\t[2] Giam dan.\n");
	    printf("\t[0] Thoat.\n");
	    printf("\t=====================\n");
		printf("\tNhap vao lua chon cua ban: ");
	    scanf("%d", &choice6);
		switch(choice6){
			struct Teacher temp;
			int i,j;
			case 1:
			    printf("\n\t  Sap xep theo cach tang dan\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(tv[i].fullName, tv[j].fullName)>0){
			                temp = tv[i];
			                tv[i] = tv[j];
			                tv[j] = temp;
			            }
			        }
			    }
			    printHeader2();
		        printTeacher(length,tv);
			    printf("\nGiao vien duoc bo tri thanh cong.\n");
				break;
			case 2:
				printf("\n\t  Sap xep theo cach giam dan\n");
				for(i=0;i<length;i++) {
			        for(j=i+1;j<length-i-1;j++) {
			            if(strcmp(tv[i].fullName, tv[j].fullName)<0){
			                temp=tv[i];
			                tv[i]=tv[j];
			                tv[j]=temp;
			            }
			        }
			    }
			    printHeader2();
		        printTeacher(length,tv);
			    printf("\nGiao vien duoc bo tri thanh cong.\n");
				break;
			case 0:
				break;
			default:
				printf("\tLoi: Vui long thu lai.\n");
	    }
	}while(choice6!=0);
}
void print_classroom_menu() {
	
    printf("\n--- Menu Quan Ly Lop Hoc ---\n");
    printf("1. Them lop hoc\n");
    printf("2. Sua lop hoc\n");
    printf("3. Xoa lop hoc\n");
    printf("4. Tim kiem lop hoc\n");
    printf("5. Them sinh vien vao lop\n");
    printf("6. Xoa sinh vien khoi lop\n");
    printf("7. Sap xep cac lop hoc\n");
    printf("8. In danh sach lop hoc\n");
    printf("9. Luu lop hoc vao file\n");
    printf("10. Tai du lieu lop hoc tu file\n");
    printf("0. Quay lai\n");
}
void add_classroom(struct Classroom classrooms[], int *num_classrooms) {
	
    struct Classroom new_classroom;

   
    printf("Nhap ma lop hoc: ");
    scanf("%s", new_classroom.classroomId);
    getchar();  
    printf("Nhap ten lop hoc: ");
    scanf("%s", new_classroom.classroomName);
    printf("Nhap ma giao vien phu trach: ");
    scanf("%s", new_classroom.teacherID);

   
   
    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &new_classroom.numStudents);

   
    new_classroom.students = (struct Student *)malloc(new_classroom.numStudents * sizeof(struct Student));
    if (new_classroom.students == NULL) {
        printf("Khong du bo nho de cap phat cho sinh vien.\n");
        return;
    }
	int i;
    for (i = 0; i < new_classroom.numStudents; i++) {
        printf("Nhap thong tin sinh vien %d\n", i + 1);
        printf("Nhap ma sinh vien: ");
        scanf("%s", new_classroom.students[i].studentId);
        getchar();  
        printf("Nhap ten sinh vien: ");
        scanf("%s", new_classroom.students[i].fullName);
    }

    classrooms[*num_classrooms] = new_classroom;
    (*num_classrooms)++;

    printf("Lop hoc da duoc them thanh cong!\n");
}
void edit_classroom(struct Classroom classrooms[], int num_classrooms) {
	
    char classroomId[10];
    printf("Nhap ma lop hoc muon sua: ");
    fgets(classroomId, 10, stdin);
    classroomId[strcspn(classroomId, "\n")] = 0;
	int i;
    for (i = 0; i < num_classrooms; i++) {
        if (strcmp(classrooms[i].classroomId, classroomId) == 0) {
            printf("Nhap ten lop moi: ");
            fgets(classrooms[i].classroomName, 20, stdin);
            classrooms[i].classroomName[strcspn(classrooms[i].classroomName, "\n")] = 0;

            printf("Nhap ten giao vien phu trach moi: ");
            fgets(classrooms[i].teacherID, 10, stdin);
            classrooms[i].teacherID[strcspn(classrooms[i].teacherID, "\n")] = 0;

            printf("Thong tin lop hoc da duoc cap nhat.\n");
            return;
        }
    }

    printf("Khong tim thay lop hoc voi ma %s.\n", classroomId);
}
void saveClassroomToFile(int length, struct Classroom classrooms[]) {
	
    FILE *fptr = fopen("classroomsData.dat", "wb");
    if (fptr == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    // Ghi du lieu cac lop hoc vao file 
    fwrite(classrooms, sizeof(struct Classroom), length, fptr);
    printf("Du lieu lop hoc duoc luu thanh cong\n");
    fclose(fptr);  // Dong file
}
void loadClassroomFromFile(int *length, struct Classroom classrooms[]) {
	
    FILE *fptr = fopen("classroomsData.dat", "rb"); 
    if (fptr == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    // doc du lieu tu file va cap nhap vao mang classrooms
    *length = fread(classrooms, sizeof(struct Classroom), 50, fptr);
    fclose(fptr);  // ??ng file
    printf("Du lieu lop hoc duoc tai thanh cong\n");
}
void delete_classroom(struct Classroom classrooms[], int *num_classrooms) {
	
    char classroomId[10];
    printf("Nhap ma lop hoc muon xoa: ");
    fgets(classroomId, 10, stdin);
    classroomId[strcspn(classroomId, "\n")] = 0;
	int i,j;
    for (i = 0; i < *num_classrooms; i++) {
        if (strcmp(classrooms[i].classroomId, classroomId) == 0) {
            for (j = i; j < *num_classrooms - 1; j++) {
                classrooms[j] = classrooms[j + 1];
            }
            (*num_classrooms)--;
            printf("Da xoa lop hoc voi ma %s.\n", classroomId);
            return;
        }
    }

    printf("Khong tim thay lop hoc voi ma %s.\n", classroomId);
}
void search_classroom(struct Classroom classrooms[], int num_classrooms) {
	
    char classroomId[10];
    printf("Nhap ma lop hoc muon tim: ");
    fgets(classroomId, 10, stdin);
    classroomId[strcspn(classroomId, "\n")] = 0;
	int i;
    for (i = 0; i < num_classrooms; i++) {
        if (strcmp(classrooms[i].classroomId, classroomId) == 0) {
            printf("Lop hoc: Ma lop: %s, Ten lop: %s, Ma giao vien: %s, So sinh vien: %d\n", 
                classrooms[i].classroomId, classrooms[i].classroomName, classrooms[i].teacherID, classrooms[i].numStudents);
            return;
        }
    }

    printf("Khong tim thay lop hoc voi ma %s.\n", classroomId);
}
void add_student_to_class(struct Classroom classrooms[], int num_classrooms) {
	
    char classroomId[10];
    printf("Nhap ma lop hoc de them sinh vien: ");
    fgets(classroomId, 10, stdin);
    classroomId[strcspn(classroomId, "\n")] = 0;
	int i;
    for (i = 0; i < num_classrooms; i++) {
        if (strcmp(classrooms[i].classroomId, classroomId) == 0) {
            if (classrooms[i].numStudents >= 30) {
                printf("Lop hoc da day khong the them sinh vien.\n");
                return;
            }

            printf("Nhap ma sinh vien: ");
            fgets(classrooms[i].students[classrooms[i].numStudents].studentId, 10, stdin);
            classrooms[i].students[classrooms[i].numStudents].studentId[strcspn(classrooms[i].students[classrooms[i].numStudents].studentId, "\n")] = 0;

            printf("Nhap ten sinh vien: ");
            fgets(classrooms[i].students[classrooms[i].numStudents].fullName, 30, stdin);
            classrooms[i].students[classrooms[i].numStudents].fullName[strcspn(classrooms[i].students[classrooms[i].numStudents].fullName, "\n")] = 0;

            printf("Nhap ngay sinh (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &classrooms[i].students[classrooms[i].numStudents].dateOfBrith.day, 
                               &classrooms[i].students[classrooms[i].numStudents].dateOfBrith.month, 
                               &classrooms[i].students[classrooms[i].numStudents].dateOfBrith.year);

            printf("Nhap gioi tinh (0: Nam, 1: Nu): ");
            scanf("%d", &classrooms[i].students[classrooms[i].numStudents].gender);

            getchar(); 
            classrooms[i].numStudents++;
            printf("Sinh vien da duoc them vao lop hoc.\n");
            return;
        }
    }

    printf("Khong tim thay lop hoc voi ma sinh vien %s.\n", classroomId);
}
void remove_student_from_class(struct Classroom classrooms[], int num_classrooms) {
	
    char classroomId[10];
    printf("Nhap ma lop hoc de xoa sinh vien: ");
    fgets(classroomId, 10, stdin);
    classroomId[strcspn(classroomId, "\n")] = 0;
	int i,j,k;
    for (i = 0; i < num_classrooms; i++) {
        if (strcmp(classrooms[i].classroomId, classroomId) == 0) {
            char studentId[10];
            printf("Nhap ma sinh vien muon xoa: ");
            fgets(studentId, 10, stdin);
            studentId[strcspn(studentId, "\n")] = 0;

            for (j = 0; j < classrooms[i].numStudents; j++) {
                if (strcmp(classrooms[i].students[j].studentId, studentId) == 0) {
                    for (k = j; k < classrooms[i].numStudents - 1; k++) {
                        classrooms[i].students[k] = classrooms[i].students[k + 1];
                    }
                    classrooms[i].numStudents--;
                    printf("Sinh vien da duoc xoa khoi lop hoc.\n");
                    return;
                }
            }

            printf("Khong tim thay sinh vien voi ma %s trong lop %s.\n", studentId, classroomId);
            return;
        }
    }

    printf("Khong tim thay lop hoc voi ma %s.\n", classroomId);
}
void sort_classrooms(struct Classroom classrooms[], int num_classrooms) {
	
    struct Classroom temp;
    int i,j;
    for (i = 0; i < num_classrooms - 1; i++) {
        for (j = i + 1; j < num_classrooms; j++) {
            if (strcmp(classrooms[i].classroomName, classrooms[j].classroomName) > 0) {
                temp = classrooms[i];
                classrooms[i] = classrooms[j];
                classrooms[j] = temp;
            }
        }
    }
    printf("Cac lop hoc da duoc sap xep theo ten lop.\n");
}
void print_classroom(struct Classroom classrooms[], int num_classrooms) {
	
    printf("Danh sach lop hoc:\n");
    int i;
    for (i = 0; i < num_classrooms; i++) {
        printf("Ma lop: %s, Ten lop: %s, Ma giao vien: %s, So sinh vien: %d\n", classrooms[i].classroomId, classrooms[i].classroomName, classrooms[i].teacherID, classrooms[i].numStudents);
    }
}
void backandexit(){
			do{
		char choice9;
		printf("Go back(b)? or Exit(0)? :");
	    scanf("%c",&choice9);
	    getchar();
	    if(choice9=='b'){
	    	return;
		}else if(choice9=='0'){
			printf("ket thuc chuong trinh");
			break;
		}else{
			printf("\tLoi: moi ban nhap lai.\n");
		}
	}while(1);
	}

//viet logic ham cho admin
int readAdminCredentials(char *username, char *password) {
    FILE *file = fopen("data/admin.dat", "r"); // Tep admin.dat
    if (file == NULL) {
        printf("Loi mo file admin.dat.\n");
        return 0;
    }
    fgets(username, 30, file);
    fgets(password, 30, file);

    // loai bo ki tu \n tu file 
    username[strcspn(username, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';

    fclose(file);
    return 1;
}

// Ham xac nhan tai khoan admin
int authenticateAdmin() {
    char inputUsername[30], inputPassword[30];
    char correctUsername[30], correctPassword[30];
	// ham doc thong tin tu file 
    if (!readAdminCredentials(correctUsername, correctPassword)) {
        return 0;
    }

    printf("Usesname:Nhap tai khoan admin: ");
    fgets(inputUsername, 30, stdin);
    inputUsername[strcspn(inputUsername, "\n")] = '\0'; 

    printf("Pass:Nhap mat khau admin: ");
    //hien thi mat khau duoi dang dau *
    int i = 0;
    while (1) {
        inputPassword[i] = getch(); //su dung ham getchar de an mat khau
        if (inputPassword[i] == '\n') {
            inputPassword[i] = '\0';
            break;
        }
        putchar('*');  // Hien thi dau *
        i++;
    }

    if (strcmp(inputUsername, correctUsername) == 0 && strcmp(inputPassword, correctPassword) == 0) {
        return 1;  //dang nhap thanh cong
    } else {
        printf("\nThong tin dang nhap sai. Vui long thu lai.\n");
        return 0;  // dang nhap that bai
    }
}

// Ham dang nhap voi yeu cau la tai khoan va mat khau
void login() {
    while (1) {
        if (authenticateAdmin()) {
            printf("\nDang nhap thanh cong!\n");
            break;
        } else {
            printf("\nVui long thu lai.\n");
        }
    }
}
