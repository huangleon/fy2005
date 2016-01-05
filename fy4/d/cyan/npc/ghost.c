
#include <ansi.h>
inherit SMART_NPC;
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("�Դ�����", ({ "zhao da","zhao","zhaoda" }) );
	set("title","����ɡ");
	set("gender", "����" );
	set("long","�Դ�����ԭΪ�������֮�ף�һ����ֽɡ�¶�ȥ���������ú�������\n");

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(20) :),
	}) );

	set("combat_exp", 8000000);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"��ʧ��Թ�����ڵ��ϣ�����Ц��������û������û�����ǻ��ϵ���������\n"NOR,
	}) );

	setup();

	set_skill("spear",300);
	set_skill("eclipse-spear",220);
	map_skill("spear","eclipse-spear");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("�������", ({ "cloth" }) );
	weapon->set("long","һ���������õĻ��ۡ�\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/spear");
	weapon->set_name("�ػ���ǹ", ({ "spear" }) );
	weapon->set("long","���Ǳ������Ͻ���һ����ʦ�ػ��������Ĵ���ĳ�ǹ��\n");
	weapon->set("value",0);
	weapon->wield();
}




int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight(100);	// rascal design :p
	return 1;
}

void smart_fight(int t)
{
	if (t <= random(100))
		return;

	ccommand("perform riyuetongtian");
	return;
}

int is_ghost()
{
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
