inherit ROOM;
#include <ansi.h>


void create()

{
        set("short", "������");
        set("long", @LONG
��û����Ѿ��а˰����ˣ�ÿ���������ʱ�򣬾ͻ����������ܵؿ�Щ����ɫ
��С�������������ó����ġ�������ģ�������Ʈ���ʱ�������µĺ�������
Ц�ţ������ţ���������������ժ������
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"road1e",
	]));
        set("objects", ([
		__DIR__"npc/bird": 	1,
	]) );
	set("outdoors", "eren");
        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",20);
	set("map","eren");
	setup();
}
