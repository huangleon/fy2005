inherit NPC;
int tell_him();
void create()
{
        set_name("����ʦ", ({ "biaoshi wang","wang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "�����ĸ��Ӳ��ߵ�һ������ӣ��൱�ؾ����ܸɡ�\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
        
        set_skill("hammer", 150);
	set_skill("dodge", 150);
        set_skill("iron-cloth", 200);
        set_skill("parry",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ʦ����ʲô����ϳ�ʮ���ļ�Ǯ��\n",
                "����ʦ����ֱ��ţ��ұ�ƭ�ˣ�\n",
        }) );
    	set("inquiry", ([
	        "sword" : (: tell_him :),
	        "����" : (: tell_him:),
	        "�з�����" : (: tell_him:),
        ]));
	
	setup();
	
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

int tell_him()
{
    	object me;
    	me =this_player();
	
		if (REWARD_D->riddle_check(me,"ʧ���粨")==1 
			|| REWARD_D->riddle_check(me,"ʧ���粨")==2) {
			tell_object(me,"�������������㶼֪���ˣ����Ѿ��������ˣ������Ǹ������İ������ˣ�\n");
			REWARD_D->riddle_set(me,"ʧ���粨",2);
		}else{
    		message_vision("$N�������Ϲ�£�û�е��£�\n",this_object());		
		}
    	return 1;
}
