
inherit NPC;

void create()
{
        set_name("������", ({ "laowuren"}) );
        set("gender", "����" );
        set("age", 32+ random(10));
        set("long", "����һλ�þ������յı����ˡ�\n");
        set("combat_exp", 5000);
        set_skill("unarmed", 30 + random(100));
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������˴걻�����˫�֡�\n",
        }) );
	setup();
        carry_object(__DIR__"obj/bigcloth")->wear();
}

