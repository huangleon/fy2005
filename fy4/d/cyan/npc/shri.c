// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("ϯ����", ({ "xi ruoyin","xi","ruoyin" }) );
        set("title","��ϼɽ "HIB"�"NOR);
		set("nickname",HIG"�紵�仨"NOR);
        set("gender", "����" );
		set("class","moon");

		set("age",21);

        set("long","ϯ�����������ڲt��̨�ߣ������ؿ��ŷ��Ʒ���\n");

	set("chat_chance",2);
	set("chat_msg", ({
		"ϯ����΢΢һЦ�������������Ҷ�����ô�ã�����Ϊʲô��\n",
		"ϯ��������������һ���Ƴ��Ƴ�����Ϣ��\n",
		"ϯ����̽��ͷ����Ųt��̨����ȥ����֪����Щʲô��\n",
	}) );

        set("combat_exp", 6700000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );


		set("death_msg",CYN"\n$N����̾�˿������һ�����ԭ��Ҳûʲô���壮����\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("˪�佣", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/dagger");
        weapon->set_name("����֦", ({ "dagger" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","tempestsword",4);
}
