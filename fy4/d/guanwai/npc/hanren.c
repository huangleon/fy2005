
inherit NPC;

void create()
{
	set_name("����", ({ "hanren"}) );
	set("gender", "����" );
	set("age", 45);
	set("str", 10);
	set("long", 
"һ������糾��Զ�����ĺ��ˡ�\n"
);
	set("attitude", "peaceful");
        set("title", "�����");
        set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	map_skill("unarmed", "bloodystrike");
	set_skill("iron-cloth", 10);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "���˲��������ĳ��������ˣ����ˣ�������������Ϳ��Իؽ����ˡ���\n",
        }) );

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
 
}
