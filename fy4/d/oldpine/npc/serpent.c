// serpent.c

inherit NPC;

void create()
{
        set_name("��ھ���", ({ "serpent" }) );
        set("long", "һֻ�ں������ľ�����ͷ������һ��ͨ��Ĵ�������\n");

        set("race", "����");
        set("age", 400);
        set("attitude", "aggressive");

        
        set("cor", 70);
        set("int", 10);

        set_temp("apply/attack", 350);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 300);
        set_temp("apply/dodge",300);

        set("combat_exp", 2000000);
        
        setup();
}
