//�ε� �ǻ� ��Ĭ ���� �ߺ� ��ʧ ���� 

#include <ansi.h>
//inherit SMART_NPC;
inherit __DIR__"mazenpc.c";
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("�ߺ޵�Թ��", ({ "ghost" }) );
	set("gender", "����" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set("target_name","�ߺ޵�Թ��");

	if (!random(10))
		set("attitude", "aggressive");

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(20) :),
	}) );

	set("combat_exp", 7000000);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"�ߺ޵�Թ��ŭ�������������������£����뵹�������˷��£��������д���\n"NOR,
	}) );

	setup();

	set("class","shaolin");
	set_skill("unarmed",400);
	set_skill("yizhichan",200);
	set_skill("force",300);
	set_skill("yijinjing",200);
	map_skill("force","yijinjing");
	map_skill("unarmed","yizhichan");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("ɮ��", ({ "cloth" }) );
	weapon->set("long","һ��ɮ�ۡ�\n");
	weapon->set("value",0);
	weapon->wear();

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

	ccommand("perform nianhua");
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
