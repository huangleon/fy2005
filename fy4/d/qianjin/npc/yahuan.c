// worker.c

inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "yahuan", "ya" }) );
        set("gender", "Ů��" );
        set("age", 11);
        set("long", "����ɰ���Ѿ�������໥��ͷ����˽� \n");
        set("combat_exp", 6700);
        set("attitude", "friendly");
        set_skill("unarmed", 10);
        set("chat_chance", 10);
        set("chat_msg", ({
			"һ��Ѿ��ߴߴ�����ĸ�����һ��Ѿ�����������˸����ˣ������ϰ˸����һ��һ����赣�\n",
			"һ��Ѿ��ߴߴ�����ĸ�����һ��Ѿ������˵ʲô��赺�һ�������޵У�\n",
        }) );

	setup();
        carry_object(__DIR__"obj/wch_skirt")->wear();
        carry_object(__DIR__"obj/clothtwo");
}

