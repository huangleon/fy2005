// Room: /d/chuenyu/dustyroad.c

inherit ROOM;

void create()
{
        set("short", "���С·");
        set("long", @LONG
ɽ�ڷ��ƳǵĶ�������ʮ��ش���ɽ������һ��С��һ������С·ͨ�����
�ǣ�������С��Ľ��⣬վ�������ƺ�������������С����������������������
һ����������ɽ��������������֣��Ǿ��Ǻ���ɽ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dustyroad0",
  "north" : __DIR__"dustyroad2",
]));
        set("outdoors", "chuenyu");
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) );

	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",-20);
	setup();
}

