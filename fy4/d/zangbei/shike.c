inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "һ�������");
        set("long", @LONG
һ�������λ�ں�����һ�����͵�ɽ���ϡ�����ԭ�ǹ�ģ����������Ⱥ��
��񣬾��󲿷��Ѿ�������û�������ֶ��档��һ����������϶����ų�ʮ���У�
���岼���ϼ���������һ���������Σ����һ�񣬴�������������롣
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"songyue",
		"southeast" : __DIR__"qingtongxia",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-550);
        set("coor/y",600);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
