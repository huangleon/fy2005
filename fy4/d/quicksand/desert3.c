#include <ansi.h>
inherit __DIR__"quicksand.c";

void create()
{
	object san, sna;
	set("short", "��Į��ɳ");
	set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸�������������������ķ�
������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�·�ֻʣ��
��һ���ˡ�����»�����������ɳ�������ı����ĸо���
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"desert4",
  "north" : __DIR__"desert5",
  "south" : __DIR__"desert6",
  "east"  : __DIR__"desert0",
  "down"  : __DIR__"quicksand3",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"npc/snake" : 2,
                "/obj/money/coin": 1,
                "/obj/money/silver": 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1030);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        	san = present("sand", this_object());
        	sna = new(__DIR__"npc/obj/jade1");
        	sna->move(san);
        	sna = present("coin", this_object());
        	sna->move(san);
        	sna = present("silver", this_object());
        	sna->move(san);
}
