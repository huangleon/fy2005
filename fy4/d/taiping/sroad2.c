#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����һ��ƽ������������ͨ�������ש���ĺ�Ժ��ס������Ĵ����
�ǿ����ճԷ��ģ��п�С�ӻ��̵ģ����ģ������ģ���ľ�ģ�Ҳ�е��ǳ��걼��
���������ԭ�������ˡ�
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"sroad3",
		"west" : __DIR__"sroad1",
		"south": __DIR__"house4",
	]));
        set("outdoors", "taiping");
	set("objects", ([
	        	__DIR__"npc/xiaotong" : 1,
	]) );
	
	set("item_desc", ([
	        
	]));
	set("coor/x",-50);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
