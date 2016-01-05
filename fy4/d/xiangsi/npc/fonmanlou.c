// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("����¥", ({ "feng manlou","feng","manlou" }) );
        set("title",HIG"��Ҵ���"NOR);
		set("nickname",HIM"�����Լ���һ����ΰ������ٵĴ���"NOR);
        set("gender", "����" );

		set("age",25);
        set("long",HIR"һ���ֺ������ˣ��������ü����ˡ�\n"NOR);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
        }) );

        set("combat_exp", 7000000);
        set("score", 50);
		set("chat_chance", 100);
		set("chat_msg", ({
		(: leave :),
		}) );

		set("death_msg",CYN"\n$N̾���������죬������Ҫ���ģ�����\n"NOR);

		setup();

		auto_npc_setup("fon manlou",200,220,0,"/obj/weapon/","fighter_w","longfenghuan",1);

        weapon=carry_object("/d/chuenyu/npc/obj/pigmeat");
        weapon->set_name(YEL"�廨�����"NOR, ({ "meat","fat" }) );
		weapon->set("long","���ֱ��ֻ��һ����֬��\n");
		weapon->delete("wield_msg");
		weapon->set("base_unit","��");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����ô������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void rob(object who)
{
	object me = this_object();
	message_vision(CYN"\n$N���Ϻ����������$n����С�����ӣ��ԹԵİ�Ǯ��������\n\n"NOR,me,who);
	me->kill_ob(who);
}

int accept_object(object who, object ob)
{
	object me = this_object();
	if (ob->query("value") >= 50000)
	{
		message_vision(CYN"\n$N����һ������������Ķ�Ƥ��\n"NOR,me,who);
		message_vision(CYN"$N�������߻�ɽʯ֮��\n\n"NOR,me,who);
		remove_all_killer();
		move(load_object("/obj/void"));
		return 1;
	}
	return 0;
}

int leave()
{
	object me = this_object();
	command("get all from corpse");
	message_vision(CYN"$Nҡҡͷ���������߻�ɽʯ֮��\n"NOR,me);
	destruct(this_object());
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
		stop_busy();
}
