
inherit ROOM;

void create()
{
	set("short", "��̨��");
	set("long", @LONG
��̨���ַ�Ϊ��̨�Ϲۡ��йۺ��¹ۡ��Ϲ۽С������̨�����й۽С�������
̨�����¹۽С�������̨�����ڵ��ز�Զ���ͱ�����һʯ������Ի��̫������
LONG
	);
	set("exits", ([
		"north" : __DIR__"dishuiyan",
		"south" : __DIR__"wall",
	]));
	set("objects", ([
                __DIR__"npc/taoist5" : 1,
                __DIR__"npc/taoist_2" : 1,
        ]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
