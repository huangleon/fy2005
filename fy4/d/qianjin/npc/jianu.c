// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{

	set_name("��ū", ({ "jianu", "nu" }) );
	set("long", "����һǧ��¥�ļ�ū��ר�ŵ��δ���֮��\n");
	set("attitude", "friendly");

	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 20000);
	set("chat_chance", 1);
	set("chat_msg_combat", ({
		"��ū�ȵ�����������Ұ����ò��ͷ��ˣ�\n",
		(: command("crazy") :),

	}) );
	set_skill("unarmed", 10+random(50));
	set_skill("move", 7+ random(70));
	set("possessed",1);
	setup();
	carry_object(__DIR__"obj/jncloth")->wear();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIW + name() + "�ݺ�����������һ�ڵ����´�û��ô���ˣ�\n\n"
		+ name() + "�޺޵ض��˶�ţ�һ�������ˡ�\n"NOR, environment(),
		this_object() );
	destruct(this_object());
}
