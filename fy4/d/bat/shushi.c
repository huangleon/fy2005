inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ��˷����پ���ǰһ�����ıڽ�������������ǽ�Ϲ���һ���Ƴ�����ġ���
�����������ϵĲ���󿪴��أ�����һλ���ָ���չ���Ṧ���ܸ߷��ͣ���Ȼ�ж�
Ѹ�ݣ�ȴ��ʧ���ŵķ��¡�
LONG
	);
	set("exits", ([
		"east" : __DIR__"huashi",
        "west" : __DIR__"qishi",
	]));

	set("objects", ([
        __DIR__"npc/tong3": 1,
    ]));

	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

