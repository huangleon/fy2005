inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
�������ͨ����������������������Ⱥɽ���壬����ǧ��������һ�ߣ���·
���򳦡�������������Σ�ҹ�ʯ����������Ǽ䣬����·Ҳ����ն���������·
����վ�Ÿ�ҹ���ĺ��´󺺡�
LONG);

         set("exits", ([ 
		"west" : __DIR__"grassland4",
		"east" : __DIR__"grassland3",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
        	__DIR__"npc/weitianpeng" : 1,
        ]) ); 
	set("coor/x",55);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
