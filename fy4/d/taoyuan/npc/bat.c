inherit NPC;

void create()
{
        set_name("��Ѫ����", ({ "bian fu" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", 
	"ר�Ŷ��ڰ�������Ѫ����\n"
	);
        set("max_kee", 150);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", }) );
        set("verbs", ({ "bite" }) );

	set("combat_exp", 500);
        set_skill("dodge", 120);


        setup();
}

