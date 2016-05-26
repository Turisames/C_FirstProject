#ifndef FIRSTHEADER_H
#define FIRSTHEADER_H "firstHeader.h"

#include <stdio.h>
#include <string.h>
#include <pthread.h>

static pthread_mutex_t printMutex;

typedef struct something
{
	int number;	
	// In C, strings are arrays of characters.
	char word[10];
} something;

void mutexed_printf( char Param[] );
void * otherThreadFunc( void * Param );
int other_function();
int param_int_function( int Param );

#endif	// FIRSTHEADER_H