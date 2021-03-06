/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    printf("begin show int %d \n", x);
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_short(short x) {
    printf("begin show short %d \n", x);
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(short x) {
    printf("begin show long %d \n", x);
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_float(float x) {
    printf("begin show float %f \n", x);
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

void show_double(double x) {
    printf("begin show double %f \n", x);
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *)); //line:data:show_bytes_amp3
}
/* $end show-bytes */


/* $begin test-show-bytes */
void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
/* $end test-show-bytes */


int main(int argc, char *argv[])
{
    short shortVal = 12345;
    long longVal = 12345;
    double doubleVal = 1.2345;
    show_short(shortVal);
    show_long(longVal);
    show_double(doubleVal);
    return 0;
}
