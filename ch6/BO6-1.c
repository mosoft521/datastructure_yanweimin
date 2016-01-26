 /* bo6-1.c ��������˳��洢(�洢�ṹ��c6-1.h����)�Ļ�������(23��) */
 Status InitBiTree(SqBiTree T)
 { /* ����ն�����T����ΪT�ǹ̶����飬����ı䣬�ʲ���Ҫ& */
   int i;
   for(i=0;i<MAX_TREE_SIZE;i++)
     T[i]=Nil; /* ��ֵΪ�� */
   return OK;
 }

 void DestroyBiTree()
 { /* ����SqBiTree�Ƕ�������,�޷����� */
 }

 Status CreateBiTree(SqBiTree T)
 { /* �������������������н���ֵ(�ַ��ͻ�����), ����˳��洢�Ķ�����T */
   int i=0;
 #if CHAR
   int l;
   char s[MAX_TREE_SIZE];
   printf("�밴�����������ֵ(�ַ�)���ո��ʾ�ս�㣬�������%d:\n",MAX_TREE_SIZE);
   gets(s); /* �����ַ��� */
   l=strlen(s); /* ���ַ����ĳ��� */
   for(;i<l;i++) /* ���ַ�����ֵ��T */
   {
     T[i]=s[i];
     if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* �˽��(����)��˫���Ҳ��Ǹ� */
     {
       printf("������˫�׵ķǸ����%c\n",T[i]);
       exit(ERROR);
     }
   }
   for(i=l;i<MAX_TREE_SIZE;i++) /* ���ո�ֵ��T�ĺ���Ľ�� */
     T[i]=Nil;
 #else
   printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n",MAX_TREE_SIZE);
   while(1)
   {
     scanf("%d",&T[i]);
     if(T[i]==999)
       break;
     if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil) /* �˽��(����)��˫���Ҳ��Ǹ� */
     {
       printf("������˫�׵ķǸ����%d\n",T[i]);
       exit(ERROR);
     }
     i++;
   }
   while(i<MAX_TREE_SIZE)
   {
     T[i]=Nil; /* ���ո�ֵ��T�ĺ���Ľ�� */
     i++;
   }
 #endif
   return OK;
 }

 #define ClearBiTree InitBiTree /* ��˳��洢�ṹ�У���������ȫһ�� */

 Status BiTreeEmpty(SqBiTree T)
 { /* ��ʼ����: ������T���� */
   /* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
   if(T[0]==Nil) /* �����Ϊ��,������ */
     return TRUE;
   else
     return FALSE;
 }

 int BiTreeDepth(SqBiTree T)
 { /* ��ʼ����: ������T���ڡ��������: ����T����� */
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* �ҵ����һ����� */
     if(T[i]!=Nil)
       break;
   i++; /* Ϊ�˱��ڼ��� */
   do
     j++;
   while(i>=pow(2,j));
   return j;
 }

 Status Root(SqBiTree T,TElemType *e)
 { /* ��ʼ����: ������T���� */
   /* �������:  ��T����,��e����T�ĸ�,����OK;���򷵻�ERROR,e�޶��� */
   if(BiTreeEmpty(T)) /* T�� */
     return ERROR;
   else
   {
     *e=T[0];
     return OK;
   }
 }

 TElemType Value(SqBiTree T,position e)
 { /* ��ʼ����: ������T����,e��T��ĳ�����(��λ��) */
   /* �������: ���ش���λ��e(��,�������)�Ľ���ֵ */
   return T[(int)pow(2,e.level-1)+e.order-2];
 }

 Status Assign(SqBiTree T,position e,TElemType value)
 { /* ��ʼ����: ������T����,e��T��ĳ�����(��λ��) */
   /* �������: ������λ��e(��,�������)�Ľ�㸳��ֵvalue */
   int i=(int)pow(2,e.level-1)+e.order-2; /* ���㡢�������תΪ�������� */
   if(value!=Nil&&T[(i+1)/2-1]==Nil) /* ��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ�� */
     return ERROR;
   else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  ��˫�׸���ֵ����Ҷ�ӣ����գ� */
     return ERROR;
   T[i]=value;
   return OK;
 }

 TElemType Parent(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ��e��T�ķǸ����,�򷵻�����˫��,���򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* �ҵ�e */
       return T[(i+1)/2-1];
   return Nil; /* û�ҵ�e */
 }

 TElemType LeftChild(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ӡ���e������,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=0;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* �ҵ�e */
       return T[i*2+1];
   return Nil; /* û�ҵ�e */
 }

 TElemType RightChild(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e���Һ��ӡ���e���Һ���,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=0;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* �ҵ�e */
       return T[i*2+2];
   return Nil; /* û�ҵ�e */
 }

 TElemType LeftSibling(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ֵܡ���e��T�����ӻ������ֵ�,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2==0) /* �ҵ�e�������Ϊż��(���Һ���) */
       return T[i-1];
   return Nil; /* û�ҵ�e */
 }

 TElemType RightSibling(SqBiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ֵܡ���e��T���Һ��ӻ������ֵ�,�򷵻أ��գ� */
   int i;
   if(T[0]==Nil) /* ���� */
     return Nil;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2) /* �ҵ�e�������Ϊ����(������) */
       return T[i+1];
   return Nil; /* û�ҵ�e */
 }

 void Move(SqBiTree q,int j,SqBiTree T,int i) /* InsertChild()�õ����� */
 { /* �Ѵ�q��j��㿪ʼ��������Ϊ��T��i��㿪ʼ������ */
   if(q[2*j+1]!=Nil) /* q������������ */
     Move(q,(2*j+1),T,(2*i+1)); /* ��q��j������������ΪT��i���������� */
   if(q[2*j+2]!=Nil) /* q������������ */
     Move(q,(2*j+2),T,(2*i+2)); /* ��q��j������������ΪT��i���������� */
   T[i]=q[j]; /* ��q��j�����ΪT��i��� */
   q[j]=Nil; /* ��q��j����ÿ� */
 }

 Status InsertChild(SqBiTree T,TElemType p,Status LR,SqBiTree c)
 { /* ��ʼ����: ������T����,p��T��ĳ������ֵ,LRΪ0��1,�ǿն�����c��T */
   /*           ���ཻ��������Ϊ�� */
   /* �������: ����LRΪ0��1,����cΪT��p���������������p����ԭ����� */
   /*           ���������Ϊc�������� */
   int j,k,i=0;
   for(j=0;j<(int)pow(2,BiTreeDepth(T))-1;j++) /* ����p����� */
     if(T[j]==p) /* jΪp����� */
       break;
   k=2*j+1+LR; /* kΪp������Һ��ӵ���� */
   if(T[k]!=Nil) /* pԭ��������Һ��Ӳ��� */
     Move(T,k,T,2*k+2); /* �Ѵ�T��k��㿪ʼ��������Ϊ��k������������ʼ������ */
   Move(c,i,T,k); /* �Ѵ�c��i��㿪ʼ��������Ϊ��T��k��㿪ʼ������ */
   return OK;
 }

 typedef int QElemType; /* �����Ԫ������Ϊ����(���) */
 #include "../ch3/c3-3.h" /* ˳���ѭ������ */
 #include "../ch3/bo3-4.c" /* ˳���ѭ�����еĻ������� */
 Status DeleteChild(SqBiTree T,position p,int LR)
 { /* ��ʼ����: ������T����,pָ��T��ĳ�����,LRΪ1��0 */
   /* �������: ����LRΪ1��0,ɾ��T��p��ָ������������� */
   int i;
   Status k=OK; /* ���в��յı�־ */
   SqQueue q;
   InitQueue(&q); /* ��ʼ�����У����ڴ�Ŵ�ɾ���Ľ�� */
   i=(int)pow(2,p.level-1)+p.order-2; /* ���㡢�������תΪ�������� */
   if(T[i]==Nil) /* �˽��� */
     return ERROR;
   i=i*2+1+LR; /* ��ɾ�������ĸ�����ھ����е���� */
   while(k)
   {
     if(T[2*i+1]!=Nil) /* ���㲻�� */
       EnQueue(&q,2*i+1); /* ����������� */
     if(T[2*i+2]!=Nil) /* �ҽ�㲻�� */
       EnQueue(&q,2*i+2); /* ����ҽ������ */
     T[i]=Nil; /* ɾ���˽�� */
     k=DeQueue(&q,&i); /* ���в��� */
   }
   return OK;
 }

 Status(*VisitFunc)(TElemType); /* �������� */
 void PreTraverse(SqBiTree T,int e)
 { /* PreOrderTraverse()���� */
   VisitFunc(T[e]);
   if(T[2*e+1]!=Nil) /* ���������� */
     PreTraverse(T,2*e+1);
   if(T[2*e+2]!=Nil) /* ���������� */
     PreTraverse(T,2*e+2);
 }

 Status PreOrderTraverse(SqBiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ����: ����������,Visit�ǶԽ�������Ӧ�ú��� */
   /* �������: �������T,��ÿ�������ú���Visitһ���ҽ�һ�Ρ� */
   /*           һ��Visit()ʧ��,�����ʧ�� */
   VisitFunc=Visit;
   if(!BiTreeEmpty(T)) /* ������ */
     PreTraverse(T,0);
   printf("\n");
   return OK;
 }

 void InTraverse(SqBiTree T,int e)
 { /* InOrderTraverse()���� */
   if(T[2*e+1]!=Nil) /* ���������� */
     InTraverse(T,2*e+1);
   VisitFunc(T[e]);
   if(T[2*e+2]!=Nil) /* ���������� */
     InTraverse(T,2*e+2);
 }

 Status InOrderTraverse(SqBiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ����: ����������,Visit�ǶԽ�������Ӧ�ú��� */
   /* �������: �������T,��ÿ�������ú���Visitһ���ҽ�һ�Ρ� */
   /*           һ��Visit()ʧ��,�����ʧ�� */
   VisitFunc=Visit;
   if(!BiTreeEmpty(T)) /* ������ */
     InTraverse(T,0);
   printf("\n");
   return OK;
 }

 void PostTraverse(SqBiTree T,int e)
 { /* PostOrderTraverse()���� */
   if(T[2*e+1]!=Nil) /* ���������� */
     PostTraverse(T,2*e+1);
   if(T[2*e+2]!=Nil) /* ���������� */
     PostTraverse(T,2*e+2);
   VisitFunc(T[e]);
 }

 Status PostOrderTraverse(SqBiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ����: ������T����,Visit�ǶԽ�������Ӧ�ú��� */
   /* �������: �������T,��ÿ�������ú���Visitһ���ҽ�һ�Ρ� */
   /*           һ��Visit()ʧ��,�����ʧ�� */
   VisitFunc=Visit;
   if(!BiTreeEmpty(T)) /* ������ */
     PostTraverse(T,0);
   printf("\n");
   return OK;
 }

 void LevelOrderTraverse(SqBiTree T,Status(*Visit)(TElemType))
 { /* ������������� */
   int i=MAX_TREE_SIZE-1,j;
   while(T[i]==Nil)
     i--; /* �ҵ����һ���ǿս������ */
   for(j=0;j<=i;j++)  /* �Ӹ������,��������������� */
     if(T[j]!=Nil)
       Visit(T[j]); /* ֻ�����ǿյĽ�� */
   printf("\n");
 }

 void Print(SqBiTree T)
 { /* ��㡢������������������ */
   int j,k;
   position p;
   TElemType e;
   for(j=1;j<=BiTreeDepth(T);j++)
   {
     printf("��%d��: ",j);
     for(k=1;k<=pow(2,j-1);k++)
     {
       p.level=j;
       p.order=k;
       e=Value(T,p);
       if(e!=Nil)
         printf("%d:%d ",k,e);
     }
     printf("\n");
   }
 }