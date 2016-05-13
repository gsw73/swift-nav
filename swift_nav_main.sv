package helpers;

    typedef enum { FALSE, TRUE } bool_t;
    
    /* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
    
/*
A prime number is only divisible by 1 and itself such that there is no
remainder.  This function checks all other possible divisors of a number to
see if any result in no remainder, in which case the number is not prime. 
*/
    function automatic bool_t is_prime( int num );
    
        if ( num == 0 || num == 1 )
            return FALSE;
    
        else if ( num == 2 )
            return TRUE;
    
        else
        begin
            for ( int x = 2; x < num; x++ )
            begin
                if ( num % x == 0 )
                    return FALSE;
            end
        end
    
        return TRUE;
    
    endfunction
    
    /* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
    
    function automatic bool_t div_by_3( int num );
    
        if ( num % 3 == 0 )
            return TRUE;
    
        else
            return FALSE;
    
    endfunction
    
    /* ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- */
    
    function automatic bool_t div_by_5( int num );
    
        if ( num % 5 == 0 )
            return TRUE;
    
        else
            return FALSE;
    
    endfunction

endpackage

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

module main;
    import helpers::*;

    const string DIV_BY_3 = "Buzz";
    const string DIV_BY_5 = "Fizz";
    const string PRIME = "BuzzFizz";

    int last_two[ 2 ] = '{ 0, 1 };
    int n = 15;
    int next_el = 0;
  	int num_in_series = 0;

    initial
    begin
        if ( $value$plusargs( "N=%d", num_in_series ) )
            n = num_in_series;

        $write( "%s ", DIV_BY_3 );
        if ( n == 1 ) $finish;
    
        $write( "%0d ", 1 );
        if ( n == 2 ) $finish;
    
        for ( int x = 2; x < n; x++ )
        begin
            
            next_el = last_two[ 0 ] + last_two[ 1 ];
            last_two[ 0 ] = last_two[ 1 ];
            last_two[ 1 ] = next_el;
    
            if ( div_by_3( next_el ) )
                $write( "%s ", DIV_BY_3 );
          
            else if ( div_by_5( next_el ) )
                $write( "%s ", DIV_BY_5 );
          
            else if ( is_prime( next_el ) )
                $write( "%s ", PRIME );
          
            else
                $write( "%0d ", next_el );
        end
          
        $write( "\n" );
        $finish;
    end
      
endmodule

