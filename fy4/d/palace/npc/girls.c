// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
	int i,amun;
	string *name= ({"С��", "ĵ��", "����", "õ��", "�ž�"});
	set_name( name[random(5)] , ({ "pretty girl", "girl" }) );
	set("long", "����һλ�����ȵ�СѾͷ\n");
	set("attitude", "friendly");

	set("age", 13);
        set("gender", "Ů��" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "СѾͷ���Ե�����˵Ҫ��������ʱ�����������ſϣ�\n",
        }) );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp",50000);
	set_skill("throwing",300);
	set_skill("dodge", 50+random(50));

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/anqi")->wield();
}
