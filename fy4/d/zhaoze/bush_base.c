#include <ansi.h>

inherit ROOM;

int do_cut(string arg)
{
        object obj, me;
        string dir;
        
        
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "bush" || arg == "����" )
	{
		me = this_player();
		obj = me->query_temp("weapon");
		if( !obj ) 
		{
			write("������֣���ô����\n");
			return 1;
		}
		if( obj->query("jungle"))
		{
			if( !query("exits/"+query("route"))) {
        			set("exits/"+query("route"), query("route_room"));			
				switch(query("route")) {
					case "south": arg = "��"; break;
					case "east" : arg = "��"; break;
					case "north": arg = "��"; break;
					case "west":  arg = "��"; break;
				}
								
				message_vision(sprintf("$N�����е�%s����һ����"+arg+"��·��\n",obj->name()),me);
			}
			else
				message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),  me);
		}
		else
 			message_vision(sprintf("$N�����е�%s������ľ���һ���ҿ���\n",obj->name()),me);
 		me->perform_busy(1);
	}
	else
	 	write("��Ҫ����ʲô��\n");
        return 1;
}

void init()
{	object ob,room;
	if( interactive( ob = this_player())) {
    		if(ob->query_skill("force",1) < 150) {
			if (!room=find_object(__DIR__"edge.c"))
				room = load_object(__DIR__"edge.c");
			ob->move(room);
			tell_object(ob, HIR"�㱻�����������������˻�������150�������ڹ���\n\n"NOR);
		}else if (userp(ob) || userp(ob->query("possessed")))
				ob->apply_condition("zhaoze",10);			
	}
	add_action("do_cut","chop");
}

void reset()
{
	::reset();
        delete("exits/"+query("route"));
}

int valid_leave(object me, string dir)
{
        object ob;
        if (query("exits/"+query("route")) && dir == query("route"))
        if (ob = present("fire giant", this_object()))
        	return notify_fail(ob->name()+"��ס�����ȥ·��\n");        
	return 1;
}

