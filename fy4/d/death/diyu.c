// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ɽ��Ⱥ�����裬�»���ɢ������֮���������ڶ����㲻�ɵ÷���񱼣�
ת���Ѿ����������ţ�һ����ţ�����ʮ�˲������������������֮���ڴ˹�Ѻ��
�̡�
LONG
        );
        set("exits", ([
		"north" : __DIR__"shandao",
		"down" : __DIR__"diaojin",
        ]) );
        set("objects", ([
                __DIR__"npc/ghost" : 5,
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
