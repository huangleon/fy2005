// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("�����", ({ "luo jiafei","luo","jiafei" }) );
        set("title",CYN"��ɽ����"NOR);
        set("nickname",CYN"ϸ��һҹ��"NOR);
        set("gender", "Ů��" );

    set("reward_npc", 1);
	set("difficulty",5);

		set("age",47);

        set("long","�������˵����������֣���������ȴʤ���ޣ������д�\n˵�˵��˵Ļط�����������߰˷������������ɡ�\n");

	set("chat_chance",6);
	set("chat_msg", ({
		"�����΢Ц���Ź˼���������⾡������֮�⡣\n",
	}) );

            set("inquiry",([
 		"���³���"  :"action���������������³��ţ������Һͼ�����ʶ�����ӣ�����\n",
  		"���Ʒ�"  :"������Ʒɸ�������������\n",
 		"�˷��"  :"������Ʒɸ�������������\n",
 		"���׷�"  :"�ɣ��㷽������ʱ��û�м�������������\n",
 		"�˵��"  :"�ɣ��㷽������ʱ��û�м�������������\n",
 		"����"  :"action�����ҡ��ҡͷ��������˵������˵��\n",
            ]) );

        set("combat_exp", 10000000);

		set_temp("busy_immune",2);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );


        set_skill("sword", 300);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("windsword", 220);
        set_skill("13-sword", 220);

        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(YEL"��Ӱ"NOR, ({ "sword"}) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("ĺ����ȹ", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
