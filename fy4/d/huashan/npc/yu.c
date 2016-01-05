 
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��һ��", ({ "yu yifei", "yu" }) );
	set("gender", "����" );
	set("age", 30);
	set("class","baiyun");	
	set("long", "һ����ɫ���Ƶĺ��ӣ��������ۡ�\n");
	set("nickname", "�ؾ���");
        set("combat_exp", 2000000);
	set("attitude", "friendly");
	
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("chessism",120);
	set_skill("feixian-steps",150);
	set_skill("feixian-sword", 150);
	
	map_skill("force","chessism");
	map_skill("sword", "feixian-sword");
	map_skill("parry", "feixian-sword");
	map_skill("dodge", "feixian-steps");
	map_skill("move", "feixian-steps");
	
	set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action ("sword.tianwaifeixian") :),
        }) );
	
	set("inquiry_now", 0);
	set("youshan", 0);
	setup();
	carry_object("/obj/armor/cloth",
		([ "name": "����",
			"long": "һ���ɾ�ƽ������ɫ������\n" ])
		)->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void init()
{       
	object me;
		
	::init();
	me = this_player();
	if( interactive(me = this_player()) && !is_fighting()) 
	{
		if(!query("inquiry_now")) 
		{
	    		if (REWARD_D->riddle_check(me,"��ɽ����")
	    				|| REWARD_D->check_m_success(me,"��ɽ����"))
	    			return 0;
	    			    		
	    		remove_call_out("do_ask");
	    		call_out("do_ask", 2, me);
		}
	}
	add_action("do_accept", "accept");
}


int do_ask(object me){
	if( !random(2) && !query("youshan") && !query("inquiry_now")) {
		message_vision("$Ņͷ������һ��$n��", this_object(), me);
		message_vision("˵��������λ" + RANK_D->query_respect(me) + "��Ըһͬ��ɽ����
���������������󣯣�\n",
				this_object());
		me->set_temp("marks/query_tongyou", 1);
		set("inquiry_now", 1);
		call_out("remove_ask", 20, me);
	} else {
	}	
}

void remove_ask(object me) {
	if(interactive(me) && environment(me) == environment(this_object())){
		message_vision("$N˵��������Ȼ��λ" + RANK_D->query_respect(me) + "��ԥ�������Ǿ����ա���\n",
				this_object());
		set("inquiry_now", 0);
		me->delete_temp("marks/query_tongyou");
	}
}

int do_accept(string arg){
	object me;
	
	me = this_player();
	if(me->is_busy() || me->is_fighting() || !query("inquiry_now")){
		return 0;
	}
	if(!arg || arg != "yes" && arg != "no") {
		return 0;
	}
	if(!me->query_temp("marks/query_tongyou")) {
		return 0;
	}
	if(arg == "yes") {
		message_vision("$N����˵�������ã�������Ե�η�һͬ��ɽ����\n", me);
		set("youshan_c", me);
		set("youshan", 1);
		me->set_leader(this_object());
		me->ccommand("follow yu yifei");
		this_object()->ccommand("south");
		call_out("check_env", 5, me);
	} else {
		message_vision("$N���������м��������ʹ˱������\n", me);
	}
	remove_call_out("remove_ask");
	me->delete_temp("marks/query_tongyou");
	set("inquiry_now", 0);
	return 1;
}

void check_env(object me){
	environment(this_object())->girl(me);
}