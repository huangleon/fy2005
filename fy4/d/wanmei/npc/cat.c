inherit NPC;
void create()
{
    	set_name("Сè��", ({ "cat" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻСС�ģ�èͷè�Ե�С��è��\n");
    	set("combat_exp", 3000);
        set("attitude","peaceful");
        set_temp("apply/dodge", 100);
	set("chat_chance", 1);
        set("chat_msg", ({
	(: random_move :)
        }) );
        set("arrive_msg", "���˹���");
        set("leave_msg", "����������һ����������");
        setup();
}
