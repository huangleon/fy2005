// seaside.c
inherit ROOM;
void create()
{
        set("short", "��լ");
        set("long", @LONG
��Ȼ���濴��ȥ�����ɣ���լ�����Ѿ��Ǻ��ƾ��ˣ�ǽ�϶�һ����һ����ѷ죬
���������ϵ����ƣ���ôҲ�ڲ�ס���µĺۼ����Ҿ���Ȼ�ʵ�һ������Ǵ���ĥ��
������ԭ������ɫ��Ψһ������ֻ���������߿�Ĵ󴲣�������������һ��һ����
���û��ɵ��۹�������㡣
LONG
        );
        set("exits", ([ 
		"down":  __DIR__"house1",
	]));
        set("objects", ([
        	__DIR__"npc/tan2" : 1,
        	__DIR__"npc/tan3" : 1,
        ]) );
        set("item_desc", ([
	
	 ]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
