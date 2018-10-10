/* algo4-1.c ʵ���㷨4.6��4.7�ĳ��� */
#include "../ch1/c1.h"
#include "c4-1.h"
#include "bo4-1.c"

void get_next(SString T, int next[]) { /* ��ģʽ��T��next����ֵ����������next �㷨 4.7 */
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0])
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else
            j = next[j];
}

int Index_KMP(SString S, SString T, int pos, int next[]) { /* ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨�� */
    /* ����,T�ǿ�,1��pos��StrLength(S)���㷨 4.6 */
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

//KMPģʽƥ��
void main() {
    int i, j, *p;
    SString s1, s2; /* �Խ̿�����ͼ4.5Ϊ�� */
    StrAssign(s1, "acabaabaabcacaabc");
    printf("����Ϊ: ");
    StrPrint(s1);
    StrAssign(s2, "abaabcac");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s2);
    i = StrLength(s2);
    p = (int *) malloc((i + 1) * sizeof(int)); /* ����s2��next���� */
    get_next(s2, p);
    printf("�Ӵ���next����Ϊ: ");
    for (j = 1; j <= i; j++)
        printf("%d ", *(p + j));
    printf("\n");
    i = Index_KMP(s1, s2, 1, p);
    if (i)
        printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n", i);
    else
        printf("�������Ӵ�ƥ�䲻�ɹ�\n");
}