// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void smart_fight()
{
	ccommand("perform tianleiyiji");
	ccommand("perform changrijiangjin");
}

void create()
{
	object weapon;
	set_name("������", ({ "xiao changsheng","xiao","changsheng","xiaochangsheng" }) );
	set("class","yinshi");
	set("gender", "����" );
	set("age", 46);

	set("nickname",CYN"�߽��Ļ�"NOR);
	set("title","������ "CYN"��ʿ"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"��Ѫƽ��": "������ڤͨ�����ٹ��У��������˷��������ֽ�"WHT"�ٲ�"CYN"������ֻ��ǲ��ǰ����",
		"�ٲ�": "����˵�ˣ�����Ů��������Ե�������б㻽�����",
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"������������ͥ����Ե���٣������˼����������ʫ����ʫ��\n",
		"��������������˵�ˣ�����Ů��������Ե�������б㻽�����\n",
	}) );

	set("combat_exp", 5000000);

	set_skill("whip", 200);
	set_skill("thunderwhip", 220);
	map_skill("whip","thunderwhip");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	map_skill("unarmed","luoriquan");

	set_skill("hammer", 200);
	set_skill("pangu-hammer", 220);
	map_skill("hammer","pangu-hammer");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();

	
	carry_object("/d/phoenix/npc/obj/cyan_drug2");

        weapon=carry_object("/obj/weapon/whip");
        weapon->set_name(RED"���´�"NOR, ({ "whip" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("�೤��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

