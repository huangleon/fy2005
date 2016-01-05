#include <ansi.h>
inherit SMART_NPC;


int strangle();
int slash();
int bite();
int octopus_attack();

void create()
{
	set_name("������" , ({ "octopus" }) );
	set("title", HIW "ǧ��ˮ��"NOR);
	set("race", "Ұ��");
	set("age", 10000);
	set("long", "����һ�������޴�����㣬�����ס����Ǻ�ɫ�Ĵ����ľ޴��۾��������㡣��
�İ�ֻ�첲������˵��ֻ�ţ��������Դ��ϣ�����������˫����ô����������
������踾�˵�ͷ��������Ʈ����ֶ������졪�����ʵ��죬���������ĵ�һ
��������ֱ�Ļ򿪻�ϡ����Ĺ��ʵ���ͷ�����м��ż���������������¶����
һ�������Ĵ���ǯ�� ����������һ������!�����������Ĵ��Σ��������ͣ���
��һ����飬�������¶�����������ǧ������ϵĲ�������ɫ������ֶ���
�ļ���������Ѹ�ٵĸı��ţ��ӻҰ�ɫ½����Ϊ���ɫ��\n");
	
	set("combat_exp", 5000000);
	
        set("boss",1);
	set("max_gin",50000);
	set("max_kee",400000);
	set("max_sen",50000);
	
	set("difficulty",40);
	set("reward_npc",1);	
	set("no_curse",1);
		
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		30:	(: octopus_attack() :),
        ]) );    	
    	
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
		(: bite()  :),     
        }) );
    	
    	set("chat_chance",1);
    	set("chat_msg",({
		"������������һ����۾������㣬ʹ�㲻��������\n",
    	}) );  
	
	set_temp("apply/attack", 600);
	set_temp("apply/armor",  200);
	set_temp("apply/dodge",  450);
	set_temp("apply/damage", 50);
	
	set_temp("fight_to_death",1);
	setup();
	if (!random(4))	carry_object(__DIR__"obj/claw");
	if (!random(4)) carry_object(__DIR__"obj/pearl2");
}

int octopus_attack() {
	
	if(time()-query("bite_time")<4) return 1;
	switch (random(2)) {
		case 0: strangle();break;
		case 1: slash();break;
	}
	return 1;
}


int strangle(){
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	me=select_opponent();
	if (!me)	return 1;
	
	message_vision(HIW"\n$N�Ĵ��ֺ�Ȼ���ſ������������ߴ�����ֻ�۾���һ���������˳�����
��һ�ž�����$n������ס��\n"NOR,ob,me);
	me->perform_busy(3);
	return 1;
}
	

int slash () {
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	enemy=ob->query_enemy();
		
	message_vision(HIM"\n$N�������Ȼ�����ɫ���漴���һ���������а����������·��ɣ�
�����ڳ���ÿһ���ˡ�\n"NOR,ob);

	for (i=0;i<sizeof(enemy);i++) {
		tell_object(enemy[i],HIB"����ö�����棬ͷ��Ŀѣ��\n"NOR);
		enemy[i]->receive_damage("sen",300,ob);
		if (!userp(enemy[i])) enemy[i]->receive_damage("sen",300,ob);
		COMBAT_D->report_status(enemy[i]);
	}	
	ob->perform_busy(1);
	return 1;
}


int bite() {
	object ob,me,*enemy;
	int i;
	
	ob=this_object();
	ob->set("bite_time",time());
	enemy=ob->query_enemy();
	me=enemy[random(sizeof(enemy))];
	message_vision(HIR"\n$N���Դ�������һ����ת�ţ���Ȼ���ſ�Ѫ����죬һ����$nҧȥ��\n"NOR,ob,me);
	me->receive_wound("kee",1000,ob);
	COMBAT_D->report_status(me);
	ob->perform_busy(2);
	return 1;
}


void die()
{
	object rstone, me,owner,money_reward;
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
	environment(this_object())->set("octopus_death",time());

	::die();
}


void init(){
	
	object me=this_player();
	
	::init();
	if (interactive(me))
	if (!me->query_temp("riddle/�̺�����/����һЦ"))
	{
		kill_ob(me);
	}
}