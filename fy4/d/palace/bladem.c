
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
ֻ����������������ʯ��ʯ�������Ŀ������ҧ���г�̬֮�����������Щ
������Ȼ���˵�ɽ������ȴ��Ȼ˿����֪���򣬶�ֻ�л��ޣ����潫��֮���ĳ���
�̻�����ľ���֡�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"holeopen",
  "east" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"npc/laoren" : 1,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",10);
	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

