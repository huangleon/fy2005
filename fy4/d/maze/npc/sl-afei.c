inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "afei", "fei" }) );
	set("gender", "����" );
        set("title", "���齣��");
        set("nickname", HIW "���齣" NOR);
	
	set("age", 22);
	set("cor",200);
	
	set("class","assassin");
	set("long","
����ü��Ũ���۾��ܴ󣬱������촽���������һ���ߣ�ֱͦ�ı���ʹ������
������������������ʹ�˺����׾ͻ����뵽����ʯ����ǿ���ᶨ����Į������
���¶�Į�����ģ����������Լ�������ȴҲ��Ӣ����һ��������Ȼ��̫������
Щ���������죬��ȴ�������㹻�����˵�������\n");
        
        set("combat_exp", 6000000);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) ); 		

	set("NO_KILL","������������֮�У�������޷������� ��\n");
	set_temp("condition_type",WHT "<������>" NOR);
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	setup();
	
	carry_object("/obj/armor/cloth")->wear();
}



void	die(){
	object cloth;
	object me, owner;
	mapping data;
	
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        
	message_vision(HIR"
���ɲ԰׵���ɫ���Ӳ԰ף�ͻȻ�����Ҳ��������һ�Ҫ��ȥ���ɶ��� 

����ͻȻ������ˣ�һ��������ʧ������\n\n"NOR,this_object());

	
	if (REWARD_D->riddle_check(me,"��������"))
	if (!REWARD_D->check_m_success(me,"��������"))
	{
		REWARD_D->riddle_done(me, "��������",100, 1);
	
		data = ([
			"name":		"�ƽ�������������",
			"target":	me,
			"att_1":	"con",
			"att_1c":	1,
			"mark":		1,
		]);
		REWARD_D->imbue_att(data);
	}
	
	if (me) me->set_temp("maze/sl_2",1);
	destruct(this_object());
}


int kill_him(object me){
	object ob = this_object();
	
	if (!me || !ob || environment(me)!= environment(ob) )
		return 1;
	ob->delete("NO_KILL");
	message_vision(HIW"
���ɺߵ�һ�������������ϵ�һ�����������俴���㣬һ��һ�ֵ���л-л-�㡣 

����ͻȻ����һ���������㣬����׷ɱ���ҵ��ɶ���˭-��-��-����˭-�͵����� 
\n\n\n"NOR,me);
	ob->kill_ob(me);
	ob->carry_object(__DIR__"obj/sl-sword");
	ob->ccommand("wield sword");
	return 1;
}


void 	unconcious(){
	die();
}