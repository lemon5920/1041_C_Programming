#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    char * key ;
    int count ;
    struct node * next ;
} ;
struct hashtable {
    struct node * data [ 97 ] ;
} ;
int hashCode ( char * key ) {
    int code = 0 ;
    while ( * key != 0) {
        code = code * 2 + * key ;
        key ++ ;
    }
    return code >= 0 ? code : - code ;
}
void init ( struct hashtable * h ) {
    int i ;
    for ( i = 0 ; i < 97 ; i ++ )
        h -> data [ i ] = ( struct node * ) NULL;
}
void put ( struct hashtable * h , char * k ) {
    int slot = hashCode ( k ) % 97 ;
    struct node * check ;
    struct node * tmp ;
    for ( check = h -> data [ slot ] ; check != NULL ; check = check -> next ) {
        if ( strcmp ( check -> key , k ) == 0 )
            break ;
    }
    if ( check == NULL ) {
        tmp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
        tmp -> key = ( char * ) malloc ( strlen ( k ) + 1 );
        strcpy ( tmp -> key , k ) ;
        tmp -> count = 0 ;
        tmp -> next = h -> data [ slot ] ;
        h -> data [ slot ] = tmp ;
        check = tmp ;
    }
    check -> count ++ ;
}
int get ( struct hashtable * h , char * key ) {
}
void print ( struct hashtable * h ) {
    int i ;
    struct node * check ;
    for ( i = 0 ; i < 97 ; i ++ ) {
        for ( check = h -> data [ i ] ; check != NULL ; check = check -> next ) {
            printf ( "%s %d\n" , check -> key , check -> count ) ;
        }
    }
}
int main() {
    char s [ 100 ] ;
    struct hashtable h ;
    init ( & h );
    while ( scanf ( "%100s" , s ) == 1 )
        put ( & h , s ) ;
    print ( & h ) ;
}
