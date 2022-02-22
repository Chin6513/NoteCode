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

/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L),*/
/*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert (SqList *L,int i,ElemType e)
{
	int k;
	if(L->length==MAXSIZE)/*顺序线性表已经满*/
		return ERROR;
	if(i<1||i>L->length+1)/*当i不在范围内时*/
		return ERROR;
	if(i<=L->length)/*若插入数据位置不在表尾*/
	{
		for(k=L->length-1；k>=i-1；k--)/*将要插入位置后数据元素向后移动一位*/
			L->data[k+1]=L->data[k];
	}
	L->data [i-1]=e;	/*将新元素插入*/
	L->length++;
	return OK;
}