//�ε� �ǻ� ��Ĭ ���� �ߺ� ��ʧ ���� 

#include <ansi.h>
//inherit SMART_NPC;
inherit __DIR__"mazenpc.c";
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("��Ĭ��Թ��", ({ "ghost" }) );
	set("gender", "����" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set("target_name","��Ĭ��Թ��");

	if (!random(10))
		set("attitude", "aggressive");

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(10) :),
	}) );

	set("combat_exp", 7000000);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"��Ĭ��Թ������أ�����ض����㣮����\n"NOR,
	}) );

	setup();

	set_skill("sword",200);
	set_skill("windsword",200);
	map_skill("sword","windsword");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("��ɽ����", ({ "cloth" }) );
	weapon->set("long","һ����ɽ���������ĵ��ۣ�ֻ����ʽ�Ѿ��Ǻܶ���ǰ���ˡ�\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name("�Ͻ�̽�", ({ "sword" }) );
	weapon->set("long","һ�����þ�����Ȼ�������µĶ̽���\n");
	weapon->set("value",0);
	weapon->wield();
}


void init(){
	::init();
//	add_action("do_go", "go");
}


int do_go(string arg) {
	if (!arg)
		return 0;
	if (query("attitude") != "aggressive")
		return 0;
	message_vision(CYN"$N�ɺ�����������$n��Ц������Ҫȥ����Ȼ��ҵ�����������\n",this_object(),this_player());
	return 1;
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

	ccommand("perform luoxiang");
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

