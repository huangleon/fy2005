inherit NPC;

void create()
{
        set_name("��ͷ���ĸ���", ({ "guest woman","woman" }) );
        set("gender", "Ů��" );
        set("age", 33);
        set("long", "һ��������ⱦ���ĸ��ˡ�\n");
        
        set("combat_exp", 800000);
        
		set("attitude", "friendly");
        
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        
            	      
        set("chat_chance", 1);
        set("chat_msg", ({
			"�����ֹ��������Ͼ�Ҫ�����ˣ���ô���˻�û������\n",
		 }) );
        setup();
    	carry_object("/obj/armor/cloth",([	"name": "����黨��",
					"long": "Ư�����·���\n",
					 ]))->wear();    
}
