inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ͷ�");
        set("long", @LONG
�ͷ�����������ȴ���õĺ����ʣ����еĶ������������ֿɼ��ĵط����ߵ���
�ڿ����������һ���޼ʵ���������ľ�Ĵ󴲣������и���ͭС�壬�����ǰ���
������ҹ��ֻҪ����һ���壬��ҵ��������̾ͻ�������ӷԸ���
LONG
        );
        set("exits", ([ 
	"south": __DIR__"corridor",
	]));
        set("objects", ([
        	__DIR__"npc/spider":	1,
	]) );
        set("coor/x",0);
        set("coor/y",105);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
