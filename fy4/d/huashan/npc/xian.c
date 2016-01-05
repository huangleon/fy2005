#include <ansi.h>
inherit NPC;

inherit F_MASTER;
void mimicurse();

void create()
{
	set_name("���ɹ�", ({ "jiang xiangong", "jiang" }) );
	set("title", HIG "�׷�ͯ��"NOR);
	set("gender", "����" );
	set("age", 80);
	set("per", 25);
	set("class","yinshi");
	set("long", "��ͷ�Ļ�������˿�����������ȴ��Ӥ��һ��û��һ˿���ơ�\n");
	set("combat_exp", 800000);
	set("attitude", "friendly");
    	set("chat_chance", 1);
    	set("chat_msg", ({
		"���ɹ��������ܵ�ͷ��������������ɽ��������\n",
		"���ɹ����ֹ�������֪�������ʲô�����챦�� \n",
    	}) );
	
	set_skill("incarnation", 150);
	
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 100);
	set_skill("zuixian-steps", 100);
	        
     	set_skill("cursism", 100);
    	set_skill("celecurse", 100);
    	  
        map_skill("unarmed","flying-dragon");
        map_skill("dodge","zuixian-steps");
	map_skill("cursism", "celecurse");
		
	set("skill_public",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int accept_fight(object me)
{
	command("say �����˼����������Ķ��֣�");
	return 0;
}

int recognize_apprentice(object ob)
{
    	if(ob->query("free_learn/incarnation"))
        	return 1;
	return 0;
}

int accept_object(object who, object ob)
{

	if (ob->name() == HIY"����"NOR){
		if (ob->query("inc"))
		{
			message_vision("$N����"+ ob->name() + "��ϸ���˿��������ã��ã�����������\n",this_object());
			message_vision("$Nתͷ���˿�$n�����Ϸ�����Ϊ�����������������ѧ��������\n", this_object(), who);
			who->set("free_learn/incarnation", 1);
			REWARD_D->riddle_done( who, "��ɽ����", 10, 1);
		} else
			message_vision("$N���ߵ�˵����Ȼ���üٻ���ƭ�����˼ң�\n", this_object());			
		return 1;
	}
	return 0;
}

int prevent_learn(object me, string skill)
{
  	if (skill != "incarnation")
  	{
      		command("shake");
      		command("say �ҿ�ֻ��Ӧ��������������");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/incarnation")	&& skill == "incarnation")
		return 0;
	
	return 1;
}


object offensive_target(object me)
{
	int sz;
	object *enemy;
	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;
	sz = sizeof(enemy);
	if( sz > 6 ) sz = 6;
	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void mimicurse()
{
	object target;
	
		target = offensive_target(this_object());
		command("curse bloodcurse on "+target->query("id"));
		return;
}

void die(){
	if (!this_object()->is_unconcious()){
		message_vision(HIR"\n$N�е�������ͷ�Ӻ���ƴ�ˣ���\n"NOR, this_object());
		mimicurse();
	}
	::die();
}
	