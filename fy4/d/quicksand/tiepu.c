// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
һ�������ںڵ�С�꣬һ�߶�ߵ��ż��ƺ��Ѿ��������ǲ�ƽ�ˡ��ſ�����һ
�����ƣ�����д�ţ�
	�� �� �� �̣� ר�������������飬����ԭ��
LONG
        );
        set("exits", ([ 
  		"northeast" : __DIR__"dengfeng",
	]));
        set("objects", ([
                __DIR__"npc/tie_waiter" : 1,
        ]) );
	set("coor/x",-610);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
