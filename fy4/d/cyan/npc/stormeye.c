// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int jice();

void create()
{
	object weapon;
        set_name("������", ({ "figure" }) );

        set("gender", "����" );
		set("age",47);

        set("long","�����������ͣ����輫�󣬵�ȴ���ݣ�ͷ�����ף�һ������������ϳ�\n�Ŷ������ۣ������׹����䣬��һֱվ��ԶԶ�أ�ע�������ؿ͡�\n");

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform tianwaifeixian") :),
             }) );

        set_skill("sword", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("feixiansword", 200);
        set_skill("13-sword", 220);

        map_skill("sword", "feixiansword");
        map_skill("parry", "feixiansword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(MAG"�ɻ꽣"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

		set("no_kill",1);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɵ���Ʒ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
