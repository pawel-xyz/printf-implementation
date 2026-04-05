#include <stdio.h>
#include <stdarg.h>

int Printf( const char* sFormat, ...  );
int PrintfV( const char* sFormat, va_list argList );

void outDec( int );
void outChar( char );
void outStr( char* );
void outDouble( double );
void outNum( int x );

int Printf( const char* sFormat, ... )
{
    va_list args;

    va_start( args, sFormat );

    int res = PrintfV( sFormat, args);

    va_end( args );

    return res;
}

int PrintfV( const char* sFormat, va_list argList )
{
    int format_counter = 0;

    char c;

    while( (c = *sFormat) != '\0' )
    {
        switch( c )
        {
            case '%':
                sFormat++;
                switch( c = *sFormat )
                   {
                     case 'd': {int val1 = va_arg( argList, int ); outDec(val1); format_counter++; break;}
                     case 'f': {double val2 = va_arg( argList, double); outDouble(val2); format_counter++; break;}
                     case 's': {char* val3 = va_arg( argList, char*); outStr( val3 ); format_counter++; break;}
                     case 'c': {char val4 = (char)va_arg( argList, int); outChar(val4); format_counter++;  break;}
                     case '%': {outChar( '%'); break;}
                     default: {outChar( c ); break;}
                   }
                    break;
            default: {outChar('%'); outChar(c); break;}
        }
        sFormat++;
    }
    return format_counter;
}

void outChar( char c )
{
    putchar( c );
}

void outStr( char* pStr )
{
    while( *pStr != '\0')
    {
        outChar( *pStr );
        pStr++;
    }
}

void outDec( int x )
{
    if( x == 0)
    {
        outChar( '0' );
        return;
    }

    if( x<0 )
    {
        outChar( '-' );
        x = -x;
    }
    outNum( x );
}

void outDouble( double x )
{
    if( x< 0)
    {
        outChar('-');
        x = -x;
    }

    int Ipart = (int)x; // Ipart stands for Integer part
    outDec( Ipart );

    double rest_from_div = x - Ipart;
    if( rest_from_div <= 1e-6) return;
    outChar('.');

    int digits =0;

    while( rest_from_div > 1e-6 && digits < 8)
    {
        rest_from_div *= 10;

        int digit = (int)rest_from_div;

        outChar(digit + '0');

        rest_from_div = rest_from_div - digit;

        digits++;
    }
}

void outNum( int x )
{
    if(x>0 )
    {
        outNum(x/10 );
        outNum( (x%10) + '0' );
    }
}

