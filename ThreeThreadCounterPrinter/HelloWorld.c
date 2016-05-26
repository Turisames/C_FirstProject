#include "firstHeader.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>//concurrency, should I feel like it.
//#include <gtk/gtk.h>//GTK, gui library, should I feel like it.

/*
This is my first C program. 
Well, not really. I did some small
work in C in some courses previously.
*/

int main()
{
	// Variable declarations
	pthread_t thread1, thread2;
	something st1;
	st1.number = 100;
	
	strcpy( st1.word, "A word.\n" );
	mutexed_printf( st1.word );
	mutexed_printf( "Hello world.\n" );
	
	pthread_create( &thread1, NULL, otherThreadFunc, "My number is" );
	pthread_create( &thread2, NULL, otherThreadFunc, "My number is" );
	other_function();

	param_int_function( 10 );
	
	pthread_join( thread1, NULL );
	pthread_join( thread2, NULL );
	
	printf("Jobs done. Exiting.\n");
	//pthread_exit( NULL );
	
	return 0;
}