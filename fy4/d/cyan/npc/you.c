// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("��Ϸ��", ({ "master you","master","you" }) );
	    create_family("��������", 4, "��Ժ��");
		set("class","taiwanese");

		set("nickname",HIG"����"NOR);
        set("gender", "����" );

		set("age",47);
        set("long","�������޳������������·���Ժ����Ϸ���������һԺԺ����\n");

		set("chat_chance",3);
		set("chat_msg", ({
			"��Ϸ������ͷ����������ӵģ�˭�ö�����ż��\n",
			"��Ϸ�������һ�۵����㽶������֣���Ϻ�ף�\n",
		}) );
        set("inquiry",([
 			"�ϴ�"  :"�ϴ󶼲�֪��������Ϸ�裡\n",
         ]) );

        set("combat_exp", 6100000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: ccommand("perform fentianzhan") :),
        }) );

		set_skill("blade",400);
		set_skill("beilongblade",240);
		map_skill("blade","beilongblade");

		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

		setup();

		carry_object(__DIR__"obj/pxblade")->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("�̱�ñ", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}



void attempt_apprentice(object me) {
	message_vision("$N��$nҡҡͷ������ȥ���������ϴ���˵��\n", this_object(),me);
}