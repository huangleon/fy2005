
inherit NPC;

void create()
{
        set_name("����", ({ "insect" }) );
        set("race", "����");
        set("subrace","����");
        set("age", 1);
        set("long", "һֻ��ͷ���ԵĴ����С�\n");
        set("max_kee", 1);
        
	set("combat_exp", 3000);
        set_skill("dodge", 150);

        setup();
}

