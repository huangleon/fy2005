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
  "west" : __DIR__"desert8",
  "north" : __DIR__"desert3",
  "south" : __DIR__"desert5",
  "east"  : __DIR__"desert2",
  "down"  : __DIR__"quicksand6",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"obj/hu-blade" : 1,
                 __DIR__"obj/skeleton" : 1,
		__DIR__"npc/snake" : 2,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1060);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        san = present("sand", this_object());
        sna = present("hu-blade", this_object());
        sna->move(san);

}

