// �ص㣬�����и���big perform

#include <ansi.h>
inherit NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("����Ц", ({ "chu changxiao","chu","changxiao" }) );
        set("title",WHT"����һЦ��"NOR);
		set("nickname",MAG"һЦ����������"NOR);
        set("gender", "����" );
		set("class","moon");

		set("age",33);

		set("no_busy",2);

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
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("13-sword", 220);
        set_skill("tie-steps", 220);

        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "luoriquan");
        map_skill("blade", "chillblade");
//      map_skill("parry", "chillblade");
        map_skill("dodge", "tie-steps");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("������", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();

		weapon=carry_object("/obj/weapon/fist");
		weapon->set_name("��ָͭ��", ({"finger" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wield();
}

void smart_fight()
{
	ccommand("perform dodge.chansi");
	
	if (query("ac")+30 < time())
	{
		set("ac",time());
		ccommand("perform changrijiangjin");	
	}
	
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

