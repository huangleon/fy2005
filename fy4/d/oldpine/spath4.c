// Room: /d/oldpine/spath4.c

inherit ROOM;

void create()
{
        set("short", "���µ�");
        set("long", @LONG
����һ����ֱ���µ��������ϵͣ���·���Գ�������������������ּ���Լ��
���������ߴ�����ˮ���������ߵ������·���Ǿ�ͷ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  			"north" : __DIR__"spath3",
		]));
		set("objects", ([ /* sizeof() == 3 */
//  			__DIR__"npc/tall_bandit" : 1,
  			__DIR__"npc/fat_bandit" : 1,
		]));
        set("outdoors", "oldpine");

		set("coor/x",-20);
		set("coor/y",-10);
		set("coor/z",30);
		setup();
        replace_program(ROOM);
}
