#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("����",({"tu cheng"}));
	set("title",WHT"ʮ��������  ����"NOR);
   	set("long","����������ʮ����������Ĵ����֮һ��\n");
   	
     	set("gender","����");
     	set("group","khlr");
     	
    	set("age",62); 	 	
    	    	
    	set("combat_exp",10000000);  
    	set("attitude", "friendly");
    	
    	set("boss",1);
    	set("resistance/kee",99);
    	set("resistance/gin",99);
    	set("resistance/sen",99);
    	set("NO_KILL","�㱻���´󺺵��������㣬�����ҳ��С�\n");
    	set("inquiry", ([
 
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,1,"/obj/weapon/","fighter_w","bat-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

void init(){
	::init();
	add_action("do_answer","answer");
}

int do_ask(object me){
	message_vision(CYN"
�������۾�������������������µس����$N�����˺ܾòŵ��������ϵú��ģ���\n"NOR,me);
	tell_object(me,WHT"\nanswer yes/no\n"NOR);
	me->set_temp("juyuan_tucheng",1);
	me->start_busy(8);	
	call_out("kill_him",10,me);
	return 1;
}

int kill_han(object ob){
	
	object peng1, peng2, peng3, peng4;
	
	peng1 = this_object();
	if (peng2=present("luo jiang",environment(peng1))) 
		peng2->kill_ob(ob);
	if (peng3=present("xiao an",environment(peng1))) 
		peng3->kill_ob(ob);
	if (peng4=present("yuan chong",environment(peng1))) 
		peng4->kill_ob(ob);
	peng1->kill_b(ob);
	return 1;	
}

int disappear(){
	object *inv;
	int i;
	message_vision("\nֻ������һ�������´�����ʧ�ںڰ��\n",this_object());
	inv = all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]->query("khlr") && inv[i]!=this_object()) 
			destruct(inv[i]);
	}
	destruct(this_object());
	return 1;
}
	
int kill_him(object me) {
	
	object han,peng1;
	peng1 = this_object();
	han = present("han tang",environment(peng1));
	if (environment(me)!=environment(this_object())
		|| !objectp(han)) {
		disappear();
		return 1;
	}
	if (me->query_temp("juyuan_tucheng")) {
		message_vision(CYN"
������̾�˿���˵�����Ȼ��Ը�ش���Ҳ����ǿ��\n"NOR,me);
		me->delete_temp("juyuan_tucheng");
	}
	message_vision(CYN"
����������ĵ���ͻȻ��$N�����������ĵ������$N������ʱ�·��㻬��ˮ��
ƽ����˳����$N������ȫû�ие�ʹ�ࡣ

$N�������������ͻ���ڰ��Ťת�鶯������ʱ�������ڵأ�\n"NOR,me);
	me->delete_temp("juyuan_tucheng");
	me->unconcious();
	kill_han(han);
	return 1;
}



int do_answer(string arg){
	object me,han,peng1;
	peng1 = this_object();
	me = this_player();	
	han = present("han tang",environment(peng1));
	remove_call_out("kill_him");	
	if (!me->query_temp("juyuan_tucheng"))	return 0;
	
	if (!arg || (arg !="yes" && arg !="no"))
		return notify_fail("answer yes/no \n");
		
	if (arg == "yes") {
		message_vision(YEL"
$Nһͦ��˵�������ϲ����ˣ������Ǿ�԰���ˣ�����ͳͳ����ȥ��\n"NOR,me);
		message_vision(CYN"
������˵���ܺã����Ƕ�����ȥ���ˡ�\n"NOR,me);
		REWARD_D->riddle_set(me,"��԰����",6);
//		me->set("marks/kuaihuo/����",1);
		
	}	
	if (arg =="no") {
		message_vision(CYN"
������˵���ܺã���������ˡ�\n"NOR,me);
//		me->set("marks/kuaihuo/����",2);
		REWARD_D->riddle_set(me,"��԰����",7);
	}
	me->delete_temp("juyuan_tucheng");
	kill_him(me);
	return 1;
}


