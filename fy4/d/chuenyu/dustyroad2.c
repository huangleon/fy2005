// Room: /d/chuenyu/dustyroad2.c

inherit ROOM;

void create()
{
        set("short", "����·��");
        set("long", @LONG
����·������ͨ������ɽ���С·������������һ��С�������˼Ҳ��࣬
�󲿷ֿ����ֵ�Ϊ����СС��ס�ң�ס�ҵĺ����Ǹ��ܴ�Ļ�԰����԰���кܶ�С
ͯ����ˣ��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"dustyroad3",
  "south" : __DIR__"dustyroad",
  "north" : __DIR__"sunnyroad",
]));
        set("outdoors", "chuenyu");

	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}

