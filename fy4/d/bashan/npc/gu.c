// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("�˼���", ({ "gu jianqiu","gu","jianqiu" }) );
        set("title",CYN"��ɽ����"NOR);
        set("nickname",CYN"ҹ�����"NOR);
        set("gender", "����" );

		set("age",47);

        set("long","��ʮ��ǰ�������ᵽ��ʱ����Ϊ����ɽС�ˡ�������������ƺ�\n�ѱ�Ϊ����ɽ�����������˵��˽��������ɼ�һ�ߡ�\n");

		set("skill_public",1);

	set("chat_chance",6);
	set("chat_msg", ({
		"�˼��������Ц�������������ꡣ\n",
	}) );

            set("inquiry",([
 		"���³���"  :"action�˼������һЦ�������³��ţ��ǲ��Ƿ��������ŵļ�������\n",
    		"���Ʒ�"  :"������Ʒɸ�������������\n",
 		"�˷��"  :"������Ʒɸ�������������\n",
 		"���׷�"  :"�ɣ��㷽������ʱ��û�м�������������\n",
 		"�˵��"  :"�ɣ��㷽������ʱ��û�м�������������\n",
 		"����"  :"action�˼���ҡ��ҡͷ��������˵������˵��\n",
           ]) );


    set("reward_npc", 1);
	set("difficulty",7);

        set("combat_exp", 10000000);

		set_temp("busy_immune",1);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );


        set_skill("sword", 300);
        set_skill("advanced-parry", 200);
        set_skill("unarmed", 180);
        set_skill("gaunforce", 190);
        set_skill("venusfinger", 170);
		set_skill("perception",200);
        set_skill("literate", 140);
        set_skill("chanting", 190);
        set_skill("dodge", 200);
        set_skill("move", 160);
        set_skill("parry", 200);
        set_skill("windsword", 220);
        set_skill("nodust-steps", 190);
        set_skill("iron-cloth", 170);

        map_skill("unarmed", "venusfinger");
        map_skill("force", "gaunforce");
        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "nodust-steps");
        map_skill("move", "nodust-steps");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(HIG"ϸ��"NOR, ({ "sword"}) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���峤��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
