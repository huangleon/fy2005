// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�����˾�");
        set("long", @LONG
����ǰ�η�����λ���ס����������ķ��ɶ������������������裬��ѧ��
Ϊ�ض��ϲ�����ѧ�����ˣ���ϧ�మ��������ɽˮ֮�֣���˵ֻ��ÿ�������ڼ䣬
�ؾ���˵��֮��Ż�������ס��һ��ʱ�䡣
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"fang",
]));
        set("objects", ([
                __DIR__"npc/master_15" : 1,
		__DIR__"npc/master_16" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
