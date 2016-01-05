#include <ansi.h>
inherit ITEM;
void create()
{
    	set_name(YEL "�����ռ�" NOR, ({ "afrji" }) );
    	set_weight(1);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
	        set("unit", "��");
	        set("material", "paper");
	        set("long", "һ��������ǰ���ռǣ�����Զ�һ��������䣩��\n");
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
    	object gold;
    	if(!query("already"))   	{
        	gold = new("/obj/money/gold");
        	tell_object(me, YEL"\n\n��һ�������ӡ������ռǡ���ָʾ�ĵط��ڳ�Щ���ӣ�\n"NOR);
        	if (me->query("combat_exp")>1000000)
        	if (!REWARD_D->check_m_success(me,"�ռǲر�")) {
        		tell_object(me,HIY"���ֱ���������Լ����۾�������һ���󱦲أ�����\n");
        		tell_object(me,HIY"������д���������50�����ӣ�����\n"NOR);
        		me->add("deposit",500000);
				REWARD_D->riddle_done(me,"�ռǲر�",10,1);
        	}
        	gold->set_amount(1+random(5));
        	gold->move(me);
        	me->delete_temp("going");
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
		if(arg != "afrji" && arg != "�����ռ�") return 0;
		
		me=this_player();
	
		if(me->query_temp("going") >= 20) {
			 markit(me);
			 return 1;
		}
		
		if( !mapp(exits = environment(me)->query("exits")) )    {
	        tell_object(me,"������Ʋ��壬�����ط�������\n");
	        return 1;
		}
	
		dirs = keys(exits);
		if (!dirs || sizeof(dirs) < 1)    {
	        tell_object(me,"������Ʋ��壬�����ط�������\n");
	        return 1;
		}
		
		thisdir = dirs[random(sizeof(dirs))];
		set("thisdir",thisdir);
		if (!query("already")) 
			tell_object(me,"��һ�����ؾ���"+thisdir+"�ķ���������� go "+thisdir+" ��Ѱ������\n");
		else 
			tell_object(me,"�ռ��ϼ�����һ�����ص�λ�ã�����ǰ�����������ؾͱ��������ˡ�\n");
		return 1;
}

int do_go(string arg)
{
	
       	if (query("already"))	return 0;
       		
       	if(arg == query("thisdir") && query("thisdir") != "none") {
			this_player()->add_temp("going",1);
    	}	else
    	{	
    		this_player()->delete_temp("going");		
//    		tell_object(this_player(),YEL"�ߴ��ˣ�ֻ����ͷ��ʼ�ˡ�\n"NOR);
    	}
    	set("thisdir","none");	
//    	tell_object(this_player(),"going is"+ this_player()->query_temp("going")+"\n");
    	return 0;
}



