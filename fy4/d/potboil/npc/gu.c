// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
		object weapon;
        set_name("�����", ({ "gu yangen","gu","yangen" }) );

		set("class","demon");
		set("title",BLU"�������"NOR);
		set("nickname",CYN"����"NOR);

		set("no_curse",1);

		set("always_duxin",1);

    	set("attitude","friendly");


	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
	
	set("group","demon");

	set("difficulty",10);
	set("reward_npc",1);


        set("gender", "����" );

		set("age",27);

	set("chat_chance",1);
	set("chat_msg", ({
		"����������������ֺ�������أ����ǳ�˾�ɼ�Ȼ�������\n",
	}) );

        set("combat_exp", 6000000);
		auto_npc_setup("gu",190,150,0,"/obj/weapon/","fighter_w","spring-blade",4);

		set("death_msg",CYN"\n$N���������ƣ�����\n"NOR);
		setup();

		weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("�����", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();
		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���Ų�ѩ", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}




int kill_ob(object who)
{
	if (who->is_zombie() == 1 || base_name(who) == "/obj/npc/danei" || base_name(who) == "/obj/npc/danei_guard")
	{
		message_vision(HIW "$N�������֣������е���ǹ���˸��ɲ�Ǽ�����������ţ�����\n" NOR,this_object());
		who->die();
		return 1;
	}
	::kill_ob(who);
	return 1;
}