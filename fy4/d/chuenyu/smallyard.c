
inherit ROOM;

void create()
{
        set("short", "���̵�С��ƺ");
        set("long", @LONG
С��ƺ�޼��ĺ����룬��ֵ���������̵Ĳ�������ȿֺ��������棬�߽��ˣ�
�˱ǵı��������֨֨���Ƴ���ǵĻ�����������Ǹ���С���������ã�Ҳ�Ǹ���
��������ϲ����Ϸˣ֮�ء�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"home",
  "south" : __DIR__"dustyroad3",
]));
        set("objects", ([
                __DIR__"npc/frog" : 2,
		__DIR__"npc/ant"  : 2,
		__DIR__"npc/fly"  : 2,
        ]) );
        set("outdoors", "chuenyu");
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",-20);
	setup();
}

