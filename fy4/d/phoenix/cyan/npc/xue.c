// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void smart_fight()
{
	if (random(2))
		ccommand("perform luoxiang");
	else
	{
		ccommand("enable sword lefthand-sword");
			ccommand("perform duxin");
		ccommand("enable sword windsword");

	}
	ccommand("perform changrijiangjin");
}

void create()
{
	object weapon;
	set_name("Ѧī֮", ({ "xue mozi","xue","mozi","xuemozi" }) );
	set("class","moon");
	set("gender", "����" );
	set("age", 46);

	set("nickname",MAG"��˫��"NOR);
	set("title","��ԭѦ�� "CYN"����"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"��Ѫƽ��": "actionѦī֮˫ָһ����һ��������ˮ�ĳ����Խ���ԾȻ������\n����������������ʵĽ�����Σ������̾�˿�����",
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"Ѧī֮̾����������ʴ�ӱ���귽������ѵ��߷��洫��Ω������ʵ̫�أ�ֻ�²��Ǻ��¡�\n",
		"Ѧī֮ҡҡͷ��ľ�����֣���ش�֮���ѳ��ڰ���������֮���и����ˣ��ڱط�֮������\n",
	}) );

	set("combat_exp", 4800000);

	set("always_duxin",1);

	set_skill("sword", 200);
	set_skill("lefthand-sword", 220);
	set_skill("windsword", 220);
	map_skill("sword","windsword");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	map_skill("unarmed","luoriquan");


	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();

	
	carry_object("/obj/medicine/pill_zhuguo");

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(WHT"����"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("�ϳ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

