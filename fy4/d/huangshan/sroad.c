// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������ʯ�ף���;����ï�������һЩ�ߴ����������֦�Ϲ�������ݣ�Խ��
�����������ľ��ĸо�����ǰ����վ���Ȼ��ͬ��ʯ�׾�ͷ��һ��С���ã���ǽ��
�ƣ���ǰ�����纣����̶��������ɫ����������
LONG
        );
	set("exits", ([ 
  		"west" : __DIR__"feicui",
  		"northup" : __DIR__"caishi",
  		"east" : __DIR__"diezhang",
		"south" : __DIR__"songgu",
	]));

    set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-30);
	set("coor/z",30);
	set("objects", ([
	__DIR__"npc/monkey1" : 1,
                        ]) );
	
	setup();
        replace_program(ROOM);
}
