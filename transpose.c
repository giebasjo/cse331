//
//  Created by H. Metin Aktulga on 2/2/17.
//  Copyright © 2017 Michigan State University. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // for clock_gettime()
#include <math.h>
#include <limits.h>
#include <string.h>

// Method declarations
double getElapsed(struct timeval*, struct timeval*);

// Naive transpose operation
void naiveTranspose(double *, double *, int, int);
// Cache blocked transpose operation
void optTranspose(double *, double *, int, int, int);

void initMatrix(double*, int, int);
int checkDifference(double*, double*, int, int);

// Main method
int main(int argc, char* argv[])
{
  // Variable declarations
  double naiveStart, naiveEnd, naiveTime;
  double optStart, optEnd, optTime;
  double* naiveinput, *naiveoutput, *optinput, *optoutput;
  int  N, M, B;
  int  testing, ninps, curtest, score, match;
  FILE *fin;
  struct timeval start, end;
  
  testing = 0;
  ninps = 0;
  curtest = 0;
  score = 0;
  
  // Get the problem size and blocking factor from the command line
  if (argc == 3 || argc == 5) {
    
    if (!strcmp(argv[1],"test")) {
      testing = 1;
      fin = fopen(argv[2], "r");
      fscanf(fin, " %d", &ninps);
    }
    else if (!strcmp(argv[1],"perf")) {
      testing = 0;
    }
    else {
      fprintf(stderr, "\nERROR: Unknown option %s\n", argv[1]);
    } 
  }
  else {
    fprintf(stderr, "\nERROR: This program can be executed in");
    fprintf(stderr, " \"test\" or \"perf\" modes:\n");
    fprintf(stderr,"           transpose test inputfile\n");
    fprintf(stderr,"           transpose perf N M B\n");
    fprintf(stderr,"           inputfile format: starts with a line indicating");
    fprintf(stderr," the number of tests, followed the tests specified with N M B values.\n");
    fprintf(stderr,"           N: number of matrix rows\n");
    fprintf(stderr,"           M: number of matrix columns\n");
    fprintf(stderr,"           B: blocking factor.\n");
    return 0; 
  }
  
  
  do { 
    // main loop: executed only once for performance testing to ensure cold start.
    //            However, it is okay to do several accuracy checks (test runs) 
    //            at once in a single execution.

    if (testing) {
      curtest++;
      // read from the input file
      fscanf(fin, " %d %d %d", &N, &M, &B);
    }
    else {
      // otherwise get the command line arguments 
      N = strtol(argv[2], NULL, 10);
      M = strtol(argv[3], NULL, 10);
      B = strtol(argv[4], NULL, 10);  
    }

    printf("ninps = %d, curtest = %d\n", ninps, curtest);
    printf("N = %d, M = %d, B = %d\n", N, M, B);
    
    // Allocations
    if (testing) {  
      naiveinput = (double *) malloc(N*M*sizeof(double));
      initMatrix(naiveinput, N, M);
      optinput = naiveinput;
    }
    else {
      naiveinput = (double *) malloc(N*M*sizeof(double));
      optinput = (double *) malloc(N*M*sizeof(double));
    }
    
    naiveoutput = (double *) malloc(M*N*sizeof(double));
    optoutput = (double *) malloc(M*N*sizeof(double));
    
    // Time naive calculation
    gettimeofday(&start, NULL);
    naiveTranspose(naiveoutput, naiveinput, N, M);
    gettimeofday(&end, NULL);
    naiveTime = getElapsed(&start, &end);
    
    // Time opt calculation with atomics
    gettimeofday(&start, NULL);
    optTranspose(optoutput, optinput, N, M, B);
    gettimeofday(&end, NULL);
    optTime = getElapsed(&start, &end);
    
    // How do results compare?
    if (testing) {
      match = checkDifference(naiveoutput, optoutput, M, N);
      
      if (!match) 
	printf("Found an error (see above for details).\n");
      else 
	++score;
    } 
    else {
      printf("Naive time: %.3f sec\n", naiveTime);
      printf("Opt. time:  %.3f sec\n", optTime);
      printf("Achieved speedup= %.2f\n\n", naiveTime/optTime);
    }
    
    if (naiveinput) free(naiveinput);
    if (naiveoutput) free(naiveoutput);
    if (optinput && !testing) free(optinput);
    if (optoutput) free(optoutput);
  }
  while(curtest < ninps);

  if (testing) fclose(fin);

  printf("Test score: %d/%d\n", score, ninps);
  
  return 0;
}


double getElapsed(struct timeval *start, struct timeval *end)
{
  double secs_used=(end->tv_sec - start->tv_sec); //avoid overflow by subtracting first
  double micros_used= ((secs_used*1000000) + end->tv_usec) - (start->tv_usec);
    
  return micros_used/1000000.0;
}


// Naive transpose operation
void naiveTranspose(double *output, double *input, int N, int M)
{
  int i, j;
    
  for (i=0; i<N; ++i)
    for (j=0; j<M; ++j)
      output[j*N+i] = input[i*M+j];
    
}

// TODO: You need to implement this function.
// Cache blocked transpose operation
#define CEIL_MACRO(x,y) ( ( (x) / (y) ) + 1 )
#define MIN(x,y) ( ( (x) < (y) ) ? (x) : (y) )
void optTranspose(double *output, double *input, int N, int M, int B)
{
    //initialize iterators
    int i,j,ii,jj;
    
    //loop over all the rows
    for (i=0; i<CEIL_MACRO(N,B)*B; i+=B) {
        for (j=0; j<CEIL_MACRO(M,B)*B; j+=B) {
     //for(i=0; i<N; i+=B){
       //  for(j=0;j<M;j+=B) {
            //get boundaries for inner loop
            for (ii=i; ii<MIN((i+B), N); ++ii ) {
                for (jj=j; jj<MIN((j+B),M); ++jj ) {

                    output[ jj*N + ii ] = input[ ii*M + jj ];

                }
            }
        }
    }
}

void initMatrix(double *matrix, int N, int M)
{
  int i, j;
    
  srand(time(NULL));

  for (i=0; i<N; ++i)
    for (j=0; j<M; ++j)
      matrix[i*M+j] = rand()*1.0/INT_MAX;
}


int checkDifference(double *matrix1, double *matrix2, int N, int M)
{
  int i, j;
    
  for (i=0; i<N; ++i)
    for (j=0; j<M; ++j)
      if (matrix1[i*M+j] != matrix2[i*M+j]) {
	fprintf(stderr, "matrices differ at position [%d, %d]: ", i, j);
	fprintf(stderr, "matrix1[%d, %d]= %.5f", i, j, matrix1[i*N+j]);
	fprintf(stderr, "matrix2[%d, %d]= %.5f", i, j, matrix2[i*N+j]);
	return 0;
      }
    
  return 1;
}
