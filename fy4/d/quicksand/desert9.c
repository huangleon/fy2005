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
  "west" : __DIR__"desert10",
  "north" : __DIR__"desert1",
  "south" : AREA_CHENXIANG"roadp",
  "east"  : __DIR__"greenland",
  "down"  : __DIR__"quicksand9",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
		__DIR__"obj/teablock" : 1,
		__DIR__"obj/skeleton" : 1,
		__DIR__"obj/perfume" : 1,
        ]) );

	set("outdoors", "quicksand");

	set("coor/x",-1090);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	san = present("sand", this_object());
        sna = present("teablock", this_object());
        sna->move(san);
        sna = present("perfume", this_object());
        sna->move(san);
       sna = present("skeleton", this_object());
        sna->move(san);


	
}

