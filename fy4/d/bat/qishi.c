inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴���Ϊ�տ����ıڿ���һ��������һ��ʯƺ��ƺ����һ�Ŵ���ʯ�̾͵�
���̣��̱߸���һ������С�У�������װ���ӵġ�ʯƺ���Ҹ���һ����档
LONG
	);
	set("exits", ([
		"east" : __DIR__"shushi",
            "west" : __DIR__"qinshi",
	]));

	set("objects", ([
        __DIR__"npc/tong2": 1,
    ]));

	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

