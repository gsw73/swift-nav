#include <cstdlib>
#include <cstdio>
#include <string>
#include <climits>

using namespace std;

static const string DIV_BY_3 = "Buzz";
static const string DIV_BY_5 = "Fizz";
static const string PRIME = "BuzzFizz";

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

/*
A prime number is only divisible by 1 and itself such that there is no
remainder.  This function checks all other possible divisors of a number to
see if any result in no remainder, in which case the number is not prime. 
*/

bool is_prime( unsigned int num ) {

    if ( num == 0 || num == 1 ) {
        return( false );

    } else if ( num == 2 ) {
        return( true );

    } else {
        for ( unsigned int x = 2; x < num; x++ ) {
            if ( num % x == 0 ) {
                return( false );
            }
        }
    }
    return( true );
}

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

bool div_by_3( unsigned int num ) {
    if ( num % 3 == 0 ) {
        return( true );
    }
    return( false );
}

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

bool div_by_5( unsigned int num ) {
    if ( num % 5 == 0 ) {
        return( true );
    }
    return( false );
}

/* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */

/*
the first n values of a Fibonacci series are generated and the value is
substituted for...

... "Buzz" if divisible by 3
... "Fizz" if divisible by 5
... "BuzzFizz" if prime
... and the number, otherwise

Note that precedence is assumed top to bottom as show, e.g., 15 becomes
Buzz (even though divisible by 5) and 5 becomes Fizz even though prime

This implmentation creates the "word" list on the fly and only saves off
the last two Fib series numbers for forward calculation

Note that the Fibonacci series may start with either 0 or 1 with the same
result.  This implementation begins with 0, which is substituted for a
Buzz because 0 is divisible by every number.
*/

int main( int argc, char *argv[] ) {
    if ( argc != 2 ) {
        printf( "Usage:  my_prompt>  a.out <num_in_series>\n" );
        return( -1 );
    }

    unsigned int last_two[] = { 0, 1 };
    unsigned int n = ( unsigned int )( atoi( argv[ 1 ] ) );
    unsigned int next_el = 0;
    unsigned long max_check = 0;

    printf( "%s ", DIV_BY_3.c_str() );
    if ( n == 1 ) {
        printf( "\n" );
        return( 0 );
    }

    printf( "%d ", 1 );
    if ( n == 2 ) {
        printf( "\n" );
        return( 0 );
    }

    for ( unsigned int x = 2; x < n; x++ ) {

        max_check = ( unsigned long )last_two[ 0 ] + ( unsigned long )last_two[ 1 ];
        if ( max_check > ( unsigned long )UINT_MAX ) {
            printf( "\nOverflow detected. Truncating at %d elements in Fibonacci series.\n", x );
            return( -1 );
        } 
        
        next_el = last_two[ 0 ] + last_two[ 1 ];
        last_two[ 0 ] = last_two[ 1 ];
        last_two[ 1 ] = next_el;

        if ( div_by_3( next_el ) ) {
            printf( "%s ", DIV_BY_3.c_str() );
        } else if ( div_by_5( next_el ) ) {
            printf( "%s ", DIV_BY_5.c_str() );
        } else if ( is_prime( next_el ) ) {
            printf( "%s ", PRIME.c_str() );
        } else {
            printf( "%u ", next_el );
        }
    }
    printf( "\n" );
    return( 0 );
}

