// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("���", ({ "feng lan","feng","lan" }) );
        set("title",HIG"�������"NOR);
		set("nickname",YEL"������Ұ�޾���"NOR);
        set("gender", "����" );
		set("class","moon");
		set("attitude", "friendly");


		set("age",21);

        set("long","һ��������ʯ����ĬĬ��˼�����깫�ӡ�\n");

	set("chat_chance",8);
	set("chat_msg", ({
		"���������񷣬ĬĬ����ָ���㡣\n",
		"���̾�������������˵��ǻ�����ұ����ɽ�������Ҳ�����������õĹ���֮�ء�\n",
		"��᰿���ָͷ��üͷ���壬�૵�������Ѫ��֮�֣�����ü�ޣ�\n",
	}) );
        set("inquiry",([
 		"����¥"  :"��磿��������Ŷ����Ĵ��ε�����Ҳ��֪�������\n",
 		"����"  :"���ܣ���������Ŵ���Ĵ��ε�����Ҳ��֪�������\n",
              ]) );

        set("combat_exp", 5500000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform mingyue") :),
             }) );


        set_skill("blade", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 150);

        map_skill("blade", "chillblade");
        map_skill("parry", "chillblade");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N̾���������Ȼ����ƭ�ң����⣬���⣮����\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("���յ�", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("īɫ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		carry_object(__DIR__"obj/box");
}
