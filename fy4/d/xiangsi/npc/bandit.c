// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("��ǿ��", ({ "naked bandit","bandit" }) );
        set("title",CYN"��������"NOR);  
        set("gender", "����" );

        set("long","һ�����Ϲ��ż����Ʋݣ��²��������ǿ����\n");

        set("combat_exp", 200000);
        set("score", 50);
		set("skill_public",1);
        set_skill("throwing", 100);
        set_skill("dodge", 100);

		set("chat_chance", 100);
		set("chat_msg", ({
		(: leave :),
		}) );

        set_skill("meihua-biao", 10);
        set_skill("13-sword", 10);

        map_skill("throwing", "meihua-biao");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N�е����ң�����ֻ�ǣ�����ֻ�����м��·���������������\n"NOR);

		setup();

        weapon=carry_object(__DIR__"obj/stone");
        weapon->set_name("ʯ��", ({ "stone" }) );
		weapon->set("long","һ��Сʯ�ӡ�\n");
		weapon->set("base_unit","��");
		weapon->set("value",0);
		weapon->set_amount(10);
		weapon->set("volumn",10);
		weapon->wield();

}

void rob(object who)
{
	object me = this_object();
	if (!who->is_naked())
	{
		message_vision(CYN"\n$N��ȵ����ѣ����ѣ������·���������\n"NOR,me,who);
		me->kill_ob(who);
	}
	else
	{
		message_vision(CYN"\n$N���´�����$n���ۣ�̾����ԭ��Ҳ�Ǹ����ˡ�\n"NOR,me,who);
		message_vision(CYN"$Nҡҡͷ������ɽʯ���治���ˡ�\n"NOR,me,who);
		destruct(this_object());
	}
}

int accept_object(object who, object ob)
{
	object me = this_object();
	if (ob->query("armor_prop") || ob->query("value") >= 10000)
	{
		message_vision(CYN"$N�Ŵ���ͣ�����"+ob->name()+CYN"�������ķ��˼�����\n"NOR,me,who);
		message_vision(CYN"$N����ϲ�ص�����"+ob->name()+CYN"�����ˡ�\n"NOR,me,who);
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
	message_vision(CYN"$Nҡҡͷ����ͷɥ����ת��ɽʯ֮��\n"NOR,me);
	destruct(this_object());
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
	if (!is_fighting())
		stop_busy();
}
