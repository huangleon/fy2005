
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ľ");
        set("long", @LONG
����·��������ͻȻ��ʧ�ˡ������ﳤ����һ�ְ��˸ߵı���ɫ��ֲ�����
����������ÿһ�����䣬��Χ���������Χ����ֵ��ǣ���������һ��ļž���
�����κζ�����ټ���
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"keng",
]));
        set("outdoors", "palace");
	set("coor/x",-30);
	set("coor/y",40);
	set("coor/z",10);
	setup();
}
int valid_leave(object me, string dir)
{
	message_vision( HIR "һ�󵭵��ķۺ�����Ʈ����$N���ɵ�������һ������\n\n\n"NOR,me);
	if(!me->query_condition("red_blood"))
		me->apply_condition("red_blood",random(10)+10);

	return 1;
}
