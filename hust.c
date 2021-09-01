#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>

#define MAX_GRAY_LEVEL 128
#define IMG_HEIGHT 128
#define IMG_WIDTH 128

struct TPPS {
    int a;
    int b;
    int *c;
};
int arry[5]={0,1,2,3,4};
struct TPPS * func_with_struct_pointer_ret();
void init_arry(void){
	int arry[10]={0};
	
}
/// pointer_return_struct
int pointer_return_struct() {
    struct TPPS *a;
    a = func_with_struct_pointer_ret();
    if (a->c[3] == 3) {
        return 0;
    } else {
        return 1;
    }
}

int func_with_struct_pointer_para(struct TPPS *i);
int func_with_struct_pointer_para(struct TPPS *i)
{
    i->a=0;
	i->b=0;
	
	i->c=arry;
	return 0;
}


/// pointer_para_struct
int pointer_para_struct() {
    struct TPPS a;
    func_with_struct_pointer_para(&a);
    if (a.c[3] == 3) {
        return 0;
    } else {
        return 1;
    }
}


int func_with_pointer_para(int *i);

/// pointer_para
int pointer_para() {
    int i = 0;
    func_with_pointer_para(&i);
    if (i > 0) {
        return 1;
    } else {
        return 2;
    }
}

int read();

unsigned int Read_FlashFIFO[16];

void spi(unsigned int);

unsigned int search(unsigned long int Flash) {
    unsigned  int a, b, c, data;
    a = (Flash >> 8) & 0xFF00;
    b = (Flash) & 0xFF00;
    c = (Flash << 8) & 0xFF00;
    while (read() & 0x01);
    spi(a);
    spi(b);
    spi(c);
    for(int j=0; j < 16; j++) {
        Read_FlashFIFO[j] = 1;
    }
    data = Read_FlashFIFO[4];
    return data;
}

struct A33 {
    int a;
};

struct A22 {
    int a;
    struct A33 a33;
};

struct A11 {
    int a;
    int b;
    struct A22 a22;
    struct A33 a33;
    struct B11 *b11;
    struct {
        int c;
        int d;
    };
    union {
        int a;
        int b;
    } m;
};

struct B11
{
    struct A11 a11;
};

struct {
    int a;
    int b;
} g_anonymous;

///complex_struct_nested_1
void complex_struct_nested_1(struct A11 a11, struct B11 *b11, struct A22 *a22)
{
    if(g_anonymous.a > 0) {
        g_anonymous.a = 1;
    }

    if(a11.a > 0) {
        a11.a = 1;
    }
}

/// complex_struct_nested
void complex_struct_nested(struct A11 a11, /*struct B11 b11,*/ struct A22 a22) {
    if (g_anonymous.a > 0) {
        g_anonymous.a = 1;
    }
    if (a11.a > 0) {
        a11.a = 1;
    }
}

struct AAA {
    int a;
};

struct BBB {
    int a;
    struct AAA aa;
};



int sta(int a)
{
	
	static int c1=0;
	static int n1=0;
	int x=0;
	if((c1<10)&&(c1>5))
	{
		if(a==10)
		{
			n1=1;
			
		}
		
		
	}
	else if(c1<20)
	{
		
		if((n1==1)&&(a==5))
		{
			x=1;
		}
	}
	else
	{
		
	}
		c1++;
		return x;
}

int mcdc(int a,int d)
{
	
	static int c=0;
	static int n=0;
	int x=0;
	if((c<10)&&(c>5)&&(d > 0))
	{
		if(a==10)
		{
			n=1;
			
		}
		
		
	}
	else if(c<20)
	{
		
		if((n==1)&&(a==5))
		{
			x=1;
		}
	}
	else
	{
		
	}
		c++;
		return x;
}

/// nest_structAA
void nest_structAA(struct BBB *bb) {
    int a;
    if (bb[0].aa.a == 1) {
        a = 1;
    }
}

extern int e;

/// extern_variable
int extern_variable() {
    if (e > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// static_local
int static_local() {
    static int a = 0;
    if (a > 0) {
        return 1;
    } else {
		a++;
        return 2;
    }
}

/// memset
void memsetm(char *a, int size) {
    memset(a, 0, size);
}

/// strcpy
void strcpy_extend() {
    char a[3];
    a[0] = 'a';
    a[1] = 'a';
    a[2] = 0;
    char b[3];
    b[0] = 'a';
    b[1] = 'a';
    b[2] = 0;
    strcpy(a, b);
}

/// abs
int abs_moc(float a) {
    if (fabs(a) == a) {
        return 0;
    } else {
        return 1;
    }
}

struct ATest{
    char a;
    char b;
    int c;
};

int ab[20];

//#pragma pack(4)
typedef struct {
    //struct A a[2];
    //int b;
    char age ;
    char  age1 ;

    short a[10];

    char ac ;
} Age;
//#pragma pack()

/// multi_paras
void multi_paras(Age b, struct ATest a)
{

    if(a.a == 1) {

    }

    if(a.b == 5) {

    }

    if(a.c == 10) {

    }

}
#define RAM_ADDR     (*(volatile unsigned long  *)0x0000555F)
/// absolute_address_read
int absolute_address_read() {
    int j = *((int *) (2));
    int k = *((int *) (2));
	int tmp = RAM_ADDR;
    RAM_ADDR = 0x55;
    *((int *) (4)) = 3;
    if (j == k) {
        
    } else {
        
    }
	if(tmp==0x11)
	{
		
	}
}

/// absolute_address_write
int absolute_address_write() {
    *((int *) (2)) = 3;
    *((int *) (2)) = 4;
	int tmp = RAM_ADDR;
    RAM_ADDR = 0x55;
    return 1;
}


/// printf
void printf_mofunc() {
    printf("abc");
}

/// dynamic_parameter
int testdp(int a, ...) {
    va_list ap;
    va_start(ap, a);
    int b = va_arg(ap, int);
    va_end(ap);
    if (b > 0) {
        return 1;
    } else {
        return 2;
    }

}

/// dynamic_parameter
int dynamic_parameter(int i) {
    return testdp(1, i);
}

/// sqrt
int test1(double a) {
    double b = sqrt(a);
    if (b == 3) {
        return 1;
    } else {
        return 0;
    }
}

struct TestP1 {
    int a;
    int b;
};

struct TestP2 {
    struct TestP1 *a;
    int b;
    int c;
};

int struct_first_field_pointer(struct TestP2 *t) {
    t->b = 1;
    if (t->a->a > 0) {
        return 1;
    } else {
        return 2;
    }
}

struct {
    int a;
    int b;
} A, *B;

/// anonymous_struct
int anonymous_struct() {
    if (A.a > 0) {
        return 1;
    } else {
        return 2;
    }
}

/// anonymous_struct_pointer
int anonymous_struct_pointer() {
    if (B->a > 0) {
        return 1;
    } else {
        return 2;
    }
}

union U {
    int *a;
    long b;
};
union U eunion[2];

union U e1;

/// union_global_1
int union_global_1(long a) {

    if (eunion[0].a[0] == 5) {
        return 3;
    }

    if (eunion[1].b == 5) {
        return 4;
    }

    return 2;
}

/// union_global_2
int union_global_2(union U test) {
    if (e1.a[0] == 5) {
        return 3;
    }

    if (test.a[0] == 5) {
        return 4;
    }

    return 2;
}


///void_pointer
int void_pointer(void *test) {
    int *a = test;
    if (a[3] > 1) {
        return 1;
    } else {
        return 2;
    }
}

typedef char (*funp)(int a);

/// function_pointer
int function_pointer(funp fun) {
    char a = fun(2);
    if (a > 0) {
        return 0;
    } else {
        return 1;
    }
}


int g1[10];
int *g2;

/// global_assignment
int global_assignment() {
    g2 = g1;
    if (g2[2] > 0) {
        return 1;
    } else {
        return 0;
    }
}

///rem
int rem(int a, int b) {
    a = a % b;
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}

int test3() {
    return 1;
}

/// precision
int precision() {
    int a = test3();
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}


extern int test2();

/// symbolize_global
int symbolize_global() {
    int a = test2();
    if (a > 0) {
        int b = test2();
        if (b > 3)
            return 0;
        else
            return 4;
    } else {
        return 1;
    }
}

struct AG2 {
    int a;
};

struct AG1 {
    int a;
    struct AG2 *b;
};

struct AG {
    int a;
    int *b;
    int c;
    int d;
    int f;
    int e;
    int g;
};

struct ABCD {
    void *a;
    int b;
};

int ABCD(struct ABCD *a) {
    if (a->b > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// dynamic_type_1
void dynamic_type_1(void *a)
{
    int b;
    struct ABCD * a1 = (struct ABCD *)a;
    int * a2 = (int *)a1->a;

    if(a1->b == 1) {
        b = 1;
    }
    if(a2[0] == 3) {
        b = 2;
    }

}

/// dynamic_type_2
void dynamic_type_2(struct ABCD *a)
{
    int b;
    struct ABCD * a1 = a;
    int * a2 = (int *)a1->a;

    if(a1->b == 1) {
        b = 1;
    }
    if(a2[0] == 3) {
        b = 2;
    }

}

/// dynamic_type
int dynamic_type(struct AG1 *t) {
    struct AG *a = (struct AG *) t->b;
    if (a->b[3] > 0) {
        return 1;
    } else {
        return 0;
    }
}

struct AG global_struct;
struct AG *global_struct_pointer;
struct AG global_struct_array[10];

/// global
int global(int a) {
    if (a > global_struct.a) {
        return 0;
    } else {
        if (global_struct.b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

/// global_pointer
int global_pointer(int a) {
    if (a > global_struct_pointer->a) {
        return 0;
    } else {
        if (global_struct_pointer->b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

/// global_array
int global_array(int a) {
    if (a > global_struct_array[4].a) {
        return 0;
    } else {
        if (global_struct_array[4].b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}






