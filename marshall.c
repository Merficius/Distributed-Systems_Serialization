#include <stdio.h>

// Variables globales
char c1 = 'A';
char c2 = 'B';

int i = 16; // Entero a 32 bits representado en LITTLE-ENDIAN

char c3 = 'C';
char c4 = 'D';

int serializeData(void);

int main()
{

    serializeData();

    return 0;
}

int serializeData()
{
    // Write binary data
    FILE* file = fopen("datos.mem", "wb"); // Creating the file
    char* p = &c1;
    
    //char *p2 = (char *) &i;

    fprintf(file, "%c\n", p[0]);                
    fprintf(file, "%c\n", p[1]);                
    
    fprintf(file, "%c\n", p[7]);                
    fprintf(file, "%c\n", p[6]);                
    fprintf(file, "%c\n", p[5]);                
    fprintf(file, "%c\n", p[4]);                

    fprintf(file, "%c\n", p[8]); 
    fprintf(file, "%c\n", p[9]); 
          
    fclose(file);                          // Closing the file
    return 0;

}
