
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǰ��Ȼһ�����׳�������յ��˼������������������һ����С��ɽ�ȣ�
ɽ������Ψһ����ڡ��������ﻨ�㣬����������������Դ��ɽ�º͹ȵ��в�����
ᾹŹֵľ�ʯ��ԶԶ��ȥ������һ�������������ɫ�ĺ����ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"grassland1",
  "south" : __DIR__"hole3",
]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
