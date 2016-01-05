// �۽��� ʹ��SEN/GIN�˺���ߵ�KEE�˺�ɱ��

#include <ansi.h>
inherit NPC;
void smart_fight();
void leave();
void create()
{
    set_name(CYN"���ꡤ��"NOR, ({  "sword spirit", "spirit","sword spirit cyan"}) );
    set("race", "����");
    set("age", 1);
    set("gender", "����");
    set("long", "������ǧ���˪�����������ڹŽ����ɽ��ϵľ���֮Ӣ�� \n");
    set("attitude","peaceful");
    set("limbs", ({ "����", "����","����", "����" }) );
    set("verbs", ({ "insect-kick"}) );
	set("weight", 300);
	set("str",105);
	set("force_factor",0);

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("max_kee", 24000);
	set("max_sen", 12000);
	set("max_gin", 12000);
	set("eff_gin", 12000);
	set("eff_kee", 24000);
	set("eff_sen", 12000);
	set("gin", 12000);
	set("kee", 24000);
	set("sen", 12000); 

	set("combat_exp", 10000000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
               (: smart_fight() :),
    }));

	set_skill("move",600);
	set_skill("unarmed",1100);
	set_skill("dual-attack",300);
	set_temp("apply/haste",300);
	set_skill("demon-steps",1);
	set_skill("dodge",1);
	map_skill("dodge","demon-steps");

	set("chat_chance", 100);
    set("chat_msg", ({
               (: leave() :),
    }));


	setup();
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[0];	// ��0ɱ��
}


void smart_fight()
{
	int i,max_busy=99;
	object *enemy,target,sword;
	string action;

	enemy = query_enemy();

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (!enemy[i]->is_busy() && enemy[i]->query("combat_exp")<2*this_object()->query("combat_exp") && enemy[i]->query("possessed"))
				this_object()->smart_busy(enemy[i]);

}


smart_busy(object target) {
	if (is_busy())
		return;
	(CLASS_D("demon") + "/demon-steps/lianhuanbabu")->perform(this_object(),target);
	return;
}


void unconcious()
{
	die();
}

void die()
{
	object owner,*pros;
	message("vision",HIC"���ꡤ�ۻ�Ϊһ���������ɿ���������Ͻ����еĹŽ����ɽ���\n" NOR, environment(),this_object() );
	if(objectp(owner=this_object()->query("possessed")))
	{
		pros = owner->query_temp("protectors");
		pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
		owner->set("cyan",time());
	}                
	destruct(this_object());

}

void leave()
{
	object owner,*pros;
	message("vision",HIC"���ꡤ�ۻ�Ϊһ���������ɿ���������Ͻ����еĹŽ����ɽ���\n" NOR, environment(),this_object() );
	if(objectp(owner=this_object()->query("possessed")))
	{
		pros = owner->query_temp("protectors");
		pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}                
	destruct(this_object());

}


void init()
{
	::init();
	add_action("do_look","look");
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
write(CYN"������ǧ���˪�����������ڹŽ����ɽ��ϵľ���֮Ӣ��\n"NOR);
write("������ʮ�ֻ��顣\n");
write("�书����������"HIR"��ɲ�"NOR"�������ƺ����ء�\n");
	return 1;
}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
