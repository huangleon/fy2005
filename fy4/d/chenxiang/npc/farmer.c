// farmer.c

inherit NPC;

void create()
{
	set_name("ũ��", ({ "farmer" }) );
	set("gender", "����" );
	set("age", 33);
	set("long", "һλ�Ը���ˮ��Ϊ����ũ�����ų��صĲ�������������ĺ�ˮ�����л�����\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
			(: random_move :)
        }) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
