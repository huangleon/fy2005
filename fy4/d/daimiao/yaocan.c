/*
** ��ӡ���(��)��
���������·����ĹŰ�����˵�Ǻ��أ�����ͦ�Σ�֦��Ҷï��
�������������֦�Ľ��Ӵ�֮�ϳ���һ�����ص�������
Խ��Խ��һֻ��Ƥ�ĺ����ں�ͷ���Եص���������
��ǰ������һ����Բ�Ʒ���ӡ�ƣ����������˾�֮һ�Ĺ�ӡ���(��)��
** ��������
�ڸ��ϳصĶ����йŰأ��������ٽ���һ����״����������һֻ˫Ŀ���ӵ��������룬
���Ϸ�����һ��Բ�����̣���Ȼ���������һ������˾�֮һ-�������¡�
** ��������
��֮����·������һ������ĹŰأ�������������˳ʱ�뷽��šŤ�������ϣ�����������
�ʸ�ϸ�壬��Ϊ���ء���˵����һλ�Ŵ��ҳ��Ļ���������ͬ���Ӽ�̩ɽʱ�����ڲ����޴�ĺ��ʶ����ݽ��ɣ�
��ŭ�����ӣ�����Ⱥ����������������һ�������������Ĺ�ֱ�������ܲ�л����ر�ն�ף�
���Ļ��Ǿ�����·����̩ɽ����ԩ��״������Ϊ����˾�֮һ---����������
** �°�����
����14�״���������һ�ùŰض������£���˵���ƴ��ҳ�����صĻ�����
�ݴ�����صĻ�������̩ɽ��ǰ������������֮״����Ϊ�˰أ����������Ұء�����Ϊ����˾�֮һ----�°����ҡ�
** �ɺ�չ��
�ڹ��Ұ������������һ�ùŰأ�����һ��֦�򱱣�����չ�����ɵ��ɺף���������˾�֮һ----�ɺ�չ�ᡣ
** �����躮
�Ű�֦��Ť�����ʣ�������������Ȼ�����Ŀݣ�ȴ�ּ�����֦���ԹŴ��������ƾ��档
����Ϊ̩���˾�֮һ�������躮����Ҳ����Ϊ����˾�֮һ��
** �ƻ�����
�ƻ�ԭ���ߴ�ïʢ������Ķ��������˥�ݣ�����ǰ�ڱ��������д��۶�����1952���ڿݻ���ֲһС�����׳ơ��ƻ����ӡ���
����Ϊ����˾�֮һ�������»��ѷ�����ï����ǰ��˫����һ��������������һ���顰�ƻ������ֱ���
��һ��Ϊ�念������������⡶�ƻ�ʫ������������ɽ����������ϼΪ�������ࡣ˭��������ҹ��һ�λ��������㡣��
** ������̨
�ں�԰����ǽ�£�Ҳ��һ�ùŰأ��Դ�������ϣ���ӵ��ï�ܵ�֦Ҷ������һ�����ƶ䣬
���Ա���Ϊ��������̨��������Ϊ����˾�֮һ��

*/


#include <room.h>
inherit ROOM;

string *scene = ({"��ӡ���","��������","��������","�°�����","�ɺ�չ��","�����躮","�ƻ�����","������̨" });
string *scene_des = ({
"һ�ò���ͦ�Σ�֦��Ҷï�ĺ��أ��������������֦�Ľ��Ӵ�֮�ϳ���һ��
���ص�������Խ��Խ��һֻ��Ƥ�ĺ����ں�ͷ���Եص�����������ǰ������
һ����Բ�Ʒ���ӡ�ơ�\n",
"һ�ùŰ��������ٽ���һ����״����������һֻ˫Ŀ���ӵ��������룬����
������һ��Բ�����̡�\n",
"һ������ĹŰأ�������������˳ʱ�뷽��šŤ�������ϣ������������ʸ�
ϸ�壬��Ϊ���ء�\n",
"һ�ùŰض������£���˵���ƴ��ҳ�����صĻ������ݴ�����صĻ�������
̩ɽ��ǰ������������֮״����Ϊ�˰أ����������Ұء���\n",
"������һ�ùŰأ�����һ��֦�򱱣�����չ�����ɵ��ɺס�	\n",
"һ�ùŰ�֦��Ť�����ʣ�������������Ȼ�����Ŀݣ�ȴ�ּ�����֦���Թ�
���������ƾ��档\n",
"һ���ƻ����ߴ�ïʢ������Ķ����������һС����������ï����ǰ�б�����
�⡰������ɽ����������ϼΪ�������ࡣ˭��������ҹ��һ�λ��������㡣��\n",
"һ�ùŰأ��Դ�������ϣ���ӵ��ï�ܵ�֦Ҷ������һ�����ƶ䡣\n",
});

void create()
{
  set("short","ң��ͤ");
  set("long",@LONG
ң��ͤ�������ǰͥ���ŵ�������������ڣ��������˽��м򵥵Ĳΰݣ�Ȼ��
ѡ��������������������ͤǰ��ʯ�����������Ǭ¡��ʮ���꣬�������䣬Ϊ
������ʽ�Ʒ������˶����š������ʯ�ޣ����顰ң��ͤ��������������ʨ���У�
��˸������Ӵ��򱱱��ң��̩ɽ����˴�ͤ�ֳ�ң��ͤ��
LONG
  );
  	set("exits",([
         	"north":__DIR__"daimiao",
         	"south":__DIR__"shuanglong",
         	"east": __DIR__"e_peidian",
//         	"west": __DIR__"w_peidian",
               ]));
        set("objects", ([
        	__DIR__"npc/guard1":	2,
        
       	]) );
        set("item_desc", ([
        ]) );
	set("NONPC",1);
	set("coor/x",0);
	set("coor/y",-65);
	set("coor/z",0);
	setup();
  
}

