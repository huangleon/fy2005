
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ���̻Ի͵Ĵ��������������������˰������ڴ�����롣����
֮�䣬����һ���ɺ쳤̺����̺��ͷ��ʯ����������һ�ž���������һ�ž��Σ�
���ξ�������񻨣���ҫ���ƽ�ɫ�Ĺ�â��
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

