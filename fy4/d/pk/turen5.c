// Room: /d/pk/turen5.c

inherit ROOM;
#include <ansi.h>
#include "turen_room.h"


void create()
{
	set("short", HIR "�Ѫ��" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"east"  : __DIR__"turen6",
		"south" : __DIR__"turen9",
		"west"  : __DIR__"turen4",
		"north" : __DIR__"turen2",
	]));
set("PK_FREE", 1);
set("no_death_penalty",1);
	setup();
       // replace_program(ROOM);
}
