inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
̫�����ڽ��ϣ�·�����Ž�⡣����ͨ��С������ģ������ǵ��̣��Ƽҡ��ֵ�
�����ǳ´��ĵĳ��ׯ�������м������ӣ�����������д�š���ˮ����ϸ�У�������
�롱������С���Ϻ��ټ����ϵ��εĵ���֮һ��
LONG
        );
        set("exits", ([ 
	"east" : __DIR__"road2",
	"west" : __DIR__"road4",
	"north": __DIR__"silkshop",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-20);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
