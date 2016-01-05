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
  "west" : __DIR__"desert6",
  "north" : AREA_GUANYIN"entrance",
  "south" : __DIR__"desert1",
  "east"  : __DIR__"desert8",
  "down"  : __DIR__"quicksand2",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"obj/hu-blade" : 1,
                 __DIR__"obj/skeleton" : 1,
                "/obj/money/silver": 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1080);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        san = present("sand", this_object());
        sna = present("hu-blade", this_object());
        sna->move(san);
        sna = present("skeleton", this_object());
        sna->move(san);
        sna = present("silver", this_object());
        sna->move(san);

}

