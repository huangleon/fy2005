// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ���");
        set("long", @LONG
����ʯ����������ͬ����ǧ�˰�̬��ÿ���������������ն�������
ϼ��ȾȺ�壬�����������֣����������Ľ���������޲����óϷ�����̾
����Ȼ֮����֮����
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"sanhua",
]));
        set("objects", ([
        __DIR__"npc/yan" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-110);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
