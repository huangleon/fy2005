#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"�ر�ͼ"NOR, ({ "map" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���������Ƥ�ر�ͼ������Զ�һ��������䣩��\n");
          }
	::init_item();
}

void init()
{
    	if(environment(this_object())==this_player()){
			add_action("do_read","read");
    		add_action("do_go","go");
		}
}

int markit(object me)
{
    	object design;
    	if(!query("already"))   	{
			design = new("/d/chenxiang/obj/design");
			tell_object(me,HIR"\n��һ�������ӡ��ر�ͼ����ָʾ�ĵط��ڳ���ȸͼ��\n"NOR);
			if(!design->move(me))	design->move(environment(me));
			me->delete_temp("map_going");
			set("already",1);
    	}
    	return 1;
}

int do_read(string arg)
{
    	object me;
    	mapping exits;
    	string *dirs;
		string thisdir;
		if(arg != "map") return 0;
		
		me=this_player();
	
		if(me->query_temp("map_going") >= 10) {
			 markit(me);
			 return 1;
		}
		
		if( !mapp(exits = environment(me)->query("exits")) )    {
	        tell_object(me,"������Ʋ��壬�����ط�������\n");
	        return 1;
		}
	
		dirs = keys(exits);
		thisdir = dirs[random(sizeof(dirs))];
		set("thisdir",thisdir);
		if (!query("already")) 
			tell_object(me,"��һ�����ؾ���"+thisdir+"�ķ���������� go "+thisdir+" ��Ѱ������\n");
		else 
			tell_object(me,"��ȸͼ�еĶ����ƺ������˵õ��ˡ�\n");
		return 1;
}

int do_go(string arg)
{
		
       	if (query("already"))	return 0;
       		
       	if(arg == query("thisdir") && query("thisdir") != "none") {
			this_player()->add_temp("map_going",1);
    	}	else
    	{	
    		this_player()->delete_temp("map_going");		
//    		tell_object(this_player(),YEL"�ߴ��ˣ�ֻ����ͷ��ʼ�ˡ�\n"NOR);
    	}
    	set("thisdir","none");	
//    	tell_object(this_player(),"going is"+ this_player()->query_temp("going")+"\n");
    	return 0;
}

