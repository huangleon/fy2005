// Room: /d/chuenyu/rope_bridge.c

inherit ROOM;

void create()
{
// this place can check on player's dodge, if toolow, drop them!
        set("short", "������");
        set("long", @LONG
ɽ��ǿ���ķ紵�����������һζ������µ�������Ԩʹ��ͷ��Ŀ������߾�ȫ
����ά������ƽ�⡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"high_b_mtn",
  "east" : __DIR__"high_b_mtn2",
]));
        set("objects", ([
                __DIR__"npc/jiading3" : 2,
        ]) );


        set("outdoors", "chuenyu");

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
