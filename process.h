/*
*����:ʢ���
*��д����:2014.6.24
*���������̹������ͷ�ļ�
*���ܣ�1.
*      2.
*
*/
#include<string>
using namespace std;




/*
 *pcb�ṹ
 */
typedef struct pcb
{
	int pId;//TODO  �����㷨����Ҫ���Լ����ϼ�
	int priority;//�������ȼ������ȼ�������Ҫ��
}
PCB;

/*
 *���нṹ
 */
typedef struct que
{
	PCB pcb;
	struct que* next;
}QUE;

/*
 *
 */
class controller
{
private :
	QUE waiting;//�ȴ�����
	QUE ready;//��������
	int procNum;//����������
public :
	controller()
	{

	}
}