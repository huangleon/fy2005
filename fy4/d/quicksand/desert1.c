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
		  "west" : __DIR__"desert5",
		  "north" : __DIR__"desert2",
		  "south" : __DIR__"desert0",
		  "east"  : __DIR__"desert7",
		  "down"  : __DIR__"quicksand1",
	]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
		"/obj/money/silver": 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1050);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        san = present("sand", this_object());
        sna = new(__DIR__"obj/hu-blade");
        sna->move(san);
        sna = present("silver", this_object());
        sna->move(san);



}