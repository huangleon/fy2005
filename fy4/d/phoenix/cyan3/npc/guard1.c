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
		"����":		"action�Ľ�ɮţ��һ�ɵ���զ������ʦ����˭�����ǵ��ˣ�\n",
//		"��Ѫƽ��": (: look_stone :),
		]) );


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

	REWARD_D->riddle_done(me,"��ɱ����",0,1);

	::die();
	return;
}

int do_answer(string arg)
{
	object me = this_player();
	if (!me->query_temp("aaa"))
		return 0;
	me->delete_temp("aaa");
	if (arg == "����ɽׯ" || arg == "����")
	{
		if (REWARD_D->check_m_success(me,"�������"))
		{
			REWARD_D->riddle_done(me,"��������ɽׯ",0,1);
			message_vision(CYN"\n�Ľ�ɮ˫�ֺ�ʮ������һ����λʩ�������\n"NOR,me);
			return 1;
		}
	}

	if (arg == "��ƽ����" || arg == "��ƽ")
	{
		if (REWARD_D->check_m_success(me,"���"))
		{
			REWARD_D->riddle_done(me,"������ƽ",0,1);
			message_vision(CYN"\n�Ľ�ɮ˫�ֺ�ʮ������һ����λʩ�������\n"NOR,me);
			return 1;
		}
	}

	if (arg == "ħ��" || arg == "����ħ��" || arg == "�������" || arg == "���")
	{
		message_vision(CYN"\n�Ľ�ɮ��ɫһ�࣬��ȵ���ħ�����ˣ����ҷ�����\n"NOR,me);
		message_vision(CYN"\n�Ľ�ɮ����ʦ�ܣ����������ˣ�\n"NOR,me);
		
		if (present("monk 2",environment(this_object())))
			present("monk 2",environment(this_object()))->kill_ob(me);
		if (present("monk 1",environment(this_object())))
			present("monk 1",environment(this_object()))->kill_ob(me);

		return 1;
	}

	// begger..û����֤��ѽ^^

	message_vision(CYN"\n�Ľ�ɮ��ü�������ﲻ����ʵ�����бض��й�\n"NOR,me);
	message_vision(CYN"\n�Ľ�ɮ����ʦ�ܣ����������ˣ�\n"NOR,me);

		
		if (present("monk 2",environment(this_object())))
			present("monk 2",environment(this_object()))->kill_ob(me);
		if (present("monk 1",environment(this_object())))
			present("monk 1",environment(this_object()))->kill_ob(me);

	return 1;
}

void init()
{
	object ob;
	::init();
	add_action("do_answer","answer");
}

