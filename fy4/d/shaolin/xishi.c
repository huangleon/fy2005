// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
ʼ�����ξ���䣬����˷�ء�������Ϊ���Ĵ��Ŷ����϶�ѩӵ���ϥ��
��ڸ߷壬��ҹ�����ӽ��ϡ����������������֡���һ���������ǡ�˫˫�񾮣�
�̳����ǧ���£��������壬���ʹ��������ơ�
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"ent3",
]));
        set("objects", ([
                __DIR__"obj/west_shi" : 1,
                __DIR__"npc/monk3" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}
