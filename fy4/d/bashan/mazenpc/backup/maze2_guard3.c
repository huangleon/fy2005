#include <ansi.h>
inherit SMART_NPC;
void smart_fight(object who);

void create()
{
	object weapon;
	set_name("�����޲���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "Ů��" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

		set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(this_object()) :),
	}) );

	set("combat_exp", 6000000);

	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","kaleidostrike2",4);

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name(HIR"�埬֮��"NOR, ({ "hairpin"}) );
	weapon->set("long","һö�������Ρ�\n");
	weapon->set("value",0);
	weapon->wear();

	carry_object(__DIR__"obj/wolfclaw")->wield();

	set_temp("apply/attack",200);
	set_temp("apply/parry",200);
}


int fight_ob(object who)
{
	if (query("immortal"))
		who->remove_enemy(this_object());
	::fight_ob(who);
	smart_fight(who);
	return 1;
}

int kill_ob(object who)
{
	if (query("immortal"))
		who->remove_killer(this_object());
	::kill_ob(who);
	smart_fight(who);
	return 1;
}


void do_ck(object * tar)
{
	int i;
	set("immortal",0);
	delete("NO_KILL");
	set("resistance/kee",0);
	set("resistance/gin",0);
	set("resistance/sen",0);
	return;
}

void smart_fight(object who)
{
	int i;
	object *tar,me=this_object();
	if ((query("kee") < query("max_kee") / 2 || query("gin") < query("max_gin") / 2 || query("sen") < query("max_sen") / 2) && query("timer/annie_immortal") + 180 < time())
	{
		message_vision(HIW"\n�����޲�����ü���ף������޷��Զ�������һ�㵭��ǳǳ�Ĳ��⡣\n"HIC"΢��������ȦȦ��������$N�ĵ�������Ůһ�㣬���˲����᷸��\n\n"NOR, me);
		set("timer/annie_immortal",time());
		set("immortal",1);
		set("NO_KILL","�����޲��ڵ���������һ�㵭��ɫ�Ĺ�â�������Ƶ�����֮�⡣\n");
		set("resistance/kee",100);
		set("resistance/gin",100);
		set("resistance/sen",100);
		call_out("do_ck",15,tar);
	}

	if (query("immortal"))
	{
		tar = query_enemy();
		for (i=0;i<sizeof(tar) ;i++ )
			tar[i]->remove_killer(me);
	}

	auto_smart_fight(100);	// rascal design :p
	return;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
