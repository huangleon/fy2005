// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();
int look_stone();

void create()
{
	object weapon;
        set_name("�Ľ�ɮ", ({ "shaolin monk","monk" }) );

        set("gender", "����" );
		set("age",47);

        set("long","�����ɵĺ��С�\n");

	set("no_fly",1);
	set("no_arrest",1);

//	set("nickname",MAG"����"NOR);
	set("title","���ֵ�ʮ��������");

        set("combat_exp", 2900000);


	set("inquiry",([
		"���":		"Ϊ�����˻��룬Ψ������߿��Բλᡣ\n",
		"��Ѫƽ��": (: look_stone :),
		]) );

		set("npc_team","shaolin_blade");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


			 set("npc_team","shaolin_blade");


        set_skill("blade", 300);
        set_skill("lianxin-blade", 300);

        map_skill("blade", "lianxin-blade");

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(YEL"���н䵶"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("��ɮ��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smt_fight()
{
	object *env, ob;
	int i;
	ob = this_object();
	env = all_inventory(environment(this_object()));
	for (i=0; i<sizeof(env);i++)
	{
		if (env[i]!= this_object() && env[i]->query("npc_team") == "shaolin_blade")
		{
			ob->ccommand("perform yipianlianxin with "+ env[i]->query("id")+ " 2");
			return;
		}
	}
	return;
}


void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	
	message_vision(CYN"\n$N���Ľ�ɮ��Ц������ԭ���ɣ�������ϧ��\n"NOR,me);

	REWARD_D->riddle_done(me,"ɱ����",0,1);


	::die();
	return;
}




int accept_object(object who, object ob)
{
	if (ob->query("name") == RED"��Ѫƽ�ܴ�����"NOR)
	{
		REWARD_D->riddle_done(who,"���",0,1);
		message_vision(CYN"�Ľ�ɮ��ʮ������λʩ�������\n"NOR,who);
	}
	return 1;
}




int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();

	me->set("annie/a",1);

	message_vision(CYN"�Ľ�ɮ˵���������ӷ�ʩ������"WHT"���"CYN"��\n"NOR,me);
	return 1;

}