// Room: /d/pk/turen9.c

inherit ROOM;
#include <ansi.h>
#include "turen_room.h"

void create()
{
	set("short", HIR "������" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"east"  : __DIR__"turen10",
		"south" : __DIR__"turen12",
		"west"  : __DIR__"turen8",
		"north" : __DIR__"turen5",
	]));
set("PK_FREE", 1);
set("no_death_penalty",1);
	setup();
        //replace_program(ROOM);
}
