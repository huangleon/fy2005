#include <ansi.h>
#include <room.h>

inherit ROOM;

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
  "west" : __DIR__"mfoot",
  "east"  : __DIR__"desert9",
]));
        set("item_desc", ([
  "sand" : "������������ɳ����һͷ���˶��ɵľ��ޣ�����������¡�\n",
  "��ɳ" : "������������ɳ����һͷ���˶��ɵľ��ޣ�����������¡�\n",
]));

	set("outdoors", "quicksand");

	set("coor/x",-1100);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
