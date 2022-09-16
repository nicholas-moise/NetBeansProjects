/*
 * CPSC 256 - C/C+ for Scientists and Engineers
 * Christopher Newport University
 * Department of Physics, Computer Science & Engineering
 */

/* 
 * File:   main.c
 * Author: brash
 *
 * Created on August 25, 2021, 2:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // need this to get variables like NULL, for example
#include <math.h>   // need this for things like pow(), sqrt(), on some systems

/*
 * Program to calculate the mean and standard deviation of a set of
 * values read from a file.
 * 
 */

double mean(double [], int); // prototype for mean function
double stdev(double [], int); // protoype for standard deviation function
                             // Even though we define these functions in this 
                             // C file, we MUST ALWAYS define prototypes for all
                             // new functions!

int main(int argc, char** argv) {
    
    const int N_Max = 1000;
    double inputData[N_Max];
    FILE* inputFilePointer;  // inputFilePointer is a POINTER to a file object on the hard drive
    
    inputFilePointer = fopen("inputData.dat","r"); // fopen returns a POINTER to a file object on the hard drive
    
    int i = 0;
    // if the file is opened successfully, then inputFilePointer will be a non-NULL pointer
    if (inputFilePointer != NULL) { 
        
        do {
            fscanf(inputFilePointer,"%lf",&inputData[i]);
            i++;
        } while (!feof(inputFilePointer));
        
        printf("Number of elements read from file = %d\n",(i-1));
        const int N_Elem = i-1;
        
        // Let's look at where in memory the array called inputData is stored
        printf("\n");
        printf("Address of first element of inputData: %p\n",inputData);
        printf("\n");
        printf("Address of N_Elem: %p\n",&N_Elem);
    
        printf("Mean value of elements = %g\n",mean(inputData,N_Elem));
        printf("Std. Dev. of elements = %g\n",stdev(inputData,N_Elem));
        
    } else {
        
        printf("Problem opening file on disk!!!\n");
        return (EXIT_FAILURE);
        
    }
   
    
    return (EXIT_SUCCESS);
}

double mean(double a[], int n) {
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        sum = sum + a[i];
    }
    double mean = sum/n;
    
    printf("\n");
    printf("Address of first element of a, in mean() function: %p\n",a);
    printf("Address of n, in mean() function: %p\n",&n);
    
    return mean;
}

double stdev(double a[], int n) {
    
    printf("Calling mean function from stdev() ... \n");
    double localmean = mean(a,n);
    double sum = 0.0;
    
    for (int i=0;i<n;i++) {
        sum = sum + pow((a[i]-localmean),2);
    }
    
    sum = sum / (n-1);
    double stdev = sqrt(sum);
    
    printf("\n");
    printf("Address of first element of a, in stdev() function: %p\n",a);
    printf("Address of n, in stdev() function: %p\n",&n);
    
    
    return stdev;
}