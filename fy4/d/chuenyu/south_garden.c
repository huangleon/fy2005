
inherit ROOM;

void create()
{
        set("short", "�ϻ�԰");
        set("long", @LONG
��վ�ں��ɳǱ����ϻ�԰���԰�ﳤ���˸�ʽ�����滨��ݡ�������������
ΰ�ĺ��ɸ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"east_blackge",
]));
                set("objects", ([
                __DIR__"npc/smallgardener" : 2,
        ]) );

	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",20);
	setup();
}

