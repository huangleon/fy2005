// inn.c

inherit ROOM;


void create()
{
	set("short", "�Ϲ�Ǯׯ");
	set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ֮
һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ�Ҳ����
�����Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
[31m
                	�Ϲ�Ǯׯ
[37m
LONG
	);
	
	set("exits", ([
		"west"    	: __DIR__"swind5",
	]) );
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan	    ��Ǯׯ��Ǯ��
TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/bankowner" : 1,

			]) );


	set("coor/x",10);
	set("coor/y",-50);
  set("coor/z",-300);
	setup();
}
