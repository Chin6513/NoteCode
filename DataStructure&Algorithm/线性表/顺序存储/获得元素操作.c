#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20			/*存储空间初始分配量*/
typedef int ElemType;		/*ElemType类型根据实际情况而定，这里假设为int*/
typedef struct
{
	ElemType data[MAXSIZE];	/*数组存储数据元素，最大值为MAXSIZE*/
	int length;					/*线性表当前长度*/
}SqList;
typedef int Status;
/*Status是函数的类型，其值是函数结果状态代码，如OK等*/
/*初始条件：顺序线性表L已存在，1≤i≤ListLength（L）*/
/*操作结果：用e返回L中第i个数据元素的值*/

Status GetElem (SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];
	return OK;
}