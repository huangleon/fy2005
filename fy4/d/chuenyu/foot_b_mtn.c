// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
��˳��ɽ·���š�С·���Ŷ��߲��ϵ���չ��Խ��Խ����С·�������������
�������������������û�С�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"base_b_mtn",
  "east" : __DIR__"foot_b_mtn2",
]));

	set("objects", ([
                __DIR__"npc/jiading" : 2,
	]) );

        set("outdoors", "chuenyu");

	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}
