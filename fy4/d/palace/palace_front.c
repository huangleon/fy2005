
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ž�����ֻ��һ�����ϵ�����ǰ����ǰһ��������ʯ�������������ޣ�����
��֣��ݺṰ��������̦޺�߲����ּ�������ӳ������΢¶��С����
LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"palace_gate",
  		"northup" : __DIR__"palace_palace",
]));
        set("outdoors", "palace");

	set("coor/x",-120);
	set("coor/y",120);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

