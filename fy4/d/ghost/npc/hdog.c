#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���ɾ�", ({ "dog" }) );
        set("gender", "����");
        set("class", "ghost");
        create_family("����ɽׯ", 3, "����");
        set("age", 34);
        set("combat_exp", 50000);
        set("long",
		"һ��ȫ��������ڣ��ڵ÷����Ĵ�Ƥ���������ˡ�\n"
	);
        set("no_arrest",1);
        set_skill("move", 100);
        set_skill("dodge", 100);
        set_skill("throwing", 100);
        set_skill("feidao", 50);
	map_skill("throwing", "feidao");
        setup();
	carry_object(__DIR__"obj/biao")->wield();
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
		HIW + name() + "�޺޵ض��˶�ţ�һ�������ˡ�\n"NOR, environment(),
		this_object() );
	destruct(this_object());
}