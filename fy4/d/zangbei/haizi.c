inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����ɽ");
        set("long", @LONG
����ָ���Ǹ�ɽ�ϵĺ����������ԭ��ɽ�Ͼ�Ȼ�м��ٸ�����������ղ�����
���µ����ᣬɢ����������ʯ�䡣��������ǵء�ǧ��ٹ�ȴ������汸����Ȼʯ
��������������˿־壬����������Ӱ���ʫ����ǰ����ʯ�ˣ��󲻼����ߣ�����
��֮���ƣ�����Ȼ�����¡���
LONG
        );
        set("exits", ([ 
		"northdown" : __DIR__"valley2",
		"southeast":  __DIR__"lake1",
		"eastdown":  __DIR__"hanmei",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2060);
        set("coor/y",560);
        set("coor/z",40);
	set("map","zbwest");
	setup();

}
