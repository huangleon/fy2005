inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "÷����");
        set("long", @LONG
�����һƬ��ɭ��ڣ����������Ҳ�������о����ˡ���������ѳ�����ͭ
�̣��ʹ�����᣺�����ü��Ŀ�ķ��񣬿���Ҳ�����˳��֮�⡣����Ϊ������
�������������������Ϊ������Ĳп�������
LONG
        );
        set("exits", ([ 
		"south": __DIR__"meihuaan2",
	]));
        set("objects", ([
		__DIR__"npc/liaoyin" : 1,
	]) );
	set("coor/x",-10);
        set("coor/y",25);
        set("coor/z",80);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
