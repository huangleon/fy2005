inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"����¥"NOR);
        set("long", @LONG
�������ȣ��߹�����������һ�����µ�С¥��������Ѫū��ס����¥���¹���
ʮ�߰˸�������ֻ������û���������ﱾ�����Ķ���Щʲô���ǲ������ģ���
�����ˣ������أ���Щ����Ҳ��ֻ�����˲��ܻش�¥���Ǹ�������һ�������ϵ�
���������̣�����������һ����ֵ������ζ����
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"corridor5",
		"up": __DIR__"birdhouse2",
	]));
	set("item_desc", ([
	        
	]));
	set("coor/x",-70);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
