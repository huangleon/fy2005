
inherit NPC;

void create()
{
        set_name("������", ({ "rat" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��ͷ���ԵĴ�����\n");
        set("max_kee", 1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 80);
	set("combat_exp", 3000);
        setup();
}

