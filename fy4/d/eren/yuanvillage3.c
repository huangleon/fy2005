inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����ɽׯƫ��");
        set("long", @LONG
ƫ�������һ�ٶ�ʮ�Ű�������ÿ�����Զ������˿��ˣ�ֻ�ǣ�ÿ�����˶�����
�������ŵ�����������ӡ��ƺ�������ʲô����֮�¡�������ͷ���ĸ��ˣ�����
������裬�ں��Աߵ�Ů������˽�
LONG       );
        set("exits", ([ 
		"west": __DIR__"yuanvillage2",
	]));
        set("objects", ([
			__DIR__"npc/guest1":	2,
			__DIR__"npc/guest2":	2,
	]) );
	set("coor/x",-45);
        set("coor/y",30);
        set("coor/z",10);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
