// ��һ�����������������Ͳ����ˣ����2�����ڽ��

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�첿��", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );
	set("nickname",HIR"������һժ�� ���������"NOR);
	
	set("attitude", "aggressive");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);

	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	set_skill("zen",200);
	set_skill("xiaodao",150);
	set_skill("demosword",150);
	set_skill("zensword",200);
	set_skill("sword",200);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
	set_skill("unarmed", 200);
	set_skill("spicyclaw",200);
	set_skill("divineforce",200);

	map_skill("force","divineforce");
	map_skill("unarmed","spicyclaw");
	map_skill("dodge","fall-steps");
	map_skill("sword","demosword");
	map_skill("parry","zensword");

	set("perform_unarmed_attack","berserker/unarmed/spicyclaw/extrahit5");
	set("perform_unarmed_attack2","berserker/unarmed/spicyclaw/extrahit4");
	set("perform_unarmed_attack3","berserker/unarmed/spicyclaw/extrahit3");	
	set("perform_weapon_attack","huashan/sword/demosword/zhutianjianzhen");

	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"��ħʥ��"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","һ������ɫ����ף���֪�Ǻ������ơ�\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name(HIW"�׹Ǵ�"NOR, ({ "unicorn spine","spine"}) );
	weapon->set("long","һ��ɭȻ�׹ǡ�\n");
	weapon->set("value",0);
	weapon->wield();

}

int kill_ob(object who)
{
	int n;
	
	n = query_busy();
	stop_busy();
	
	::kill_ob(who);
	ccommand("perform force.wudumiaodi "+who->query("id"));
	
	perform_busy(n);
	
	return 1;
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
