inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����С��");
        set("long", @LONG
���������֣����۵��������Ƴγε�С�����Ƶ�������ÿһ�����붼���Զ�
������˸�ź���͸���������ɫ�ʣ�����״����ɫ���ɱ����������ҫ�ñ�ĸ��Ѥ
�á���ɼͦ���ţ�֦Ȩ�������������һ���γ���һ�º���ǽ�ڣ�����һ֧��
��һ�µľ��ӡ�
LONG
        );
        set("exits", ([ 
		"eastup" : __DIR__"road1b",
		"west": __DIR__"road1d",
	]));
        set("objects", ([
             	__DIR__"npc/xuedahan":	1,   	
	]) );
	set("outdoors", "eren");
        set("coor/x",-30);
        set("coor/y",10);
        set("coor/z",10);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
