// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit NPC;
int leave();

void create()
{
	object weapon;
        set_name("���²���", ({ "qingyi ren","ren" }) );
        set("gender", "����" );
		set("class","assassian");

		set("age",25);
		set("annie/duxin",1);

        set("long","�������Ƶ���ɫ�ڻ���¿����·�ò��Ѿã�\nӦ�����ڴ��ϳ�ҩ��ȴ��������档\n");

        set("combat_exp", 600000);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: ccommand("perform duxin") :),
             }) );
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);

        map_skill("sword", "lefthand-sword");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("���߽�", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ʪ������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();
}
