inherit NPC;
#define MONEY_VALUE 100000
#include <ansi.h>

void create()
{
        set_name("���ƹ�", ({ "han zhanggui","zhanggui","han" }) );
    	set("nickname","һ���");
        set("gender", "����" );
        set("age", 54);
               
        set("long","һ�����ӣ��������������������߽���������Ҫ˵��ʲô����ͷ�Ľ������ˡ�\n");

        set("combat_exp", 10000);
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "�����ͺ�ɢ": "action���ƹ�Ī������Ц������˵������º�ҹ��ժ������ʱ�����ϡ�������\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
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
	if (!ob || environment(ob) != environment())	return 1;
		
	if (random(100)>70 )
	{
        if(NATURE_D->get_current_day_phase() == 0) 
		{
			message_vision("$N���ϸ�����һ�ֹ����Ц�ݡ�\n",this_object(),ob);
			command("whisper "+ob->query("id")+" ������һ��纫��Ҳ�Ǻڵ��ϵĽǶ���
�����ʹ��ˣ���ϴ�ֲ����ˣ�����������\n");
			command("grin");
			return 1; 
		}
		else 
		{
			command("heihei");
			command("say С�����к�Щ�ö���������ô������ʵ�ڲ����㣬��Щ
�����Ϲٲ�Ҳ�࣬��ү�������������ơ�");
			return 1;
		}
	}
	else
		return 0;
}

int accept_object(object me, object obj)
{	
	object hhs, ob1;
	
    if(NATURE_D->get_current_day_phase() < 2) 
	{ 
       	if (query("gived")) {
       		if (objectp(ob1 = query("gived_who")))
       			command("whisper "+ me->get_id() + " ���ˣ��Ѿ���"+ ob1->name(1) + "�����ˡ�\n");
       		else
       			command("say ���ˣ��Ѿ����������ˡ���\n");
       		return 0;
       	} 
       	
       	if( (int) obj->value() >= (MONEY_VALUE+ random(MONEY_VALUE)) && !query("gived"))
       	{
        	command("grin");
        	command("say ����С���������ͺ�ɢ��������Ů�Ҹ�Ҳ������޵�����\n");
       		hhs = new(__DIR__"obj/hehesan");
       		if(hhs)	hhs->move(me);
       		set("gived",1);
       		set("gived_who", me);
       		message_vision("$N�ó�"+HIY "�����ͺ�ɢ"NOR+"��$n��\n",this_object(),me);
       		return 1;       
       	}

        if( !obj->value() &&  !obj->query("value")) return 0;
        command("heihei");
        command("say ���������»��������۳����İ��������򡣡���ҩ��");
        return 0;
	}
	else
	{
		command("heihei");
        tell_object(me,"���ƹ������������˵�������˶����ӣ�������������ɡ�\n");
        return 0;
    }
	return 0;
}

