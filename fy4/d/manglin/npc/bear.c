
inherit NPC;

void create()
{
	set_name("�׾�����", ({ "bear", "big bear" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", "����һֻ�����ޱȵĻ��ܡ�\n");
	
	set("attitude", "aggressive");

	set("combat_exp", 900000);
	set("bellicosity", 3000 );
	set("agi", 10 );	
	set_temp("apply/attack", 100);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 100);
	setup();
}
