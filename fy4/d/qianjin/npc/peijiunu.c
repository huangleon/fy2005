
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("���Ů", ({ "peijiunu" }) );
	set("gender", "Ů��" );
	set("title", HIG "������Ц"NOR);
	set("age", 18);
	set("long",
		"һ��������Ц�����Ů\n");
	set("combat_exp", 300000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
"���Ů�䵽�����ԣ������𣬺ȣ�\n",
"���Ů�����еı̾Ƶ��������ϣ�Ȼ������ͷ����İ�����ɣ���\n",
        }) );
	set_skill("unarmed",100);
	set_skill("tenderzhi",45);
	set_skill("dodge",100);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/halfcloth")->wear();
}
