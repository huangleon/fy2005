inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"���ƽ�"NOR);
    set("long", @LONG
�ֵ�����ˮϴ����ô�ĸɾ�������������·������羵��������߷��ߴ��ΰ��
˫�˺ϱ�������ʮ��һ�꣬������������ߡ����������һ����ⱦ����С��С
�ɾ��£����������鱦���ˡ���ֶ���լ����һ��ʽ���Ľ�����լ�����Ÿ߸ߵ�
ʮ�ּܣ�һЩ�𷢱��ۣ��������۵��˲�ʱ�������롣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"swind3",
	"north" : __DIR__"yundoor",
	"east" : __DIR__"church",
	"west" : __DIR__"yuljade",
      ]));
    set("objects", ([
	__DIR__"npc/dtz1" : 2,
//	__DIR__"npc/patrol_soldier": 1,
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-80);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
