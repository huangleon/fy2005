inherit NPC;

void create()
{
        set_name("��������", ({ "naked man","man" }) );
        set("title","��������");  
        set("gender", "����" );
        set("age", 28);
        set("per", 30);
        set("long","����һλ����ϴ����������ˣ����׳������ļ��������������·��Ա�һ�㡣\n");

        set("combat_exp", 1200000);
        set("score", 50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("meihua-shou", 10);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");
		setup();
}

