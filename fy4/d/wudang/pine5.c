#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ï�ܵ����֣���ʱ�ܼ�����ֻ����������������ȥ����Ȼֻ�м�˿������͸��
���룬ȴ���Ե���ɭ�ɲ���ϰϰ���粻ʱӭ�洵����ʹ�˻����泩��ʹ����������
�˯��һ����
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"pine1",
  		"west" : __DIR__"pine1",
  		"north" : __DIR__"pine2",
  		"south" : __DIR__"pine2",
	]));

	set("objects", ([
		__DIR__"npc/oldtaoist8" : 1,
		__DIR__"obj/pine" : 1,
		__DIR__"obj/hole" : 1,
   ]) );
	set("no_lu_letter",1);
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",-40);
	setup();
}


void init()
{
	add_action("do_look", "look");
	add_action("do_get","get");
}

int do_look(string arg)
{
	if (!arg)	return 0;
	if (arg == "����" || arg == "hole")
	{
		write("һ������������������߿���һ��СС�Ļƽ𽣡�"NOR"\n");
		return 1;
	}
	return 0;
}


int do_get(string arg)
{
    string what,where;
    object the_wall;
	object ye,ye1;
	object me = this_player();
	ye=present("taoist elder",this_object());
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,this_object()) ;
    if (the_wall)
    if(the_wall->query("name") == "����" || the_wall->query("name") == "hole" )       
    {
		if (ye)
		{
			message_vision("$N����س���$n�Ķ�����$n��������һ��Ƥ���ͣ���ֵ���һ��$N��\n",ye,this_player());
			return 1;
		}
    }
    return 0;
}


void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("����", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		if (!random(4))
		{
		stone = new(__DIR__"obj/mask");
		if(stone)
			stone->move(river);
		}
	}
	return;
}
