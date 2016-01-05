// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��¶��");
        set("long", @LONG
����¶��λ�ڰ�ɽ���ϣ�ԭ��ɽ����ѩˮ�ܺ�ɽ�������������ɣ����
һ����ˮ�Ⱥ��ҳ���ȴ����������һ·��ɽ���������������������������ϣ�
��������һȦ����ʯ���������磬ʮ�־��£�����ˮ������һ������������
��ˮ���������еε����¡���Ҫ����¿��ԣ��󣻣����⡡�����壩 
LONG
        );
	set("objects", ([
		__DIR__"obj/pond" : 1,
		__DIR__"npc/leng1" : 1,
	]));
	set("exits",([
  		"south" : __DIR__"xiangsi",
	]) );

	set("outdoors", "xiangsi");
	set("water",100);
	set("dewsoul",1);

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
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

	if (!query("water"))
	{
		write("��¶���Ѿ��ɺ��ˣ�����һ��ˮҲû�С�\n");
		return 1;
	}

	add("water",-1);

    if( skin->query("liquid/remaining") )
	{
		write(skin->name() + "�л���һЩ" + skin->query("liquid/name")+"����Ҫ�˷ѡ�\n");
		return 1;	//giggle
	}

    type="water";
    name="�����¶";
    container="��¶��";
    drunk_apply = 6;

    message_vision("$N��"+container+"�н�" + skin->name() + "װ��"+name+"��\n",me);

	if (!query("water"))
	{
		if (query("dewsoul"))
		{
			message_vision(CYN"��¶���е����һ��¶ˮҲ��$N����ˣ�����\n\n"HIC"ͻȻ��һ�ξ�Ө��͸��¶���ʯ���л������˳�����\n"HIW"¶�����������ҫ�»ó��߲ʵĹ�â�����䵽�ɺԵ���¶���С�\n"NOR,me);
			set("dewsoul",0);
			dew=new(__DIR__"obj/dewsoul");
			dew->move(present("dew pond"));
		}
		else
			message_vision(CYN"��¶���е����һ��¶ˮҲ��$N����ˣ�����\n\n"NOR,me);

		if (present("water",present("dew pond")))
			destruct(present("water",present("dew pond")));
	}

    if( me->is_fighting() ) me->start_busy(2);
    skin->set("liquid/type", type);
    skin->set("liquid/name", name);
    skin->set("liquid/remaining", skin->query("max_liquid"));
    if(drunk_apply) skin->set("liquid/drunk_apply",drunk_apply);
    skin->set("liquid/drink_func", 0);
    
    return 1;
}
 

void reset()
{
	object w;
	::reset();
	set("water",100);	// 100�Σ�һ����Ҫ�����impossible��..^^

	if (!present("water",present("dew pond")))
	{
		w = new(__DIR__"obj/water");
		w->move(present("dew pond"));
	}
}