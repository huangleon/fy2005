inherit NPC;

void create()
{
        set_name("���ͷ��ı���", ({ "guest man","man" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ�����Ż����ı��͡�\n");
        
        set("combat_exp", 1000000);
        
		set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
                
        set("chat_chance", 1);
        set("chat_msg", ({
			"���ͽе��������ӡ������������\n",
		 }) );
        setup();
    	carry_object("/obj/armor/cloth",([	"name": "�Ϻõĳ���",
					"long": "Ư�����·���\n",
					 ]))->wear();    
}
