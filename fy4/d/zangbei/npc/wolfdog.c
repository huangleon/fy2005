
inherit NPC;

void create()
{
        set_name("����", ({ "wolfdog" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10);
        set("long", "����һֻ��������������ޱȵ���Ȯ��Ƥ����������ޱȡ�\n");
        
   //     set("str", 50);
        
        set("attitude", "friendly");

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "��������ű�ת��תȥ���þ����Ŀ��������㡣\n"
        }) );
        set("combat_exp", 1200000);
                
        set_temp("apply/attack", 250);
        set_temp("apply/dodge",200);
        set_temp("apply/move",320);
        set_temp("apply/armor",100);
        set_temp("apply/damage",30);
        
        setup();
}
