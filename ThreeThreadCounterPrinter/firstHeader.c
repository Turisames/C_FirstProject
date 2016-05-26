#include "firstHeader.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void mutexed_printf( char Param[] )
{
	pthread_mutex_lock( &printMutex );
	printf( Param );
	pthread_mutex_unlock( &printMutex );
}

void * otherThreadFunc( void * Param )
{
	char * message = (char*)Param;
	int i = 0;
	for (i = 0; i < 50; i++)
	{
		pthread_mutex_lock( &printMutex );
		printf( "Thread:\t" );
		printf( message );
		printf( " %i\n", i );
		pthread_mutex_unlock( &printMutex );
	}
	pthread_exit( NULL );
}

int other_function()
{
	char txt[] = "This is a function. It says 'Hello!'\n";
	mutexed_printf( txt );
	return 0;
}

int param_int_function( int Param )
{
	int i = 0;
	char txt = ("%i\n", i);
	printf( "%i", Param );
	mutexed_printf( (char*)(&Param) );
	
	if ( Param > 0 )
	{
		for (i = 0; i < Param; i++)
		{
			mutexed_printf( &txt );
		}
	}
	return Param;
}