// Room: /d/oldpine/npath3.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���ּ��С·�ϣ�С·�����ƺ�ͨ��һ���յأ����ӵ�������
��þ����ĵģ�С·���Ե�����Ҳ�����ߵİ�С���������е�Ӫ�����������ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"clearing",
  "northwest" : __DIR__"npath2",
]));
        set("outdoors", "oldpine");

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
