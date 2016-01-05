#include <ansi.h>
inherit NPC;

void create()
{
	object		biao, bag;

        set_name("������", ({ "fen yan zi", "fen" }) );
        set("nickname", "����̤��");
        set("title", "���");
        set("gender", "����");
        set("age", 27);
        set("per", 30);
        set("combat_exp", 50000);
        set("long",
		"һ����Ů���̺������һ����ü�����ķۺ�ɫ����\n�ۺ�ɫ�������ԣ�б����һ֧�ۺ�ɫ�����ҡ�\n"
	);
        set("no_arrest",1);
        set_skill("move", 200);
        set_skill("dodge", 100);
        set_skill("notracesnow", 100);
        set_skill("throwing", 100);
        set_skill("feidao", 50);
	map_skill("throwing", "feidao");
	map_skill("dodge", "notracesnow");
	map_skill("move", "notracesnow");
        setup();
	biao = new(__DIR__"obj/biao");
	bag = new(__DIR__"obj/bag");
	biao->move(bag);
	bag->move(this_object());
	carry_object(__DIR__"obj/biao")->wield();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, me);
        }
}

int greeting(object who)
{
	object		env;

	env = environment();
	if(present("ye gu hong", env)) {
		say( YEL "\n�������������´�����" + who->name() + "��Ҷ�º�˵������������ҵģ��Ҳ�����������\n"NOR);
		say( YEL "\nҶ�º�����¶������Ż�µı���˵��������Ů���㶼Ҫ��\n"NOR);
		say( YEL "\n������Ц��Ц������ʱ�������㶼��Ҫ��\n\n"NOR);
	}
	return 1;
}
