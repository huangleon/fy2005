inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�Ϲ�Ǯׯ");
        set("long", @LONG
��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����˼�Ǯׯ���Һ��֣������Ϲ���ҵ
֮һ���Ϲ�Ǯׯ����Ʊ�������ã����ϱ����ɶ��֡�Ǯׯ������һ��ľ��̨����
�˶�ߣ������ƣ�����һ�顣
LONG
        );
        set("item_desc", ([
                "sign": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�

convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��
transfer    ֱ��ת�ʡ�

TEXT
        ]) );


        set("objects", ([
                __DIR__"npc/bankowner" : 1,
        ]) );
        
        set("exits", ([ 
		"north" : __DIR__"vroad3",
	]));

	set("coor/x",70);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();

}
