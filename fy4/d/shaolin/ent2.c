// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��ʯ�׵���һ����̧ͷ�������Ѿ��ɿ��������޴��ʯ����·���������ɽ��
ҲԽ��Խ�࣬ԶԶ���Կ�����������ɮ�ˣ�������ο���������һ��������
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"ent3",
  "southdown" : __DIR__"ent",
]));
        set("objects", ([
                __DIR__"npc/xiangke" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-120);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}
