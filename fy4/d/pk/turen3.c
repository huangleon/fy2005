// Room: /d/pk/turen3.c

inherit ROOM;
#include <ansi.h>
#include "turen_room.h"


void create()
{
	set("short", HIR "���˳�" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"east"  : __DIR__"turen4",
		"south"  : __DIR__"turen7",
		"northeast" : __DIR__"turen1",
	]));
set("PK_FREE", 1);
set("no_death_penalty",1);
	setup();
     //   replace_program(ROOM);
}
