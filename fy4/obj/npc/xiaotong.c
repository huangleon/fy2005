// teacher.c

inherit NPC;

void create()
{
        int i,amun;
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��",
"��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "��"});
	string *orderr = ({"����", "����", "�Թ�", "СС", "����",
"����", "ѻѻ", "����"});
        set_name( order[random(20)] + orderr[random(8)], ({ "kid", "small kid" }) );
	set("title", "��֪Сͯ");
	set("gender", "����" );
	set("age", random(5)+4);
	set("int", 26);
	set("long",
		"����С, �ܺ��۸���\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

	set("attitude", "peaceful");
	set("combat_exp", random(5));
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
