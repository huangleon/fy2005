//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIR"ҡ����"NOR);
    set("long", @LONG
������£�ż���鹬��δ��������׺��ȡ����ױ��Ѱ������еü��������
��������ȡ�������Ц�ң�̸�����ס�ϸ˼�㣬�����޻ܣ�Ω�����ǳ�׶��ѡ���
������飬ռ���˼䣬ǧ�����ġ����Ż�����������磬�̰ѹ����������Թ�
���񣬼��˲��ӣ��ٵõ���˫������������С�δ���ã����Ҷ�Ŷ��ա�Ը���̡�
����ޥ�ԣ���ǰ���£��������⡣Ϊ���ġ������ϲ���ԧ���� 
LONG
    );
    set("exits",
      ([
	"up" : __DIR__"mixian",
	"down" : __DIR__"wangxian",
      ]));
    set("objects",
      ([
	__DIR__"npc/yaoxian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",40);
    setup();
    replace_program(ROOM);
}
