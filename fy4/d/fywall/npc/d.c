// �ص㣺��Ϭָ��high perception

#include <ansi.h>
inherit NPC;
int smart_fight();

void create()
{
	object weapon;
        set_name("�β���", ({ "he bugui","he","bugui" }) );
        set("title",WHT"���ݿո���"NOR);
		set("nickname",MAG"��ȥ�����ｫ��"NOR);
        set("gender", "����" );
		set("class","moon");

		set("age",33);
//		set("per",37);

		set("no_busy",2);

        set("combat_exp", 10000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//                (: smart_fight() :),
             }) );
		set_temp("apply/haste",200);

        set_skill("unarmed", 250);
        set_skill("luoriquan", 350);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("magic", 220);
        set_skill("force", 220);
        set_skill("snowforce", 220);
        set_skill("music", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 220);
        set_skill("stormdance", 200);
        set_skill("lingxi-zhi", 200);
		set_skill("perception", 300);

        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "lingxi-zhi");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("force", "snowforce");
        map_skill("sword", "qiuzhi-sword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "stormdance");

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�ջ���", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


		weapon=carry_object("/obj/weapon/fist");
		weapon->set_name("����ָ��", ({"finger" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wield();
}
/*
void smart_fight()
{
	
	if (query("ac")+16<time())
	{
		set("ac",time());
		if (ccommand("perform dodge.chansi"))
			stop_busy();
		else
			start_busy(1);
	}
	set("atman",query("max_atman")*2);
	if (ccommand("perform npc_by_shimian"))
		stop_busy();

	if (is_busy())
		return;

	ccommand("wield all");
	if (!ccommand("conjure guanglingsan"))
		stop_busy();
	
	ccommand("conjure bihai");
	ccommand("unwield all");
}

*/


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/


