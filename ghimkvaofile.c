#include <stdio.h>

int main() {
    FILE *file = fopen("data/admin.dat", "w");  // Mo file da ghi
    if (file == NULL) {
        printf("Loi mo file admin.dat.\n");
        return 1;  // Neu khong the mo file thi thoata chuong trinh
    }

    // Ghi tai khoan mat khau vao file 
    fprintf(file, "ngotrungchien\n");    // Ten nguoi dung
    fprintf(file, "14102005\n");  // at khau

    fclose(file);  // dong file

    printf("Tai khoan va mat khau da duoc ghi vao file admin.dat.\n");
    return 0;
}

