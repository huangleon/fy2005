// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
��ɽ����ȥ������ϡ�Ŀ����������������̡�ɽ·������ת�˸��䣬����
�����ȥ���������ߣ���һ����������ֹ���������ţ�����������ͱ�֮�ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"foot_b_mtn2",
  "east" : __DIR__"rope_bridge",
]));

	set("objects", ([
                __DIR__"npc/jiading2" : 2,
		"/obj/npc/trashcan" :1,
	]) );

        set("outdoors", "chuenyu");

	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
