// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit __DIR__"maze_npc.c";
void smart_fight();

void create()
{
	set_name("һ��", ({ "bo",}) );
	set("class","moon");
	set("race", "Ұ��");
	set("target_name","һ�����");
	set("group","icecave_maze");
	set("title",HIW"��ѩ����"NOR);

	set("combat_exp", 1000000);
	set_skill("mapo", 110);
	set_skill("spells", 200);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("spells", "mapo");

	if (!random(10))
		set("attitude", "aggressive");
	else
		set("attitude", "friendly");

	set("long","һֻ��������ֵֹİ�ɫ���ܡ�\n");

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw", "hoof", "poke" }) );

	set("no_arrest",1);
	set("no_fly",1);

	set("drop/bg",85);
	set("drop/common",70);
	set("drop/rare",30);
	set("drop/amount",1);
	set("drop/common_drop",({
__DIR__"obj/snowball.c",
__DIR__"obj/hastedrug.c",
__DIR__"obj/statdrug.c",
__DIR__"obj/seal.c",
	}) );
	set("drop/rare_drop",({
__DIR__"obj/binglunyinjing_1.c",
__DIR__"obj/bingpojingbi_1.c",
__DIR__"obj/mingyue_1.c",
__DIR__"obj/qinghui_1.c",
	}) );

	setup();

}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();
	target = select_opponent();
	if (target->query_temp("is_unconcious"))
		return;
	SKILL_D("mapo")->cast_spell(me,"freeze",target);
	
}
