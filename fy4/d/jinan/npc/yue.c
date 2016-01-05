// Copyright (C) 2001, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
void dream_return(object me);
void create()
{
    	set_name("����", ({ "yue fei" }) );
    	set("long",
        	"һλ�������ף�����Ʈ����ӧ�����꽫������֪�Ƿ�ú����к�һ�£���飩��\n");
    	set("attitude", "friendly");
    	set("chat_chance", 1);
    	set("chat_msg", ({
                "������ɫ���ص����������������૵�����֪���������������ڵ��˺δ�������\n",
                "����������ס��ǹ�ˣ�����Ĺ�ע����ǰ��ս�֡� \n",
    	}) );
		set("gender", "����");
    	set("title", "�ٱ�");
    	set("nickname", "����·������ʹ");
    
    
    	set("cor", 40);
    	set("cps", 25);
    	set("agi",25);
    	set("int",30);
    	
		set("age",40);
    	set("combat_exp", 90000000);
    
    	set_temp("apply/damage",500);
    	
    	set_skill("unarmed", 200);
    	set_skill("changquan",220);
    	set_skill("yue-spear",180);
    	set_skill("manjianghong",120);
    	set_skill("move", 100);
    	set_skill("literate",150);
    	set_skill("leadership",200);
    	set_skill("strategy",200);
    	set_skill("puti-steps",150);
    	set_skill("spear",120);
    	set("no_arrest", 1);
    
    	map_skill("unarmed","changquan");
    	map_skill("dodge","puti-steps");
    	map_skill("parry","yue-spear");
    	map_skill("force","manjianghong");
    	map_skill("spear","yue-spear");
    
    	setup();
    	carry_object(__DIR__"obj/kuijia")->wear();
		carry_object(__DIR__"obj/silverhat")->wear();
		carry_object(__DIR__"obj/spear")->wield();
}

void init(){
	::init();
	add_action("do_hi", "hi");
	add_action("do_accept", "accept");
	add_action("do_confirm", "confirm");
}

int do_accept(string arg){
	object me;
	me = this_player();
	if(!me->query_temp("marks/yue_ask")) {
		return 0;
	}
	if(arg == "yes") {
		remove_call_out("dream_return");
		message_vision(HIC"\n$N������ѧ���ҵ�ǹ�����Ӵ˾��ǳ�ɱ��ǧ�������У����������������еİ����ˡ�\n"NOR,
				this_object());
		message_vision(HIC"�����Ը�⣿����������������󣯣�\n"NOR, this_object());
		me->delete_temp("marks/yue_ask");
		me->set_temp("marks/yue_confirm", 1);
		call_out("dream_return", 45);
	} else if(arg == "no"){
		remove_call_out("dream_return");
		dream_return(me);
	}
	return 1;
}

int do_confirm(string arg){
	object me;
	me = this_player();
	
	if(!me->query_temp("marks/yue_confirm")){
		return 0;
	}
	if(arg == "yes"){
		remove_call_out("dream_return");
		message_vision("$N��$n˵�������ã���������Ҫ�����ֶ�������\n", this_object(), me);
		message_vision("\n�������䣬$NͻȻ�������������㻹�����ȥ������������������$n���顣\n", this_object(), me);
		tell_object(me, WHT"\n��ֻ����һ�ɸ����Ĵ���ѹ����͸������������ǰ��ɫ�������һƬ��\n"NOR);
		me->set("marks/�ٸ�/����", 1);  
		REWARD_D->riddle_done( me, "�ݺ�����", 50,1);
		dream_return(me);
	} else {
		remove_call_out("dream_return");
		dream_return(me);
	}
	return 1;
}

int do_hi(string arg){
	object me;
	me = this_player();
	if(!arg) {
		return 0;
	}

	if(arg == "yue fei" && REWARD_D->riddle_check( me, "�ݺ�����")==3) {
		if(me->query_temp("marks/got_yue_attention")){
			message_vision("$N˫�ֱ�ȭ�����������˸�Ҿ������λӢ�����ˣ�\n", me);
			message_vision("\n$N��̾һ���� �������⡣���� ����Ҳ����\n", this_object());
			message_vision("\n$N���˶��� ��$nһ�ϣ�����λ"+ RANK_D->query_respect(me) + "���ˣ�ˡ����ʧ̬����ʵ�����Թ�˭\n",
					this_object(), me);
			message_vision("������Ψ����ȡ�����պ�����ѡ��� \n", this_object());
			message_vision("\n$N�þ��������˫Ŀ����$n��һ��һ�ٵ�˵��������Ȼ������ˣ���ĳҲ����\n",
					this_object(), me); 
			message_vision("�ں���ֻ����һ���������ı��죬δ���ϧ�ˡ���ĳԸ���Ҷ��ڣ���֪��λ\n", 
					this_object()); 
			message_vision(RANK_D->query_respect(me) +"��Ը���ܣ����������������󣯣�\n", this_object());
			me->set_temp("marks/yue_ask", 1);
			me->delete_temp("marks/got_yue_attention");
			call_out("dream_return", 30, me);
		} else if (REWARD_D->riddle_check( me, "�ݺ�����")==3)	{ 
		//	else if(me->query("marks/dreaming_yue")){
			message_vision("$N˫�ֱ�ȭ�����������˸�Ҿ������λӢ�����ˣ�\n", me);
			message_vision("\n$N��ɫ���ص�ע����Զ����������ȫû��ע�⵽$n�Ĵ��ڡ�\n", this_object(), me);
			me->set_temp("marks/hi_yue", 1);
			remove_call_out("responed");
			call_out("responed", 10, me);
		} else {
			return 0;
		}
	} else {
		return 0;
	}
	return 1;
}

void dream_return(object me){
	object room;
	if(environment(me) != environment(this_object()) || !interactive(me)){
		return 0;
	}
	if (!REWARD_D->check_m_success(me,"�ݺ�����"))	{
		message_vision("$Nҡ��ҡͷ����Ҳ�ա��������� \n", this_object());

	} else {
		tell_object(me, HIR"\n�������·���������˵�������мǾ��ұ������֡�������\n"NOR);
	}
	set("in_action", 0);
	me->delete_temp("marks/yue_ask");
	tell_object(me, HIY"\n��������Ȼһ����̧ͷ�������Լ�����������⣬ԭ����ֻ�������Ͽ�һ�Ρ�\n\n"NOR);
	room = find_object("/d/jinan/shufang2");
	if(!objectp(room)){
		room = load_object("/d/jinan/shufang2");
	}
	me->move(room);
	me->set("startroom",AREA_FY"fqkhotel");
}


void responed(object me){
	if(environment(me) != environment(this_object()) || !interactive(me)){
		return 0;
	}
	message_vision(WHT"ͻȻ��������Զ��������һ�����̣�\n"NOR, me);
	message_vision("\n$N���һ�����ü��ˣ������쳤Ц, ��ϲ��˵���������ǵ��������������ˣ���\n", 
			this_object());
	message_vision("\n$N��ʱ��ͷע�⵽$n, ���ס���һ������λ" + RANK_D->query_respect(me)+"���ǡ���������\n", 
			this_object(), me); 	 
	message_vision(YEL"\n$N�´�����$nһ������һ������ͻȻ������֮ɫ������������������\n"NOR, 
			this_object(), me); 
	message_vision(YEL"$Nҡ��ҡͷ����ɫ������˵������ô�������� ��ô��������������\n"NOR, 
			this_object()); 
	me->set_temp("marks/got_yue_attention", 1);

}

