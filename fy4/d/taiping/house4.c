#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���˾�");
        set("long", @LONG
ǽ��һ�Ź��ż���Ұⵣ�ɽ�ǣ�����ȵ�Ƥë���Ա���һ�Ż��������ɵĳ�����
�����������Զ�����������Ի������Ի���������Ϊ����һ�ְٲ�����ľ�������
��ү�������ģ���������������ȥ����ʦ����ÿ�ζ������Ի�����л����������ֻ
��ɽ��ֻ�����ӣ������ӵ�Ұ�ޡ�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"sroad2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("objects", ([
	        __DIR__"npc/hunter": 1,
	]));
	set("coor/x",-50);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
