#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1000

typedef struct {
    char name [80];
    char schedule [4];
    unsigned hours ;
    unsigned size ;
    unsigned padding ;
} COURSE ;

COURSE* createCourse();

int main(int argc, char* argv[]){
    char inputBuffer[BUFFER_SIZE];
    FILE *dataFile = NULL;
    dataFile = fopen("courses.dat", "r+");
    if(dataFile == NULL){
        fprintf(stderr,"Unable to open file courses.dat");
        return 1;
    }
    fseek(dataFile, 0L, SEEK_SET);

    printf("Assignment 5 created by Quinn Murphey (pfl955)");
    while(1){
        char choice = '\0';

        printf("\nEnter one of the following actions or type CTRL-D to exit.\nC - create a new course record\nR - read an existing course record\nU - update an existing course record\nD - delete an existing course record\nF - search courses by name\n> ");

        if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
            break;
        sscanf(inputBuffer,"%c",&choice);
        if(choice == 'C' || choice == 'c'){ // Create new course record
            int num;
            char name[80];
            char schedule[4];
            unsigned creditHours;
            unsigned enrollment;
            
            printf("Enter a course number (nonnegative integer): ");
            while(1){ // Get num
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;
                
                if(sscanf(inputBuffer, "%d", &num) == 1 && num >= 0){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a course number (nonnegative integer): ");
                }
            }

            printf("Enter a course name: ");
            while(1){ // Get name
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;
                if(sscanf(inputBuffer, "%79[^\n]", name) == 1){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a course name: ");
                }
            }

            printf("Enter a course schedule (MWF or TR): ");
            while(1){ // Get schedule
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;

                if( sscanf(inputBuffer, "%3[^\n]", schedule) == 1 && ( strcmp(schedule, "MWF") == 0 || strcmp(schedule, "TR") == 0 ) ){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a course schedule (MWF or TR): ");
                }
            }

            printf("Enter course credit hours (positive integer): ");
            while(1){ // Get creditHours
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;

                if(sscanf(inputBuffer, "%u", &creditHours) == 1 && creditHours > 0){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a positive integer: ");
                }
            }

            printf("Enter student enrollment (positive integer): ");
            while(1){ // Get num
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;

                if(sscanf(inputBuffer, "%u", &enrollment) == 1 && enrollment >= 0){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter student enrollment (positive integer): ");
                }
            }
    
            // Create new COURSE object
            COURSE* course = malloc(sizeof(COURSE));
            strcpy(course->name, name);
            strcpy(course->schedule, schedule);
            course->hours = creditHours;
            course->size = enrollment;
            
            // Write data to data file
            fseek(dataFile, num * sizeof(COURSE), SEEK_SET);
            fwrite(course, sizeof(COURSE), 1, dataFile);
            fflush(dataFile);
            free(course);

        }else if(choice == 'R' || choice == 'r'){ // Read an existing course record
            int num;

            printf("Enter a course number (nonnegative integer): ");
            while(1){ // Get num
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;
                
                if(sscanf(inputBuffer, "%d", &num) == 1 && num >= 0){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a course number (nonnegative integer): ");
                }
            }

            COURSE* course = malloc(sizeof(COURSE));
            printf("\n");
            fseek(dataFile, 0L, SEEK_END);
            if(ftell(dataFile) > (long unsigned)(num * sizeof(COURSE)) ){
                fseek(dataFile, num*sizeof(COURSE), SEEK_SET);
                fread(course, sizeof(COURSE), 1, dataFile);
                
                if(course->hours != 0){
                    printf("Course number: %d\n", num);
                    printf("Course name: %s\n", course->name);
                    printf("Scheduled days: %s\n", course->schedule);
                    printf("Credit hours: %u\n", course->hours);
                    printf("Enrolled Students: %u\n", course->size);
                }else{
                    printf("ERROR: course not found");
                }
            }else {
                printf("ERROR: course not found");
            }
            free(course);

        }else if(choice == 'U' || choice == 'u'){ // Update an existing course record
            int num;
            COURSE* course = malloc(sizeof(COURSE));

            printf("Enter a course number (nonnegative integer): ");
            while(1){ // Get num
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;
                
                if(sscanf(inputBuffer, "%d", &num) == 1 && num >= 0){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a course number (nonnegative integer): ");
                }
            }

            fseek(dataFile, 0L, SEEK_END);
            if(ftell(dataFile) > (long unsigned)(num * sizeof(COURSE)) ){
                fseek(dataFile, num*sizeof(COURSE), SEEK_SET);
                fread(course, sizeof(COURSE), 1, dataFile);

                if(course->hours != 0){
                    printf("Enter a course name: ");
                    while(1){ // Get name
                        char name[80];
                        if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                            return 1;

                        if(strcmp(inputBuffer, "\n") == 0){
                            break;
                        }else if(sscanf(inputBuffer, "%79[^\n]", name) == 1){
                            strcpy(course->name, name);
                            break;
                        }else{
                            printf("ERROR: invalid input. Enter a course name: ");
                        }
                    }

                    printf("Enter a course schedule (MWF or TR): ");
                    while(1){ // Get schedule
                        char schedule[4];
                        if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                            return 1;

                        if(strcmp(inputBuffer, "\n") == 0){
                            break;
                        }else if( sscanf(inputBuffer, "%3[^\n]", schedule) == 1 && ( strcmp(schedule, "MWF") == 0 || strcmp(schedule, "TR") == 0 ) ){
                            strcpy(course->schedule, schedule);
                            break;
                        }else{
                            printf("ERROR: invalid input. Enter a course schedule (MWF or TR): ");
                        }
                    }

                    printf("Enter course credit hours (positive integer): ");
                    while(1){ // Get creditHours
                        unsigned creditHours;
                        if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                            return 1;

                        if(strcmp(inputBuffer, "\n") == 0){
                            break;
                        }else if(sscanf(inputBuffer, "%u", &creditHours) == 1 && creditHours > 0){
                            course->hours = creditHours;
                            break;
                        }else{
                            printf("ERROR: invalid input. Enter a positive integer: ");
                        }
                    }

                    printf("Enter student enrollment (positive integer): ");
                    while(1){ // Get num
                        unsigned enrollment;
                        if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                            return 1;

                        if(strcmp(inputBuffer, "\n") == 0){
                            break;
                        }else if(sscanf(inputBuffer, "%u", &enrollment) == 1 && enrollment >= 0){
                            course->size= enrollment;
                            break;
                        }else{
                            printf("ERROR: invalid input. Enter student enrollment (positive integer): ");
                        }
                    }    
                    
                    // Write data to data file
                    fseek(dataFile, num * sizeof(COURSE), SEEK_SET);
                    fwrite(course, sizeof(COURSE), 1, dataFile);
                    fflush(dataFile);
                }else {
                    printf("ERROR: course not found");
                }

            }else {
                printf("ERROR: course not found");
            }

            free(course);
            
        }else if(choice == 'D' || choice == 'd'){ // Delete an existing course record
            int num;

            printf("Enter a course number (nonnegative integer): ");
            while(1){ // Get num
                if(fgets(inputBuffer, BUFFER_SIZE, stdin) == NULL)
                    return 1;
                
                if(sscanf(inputBuffer, "%d", &num) == 1 && num >= 0){
                    break;
                }else{
                    printf("ERROR: invalid input. Enter a course number (nonnegative integer): ");
                }
            }

            COURSE* course = malloc(sizeof(COURSE));
            fseek(dataFile, 0L, SEEK_END);
            if(ftell(dataFile) > (long unsigned)(num * sizeof(COURSE)) ){
                fseek(dataFile, num*sizeof(COURSE), SEEK_SET);
                fread(course, sizeof(COURSE), 1, dataFile);
                
                if(course->hours != 0){
                    fseek(dataFile, num*sizeof(COURSE), SEEK_SET);
                    course->hours = 0;
                    fwrite(course, sizeof(COURSE), 1, dataFile);
                    fflush(dataFile);
                    printf("%d was successfully deleted\n", num);
                }else{
                    printf("ERROR: course not found");
                }
            }else {
                printf("ERROR: course not found");
            }
            free(course);

        }else if(choice == 'F' || choice == 'f'){ // Delete an existing course record
            

            printf("Enter a search phrase: ");
            if(fgets(inputBuffer, BUFFER_SIZE, stdin) != NULL){

                fseek(dataFile, 0L, SEEK_END);
                long unsigned numCourses = ftell(dataFile) / sizeof(COURSE);
                COURSE* courses = malloc(numCourses * sizeof(COURSE));

                fseek(dataFile, 0L, SEEK_SET);
                fread(courses, sizeof(COURSE), numCourses, dataFile);

                char searchString[BUFFER_SIZE];
                sscanf(inputBuffer, "%[^\n]", searchString);
                
                for(int i = 0; searchString[i]; i++){ 
                    searchString[i] = tolower(searchString[i]);
                }

                for(int i = 0; i < numCourses; i++){
                    char name[80];
                    strcpy(name, courses[i].name);

                    for(int j = 0; name[j]; j++){ 
                        name[j] = tolower(name[j]);
                    }

                    if(strstr(name, searchString)){
                        printf("%d : %s\n", i, courses[i].name);
                    }
                }
            }

        }else{ // Invalid input
            printf("ERROR: invalid option\n");
        }

                    
    }
    printf("\n");
    fclose(dataFile);
    return 0;
}
