// lady.c

inherit NPC;

void create()
{
        set_name("ǧ��С��", ({ "lady" }) );
        set("long", "һ�����λ����ĸ��������������ϵ�Ĥ������\n");
        set("age", 32);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 3000);

        setup();
        carry_object(__DIR__"obj/lady_dress")->wear();
        carry_object(__DIR__"obj/silver_clasp")->wear();

}
