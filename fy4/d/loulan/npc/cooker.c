inherit NPC;

void create()
{
        set_name("����", ({ "cooker" }) );
        set("gender", "����" );
        set("age", 43);
        set("long", "һ�������Ͻ��ǻʹ����ŷ��Ĵ���������������ץ��¥���ع������ղˡ�\n");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        
        set_temp("apply/attack", 150);
	set_temp("apply/dodge",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"��������䤱���æ�����������㣬��ζ���硣����\n",
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
