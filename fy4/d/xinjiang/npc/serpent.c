// serpent.c

inherit NPC;

void create()
{
        set_name("�ڹھ���", ({ "serpent" }) );
        set("long", "һֻ�ں������ľ�����ͷ������һ����������\n");

        set("race", "����");
        set("age", 400);
        set("attitude", "aggressive");

        set("combat_exp", 150000);
        
        setup();
}
