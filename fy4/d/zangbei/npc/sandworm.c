
inherit NPC;

void create()
{
        set_name("ɳ��", ({ "sandworm" }) );
        set("race", "����");
        set("age", 15);
        set("long", "һ��ˮͰ��ϸ��ɳ�棬����һ�ɶ೤���Ŵ���Ѫ��������������\n");

        
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", 200000);
	set("bellicosity", 30000 );
	set("str",80);
	set_temp("apply/attack",400);
	set_temp("apply/dodge",400);
	set_temp("apply/damage",150);
        setup();
        carry_object(__DIR__"obj/liver");
}
