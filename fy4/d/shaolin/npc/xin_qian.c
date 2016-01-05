// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int kill_him();

void create()
{
        set_name("�ļ�", ({ "master jian","master", "jian"}) );
        set("gender", "����" );
        set("age",62);
		create_family("������", 17, "����");
        set("long", "�������ߴ����֮һ��\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 6000000);
        set("attitude", "friendly");
        
        set("chat_chance", 2);
        set("chat_msg", ({
//                name()+"˵�����ؾ����飬�Ϸ���Ը�ڴ����ʮ�ꡣ\n",	// �Ϸ�...>_< �һ��Ϸ�����
                name()+"˵�����ؾ����飬������Ը�ڴ����ʮ�ꡣ\n",
        }) );
        
        
	    set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);   
		setup();
		carry_object(__DIR__"obj/monk_cloth")->wear();
}

void init()
{
	::init();
	if (environment(this_object())->query("short") == "�����" && !is_fighting() && !is_busy()) {
		command("say ������ʲô����\n");
		call_out("do_kick",2+random(3),this_player());
	}
}

int do_kick(object me)
{
	object room;
	if(me && environment(me) == environment() && !me->is_fighting()
		&& !me->is_busy())
	{
		command("say û������������ˡ���\n");
		message_vision("$N����һ�ӣ�һ�ɴ�����$n�ͳ����⡣\n",this_object(),me);
		room = 	load_object(AREA_SHAOLIN"liuzu");
		if(room) me->move(room);
	        message_vision("$N�����ߵ������з��˳��������ص�ˤ�ڵ��£�\n",me);
		me->receive_damage("kee",50,this_object());
	}
	return 1;
}


/*
int kill_him()
{
	object me;
	me = this_player();
	if(!me->query("m_success/�±�����") || is_fighting())
	{
		message_vision(CYN"�ļ�˵������͵�������ŵ��֣������Ѿ���ְ����Ը�ڴ����ʮ�ꡣ\n"NOR,me);
		return 1;
	}
	delete("vendetta_mark");

	me->set_temp("annie/demon_gao_askqian",1);

	message_vision(CYN"�ļ��ȵ����������͵�������Ī�������Ҳ������㣡\n"NOR,me);
	message_vision(CYN"�ļ��ȵ������������ַ������������������Ĳ������ģ�\n"NOR,me);
	message_vision(CYN"�ļ�����һ�������Ķ�����ȵ������ˣ��ҿ��ҽ�ħ�ֶΣ�\n"NOR,me);
	set("combat_exp",3000000);
    set("chat_chance_combat", 100);
	map_skill("unarmed", "dabei-strike");
	set("chat_msg_combat", ({
            (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
	kill_ob(me);
	me->kill_ob(this_object());
	return 1;
}

void killed_enemy(object who)
{
    command("heng");
    command("say �ҷ��������ֶΣ������ĳ�����������Թ�����ң�");
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
	{
		set("vendetta_mark","shaolin");
		set("chat_chance_combat", 10);
		set("chat_msg_combat", ({
				(: perform_action, "unarmed.qiankun" :),
		}) );
		set("combat_exp", random(600000)+600000);
	}
}

void unconcious()
{
	::die();
}

void die()
{
	int i;
	object killer, owner;
	object room;
	room = environment();
	if(objectp(killer = query_temp("last_damage_from")))
	{
		if(owner=killer->query("possessed"))
			killer = owner;

		if(!killer->query("m_success/�±�����") || room->query("short") != "�����" || !killer->query_temp("annie/demon_gao_askqian"))
		{
			// rob��?
			set("vendetta_mark","shaolin");
			::die();
			return ;
		}

		message_vision(HIR"\n$NĿ�����ѣ���ȵ����ã��ã�\n$N������𣬼�ȫ������$n��ȥ��\n"NOR,this_object(),killer);

		killer->set("annie/demon_gao",1);

		if (random(killer->query_skill("move",1)) > 100)
		{
			message_vision("$n������ת������һ�ԣ�$N������������ǽ�ϣ�����ǽ�ں��һ���󶴣�\n\n",this_object(),killer);
		}
		else
		{
			message_vision(CYN"$n���㲻������$N�����������۵�һ��ӡ���ؿڣ���ʱ����߷��ݰ�ɳ���\n$n�ɵ����ɿ��⣬��Ȼײ��ǽ�ϣ�����ǽ��ײ��һ���󶴣�\n"NOR,this_object(),killer);
			killer->receive_wound("kee",(400-random(killer->query_skill("parry",1)))*20,this_object());
			COMBAT_D->report_status(killer);
		}
        room->opengate();
	}
	::die();
}
*/