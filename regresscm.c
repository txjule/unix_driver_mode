#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>

int test(int i) {
    return i + 1;
}

#ifdef __cplusplus
extern "C" {
#endif

void secore_symbolize(void *address, unsigned int size);

#ifdef __cplusplus
}
#endif

/// malloc
int malloc_fack() {
    int *p = malloc(sizeof(int) * 4);
    secore_symbolize(p, sizeof(int) *4);
    if (p[2] > 0) {
        return 1;
    } else {
        free(p);
        return 2;
    }
}

struct A {
    int a;
    int b;
};


struct B {
    double a;
    int *b;
    int *d;
    struct A *c;
};

struct C {
    float *a;
};


struct D {
    double a;
    int *b;
    int *d;
    struct C *c;
};

struct E {
    int *a;
    struct D *b;
};

typedef struct {
    int a;
    struct E b;
} F;

typedef struct {
    struct A a;
    int b;
} G;


typedef struct {
    float *a;
} AA;

typedef struct {
    AA a;
} BB;

typedef struct {
    BB a;
} CC;

typedef struct {
    CC a;
} DD;

struct Z {
    int a[5];
};


union UU {
    int a;
    int b;
    double c;
};

enum AE {
    a1 = 5,
    a2
};

union UU1 {
    int *a;
    double c;
};


struct ABit {
    char a:1;
    char b:7;
    int *c;
};

#pragma  pack(2)

struct ABit1 {
    int a:1;
    int b:2;
    int c:1;
	int d:8;
	int short1:16;
	int integer:32;
};

#pragma  unpack

typedef union {
    char a;
    int b;
    float c;
    double *d;
} unionA;

typedef struct {
    unionA a;
    unionA *b;
    unionA c[5];
} structA;

///union_pointer_array
int union_pointer_array(unionA test) {
    if (test.d[4] > 5.0) {
        return 0;
    } else {
        return 1;
    }
}

/// union_complex
int union_complex(structA test) {
    if (test.b->d[2] > 5.0) {
        return 0;
    } else {
        return 1;
    }
}

/// struct_bit
int struct_bit(struct ABit1 *a) {
    if (a->a == 1) {
        return 1;
    } else {
        return 2;
    }
}

/// union_pointer
int union_pointer(union UU1 *a) {
    if (a->a[2] == 2) {
        return 1;
    } else {
        return 2;
    }
}

/// enum
int enum_test(enum AE t) {
    if (t == a1) {
        return 1;
    } else {
        return 2;
    }
}

/// union
int union_pp(union UU *a) {
    if ((a->a + a->b) == 2) {
        return 1;
    } else {
        return 2;
    }
}


/// switch
int switchindex(int i) {
    switch (i) {
        case 1:
        case 10:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 4;
    }
}

/// struct_array_element
int struct_array_element(struct Z a) {
    if (a.a[3] == 5) {
        return 1;
    } else {
        return 2;
    }
}

/// struct_array
int struct_array(struct B test[]) {
    if (test[1].b[3] > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// nested_typedef
int nested_typedef(DD *t) {
    if (t->a.a.a.a[5] > 11.1) {
        return 0;
    } else {
        return 1;
    }
}

/// wxb_simple_struct
int wxb_simple_struct(G test) {
    if (test.b > 11) {
        if (test.a.a + test.a.b < 11) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

/// wxb_struct_field_complex
int wxb_struct_field_complex(F *struct_f, struct B struct_b) {
    if (struct_f->a > 2) {
        return 1;
    } else {
        if (struct_f->b.a[3] == 5) {
            return 2;
        } else {
            if (struct_f->b.b->a == 11.1) {
                return 3;
            } else {
                if (struct_b.a == 11.1) {
                    return 4;
                } else {
                    if (struct_b.c->a > 8) {
                        return 5;
                    } else {
                        return 6;
                    }
                }
            }
        }
    }
}


/// typedef
int typedef_function(F *test) {
    if (test->b.a[3] == 5) {
        return 1;
    } else {
        return 0;
    }
}


/// watchdog
int watchdog(int i) {
    while (i < 0) {
        i--;
    }
    return i;
}

/// double_pointer_integer
int double_pointer_integer(double *a, int i) {
    if (a[i] > 100) {
        return 0;
    } else {
        return 1;
    }
}


/// double_pointer
int double_pointer(double *a) {
    if (a[1] == 10.0) {
        return 1;
    } else {
        return 2;
    }
}

/// char_a
int char_a(char *a, char *b) {
    int index = 24 / 6;
    if (a[0] == b[0]) {
        return 1;
    } else if (a[index] == b[index]) {
        return 2;
    } else {
        return 0;
    }
}

/// struct_field
int struct_field(struct B *test) {
    if (test->c->a == 11) {
        if (test->b[10] == 3) {
            return 1;
        } else if (test->d[3] == 4) {
            return 2;
        }
        return 0;
    } else {
        return 3;
    }
}

/// wxb_struct_field
int wxb_struct_field(struct E *test) {
    if (test->b->c->a[5] == 11) {
        if (test->b->b[10] == 3) {
            return 1;
        } else if (test->b->d[3] == 4) {
            return 2;
        }
        return 0;
    } else {
        return 3;
    }
}


/// while
int while_test(unsigned int a) {
    while (a > 0 && a < 5) {
        a--;
    }
    return 1;
}

/// divbyzero
double divbyzero(double a, int b , float s, long m) {
	int i;
	float k;
	i = a / b;
	k = s / a;
	k = m / s;
	k = b / a;
    if (a == 5) {
        return a / b;
    } else {
        return i;
    }
}

/// int_pointer
int int_pointer(int *a, int i) {
    if (i >= 0 && a[i] > 0) {
        if (a[i + 1] < 0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 3;
}

/// char
int char_test(char a, char b, char c) {
    char t = 0x12;
    if (a == 'c') {
        if (b == 'a' && c == 'b') {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

/// float_1
int float_1(float a) {
    if ( a == 15) {
        return 1;
    } else {
        return 0;
    }
}

/// float
int float_test(float a) {
    if (a * a * a == 8) {
        return 0;
    } else {
        return 1;
    }
}

/// overflow
int overflow(int a, int b) {
    if (a > 0 && b > 0) {
        if ((a + b) < 0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

/// bfs
int bfs(int a, int b) {
    if (a == 0) {
        if (b == 0) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (b == 3) {
            return 3;
        } else {
            return 4;
        }
    }
}


/// UC_multiple_arguments_pointer_pointer_integer_integer
int UC_multiple_arguments_pointer_pointer_integer_integer(int *a, int *b, int i, int j) {
    if (a[i] > 10) {
        if (b[j] > 100) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 3;
    }
}

/// UC_multiple_arguments_pointer_integer
int UC_multiple_arguments_pointer_integer(int *a, int i) {
    if (a[i] > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// UC_multiple_arguments
int UC_multiple_arguments(int a, int b) {
    if (a > 90) {
        if (b > 20) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 3;
    }
}

/// UC_se_symbolic_pointer_write_complex
int UC_se_symbolic_pointer_write_complex(int *a) {
    a[0] = 1;
    int *b = a;
    b++;
    if (b[1] > 1) {
        int *c = a;
        if (c[1] > 1)
            return 1;
        else
            return 2;
    } else {
        return 0;
    }
}

/// UC_se_symbolic_pointer_write
int UC_se_symbolic_pointer_write(int *a) {
    a[5] = 1;
    if (a[5] > 1) {
        return 1;
    } else {
        return 0;
    }
}

/// UC_se_symbolic_pointer
int UC_se_symbolic_pointer(int *a) {
    if (a[1] > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// UC_se_symbolic_int
int UC_se_symbolic_int(int a) {
    if (a > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// assign
int assign(int *a) {
    a[2] = 1;
    return a[2];
}

enum State {
    SET,
    UNSET
};

enum State getState();


typedef struct DataTime
{
	unsigned int a ;
	int b;
	int data[6];
	structA sa;
};
typedef struct strUpDataTime_1
{   
    
	unsigned char type;
	unsigned int time;
	unsigned int **poin;
	struct DataTime DATA[6];
}UP_DATA_TIME_1;
UP_DATA_TIME_1 g_strUpDataTime_1[6][5];

/*
unsigned int fModifyTime_1(unsigned int addr,unsigned char num,unsigned char step)
{
	//二维结构体
    unsigned int n_uiTime;
    //n_uiTime = fReadInt(addr);
	if(g_strUpDataTime_1[num].DATA[step].data[10]==10)
	{
		return g_strUpDataTime_1[num].DATA[step].a;
		
	}
    if(g_strUpDataTime_1[step].type == 0xaa)/*替换新的时间*//*
    {
        return g_strUpDataTime_1[step].time;
    }
    else
    {
        return n_uiTime;
    }
}
*/
char *str=NULL;
void GetMemory(char**p,int num)
{
	*p=(char*)malloc(num);
}

void Test(void)
{
	
	GetMemory(&str,100);
	if(str==NULL)
	{
		return ;
	}
	strcpy(str,"hello");
	printf(str);
	free(str);
	str=NULL;
	
}
void pointer(int** p)
{
	
	if( p[1][2]==3)
	{
		
		int a=0;
		
	}	
}


int func_t(UP_DATA_TIME_1 **ai)
{
	int i = 0;
	*ai = *g_strUpDataTime_1;
	ai[0][0].time = 0;
	for(; i<ai[0][0].type; i++)
	{
		ai[i][i].time = i;
	}
	
	if(ai[i][i].time > 10)
	{
		return 0;
	}
		return 1;
}




unsigned short g_usBrcstTimeBuf[4];
unsigned short g_usBrocTime[3];
unsigned int g_uiSysTime[3];
unsigned int g_uiSatChkTimerFlag;
#define Ace_Mem_Base 0
#define aceRegWrite(aceReg,data) ((*(unsigned int*)(aceReg))=(unsigned int*)(data))
#define	aceMemRead(aceMem)       ((unsigned short) ((*(unsigned int *)((aceMem)*4+(Ace_Mem_Base)))))
#define Time_Tag_REG 66
#define IMMEVENT_NUM 5 
#define IMMEVENT_PER_LEN 6
#define WORK_TABLE_NUM 33
void fDealBrocTimeInfo(unsigned short msp)
{
	//绝对地址
    unsigned short dp,i;
    unsigned int n_uiEomTime,n_uiRandomDelay;
    unsigned short n_usChkTimeType;
    unsigned char n_ucRec,n_ucCur;
    unsigned char n_ucTempBrocTime[6];
    dp = aceMemRead(msp + 2);
    n_uiEomTime = aceMemRead(msp + 1);/*读取消息时间标签*/
     
    for(i = 0; i < 4; i = i + 1)
    {
        g_usBrcstTimeBuf[i] = aceMemRead(dp+i);
       // logMsg("BrocTimeNo.%04x = %04x\n",i,g_usBrcstTimeBuf[i],0,0,0,0);   
         
    }
    n_usChkTimeType = g_usBrcstTimeBuf[0];
    g_usBrocTime[0] = g_usBrcstTimeBuf[1];
    g_usBrocTime[1] = g_usBrcstTimeBuf[2];
    g_usBrocTime[2] = g_usBrcstTimeBuf[3];
     
    n_ucRec = (unsigned char)(g_usBrocTime[0]>>8);
    n_ucCur = (unsigned char)(g_uiSysTime[0]>>24);
    if(n_ucRec>=n_ucCur)
    {
        g_uiSysTime[0] = ((unsigned int)g_usBrcstTimeBuf[1]<<16)|(unsigned int)g_usBrcstTimeBuf[2];
        g_uiSysTime[1] = g_usBrcstTimeBuf[3];
        n_uiRandomDelay = aceMemRead(Time_Tag_REG);
        aceRegWrite(Time_Tag_REG,0);/*clear ace time tag register,and clear time rest*/
        g_uiSysTime[2] = 0;
        /*补偿1553B传输时间和语句处理时间*/
        if(n_uiRandomDelay >= n_uiEomTime)
        {
            n_uiRandomDelay = n_uiRandomDelay - n_uiEomTime;
        }
        else
        {
            n_uiRandomDelay = 0x10000-n_uiEomTime + n_uiRandomDelay;
        }
        n_uiRandomDelay = (n_uiRandomDelay << 6) +80;/*传输1Mbps，传输8字节大概需要的时间，单位us*/
        if((n_uiRandomDelay % 100)>=50)/*四舍五入*/
        {
            n_uiRandomDelay = n_uiRandomDelay/100;/*100us的计数*/
            n_uiRandomDelay = n_uiRandomDelay + 1;  
        }
        else
        {
            n_uiRandomDelay = n_uiRandomDelay/100;
        }
        g_uiSysTime[1] = g_uiSysTime[1] + n_uiRandomDelay;
        g_uiSysTime[0] = g_uiSysTime[0] + (g_uiSysTime[1]>>16);
        g_uiSysTime[1] = g_uiSysTime[1] & 0xFFFF;
             
        g_uiSatChkTimerFlag = 0x5A5A5A5A;
    }
     
}



unsigned short g_usInjectMultCnt;
unsigned char g_ucNewCodeFlag;
unsigned char g_ucInjectErrType;
unsigned char g_ucImmEventCnt;
unsigned int g_uiNewCodeLeng;
unsigned char g_ucInjectErrCnt;
unsigned char g_ucInjectFrameNum;
unsigned char g_ucUploadFlag;
unsigned char g_ucInjectExeCnt;

unsigned short g_usUpPromPakFlag;
unsigned short g_usInjectDataBuf[150];
unsigned int g_uiUploadLen;
unsigned int g_uiNewCodeBuf[30];
unsigned short g_usImmEventTable[10][5];/* 立即指令表 */
void fDataInjectMove(UP_DATA_TIME_1 **n_uiEomTime, int ks)
{
	//不明原因
    unsigned short n_usPakCnt, n_usPakFlag;
    unsigned short n_usIdx,n_usIdy;
    unsigned int n_uiKdx;
    unsigned int n_uiWrAddr;
    unsigned short n_usLength,n_usDataType;
    unsigned int n_uiDataTmp;
    unsigned char n_ucPayLoadNum,n_ucSatelliteNum,n_ucRsIndexNum;
    unsigned char n_ucWorkTableNum,n_ucWorkStepNum;
     
    unsigned short* pBuf;
    unsigned short n_usPakLen,n_usLenTmp1,n_usLenTmp2;
	*n_uiEomTime = *g_strUpDataTime_1;

     
/*  unsigned int n_uiSrcAddr;*/
     
    n_usPakFlag = g_usInjectDataBuf[1] & 0xC000;  /* 分组标识 */
    n_usPakCnt  = g_usInjectDataBuf[1] & 0x3FFF;    /* 包序号 */
    if(0xC000 == n_usPakFlag)/* 独立包 */
    {
        g_ucInjectFrameNum = g_ucInjectFrameNum + 1;/* 数据注入帧计数加1 */
        if(g_usInjectDataBuf[3] == 0x000A)/*功能注数-立即执行数据注入*/
        {
            if(g_usInjectDataBuf[2] == 0x000D)/*常用数据注入指令包长度固定为0x0d*/
            {
                    if(g_ucImmEventCnt < IMMEVENT_NUM )
                    {
                        for(n_usIdx = 0; n_usIdx < IMMEVENT_NUM; n_usIdx = n_usIdx + 1)
                        {
                            if(g_usImmEventTable[n_usIdx][0] == 0)
                            {
                                g_usImmEventTable[n_usIdx][1] = g_usInjectDataBuf[4];/* 立即指令内容--码字 */
                                g_usImmEventTable[n_usIdx][2] = g_usInjectDataBuf[5];/* 立即指令内容--指令内容 */
                                g_usImmEventTable[n_usIdx][3] = g_usInjectDataBuf[6];/* 立即指令内容--指令内容 */
                                g_usImmEventTable[n_usIdx][4] = g_usInjectDataBuf[7];/* 立即指令内容--指令内容 */
                                g_usImmEventTable[n_usIdx][5] = g_usInjectDataBuf[8];/* 立即指令内容--EEPROM指令编号 */
                                g_usImmEventTable[n_usIdx][0] = 0x5A;/* 置上更新标识 */
                                g_ucImmEventCnt = g_ucImmEventCnt + 1;
                                break;
                            }
                        }
                    }
                    else
                    {
                        g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                        g_ucInjectErrType = 0x77;/* 事件表满 */
                    }
            }
            else
            {
                g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                g_ucInjectErrType = 0x22;/* 数据注入指令长度错误 */
            }
        }
        else if(n_uiEomTime[0][1].DATA->data[4]== 0x000B)/*功能注数-大型数据块数据注入*/
        {
            n_usPakLen = g_usInjectDataBuf[2] + 1;/* 字节长度 =  功能识别2字节+数据内容N字节+4字节数据内容校验和+2字节数据包校验和 */
            n_usLenTmp1 = (n_usPakLen-8)%4;
            n_usLenTmp2 = (n_usPakLen-4)/2;/*数据内容+数据内容校验和的2字长度*/
            g_uiUploadLen = (n_usPakLen-8)/4;/*数据内容的4字节长度*/
            if((n_usPakLen>=12)&&(n_usPakLen<=248)&&(n_usLenTmp1 == 0))
            {
                pBuf = (unsigned short*)&g_uiNewCodeBuf[0];
                for(n_usIdy = 0; n_usIdy < n_usLenTmp2; n_usIdy = n_usIdy + 1)
                {
                    pBuf[n_usIdy] =  g_usInjectDataBuf[n_usIdy+4];
                }
                g_ucInjectExeCnt = g_ucInjectExeCnt + 1;
/*              g_ucInjectFrameNum = g_ucInjectFrameNum + 1;*//* 数据注入帧计数加1 */
/*              g_uiNewCodeSum = 0;*/
                g_ucNewCodeFlag = 0x3c;/*开始对数据内容缓冲区进行校验*/
/*              logMsg("g_ucNewCodeFlag = 0x3c !!!!\n",0,0,0,0,0,0);*/
            }
            else
            {
                g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                g_ucInjectErrType = 0xDD;/* 数据注入内容错误-修改长度错误 */
            }
        }
        else
        {
            g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
            g_ucInjectErrType = 0x44;/* 数据注入功能识别错误 */
        }
    }
    else if(0x4000==n_uiEomTime[0][1].DATA->a && 0x4000==n_uiEomTime[0][1].DATA->b)/*首包*/
    {
        g_usInjectMultCnt = 0;
        if(g_usInjectDataBuf[2] == 0x00F9)/*程序上载包长度固定为0xF9*/
        {
            if(n_usPakCnt == 0)
            {
                if(g_usInjectDataBuf[3] == 0x000B)
                {
                    pBuf = (unsigned short*)&g_uiNewCodeBuf[0];
                    for(n_usIdy = 0; n_usIdy < 20; n_usIdy = n_usIdy + 1)
                    {
                        pBuf[n_usIdy] = g_usInjectDataBuf[4+n_usIdy];
                    }
                    g_uiNewCodeLeng = 123;  /* 已注入程序代码的2字长度 */
                    g_usInjectMultCnt = g_usInjectMultCnt+1;    /* 首包-数据注入多包计数置1 */
                    g_usUpPromPakFlag = 0x5555; /*包控制序置为首包*/
                    g_ucInjectExeCnt = g_ucInjectExeCnt + 1;
                }
                else
                {
                    g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                    g_ucInjectErrType = 0x44;/* 数据注入功能识别错误 */
                }
            }
            else
            {
                g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
                g_ucInjectErrType = 0x99;/*首包包序号不为0*/
            }
        }
        else
        {
            g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
            g_ucInjectErrType = 0x22;/* 数据注入指令长度错误 */
        }
    }
    else/*中间包*/
    {
        if(g_usInjectDataBuf[2] == 0x00F9)/*程序上载包长度固定为0xF9*/
        {

			g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
			g_ucInjectErrType = 0xAA;/*中间包序错误*/
        }
        else
        {
            g_ucInjectErrCnt = g_ucInjectErrCnt + 1;
            g_ucInjectErrType = 0x22;/* 数据注入指令长度错误 */
        }
    }
    return;
}


int func3(int aaa)
{
	if(aaa == 1)
		return 1;
	else if(aaa == 2)
		return 2;
	return 3;
}


typedef struct strUpDataTime
{
	unsigned char type;
	unsigned int time;
}UP_DATA_TIME;
UP_DATA_TIME g_strUpDataTime[WORK_TABLE_NUM][64];


unsigned int fModifyTime(unsigned int addr,unsigned char num,unsigned char step)
{
	//二维结构体
    unsigned int n_uiTime;
    n_uiTime = 1;
    if(g_strUpDataTime[num][step].type == 0xaa)/*替换新的时间*/
    {
        return g_strUpDataTime[num][step].time;
    }
    else
    {
        return n_uiTime;
    }
}


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>


#define MAX_GRAY_LEVEL 128
#define IMG_HEIGHT 128
#define IMG_WIDTH 128

typedef unsigned short UINT16;
typedef UINT16 PIXELTYPE;
typedef signed int SINT32;

typedef struct tagSEGMENT_LINE
{
	SINT32 start;
	SINT32 finish;
}SEGMENT_LINE;


SINT32 GetBkginfo(PIXELTYPE* pImg,SEGMENT_LINE* pRgn){
	SINT32 i,j;
	SINT32 GreyNum[MAX_GRAY_LEVEL + 1];
	
	memset(GreyNum,0,sizeof(SINT32) * (MAX_GRAY_LEVEL + 1));
	for(i = 0;i < IMG_HEIGHT; i++){
		for(j = 0;j <= 128;j++){
			GreyNum[pImg[i * IMG_WIDTH + j]]++;
			
		}
	}
	for(i = 0;i < MAX_GRAY_LEVEL; i++){
		GreyNum[i + 1] = GreyNum[i + 1] + GreyNum[i];
	}
	i = 1;
	while(GreyNum[i] < (GreyNum[MAX_GRAY_LEVEL] >> 4)){
		i++;
	}
	return i - 1;
}

//typedef unsigned short UINT16;
typedef struct{
	UINT16 wparaindex;
	UINT16 wparatype;
	UINT16 wCRC;
	UINT16 wParaL;
	UINT16 wParaH;
	
}PARA_PACKAGE_DATA;


typedef union{
	PARA_PACKAGE_DATA word;
	UINT16 all[5];
}PARA_PKG_DATA;

enum _ParaIndex{
	Para_Sys_Serial_Ctrl = 100,
	Para_Sys_Ver_soft = 101,
	Para_Sys_Serial_Reg = 102,
	Para_Sys_Max = 103,
	Para_CRC = 104
};

void paraUpdate(UINT16 wData[]){
	PARA_PKG_DATA pkg;
	char bDat[4];
	UINT16 wCRC = 0;
	memcpy(pkg.all,wData,sizeof(pkg.all));
	
	if(pkg.all == NULL){
		int i = 0;
	}
	
	if(wData == NULL){
		int i = 1;
	}
	
	if(pkg.all[2] == 0){
		int i = 2;
	}
	
	if(pkg.word.wparaindex == Para_CRC){
		int i = 3;		
	}
}

struct app{
    int a;
    int b;
    int c;
	int *e;
};

void func_struct_para(struct app *i)
{
	if(i->a > 10){
		i->a = 100;
		i->b = 101;
		i->c = 102;
		i->e = NULL;
	}
	else{
		i->a = 108;
		i->b = 109;
		i->c = 110;
		i->e = NULL;
	}   
}

int pointer_parament(){
    struct app a;
    func_struct_para(&a);
	
	if(a.e[2] > 10){
		return 1;
	}
	else{
		return 1;
	} 
}
 

int pointer_para1(){
    struct app *a;
	struct app temp;
	a = &temp;
    func_struct_para(a);
	if(a->c == 102){
		a->b+=1;
		return a->b;
	}
	else{
		a->b+=2;
		return a->b;
	}
	if(a->e[2] > 10){
		a->b+=3;
		return a->b;
	}
	else{
		a->b+=4;
		return a->b;
	} 
}







