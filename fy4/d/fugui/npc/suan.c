// suan.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��÷��", ({ "suanmei tang","tang" }) );
        set("gender", "Ů��" );
//		set("vendetta_mark","fugui");
        set("age", 24);
        set("no_arrest",1);
        set("long",
"��÷���ǵ�Ư��������Ư�����ˡ������ϴ�����Ȼ�Ǽ��ֲ��·�������
��ʲô�·����������ϣ������úܺÿ���\n\n");

        set("combat_exp", 500000);
        set("attitude", "friendly");
                
        set_skill("sword", 100);
        set_skill("move", 100);
        set_skill("snowshade-sword", 120);
        set_skill("force", 100);
		set_skill("notracesnow",100);
		set_skill("dodge",120);
		set_skill("parry",120);
		set_skill("gouyee",100);
        map_skill("sword", "snowshade-sword");
        map_skill("parry", "snowshade-sword");
        map_skill("dodge", "notracesnow");
        map_skill("move", "notracesnow");
        map_skill("force", "gouyee");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.baixueaiai" :),
        }) );
	
		set("chat_chance",2);
        set("chat_msg", ({
        "��÷���ƺ����Ĵ�Ѱ����Щʲô���������������֣�ǰЩ������\n�������Ǽ���Ʊ�������񷿵�ѽ����\n\n",
                                })  );
        setup();
        carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void init()
{
        object  ob;
        ::init();
        ob = this_player();
		call_out("greeting", 1, ob);       
}


int greeting(object ob)
{
	if (!ob || environment(ob)!= environment(this_object()))	return 1;
		
	message_vision("$N����üͷ�������ӵ�������Թ���������Ҳʵ���ൽ���ˣ�
Ŷ���鷳��λ"+RANK_D->query_respect(ob)+"���Ҵ�ɨһ��,��ô����\n",this_object());
	return 1;
}