inherit NPC;

void create()
{
        set_name("����", ({ "examinee","student"}) );
        set("gender", "����" );
        set("age", 12+ random(10));
        set("attitude", "friendly");
        set("long", "����һλ���ڿ��ԵĿ�����\n");
                
        set("combat_exp", 50000);
        
        set_skill("dodge", 100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����̧��ͷ����������һ�ۣ�����\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

