// Room: /d/pk/turen12.c

inherit ROOM;
#include <ansi.h>
#include "turen_room.h"


void create()
{
	set("short", HIR "¾�˳�" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"northeast"  : __DIR__"turen10",
		"west"  : __DIR__"turen11",
		"north" : __DIR__"turen9",
	]));
set("PK_FREE", 1);
set("no_death_penalty",1);
	setup();
    //    replace_program(ROOM);
}
