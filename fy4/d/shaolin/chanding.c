// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������ҵ����Ȼ��ͬ����һ˿����������ɮ������ϥ���У������Ϊ��������
����Ϊ����ѧһ����;ͬ�飬�����ڹ��������ɷ𷨶���������������������ڹ���
�����°빦����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"jialan",
]));
        set("objects", ([
                __DIR__"npc/monk20a" : 1,
                __DIR__"npc/monk20" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
