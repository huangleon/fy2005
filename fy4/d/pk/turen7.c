// Room: /d/pk/turen7.c

inherit ROOM;
#include <ansi.h>
#include "turen_room.h"


void create()
{
	set("short", HIR "ɥ����" NOR);
	set("long", @LONG
������ɭ�ֲ������ϵ����ǲ�֫��ʬ���޴����ǰ���ɫ��Ѫ�Ρ�������
������������־��裬��֪��������ͻ�ܳ�һ����Ӱ��
LONG
	);
	set("exits", ([
		"east"  : __DIR__"turen8",
		"southeast" : __DIR__"turen11",
		"north" : __DIR__"turen3",
	]));
set("PK_FREE", 1);
set("no_death_penalty",1);
	setup();
        //replace_program(ROOM);
}
