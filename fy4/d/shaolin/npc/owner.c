#include <ansi.h>
inherit SMART_NPC;

void create()
{
    set_name("л�ƹ�", ({ "xie zhanggui"}) );
    set("gender", "����" );
    set("age", 42);
	set("title","��ɽׯ �ڶ�����Ϊ�徲¥�ƹ�");
    set("long",
        "�������Ϊ�徲¥л�ƹ񣬴��һ�����л��������˵�书�ѳ����뻯��\n");
    set("combat_exp", 4000000);
    set("reward_npc", 1);
    set("difficulty", 5); 
    set("attitude", "friendly");

    set("fly_target",1);
    set("chat_chance", 1);
    set("chat_msg", ({
      		"л�ƹ����û�뵽����С��������ү��ǰ��Ȼ��ô����һ����\n",
            "л�ƹ������Ҫȥ����¥��Ӯ�����ҵ�"YEL"����˵�"NOR"���С�\n",
            }) );
    
    set("inquiry",([
    	"����˵�":	"actionл�ƹ������˵������һ�С��Ƴ���������������Ϳ���ȥ����¥��(accept test)��\n",
    ]));	
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) ); 		

	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","shenji-blade",1);
    setup();
    carry_object(__DIR__"obj/qingcloth")->wear();
    carry_object(__DIR__"obj/blade")->wield();
}


void init()
{
	object me,meizhi;
//	if(interactive(me = this_player()) && !me->is_fighting() && userp(me) && me->query("marks/����_��_��ʮ��"))
	if(interactive(me = this_player()) && !me->is_fighting() && userp(me))
	{
		remove_call_out("greeting");
		call_out("greeting",2,me);
	}
	add_action("do_answer","answer");
	add_action("do_accept","accept");
}


void greeting(object me)
{
	if (objectp(me) && present(me,environment(this_object())))
	{
		if (!me->query_temp("marks/pass_xiezhanggui"))
		{
			message_vision("$N����$nһ�ۣ������˵����ƾ��Ĺ���Ҳ��ȥ��ս��ʮ�����������ʮ���Ľ����𣿡�\n",this_object(),me);
			me->set_temp("marks/xie_inask",1);

		}
		
	}
}


int do_answer(string arg)
{
	object me;
	me = this_player();
	if (!me->query_temp("marks/xie_inask"))
	{
		return 0;
	}
	
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("��ֻ�ɴ�yes/no \n");
	}
	me->delete_temp("inask");
	if (arg == "yes")
	{
		message_vision("$N�۾�һ������$n������������ҿ���(show)���Ľ�����ʲô���ģ��� \n",this_object(),me);
		add_action("do_show","show");
	}else
	{
		message_vision("$N��$n˵���������Ľ�����û�������Ͳ�Ҫȥ�����ˡ��� \n",this_object(),me);
	}
	return 1;
}


int do_show(string arg)
{
	object me,meizhi;
	me = this_player();
	if (arg != "meizhi" && arg != "���ϵ�÷֦" && arg != "÷֦")
	{
		return 0;
	}
	if (!present("meizhi",me))
	{
		return notify_fail("������û������������\n");
	}
	if (me->query_temp("lookmeizhi")!=2)
	{
		message_vision("л�ƹ��Ц������ССһ�ο�֦�����㶼��֪����ʲô���ø���������\n",me);
		return 1;
	}
	
	message_vision( "$n�ó����ϵ�÷֦�����ȵغ���$N��ǰ�� 
$N����÷֦�ĶϿڣ���ɫ������ûҰ���ʧ�����ǵ����ŵ���
����ʮ�彣����ʮ�彣������ ��ȥ�ɡ���\n ",this_object(),me);
	me->set_temp("marks/pass_xiezhanggui",1);
	return 1;

}


int do_accept(string arg)
{
    	mapping guild;
    	int extra,x;	
    	int mgin,mkee,msen;
    	object player, ob, blade;
    	string msg;
    	
    	player = this_player();
    	ob = this_object();	
    		
    	if( arg== "test" )    {
			if (REWARD_D->check_m_success(player,"������¥")) {
				tell_object(player,"л�ƹ�������õ�һ�ԡ�\n");
				return 1;
			}
			
			if (player->is_busy()|| player->is_fighting()) 	{
	    		tell_object(player,"��������æ�ţ��Ȱ��ֱߵ��¶������˰ɡ�\n");
	    		return 1;
	    	}
		
			if (ob->is_busy()|| ob->is_fighting()) {
				tell_object(player,"л�ƹ���æ���أ�û�����㡣\n");
				return 1;
			}
			
			if (ANNIE_D->check_buff(ob, "lockup"))
				ANNIE_D->debuff(ob,"lockup");
				
			ob->fight_ob(player);
			player->fight_ob(ob);
			
			if (!(blade=ob->query_temp("weapon"))) {
				blade = new("/obj/weapon/blade");
				blade->set("name",CYN"�ֵ�"NOR);			
				blade->set("nodrop_weapon",1);
				blade->move(ob);
				message_vision(CYN"л�ƹ��Ȼ������֣���ָ�絶���ǽ�����ֵ���\n"NOR, ob);
				message_vision(CYN"л�ƹ������ʮ���������ǵ�һ������ʹ����ʽ�ģ����аɣ�\n"NOR, ob);
				blade->wield();
				x= 1;
				ob->add_temp("apply/damage",700);
			}
		
			player->perform_busy(1);
			ob->ccommand("perform jichulianhuan");
			player->stop_busy();
			ob->stop_busy();
			ob->remove_all_killer();
			if (x && blade)	destruct(blade);
			if (x)	ob->add_temp("apply/damage",-700);
		
			if (player->query("kee")<0)
				msg = "л�ƹ���Ц��������֮ͽ��������ϧ��\n";
			else if (player->query("kee")< player->query("max_kee")/4)
				msg = "л�ƹ�ҡҡͷ˵������书�����ǲ�Ҫ���׳��˰ɡ�\n";
			else if (player->query("kee") < player->query("max_kee")/2)
				msg = "л�ƹ�ҡҡͷ˵�����нӵ�����Ǳ�����ô��ȥ����¥��\n";
			else if (player->query("kee") < player->query("max_kee")*3/4)
				msg = "л�ƹ�������⹤��ô����ȱ��ôһ��������\n";
			else {
				msg = "\nл�ƹ���ɫ�Ұ���������Խ�ȥ�ˡ�\n";
				message_vision(CYN+msg+NOR, player);
				REWARD_D->riddle_done(player,"������¥",20);
				return 1;
			}

			message_vision(CYN+"\n"+msg+NOR, player);				
		}
		
		return 1;
}	
		
		
		
		
		
			