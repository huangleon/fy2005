#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��С��", ({ "qi xiaoyan", "qi" }) );
        set("long",
                "һ���������ݰ��࣬����ֱ���ġ�С�к�����\n");
        set("gender", "Ů��" );
        set("age", 19);
        set("title", HIR"������"NOR);
        set("chat_chance",1);
	set("chat_msg",	({
			"��С�ཹ���ص��������İ���С��ȸ�����ˣ����ܰ��Ҵ�����ô��\n",
	})  );
        set("per", 30);
        
        set("combat_exp", 500000);
		
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("sword",100);
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{	
	object sheepskin;
	
	if ( ob->query("name")=="��������" && ob->query("skylark") )
	{ 
		write("��С�ࡰ����һ�����˵�����������æ�����л�������ˣ����㱾��\n����񵽵���Ƥʫ����\n");
		sheepskin = new(__DIR__"obj/sheepskin");
            	sheepskin->move(who);
            	call_out("tell_secret", 3, who);
		return 1;
	}
	if ( ob->query("name")=="��������" && !ob->query("skylark") )
	{
		write("��С��������ͨ�죬ʹ��������һ�ۣ��Ҳ����ҵ���Ͱ��ˣ����ÿ�\n����ƭ�ң��󻵵���\n");
		return 1;
       	}
	message_vision("$N���˿�$n��������˵���������ҵ�С��ȸ��ʲô����Ҫ����\n",this_object(),who);
	return 0;
}

void tell_secret(object me)
{
	object obj;
	obj = this_object();
	me->set_temp("marks/guanwai_knowsecret",1);
	message_vision("$N�ֽ����գ��գ�ۣ��������ǽ�������ɲ��Ů�������ģ�swear����\n�Ҿ��ٸ�����һ�����ܡ���\n",obj);
	return ;
}
