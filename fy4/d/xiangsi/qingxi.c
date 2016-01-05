// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	object river,stone;
	set("short", "�������");
        set("long", @LONG
�ߵ����ֱ�Ե��һ�����ѵ�СϪ��б���������ǰ��Ϫˮ�����������
һ���Բ�ɰ�����ʯ�����������������ˮ���˴���Ϫ�ߵ�ʯ���ϣ��Ƽ�����
������ȥ���������齦�飬�ö���������Ŀ��ɽ����Լ�ɼ�һ�Ǻ��ܷɹ�����
�����У����ߴ�����ױ��ѩ�����ⶫ��֮�����Ǻ�����
LONG
        );
	set("objects", ([
		__DIR__"obj/river" : 1,
	]));
	set("exits",([
  		"north" : __DIR__"lvzhu",
  		"south" : __DIR__"huju",
  		"east" : __DIR__"shuixie",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("Ϫˮ", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/stone2");
		if(stone)
			stone->move(river);
		stone = new(__DIR__"obj/stone2");
		if(stone)
			stone->move(river);
	}
	return;
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	if (dir == "east")
		me->set_temp("annie/gits",1);
	return ::valid_leave(who,dir);
}


void init()
{
	add_action("do_fill", "fill");
}


int do_fill(string arg)
{
    string name, type, container;
	object me,skin,dew;
    int drunk_apply;
	function f;
	
	me = this_player();
	
	
	if (!arg)
		return 0;
	skin = present(arg,me);
	if (!skin)	return 0;
    if( me->is_busy() )
	{
		write("����һ��������û����ɡ�\n");
		return 1;
	}

	if (!skin->query("liquid/name"))
	{
		write("��û��װˮ�Ķ�������\n");
		return 1;
	}

    if( skin->query("liquid/remaining") )
        message_vision("$N��" + skin->name() + "��ʣ�µ�" + 
                       skin->query("liquid/name") + "������\n", this_player());

    type="water";
    name="��Ϫˮ";
    container="СϪ��";
    drunk_apply = 6;

    message_vision("$N��"+container+"�н�" + skin->name() + "װ��"+name+"��\n",me);

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
    
    f = (: call_other, __FILE__, "drink_drug" :);    
    skin ->set("liquid/drink_func", bind(f, skin));  
    
    return 1;
}


int drink_drug(object ob)
{
    tell_object(this_player(),HIG"Ϫˮ�д��ŵ����Ĳ��㡣\n"NOR); 
    return 0;
}


 






/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
