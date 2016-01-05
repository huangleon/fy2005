#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name(HIY"����������"NOR, ({ "nanwang bodyguard","bodyguard"}) );
	set("class","berserker");
	set("attitude", "friendly");
	set("long","�������еĸ��֣���Ȼ��Ϊ����֮����������׿������ѷ�������е���һһ��һ�ĸ��֡�\n");

	set("no_arrest",1);
	set("no_fly",1);
	set("no_curse",1);

	set("combat_exp", 6000000);	

	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
		
	set_skill("spear", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("move", 200);
	set_skill("xifengying", 200);
	set_skill("unarmed",200);
	set_skill("venusfinger",200);
	set_skill("force",200);
	set_skill("gaunforce",200);
	set_skill("eclipse-spear", 200);
	map_skill("spear","eclipse-spear");
	map_skill("spear","eclipse-spear");
	map_skill("move","xifengying");
	map_skill("dodge","xifengying");
	map_skill("unarmed","venusfinger");
	map_skill("force","gaunforce");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	setup();
	carry_object(__DIR__"obj/heavyspear")->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	if (!is_busy())
		smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();
	target = select_opponent();
	ccommand("exert damageup");
	ccommand("perform panguaxe");
	if (target->query_temp("annie/eclipse_dot") || random(3))
	{
		ccommand("perform riyuetongtian");
		return;
	}
	ccommand("perform eclipse");
}

void die()
{
	object owner,*enemy;
	int i;
	if (present("nanwang prince",environment()))
		if (!userp(present("nanwang prince",environment())))
		{
			owner=present("nanwang prince",environment());
			enemy = query_enemy();
	        i = sizeof(enemy);
			owner->delete("NO_KILL");
	        while(i--)
				if( enemy[i] && living(enemy[i]) )
					if (COMBAT_D->legitimate_kill(enemy[i],owner))
					{
						owner->kill_ob(enemy[i]);
						enemy[i]->kill_ob(owner);
					}
			owner->set("NO_KILL","�������������ǣ����ɺ��Ҷ��֣�����ٸ�׷ɱ��\n");
		}
	::die();
}

void invocation(object who)
{
	object owner,*enemy;
	int i;
	message("vision", name() + "�ȵ����󵨣����Һ͵������ӹ���ȥ��\n" NOR,
		 environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
//	ccommand("say i="+i);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			enemy[i]->kill_ob(this_object());
		}
	}
	set("master",who);
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
