inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�����");
        set("long", @LONG
������ڶ���ɽ�£����Ǹ���վ������ջ�԰ֻ���߰�ʮ��·���Դ����ĵ���
��վ�����ã���ط����ս������������۶�����ĵط�������ס�ġ�������ط�ֻ
ʣ��ʮ���߻��˼ң������и������е��ˣ���ס��������վ�Ĺ����
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"wild1",
		"east":		__DIR__"mgarden",
	]));
        set("objects", ([
        	__DIR__"npc/mayueyun":	1,
        	__DIR__"npc/ma1":	1,
        	__DIR__"npc/ma2":	1,
	]) );
	
        set("coor/x",-1300);
        set("coor/y",680);
        set("coor/z",0);
        set("ma_room1",1);
	set("map","zbeast");
	setup();
}
