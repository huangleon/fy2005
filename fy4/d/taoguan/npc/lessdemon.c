// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>

inherit NPC;
void create()
{

	set_name("�׺�", ({ "lesser demon","demon" }) );
	set("long", "����һ��ս��ɳ���Բ���֪����������а�����ص��׺���\n");
	set("race", "Ұ��");
	set("attitude", "friendly");
	set("title",YEL"�������"NOR);
	set("nickname",WHT"���߲�Ϣ"NOR);
	set("no_fly",1);
	set("no_arrest",1);
	set("combat_exp", 4000000);

	set("bellicosity", 30000 );
    set("attitude", "aggressive");

	set("max_kee",20000);
	set("max_gin",10000);
	set("max_sen",10000);

	set("limbs", ({ "ͷ��", "����", }) );
	set("verbs", ({ "bite", "claw" }) );

	set("str",60);

	set_skill("blade", 200);
	set_skill("spring-blade",200);
	set_skill("unarmed",200);
	set_skill("yue-strike",200);
	
	map_skill("unarmed","yue-strike");
	map_skill("blade","spring-blade");

	setup();
	carry_object(__DIR__"obj/demonblade")->wield();
}

void call_die()
{
	if( environment() ) {
			say( "\n"+name() + "���ڵ��ϣ�һ˲���û��������ʧ�ˡ�\n\n");
	}
	destruct(this_object());
}

void die()
{
	call_die();
}

/*
void die()
{
	object owner,enemy;
	set_name("�׺�", ({ "x x x x x" }) );
	if ( present("lesser demon",environment() ) )
		call_die();
	else
	{
	    if(objectp(enemy=query_temp("last_damage_from")))
		    if(owner=enemy->query("possessed"))
				enemy = owner;
		if (enemy)
		{
			message_vision(CYN"\n������һ��Ц���������������Ĺ��ơ�\n"NOR,enemy);
			message_vision(CYN"һ��������������������Ȼ���ʡ�\n"NOR,enemy);
			message_vision(CYN"����ǰ�ĺ����Ȼɢ����ԭ���㻹��С��֮�У���������վ������ǰ�ĳ�֮�⡣\n\n"NOR,enemy);
			enemy->set_temp("annie/demon_xin_1",0);
			enemy->set_temp("annie/demon_xin_2",1);
			enemy->move(load_object("/d/taoguan/dimroom"));
		}
		call_die();
		return ;
	}
}


*/
