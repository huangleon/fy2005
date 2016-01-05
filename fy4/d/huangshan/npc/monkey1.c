#include <ansi.h>

inherit NPC;
void create()
{
    set_name("�����", ({ "monkey"}) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "һֻ��������Ĵ��������������ؿ����㡣\n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��" }) );
    set("chat_msg", ({
        "�����ץ��ץͷ��\n",
    }) );
	set_skill("move",500);
    	set_skill("unarmed",600);
    	set_skill("dodge",600);
    	set("combat_exp", 2000000);
    	set("verbs", ({ "bite","claw" }) );
    	setup();
	
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int havenothingon(object ob)
{  
	object *inv;
	inv = all_inventory(ob);
	if (sizeof(inv)==0) 
		return 1;
	else
		return 0;
}

void greeting(object ob)
{
        object *tar;
        object obj;
        int i,size;
		
	if( !ob || !visible(ob) || environment(ob) != environment() ) 
		return;
	if( ob->query("combat_exp")<30000 ) 
		return;
	
	tar = all_inventory(ob);
	size=sizeof(tar);
	
	if(!havenothingon(ob))
	{
		if (random(100)<10)
		{
			i=random(size);
			obj=tar[i];
			if(!(int)obj->query("no_get") && !(int)obj->query("equipped") && !(int)obj->query("no_drop"))
			{
				obj->move(this_object());        	
				tell_object(ob, "�����ವ�һ�´���ͷ��������������������\n");
	      			tell_object(ob, "��о�����һ�ᣬ�ƺ�����ʲô����������������\n");
	      			message("vision", "�㿴��" + this_object()->name() + "�������ش�" + ob->name() + "����������һ" + obj->query("unit") 
	      			+ obj->name() + "��\n", environment(ob), ({ this_object(), ob }) );
	      			return;
	      		}
	      		else
	      		{
	      			tell_object(ob, "�����"+this_object()->name()+"�������Ķ����㣮������������\n");
	      			tell_object(ob, "��������߾�����С������Ŀ������Լ��Ĺ�����Ʒ��������������\n");
	      			return;
	      		}
      		}
      		else
      		{
                say( "�����֨֨�ؽ��˼�����\n");
			return;
		}
      	}
      	else
        {
        	say( "���������ʧ���ؿ����㼸��.\n");
		return;
	}
}