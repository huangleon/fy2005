inherit NPC;

void do_drink();

void create()
{
        seteuid(getuid());
        set_name("������", ({"jiang", "jiang chongwei"}));
        set("long","
���������ǳ�͢�س������Դӻ��͹�Ʒ���廨������٣�˫Ŀ�ֱ����
Ϲ�󣬱����սӾ����һ�겻��������ʧ��ٳ�����֮ͬ��������
��˰����������µ�ʦү��ƽ��Ҳûʲô�¡�\n");
        set("title", "����ʦү");
        set("gender","����");
        set("age", 50);
        
        set("max_atman", 1000);
        set("atman", 1000);
        
        set("combat_exp", 999999);
        set("fly_target",1);
        
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 150);
        set_skill("fall-steps", 150);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

        set("chat_chance",1);
        set("chat_msg", ({
        	"������Ϲ�˵��۾��ն��޹⣬������ơ����ơ�������Ҫ�Ⱦơ��� \n",
			"������һ��ץס��ȹ�ľ�ƿ���ƺ�Ҫ�����һ�ξơ�\n",
        	"��������������������Ϊ��ƶ�����ı��ӡ�\n",
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
    object obj;
    if ((string)ob->query("liquid/type")=="alcohol") 
    {
        if ((int)ob->query("liquid/remaining") == 0) 
        {
            command("shake");
            command("say �յ��Ҳ�Ҫ...");
            return 0;
        }
        else if ((int)ob->query("value")<100)
        {
                message_vision("$Nɨ��һ��$n���е�"+ob->query("name")+"��\n���˾䣺�Һô�Ҳ������֪��ʦү�������ܺ����ֶ���������\n",this_object(),who);
		return 0;
      	}
       	else 
       	{
        	message_vision("$Nһ��ץ��$n���е�"+ob->query("name")+"��һ��������������ͷ��������񫣬����񫣬����������������\n",this_object(),who);
       		this_object()->add("drink_wine",1);
       		if (this_object()->query("drink_wine")==10)
       		{
        		message_vision("$N�������ʣ���������ƴ�������࣬ȴһ�����ģ�ˤ���ڵء� \n",this_object());
				message_vision("һ���ĵ���$N��������������� \n",this_object());
				obj = new(__DIR__"obj/miling");
				obj->move(environment(this_object()));
				delete("drink_wine");
        	}
        	return 1;
	}
    }
    else
    	return 0;
}

