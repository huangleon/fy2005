inherit NPC;

void create()
{
	set_name("����Ȯ", ({ "shepherd dog", "dog" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", "����һֻ���ز�������Ȯ������ʵ�ؿ�������Ⱥ��\n");
	
	set("agi",60);
	
	set("attitude", "friendly");

	set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "����Ȯ�����ؽ��˼���������������ܿ��˼��ۡ�\n"
        }) );
	set("combat_exp", 2000000);
		
	set_temp("apply/attack", 300);
	set_temp("apply/dodge",280);
	set_temp("apply/move",320);
	set_temp("apply/damage",50);
	set_temp("apply/armor", 120);

	setup();
}
