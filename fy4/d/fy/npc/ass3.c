// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("������", ({ "one-armed man","man" }) );
        set("gender", "����" );
		set("class","swordsman");

		set("age",35);
		set("annie/duxin",1);

        set("long","���������������ͣ����ȴ��ó��档����б����һ����\n��ͣ���һ���ƾɵ����ҵ͵͵�ѹ��ü�£�ֻ¶����߰�ֻ\n�۾���\n");

        set("combat_exp", 1200000);


        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: ccommand("perform muyufeihong") :),
             }) );
        set_skill("sword", 200);
        set_skill("softsword", 150);
        map_skill("sword", "softsword");


		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(BLK"�����"NOR, ({ "bamboo stick","stick" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("�ƶ���", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();
}
