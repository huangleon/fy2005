
inherit NPC;

void create()
{
        set_name("����������", ({ "tangzi shou", "tangzi"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ��ʨ�ھֵ������֡�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("unarmed", 10+random(50));
	set_skill("dodge", 10 + random(50));
	set_skill("move",200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������վ���������£�����ܲ��ͷ���\n",
		"�����ֵ����ֹ�������ô������ֻ��һ���˿��أ�̫�������ˣ���\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	if (!random(2))
	carry_object(__DIR__"obj/huopiao");

}

