
inherit NPC;

void create()
{
	set_name("������", ({ "bhutanese"}) );
	set("gender", "Ů��" );
	set("age", 25);
	set("str", 10);
	set("long", "һ��ϲ�������Ĳ��������ˡ�\n");
	set("attitude", "peaceful");
        set("title", "�����");
        set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	set_skill("iron-cloth", random(30)+10);
        map_skill("unarmed", "bloodystrike");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "\n��������̾��������������ʫ��������˹�͵�һ��ʫô���Ǽ�򵥵�\n��ʮ�ĸ��ְ��������ж��ǵ���Ѫһ��������ܡ�\n",
        }) );

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
}
