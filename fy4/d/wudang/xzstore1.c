
inherit ROOM;

void create()
{
	set("short", "ũ�ߵ�");
	set("long", @LONG
СС��һ��ũ�ߵ꣬���������ʽ������ũ�ߡ�����ǽ�Ϲ��������������ұ�
ǽ�Ƿ������Ѷ��١��м�һ�����¯��¯��������һλ�ձ���������¯������ĳ�
��
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"xzroad2",
	]));
        set("objects", ([
                __DIR__"npc/seller1" : 1,
        ]) );
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",-50);
	setup();
replace_program(ROOM);

}
