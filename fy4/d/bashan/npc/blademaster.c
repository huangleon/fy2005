// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("���ؿ�", ({ "figure","figure jiang" }) );

        set("gender", "����" );
		set("age",47);

        set("long","һ��ͷ�����ң��͵���ס���ݵ��ˣ�����ɢ����ǿ�ҵ�ɱ����\n");

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform fentianzhan") :),
             }) );


            set("inquiry",([
 		"���³���"  :"action���ؿ�һ�ﲻ����������$nһ�¡�\n",
 		"�˵���"  :"action���ؿ�һ�ﲻ����������$nһ�¡�\n",
 		"�˼���"  :"action���ؿ�һ�ﲻ����������$nһ�¡�\n",
           ]) );

        set_skill("blade", 240);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("beilongblade", 200);
        set_skill("13-sword", 220);

        map_skill("blade", "beilongblade");
        map_skill("parry", "beilongblade");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(HIB"��ߵ�"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("����", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}

void die()
{
	stop_busy();
	ccommand("perform fenqin");
	::die();
}
