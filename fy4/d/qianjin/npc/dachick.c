#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "bu yanan","bu" }) );
	set("title", HIM "����"NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("per", 30);
	set("long", @LONG
�����д���û���������Ӣ�ۺú�����������ʯ��ȹ�£�
LONG
);
	set("combat_exp", 13000);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/shi_skirt")->wear();
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
        return 1;
}
