// Room: /d/oldpine/npath2.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���ּ��С·�ϣ�С·���Գ����˸��ʵ����������ּ䴫����
���������С·���ϱ��������������ȥ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"npath3",
  "north" : __DIR__"npath1",
]));
        set("outdoors", "oldpine");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
