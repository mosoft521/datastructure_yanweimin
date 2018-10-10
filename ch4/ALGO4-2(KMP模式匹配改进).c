/* algo4-2.c ʵ���㷨4.6��4.8�ĳ��� */
#include "c4-1.h"
#include "bo4-1.c"

void get_nextval(SString T, int nextval[]) { /* ��ģʽ��T��next��������ֵ����������nextval���㷨4.8 */
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T[0])
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if (T[i] != T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
}

int Index_KMP(SString S, SString T, int pos, int next[]) { /* ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨�� */
    /* ����,T�ǿ�,1��pos��StrLength(S)���㷨 4.6 ͬalgo4-1.c */
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0])
        if (j == 0 || S[i] == T[j]) /* �����ȽϺ���ַ� */
        {
            ++i;
            ++j;
        } else /* ģʽ�������ƶ� */
            j = next[j];
    if (j > T[0]) /* ƥ��ɹ� */
        return i - T[0];
    else
        return 0;
}

void main() {
    int i, j, *p;
    SString s1, s2; /* �Խ̿����㷨4.8֮�ϵ�����Ϊ�� */
    StrAssign(s1, "aaabaaaab");
    printf("����Ϊ: ");
    StrPrint(s1);
    StrAssign(s2, "aaaab");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s2);
    i = StrLength(s2);
    p = (int *) malloc((i + 1) * sizeof(int)); /* ����s2��next���� */
    get_nextval(s2, p);
    printf("�Ӵ���nextval����Ϊ: ");
    for (j = 1; j <= i; j++)
        printf("%d ", *(p + j));
    printf("\n");
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", Index_KMP(s1, s2, 1, p));
}
