#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���˾�");
        set("long", @LONG
�ſ�ɹ��һ�����������µ��ż������㡣��������·�Ǹ����ˣ���������㣬
����ɹ������仰����������ʱ��ȷ�в�����Ȼ������·�ı��¾��ǣ�ÿ��������
�������ض��飬����Χ���ھ��ۺ첻�ѡ�̫ƽ����Χ������أ�������·�Ļ�˵��
ÿ��һ����͵�����һ����ݲ��С�
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"mroad6",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("objects", ([
	        __DIR__"npc/fishman": 1,
	]));
	set("coor/x",-30);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
