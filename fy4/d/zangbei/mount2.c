inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ϲ��");
        set("long", @LONG
�ϲ���������£�ɽ�嶸�ͣ���������������Ů��浾���ׯ��������ࡣɽ��
ǰ��Ƕ�ű�������ĺ����Ͳݵ顣Զ��ɽ�����и߸ߵ͵ͼ�����ש���������Ľǵ�
�ס��ơ��졢��������������עĿ�����������������¡�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"nianqing",
		"southdown":  __DIR__"temple2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1700);
        set("coor/y",600);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
