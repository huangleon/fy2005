#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "ç��֮��");
        set("long", @LONG
���ܹ������죬�����ܲ���Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ�����ҹ��
��������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������Х�Ǻ������ȷ�
Ʈ�����ʡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"east" : __DIR__"dummy2",
  			"west" : __DIR__"dummy2",
  			"south" : __DIR__"center2",
  			"down":  __DIR__"hole",

]));
        set("outdoors", "manglin");
	set("coor/x",60);
	set("coor/y",-50);
	set("coor/z",20);
	setup();

}
