inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
̫�����ڽ��ϣ�·�����Ž�⡣����ͨ��С������ģ������ǵ��̣��Ƽҡ�С
��ľ��񲢲��ÿͣ��������к���ͽ䱸���۹���͵͵������·����İ���ˣ�����
�۹����������յĽ��������ˣ����޷����ܡ��ֵ�������һ��С���ݺ�һ�����̡�        
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road3",
		"west" : __DIR__"road5",
		"north": __DIR__"riceshop",
		"south": __DIR__"meatshop",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-30);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
