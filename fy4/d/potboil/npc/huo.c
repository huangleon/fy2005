// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("������", ({ "huo qingyi","huo","qingyi" }) );

		set("class","assassin");
		set("title",BLU"�������"NOR);
		set("nickname",WHT"�����绨���ƶ�"NOR);

		set("always_duxin",1);

        set("gender", "����" );

		set("age",47);

	set("chat_chance",1);
	set("chat_msg", ({
		"�����´��˸���Ƿ��Ц������˾��Ҳ̫�����ˣ�˭�������ȷ�����\n",
	}) );

        set("combat_exp", 6100000);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

        set("perform_unarmed_attack",	"demon/unarmed/venusfinger/panguaxe");
		set("perform_busy_d", 			"legend/dodge/fall-steps/qiufengluoye");
		
        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 150);
        set_skill("unarmed", 200);
        set_skill("hammer", 200);
        set_skill("longfenghuan", 186);
        set_skill("lingxi-zhi", 190);
		set_skill("force",200);
		set_skill("jingxing",200);
		set_skill("luoriquan",350);
		set_skill("venusfinger",200);
		set_skill("xifengying",180);

		

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("force", "jingxing");
        map_skill("hammer", "longfenghuan");
        map_skill("unarmed", "venusfinger");
        map_skill("sword", "lefthand-sword");
        map_skill("parry", "venusfinger");
        map_skill("dodge", "xifengying");

		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����֮��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

/*
void smart_fight()
{
	object me = this_object();
	object ob = select_opponent();
	int i,j;

	if (is_busy())
		return 0;

//	if (random(3))
//		return 0;

	ccommand("perform dodge.qiufengluoye");
	ccommand("perform panguaxe");
	return;
}

*/