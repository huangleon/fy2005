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
  "west" : __DIR__"desert0",
  "north" : __DIR__"desert7",
  "south" : __DIR__"desert8",
  "east"  : __DIR__"desert3",
  "down"  : __DIR__"quicksand4",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"npc/snake" : 2,
				__DIR__"npc/black_pearl" :1,
                "/obj/money/silver": 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1040);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


