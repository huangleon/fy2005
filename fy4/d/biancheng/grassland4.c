inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ݳ�");
        set("long", @LONG
ĺ�����£��򻶲ݳ��������������÷����Ĳݳ���ǡ��һ����ɫ�������Ƕ��
�ޱ��޼ʵĻ�ԭ֮�С����ԭ�ϣ���������һƬ���裬����Բԣ�Ұãã���紵��
�ͼ�ţ�򡣡�û��ţ��ֻ������Ⱥ�������±��ۣ���ؼ�����������Ļ�����
�ݳ���������һ������̨�����������ϡ�
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"grassland5",
		"south": 	__DIR__"sentry",
		"west":		__DIR__"grassland3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",110);
        set("coor/y",80);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
