
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
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
	printf("Chuong trinh quan ly - Admin Login\n");
	login(); //yeu cau dang nhap
    int choice, choice1, choice3, choice7, choice5, choice9;
    int studentCount= 0;
    int teacherCount= 0;
    int num_classrooms = 0;
	struct Classroom classrooms[50];
    struct Student students[50];
    struct Teacher teachers[50];
    do {
        menuStart();
        printf("\tLua chon cua ban la: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            	system("cls");
                do{
                    menuAdmin();
                    printf("\tNhap lua chon cua ban: ");
                    scanf("%d", &choice1); 
                    switch(choice1){
                        case 1:
                        	system("cls");
                            do {
                                menuStudents();
                                printf("\tNhap lua chon cua ban: ");
                                scanf("%d", &choice3);
                                switch(choice3){
                                    case 1:
                                    	system("cls");
                                        addStudent(&studentCount, students);
                                        backandexit();
                                        break;
                                    case 2:
                                    	system("cls");
                                        printHeader();
                                        printStudent(studentCount, students);
                                        backandexit();
                                        break;
                                    case 3:
                                    	system("cls");
                                    	deleteStudent(&studentCount, students);
                                    	backandexit();
                                    	break;
                                    case 4:
                                    	system("cls");
                                    	editStudent(studentCount, students);
                                    	backandexit();
                                    	break;
                                    case 5:
                                    	system("cls");
                                    	searchStudent(studentCount, students);
                                    	backandexit();
                                    	break;
                                    case 6:
                                    	system("cls");
                                    	sortStudentsByName(studentCount, students);
                                    	backandexit();
                                    	break;
                                    case 0:
                                        break;
                                    default:
                                        printf("\tLoi: vui long nhap lai.\n");
                                }
                            }while(choice3!=0);
                            break;
                        case 2: 
                        	system("cls");
    						do {
					        print_classroom_menu();  
					        printf("\tlua chon cua ban la:");
					        scanf("%d", &choice7);
					        switch (choice7) {
					            case 1:
					            	system("cls");
					                add_classroom(classrooms, &num_classrooms);
					                backandexit();
					                break;
					            case 2:
					            	system("cls");
					                edit_classroom(classrooms, num_classrooms);
					                backandexit();
					                break;
					            case 3:
					            	system("cls");
					                delete_classroom(classrooms, &num_classrooms);
					                backandexit();
					                break;
					            case 4:
					            	system("cls");
					                search_classroom(classrooms, num_classrooms);
					                backandexit();
					                break;
					            case 5:
					            	system("cls");
					                add_student_to_class(classrooms, num_classrooms);
					                backandexit();
					                break;
					            case 6:
					            	system("cls");
					                remove_student_from_class(classrooms, num_classrooms);
					                backandexit();
					                break;
					            case 7:
					            	system("cls");
					                sort_classrooms(classrooms, num_classrooms);
					                backandexit();
					                break;
					            case 8:
					            	system("cls");
					                print_classroom(classrooms, num_classrooms);
					                backandexit();
					                break;
					            case 9:
					            	system("cls");
					                saveClassroomToFile(num_classrooms, classrooms);
					                backandexit();
					                break;
					            case 10:
					            	system("cls");
					                loadClassroomFromFile(&num_classrooms, classrooms);
					                backandexit();
					                break;
					            case 0:
					                printf("Thoat chuong trinh.\n");
					                break;
					            default:
					                printf("Lua chon khong hop le!\n");
					        }
					    } while (choice7 != 0);  
					    break;
                        	

                        case 3:
                        	system("cls");
                        	do{
                        		menuTeacher();
                        		printf("\tNhap lua chon cua ban: ");
                                scanf("%d", &choice5);
                                switch(choice5){
                                	case 1:
                                		system("cls");
                                		addTeacher(&teacherCount, teachers);
                                		backandexit();
                                		break;
                                	case 2:
                                		system("cls");
                                		printHeader2();
                                        printTeacher(teacherCount, teachers);
                                        backandexit();
                                		break;
                                	case 3:
                                		system("cls");
                                    	deleteTeacher(&teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                    case 4:
                                    	system("cls");
                                    	editTeacher(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                    case 5:
                                    	system("cls");
                                    	searchTeacher(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                    case 6:
                                    	system("cls");
                                    	sortTeachersByName(teacherCount, teachers);
                                    	backandexit();
                                    	break;
                                	case 7:
                                		system("cls");
                                		backandexit();
                                		
                                		
                                		
                                		break;
                                	case 0:
                                		printf("ban da thoat chuong trinh\n");
                                		break;
                                	default:
                                		printf("\tLoi:vui long nhap lai.\n");	
                                }
							}while(choice5!=0);
                        	break;
                        case 4:
                        	system("cls");
              				printf("Ban dang su dung he thong quan ly sinh vien bang ngon ngu lap trinh c do Ngo Trung Chien viet");
            				break;
                        case 0:
                        	printf("Ban da chon thoat chuong trinh");
                            break;
                        default:
                            printf("\tLoi: vui long nhap lai.\n");
                    }
                }while(choice1!=0);
                break;
            case 2:// cai nay la quyen truy cap cua sinh vien
            	system("cls");
                break;
            case 3: // cai nay la quyen truy cap cua teacher
           		system("cls");
                break;
            case 0:
                printf("\tDang thoat chuong trinh...\n");
                saveStudentToFile(studentCount, students);
                saveClassroomToFile(num_classrooms, classrooms); 
                saveTeacherToFile(teacherCount, teachers);
                break;
            default:
                printf("\n");
				printf("\tLoi: vui long nhap lai\n");
        }
    }while(choice!=0);  
    return 0;
}


