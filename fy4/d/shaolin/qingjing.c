// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�徲¥");
        set("long", @LONG
һ����¥���͵͵ģ��Ҷ��ϵ����������֡��徲����¥��һ�ź�ľ������Ͳ��
ϡ��Ĳ��ż�ֻ�Ǻ���һֻ��ƿ�������µĲ��ż����ʻ����������⣬���ޱ��
��ǽ��һ�������

			[37m�ͽ̾���[32m

LONG
        );
        set("exits", ([ 
  			"south" : __DIR__"diyuan",
		]));
        set("objects", ([
                __DIR__"npc/girlfi" : 1,
       ]) );
		set("coor/x",-20);
		set("coor/y",130);
		set("coor/z",20);
		setup();
        replace_program(ROOM);
}
