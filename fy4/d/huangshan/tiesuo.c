// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG

�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�

LONG
        );
        set("exits", ([ 
  		"south" : __DIR__"xuanyuan",
  		"north" : __DIR__"huangshan",
	]));
        set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",0);
	set("coor/z",40);
	setup();
}


void init()
{
	object ob;
	if (this_player()->query_kar() < random(30))
	{
		this_player()->move(this_object());
		message_vision("$N����һ�����ȣ���������ֱˤ��ȥ��\n",this_player());
		ob = load_object(__DIR__"kuzhu");
		this_player()->move(ob);
		message("vision", "ֻ����һ���ҽУ�" + this_player()->name() + "��֪��ʲô�ط����ص�ˤ��������\n",
		environment(this_player()), this_player());
		this_player()->unconcious();
	}
	return;
}
