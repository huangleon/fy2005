inherit ROOM;
void create()
{
	set("short", "�Ϲ�Ǯׯ");
	set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ
֮һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡����Ǹ��ɵй��Ľ�Ǯ�Ҳ
���������Ǯׯ������һ��ľ��̨�����˶�ߣ������ƣ�����һ�顣
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

        set("exits", ([ 
  "northeast" : __DIR__"bazha",
  "east" : __DIR__"bazha1",
  "southeast" : __DIR__"bazha3"
]));
        set("objects", ([
        __DIR__"npc/bankowner" : 1,
        __DIR__"npc/swaiter7" : 1,
        __DIR__"npc/swaiter8" : 1,
                        ]) );
        //set("no_pk",1);
        
        
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
