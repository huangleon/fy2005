#include <ansi.h>
inherit __DIR__"quicksand.c";

void create()
{
	set("short", "��Į��ɳ");
	set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸�������������������ķ�
������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�·�ֻʣ��
��һ���ˡ�����»�����������ɳ�������ı����ĸо���
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"greenland",
  "north" : __DIR__"desert4",
  "south" : __DIR__"desert7",
  "east"  : __DIR__"desert6",
  "down"  : __DIR__"quicksand8",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
		__DIR__"npc/snake" : 2,
        ]) );

	set("outdoors", "quicksand");

	set("coor/x",-1070);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
