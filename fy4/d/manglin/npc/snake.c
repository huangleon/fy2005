
inherit NPC;

void create()
{
        set_name("�ϰ߾���", ({ "snake" }) );
        set("race", "����");
        set("age", 15);
        set("long", "һ��ˮͰ��ϸ�ľ�����\n");

        
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", 999999);
        set("agi", 10 );
	
	set("bellicosity", 30000 );
	set_temp("apply/attack",200);
	set_temp("apply/damage",150);
        setup();
}
