inherit NPC;

void create()
{
	set_name("����", ({ "bear", "big bear" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", "����һֻ�����ޱȵĳ���ɽ���ܡ�\n");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 2000000);
	
	set_temp("apply/attack", 400);
	set_temp("apply/armor", 100);
	set_temp("apply/dodge",300);
	set_temp("apply/damage", 300);
	setup();
	carry_object(__DIR__"obj/palm");
}
