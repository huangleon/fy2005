// Room: /d/oldpine/keep3.c

inherit ROOM;

void create()
{
        set("short", "����կ����");
        set("long", @LONG
�����������կ�Ĵ����ˣ������ߵĵ���������һ�ž޴����Ƥ�����������
�����ӣ���������ɢ��������ȡů�õĻ��裬������������ľ���ӣ��Ƚ����ص���
�������һ����ӣ����������ͷ�ǣ�����һ�ַ��Ŷ���Ļ�ˮ֮�С�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "west" : __DIR__"keep2",
                "south" : __DIR__"keep4",
        ]));
        set("objects", ([
                __DIR__"npc/bandit_leader": 3,
                __DIR__"npc/bandit_commander":1,
                __DIR__"npc/bandit_guard" : 3,
        ]) );

        set("coor/x",60);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
