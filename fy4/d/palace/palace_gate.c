
inherit ROOM;

void create()
{
        set("short", "�ճ�԰");
        set("long", @LONG
�����ȵ���һ����һ�����ŵĻ�԰�����ţ�ֻ��������䣬����Ͳ����������
�������������ϸ�������������Ϳ�Σ�һɫˮĥȺǽ����ʯ̨�ף����������
����������ѩ�׷�ǽ�����滢Ƥʯ��������
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"palace_front",
  		"southeast" : __DIR__"entrance",
]));
        set("outdoors", "palace");

	set("coor/x",-120);
	set("coor/y",110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

