inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ��һ���ֿ���������������Ǿ��ǣ��󣢣���������������ǧ�ˣ����Ҳ���
�Ե�ӵ�������ֱ���һ������¥��ͨ���¥��������Χ�������˶�ߵĴ��š�
LONG
	);
     set("exits", ([
		"east" : __DIR__"zoulang2",
        "north" : __DIR__"d1",
        "up"    : __DIR__"qinshi",
        "west"  : __DIR__"room7",

    ]));
	
	set("objects", ([
		__DIR__"npc/zhao": 1,
	]));

	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
}
