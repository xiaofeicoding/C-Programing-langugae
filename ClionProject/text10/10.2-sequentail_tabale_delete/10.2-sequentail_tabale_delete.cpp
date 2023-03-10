#include <iostream>

//顺序表的定义
#define MaxSize 50 //定义线性表的长度
typedef int ElementType;
typedef struct{
    int length;//顺序表的长度命名
    ElementType date[MaxSize];//顺序表的元素
}SqTable;//顺序表的类型定义

bool TableInsert(SqTable &T,int location,ElementType e){
    if (location<1 || location>T.length+1){
        return false;
    }
    if (T.length>=MaxSize){
        return false;
    }
    for (int j=T.length;j>=location;j--){
        T.date[j]=T.date[j-1];//把j-1赋值给j
    }
    T.date[location-1]=e;//放入要插入的元素
    T.length++;
    return true;
}

void PrintTable(SqTable T){
    int i;
    for(i=0;i<T.length;i++)
    {
        printf("%3d",T.date[i]);
    }
    printf("\n");
}


//删除顺序表中的元素
bool TableDelete(SqTable &T,int location,ElementType &e){
    //判断删除的位置是否合法
    if(location<1 || location>T.length){
        return false;
    }
    e=T.date[location-1];//获取顺序表中对应的元素，赋值给e
    int j;
    for(j=location;j<T.length;j++){
        T.date[j-1]=T.date[j];
    }
    T.length--;
    return true;
}

int LocateElem(SqTable T,ElementType e){
    int i;
    for (i = 0; i < T.length; i++) {
        if (e == T.date[i]){
            return i+1;
        }
    }
    return 0;
}

int main(){
    SqTable T;//给顺序表取名
    bool ret;//用来装函数的返回值，布尔型是true或者false
    //手动放置元素
    T.date[0]=1;
    T.date[1]=2;
    T.date[2]=3;
    T.length=3;
    printf("----------------insert--------------\n");
    ret=TableInsert(T,1,60);
    if (ret){
        printf("insert SqTable success\n");
        PrintTable(T);
    } else{
        printf("insert SqTable failed\n");
    }
    printf("----------------delete--------------\n");
    ElementType del;
    ret=TableDelete(T,2,del);
    if(ret)
    {
        printf("Delete element success\n");
        printf("Delete element=%d\n",del);
        PrintTable(T);
    } else{
        printf("Delete element failed\n");
    }
    printf("----------------locate--------------\n");

    int location;
    location=LocateElem(T,60);
    if (location)
    {
        printf("find this Element\n");
        printf( "element location=%d",location);
    } else{
        printf("don't find this element\n");
    }

    return 0;
}
//E:\WangDao_C\ClionProject\text10\10.2-sequentail_tabale_delete\cmake-build-debug\10.2-sequentail_tabale_delete.exe
//----------------insert--------------
//insert SqTable success
// 60  1  2  3
//----------------delete--------------
//Delete element success
//Delete element=1
// 60  2  3
//----------------locate--------------
//find this Element
//element location=1
//进程已结束,退出代码0
