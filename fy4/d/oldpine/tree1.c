// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ʸ���һ��������������ϣ���������Ժ�������������µ�һ�ж�
�����������˷������ƺ��Ǹ���͵�����������ĺõط���
LONG
        );
        set("objects", ([
                __DIR__"npc/spy":1 ]) );

        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tree2",
  "down" : __DIR__"clearing",
]));

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
