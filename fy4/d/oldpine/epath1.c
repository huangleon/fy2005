// Room: /d/oldpine/epath1.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���������е�С·����������������϶�����һЩ��ֵļǺţ�
���Ǳ����õ��ӻ�����С·��������һ��յأ�������Զ���Կ���һ��ɽ��������
�����һ��Сʯ�š�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"clearing",
  "east" : __DIR__"epath2",
]));
        set("outdoors", "oldpine");

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
