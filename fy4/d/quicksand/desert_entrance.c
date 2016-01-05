// Room: /d/chuenyu/trap_castle.c
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
  "west" : __DIR__"desert0",
  "east"  : __DIR__"saiwai2",
]));
        set("item_desc", ([
  "sand" : "������������ɳ����һͷ���˶��ɵľ��ޣ�����������¡�\n",
  "��ɳ" : "������������ɳ����һͷ���˶��ɵľ��ޣ�����������¡�\n",
]));

	set("outdoors", "quicksand");

	set("coor/x",-1070);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{	object ob;
	string outexit;
	if( interactive( ob = this_player()))
	{
	if(query("exits/west")) delete("exits/west");
	outexit = __DIR__"desert"+(string) random(5)+ ".c";	
	set("exits/west", outexit);

	}
}

