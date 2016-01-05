// �ص㣺1) don't drop her weapon, 2) only perform when target kee>50%

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("������", ({ "lei mingzhu","lei","lei mingzhu" }) );
        set("title",WHT"����������"NOR);
		set("nickname",MAG"�׺�����������"NOR);
        set("gender", "Ů��" );
		set("class","baiyun");

		set("age",33);
		set("per",37);

		set("no_busy",4);

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set_skill("unarmed", 250);
        set_skill("luoriquan", 350);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 220);

        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "luoriquan");
        map_skill("blade", "chillblade");
        map_skill("sword", "qiuzhi-sword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "tie-steps");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("ϸ����", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��޿��", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();

}

void smart_fight()
{
	object target;
	target = select_opponent();
	if (!target) return;
		
	if (target->query("kee")> target->query("max_kee")/2 )
	{
		if (!query_temp("weapon"))
			ccommand("perform changrijiangjin");
		else
			ccommand("perform hanmeiluo");		
	
	} 
}

