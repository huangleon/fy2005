inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ͷ�");
        set("long", @LONG
�ϲ��Ŀ��˺ܶ࣬������ǿ���ס������֮һ���ϲ��Ӳ��д����ã�Ҳ������
����ŵ��ֻҪ����Ӧ���㣬�������㶼���Է���һ�ߣ���Ϊ����������ʧ������
���ظ����κα��������ڲ��������������ѡ��������ô�¿������������Ὣ���
����������ϣ���취Ϊ������
LONG
        );
        set("exits", ([ 
		"south" :   	__DIR__"garden2",

	]));
        set("objects", ([
        	__DIR__"npc/lumantian":		1,
	]) );
        set("coor/x",-1320);
        set("coor/y",980);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}
