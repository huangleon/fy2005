//�ε� �ǻ� ��Ĭ ���� �ߺ� ��ʧ ���� 

#include <ansi.h>
//inherit SMART_NPC;
inherit __DIR__"mazenpc.c";
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("�ǻ���Թ��", ({ "ghost" }) );
	set("gender", "����" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);
	set("target_name","�ǻ���Թ��");
	
	if (!random(10))
		set("attitude", "aggressive");

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(20) :),
	}) );

	set("combat_exp", 7000000);
	set("m_success/���괫��",1);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"�ǻ���Թ���ڵ����������ҵĽţ����ҵĽ�����ȥ�ˣ�����\n"NOR,
	}) );

	setup();

	set_skill("sword",400);
	set_skill("xiaohun-sword",220);
	map_skill("sword","xiaohun-sword");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("ֹ������", ({ "cloth" }) );
	weapon->set("long","��������ֹ��ɽׯ���µ�װ����ֻ�������ڽ����о������ꡣ\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name("�ϵ��Ķϵ��ĳ���", ({ "broken sword","sword" }) );
	weapon->set("long","һ�Ѷϵü���ֻʣ�½����Ľ���\n");
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

	ccommand("perform libie");
	if (query("timer/libie") +3 >= time())
		set("timer/libie",time()-270);
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


// call mingyue->set(annie_quest/name,��ϼɽɱ��);call mingyue->set(annie_quest/number,1);update /d/cyan/npc/maze_guard2;clone
