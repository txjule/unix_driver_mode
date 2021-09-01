#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>


#define MAX_GRAY_LEVEL 128
#define IMG_HEIGHT 128
#define IMG_WIDTH 128
int max_while(unsigned int i)
{ 
	i = 0;
    while (1){
        i++;
		if(i >= 6)
		{
			return i;
		}
    }
    return 0;	
}

int product(int a)
{
  
  if(a<0)
  {
    printf("error\n");
	return 5;
  }else if(a==0||a==1)
  {
    return 1;
  }else{
    return a*product(a-1);
  }         
}

#define WIDTHBYTES(bits) (((bits)+31) / 32 * 4)





typedef unsigned short UINT16;
typedef signed short SINT16;
typedef unsigned int UINT32;
typedef signed int SINT32;
typedef unsigned char UINT8;
typedef signed char SINT8;
typedef float REAL32;
typedef double REAL64;
typedef UINT16 PIXELTYPE;
typedef SINT16 SPIXELTYPE;
typedef PIXELTYPE TPLATEIMGTYPE;
typedef UINT8 EDGEIMGYTYPE;

typedef struct tagCIRCLE_CHAR
{
	SINT16 CenRow;
	SINT16 CenCol;
	SINT16 Radius;
	SINT16 RegionID;
}CIRCLE_CHAR;



void HoughtTransFixRadius(UINT8* lpDIBBits,SINT32 lWidth,SINT32 lHeight,SINT32 radius,SINT32* TransResult,SINT32 edgevalue,REAL32 th0);
SINT32 EdgeCirqueCorrMatchForPoint(UINT8* lpDIBBits,SINT32 lWidth,SINT32 lHeight,REAL32 radius,SINT32 x0,SINT32 y0,SINT32 edgevalue,SINT32* pNumOfTemplate);

void HoughTransFindCirque(UINT8* lpDIBBits, SINT32 lWidth, SINT32 lHeight, SINT32 edgevalue, CIRCLE_CHAR *cir)
{
	SINT32 i;
	SINT32 j;
	SINT32 num;
	SINT32 lLineBytes;
	REAL32 ratio;
	UINT8 lpNewDIBBits[IMG_HEIGHT*IMG_WIDTH];
	SINT32 cirInRad = 3;
	SINT32 cirOutRad = 50;
	SINT32 houghTres = 3;
	SINT32 cirCurRad;
	SINT32 sum;
	REAL32 maxRatio;
	SINT32 optix;
	SINT32 optiy;
	SINT32 TransResult[IMG_HEIGHT*IMG_WIDTH];
	SINT32 rad;
	lLineBytes = WIDTHBYTES(lWidth * 8);
	for(i = 0; i<lHeight; i++)
	{
		for(j = 0; j<lWidth; j++)
		{
			TransResult[i*lLineBytes+j] = 0;
		}
	}
	memcpy(lpNewDIBBits, lpDIBBits, lLineBytes*lHeight);
	for(cirCurRad = cirInRad; cirCurRad <= cirOutRad; cirCurRad++)
	{
		HoughtTransFixRadius(lpNewDIBBits, lWidth, lHeight, cirCurRad, TransResult, edgevalue, 0.3);
		for(i=0; i<lHeight; i++)
		{
			for(j=0; j<lWidth; j++)
			{
				if(TransResult[i*lLineBytes+j] >= houghTres)
				{
					sum = (SINT32)EdgeCirqueCorrMatchForPoint(lpNewDIBBits,lWidth, lHeight, cirCurRad, j, i, edgevalue, &num);
					ratio = (REAL32)sum/(REAL32)(num);
					if(ratio > maxRatio)
					{
						maxRatio = ratio;
						optix = j;
						optiy = i;
						rad = cirCurRad;
					}
				}
			}
		}
	}
	if(maxRatio < 0.3)
		return;
	cir->CenRow = optix;
	cir->CenCol = optiy;
	cir->Radius = rad;
	return;
}

struct returninteg { 
	unsigned char Sign; 
	float CurrentInteg; 
	unsigned int Control; 
}; 

struct returninteg AziFXPIOutput,HeiFXPIOutput;

struct integ { 
	float LastDev; 
	float CurrentDev; 
	float LastInteg; 
}; 

struct integ AziFXPIInput,HeiFXPIInput; 

float Ux2_PI ,Ux2_PI0 ,Ux2_D; 

#define AzimuthKP2 3 
#define AzimuthZERO 2047.0 
#define AzimuthKI2 0.005
#define AzimuthKD2 0

void Sys_AzimuthControl_PID() 
{ 
	float AziFXPIControl; 
	AziFXPIOutput.Sign = 0; 
	
	Ux2_PI=Ux2_PI0+AzimuthKP2*(AziFXPIInput.CurrentDev-AziFXPIInput.LastDev)+AzimuthKI2*(AziFXPIInput.CurrentDev+AziFXPIInput.LastDev); 
	
	Ux2_D=AzimuthKD2*(AziFXPIInput.CurrentDev-AziFXPIInput.LastDev);  
	
	AziFXPIControl =Ux2_PI + Ux2_D + AzimuthZERO;
	
	if( AziFXPIControl > 0 ) 
	{ 
		AziFXPIOutput.Sign = 1; 
	} 
	if( AziFXPIControl>4095.0 ) 
	{ 
		AziFXPIOutput.Control = 0xFFF; 
	} else if( AziFXPIControl<0.0 ) 
	{ 
		AziFXPIOutput.Control = 0; 
	} else { 
		AziFXPIOutput.Control = (unsigned short)AziFXPIControl; 
	} 
	
	AziFXPIInput.LastDev = AziFXPIInput.CurrentDev; Ux2_PI0=Ux2_PI; 
}

void sys_temp()
{
	Sys_AzimuthControl_PID();
}

int Ternary_expression(int a)
{
	int j = a;
	if(((j>0)?1:2) == 1)
	{
		return 1;
	}else
	{
		return 2;
	}
}

int fortest(int i)
{
	for(;;) {
		i++;
    }
	return i;

}

unsigned int NavInfoTrans(char cInfo[], char* cNavInfo, int iDev)
{
	unsigned int i = 0;
	char cDev = '0';
	int iInfoHead = 0;
	int iInfoEnd = 0;
	unsigned int iLen = 0;
	
	if(iDev == 0)
	{
		cDev = 'I';
	}else
	{
		cDev = 's';
	}
	
	for(i = 0; i < strlen(cNavInfo); i++)
	{
		if((cNavInfo[i] == cDev) && (cNavInfo[i + 1] == ':'))
		{
			iInfoHead = i + 2;
		}
		
		if((iInfoHead > 0) && (cNavInfo[i] == ';'))
		{
			iInfoEnd = i;
			iLen = iInfoEnd - iInfoHead;
			memcpy(cInfo, &cNavInfo[iInfoHead], iLen);
			cInfo[iLen] = '\0';
			break;
		}
	}
	
	return (iLen + 1);
}

int doubleTestdoubleTest(double a, double b, int g){
  double c = 0.0;
  double d = 0.0;
  
  int e = 0;
  int f = 0;
  
  c = a / g;
  e = a / b;
  
  if ( b == 2)
    e++;
  
  return c;
}

#define GL_LUMINANCE 3

unsigned int texFomat;


unsigned char* getGray(FILE *s, int size)
{
	unsigned char *grayData = NULL;
	int bread;

	if(NULL == s){
		return 0;
	}
	grayData = (unsigned char*)malloc(size);

	if(grayData == NULL){
		return 0;
	}
	bread = fread(grayData, sizeof(unsigned char), size, s);

	if(bread != size)
	{
		free(grayData);
			grayData = NULL;
		return 0;
	}else{
		grayData = (unsigned char*)malloc(size);
	}		

	texFomat = GL_LUMINANCE;

	return grayData;
}

int (*function_pointer[3])(int i);
/*
int func_p1(int kk);

int func_p2(int b);

int func_p3(int c);

function_pointer[0] = func_p1;
function_pointer[1] = func_p2;
function_pointer[3] = func_p3;
*/
int function_pointer_array(int k)
{
	int p;
	k = function_pointer[0](k);
	if(k > 0)
	{
		k = 1;
		return k;
	}else if(k == 0){
		k = -1;
		return k;
	}
	
	p = function_pointer[1](p);
	if(p == -1)
	{
		return p;
	}else{
		return function_pointer[2](function_pointer[0](k));
	}
}

int stub(){
	int b = 1;
	return b;
}

int stub1();

int concrete_endless_loop(int i)
{
	i = 1;
	int a = 1;
	int b = 2;
	while (i < 10)
	{
		b = stub();
		a++;
	}
	return a;
}

int symbolic_endless_loop(int i)
{
	int a = 1;
	int b = 2;
	while (i < 10)
	{
		b = stub();
		a++;
	}
	stub1();
	return a;
}


int endless_loop(int i)
{
	int a = 1;
	int b = 2;
	while (1)
	{
		stub1();
		a++;
	}
	return a;
}








