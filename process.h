/*
*作者:盛旭辉
*编写日期:2014.6.24
*描述：进程管理类的头文件
*功能：1.
*      2.
*
*/
#include<string>
using namespace std;




/*
 *pcb结构
 */
typedef struct pcb
{
	int pId;//TODO  各个算法有需要的自己往上加
	int priority;//进程优先级，优先级调度需要用
}
PCB;

/*
 *队列结构
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
	QUE waiting;//等待队列
	QUE ready;//就绪队列
	int procNum;//处理器数量
public :
	controller()
	{

	}
}