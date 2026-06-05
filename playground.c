#include <stdio.h>
#include <string.h>
#include <ctype.h>

    /*Task #1*/
// int main(){
//     int num[5] = {10, 20, 30, 40, 50};
//     int sum = 0; 
//     float avg;
//
//     //output
//     printf("Task 1: 1D Array Traversal\n--------------------------\n");
//     printf("Array elements:\n");
//     for (int i = 0; i < 5; i++){
//         sum += num[i];  //find sum of array
//         avg = (double)sum / 5;  //find average of array (decimal supported)
//         printf("Numbers[%d]: %d\n", i, num[i]);
//     }
//
//     printf("\nSum: %d\n", sum);
//     printf("Average: %.2f\n", avg);
//     return 0;
// }

    /*Task #2*/
// int main(){
//     int r, c, t = 0;
//     printf("Rows: "); scanf(" %d", &r);
//     printf("Columns: "); scanf(" %d", &c);
//  
//     //create ne matrix
//     int m[r][c];
//     for (int i = 0; i < r; i++){
//         for (int j = 0; j < c; j++){
//             printf("Input indexes %d/%d : ", ++t, r*c);
//             scanf(" %d", &m[i][j]);
//         }
//     }
//
//     //output
//     printf("Task 2: 2D Matrix Row Sums\n--------------------------\n");
//     for (int i = 0; i < r; i++){
//         int sum = 0;    //roof to reset sum for each row
//         for (int j = 0; j < c; j++){
//             sum += m[i][j];     //find row sum
//         }
//         printf("Sum of row %d: %d\n", i+1, sum);
//     }
//     return 0;
// }

    /*Task #3*/
// int main(){
//     char name1[] = "Dara";
//     char name2[10] = {'S','o','k','h','a','\0'};
//
//     //obtain length of both names
//     int len1 = strlen(name1);
//     int len2 = strlen(name2);
//
//     //output
//         printf("Task 3: String Initialization\n-----------------------------\n");
//         printf("String initialized using literal: %s\n", name1);
//         printf("String initialized character by character: %s\n", name2);
//
//         printf("length of name1 = %d\n",len1);
//         printf("length of name2 = %d\n", len2);
//
//     return 0;
// }

    /*Task #4*/
// int main(){
//     int r, c, t = 0;
//     printf("Rows: "); scanf(" %d", &r);
//     printf("Columns: "); scanf(" %d", &c);
//  
//     //create new matrix
//     int m[r][c];
//     for (int i = 0; i < r; i++){
//         for (int j = 0; j < c; j++){
//             printf("Input indexes %d/%d : ", ++t, r*c);
//             scanf(" %d", &m[i][j]);
//         }
//     }
//
//     int total = 0;
//     int max = m[0][0], min = m[0][0];
//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             //find total sum
//             total += m[i][j];
//
//             // Check for new max
//             if (m[i][j] > max) {
//                 max = m[i][j];
//             }
//          
//             // Check for new min
//             if (m[i][j] < min) {
//                 min = m[i][j];
//             }
//         }
//     }
//
//     //output
//         printf("\nTask 4: Matrix Analysis\n");
//         printf("-----------------------\n");
//         printf("Total sum = %d\n", total);
//         printf("Maximum value = %d\n", max);
//         printf("Minimum value = %d\n", min);
//     return 0;
// }

    /*Task #5*/
// int main() {
//     char text[100], lowercase[100], uppercase[100];
//     int vowels = 0;
//     int words = 0;
//
//     printf("Task 5: Text Processing Toolkit\n");
//     printf("-------------------------------\n");
//     printf("Enter a sentence: ");
//  
//     //safely capture a sentence line
//     fgets(text, sizeof(text), stdin);
//  
//     //Remove trailing newline character
//     text[strcspn(text, "\n")] = '\0';
//  
//     int length = strlen(text); //Obtain final string length
//  
//     for (int i = 0; i < length; i++) {
//         //Convert to uppercase and lowercase arrays
//         uppercase[i] = toupper(text[i]);
//         lowercase[i] = tolower(text[i]);
//      
//         //Count vowels
//         char ch = lowercase[i];
//         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
//             vowels++;
//         }
//      
//         //Count words by detecting non-space characters that follow a space or start the string
//         if (text[i] != ' ' && (i == 0 || text[i - 1] == ' ')) {
//             words++;
//         }
//     }
//  
//     //add null terminators to the transformed strings
//     uppercase[length] = '\0';
//     lowercase[length] = '\0';
//  
//     //Output
//     printf("Original text: %s\n", text);
//     printf("Length: %d characters\n", length);
//     printf("Uppercase: %s\n", uppercase);
//     printf("Lowercase: %s\n", lowercase);
//     printf("Vowels: %d\n", vowels);
//     printf("Words: %d\n", words);
//  
//     return 0;
// }

    /*Task #6*/
// int main() {
//     // 2 Groups, 3 Students per group, 20 Maximum characters per name string
//     char students[2][3][20] = {
//         {"Dara", "Sokha", "Rina"},
//         {"Vuthy", "Mony", "Nita"}
//     };
//
//     printf("Task 6: Bonus - 3D Student Names\n");
//     printf("--------------------------------\n");
//  
//     // Outer loop accesses each group block 
//     for (int i = 0; i < 2; i++) {
//         printf("Group %d:\n", i + 1);
//      
//         // Inner loop iterates through names inside current group
//         for (int j = 0; j < 3; j++) {
//             // Print the string name elements directly
//             printf("  Student %d: %s\n", j + 1, students[i][j]);
//         }
//     }
//
//     return 0;
// }