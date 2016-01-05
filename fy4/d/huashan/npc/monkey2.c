#include <ansi.h>

inherit NPC;
void create()
{
    set_name("С�ֺ�", ({ "monkey"}) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "һֻ���������С�ֺ�������صؿ����㡣\n");
    set("attitude","peaceful");
    set("chat_msg", ({
        "С�ֺ�������ϵ��������������ͷ���ϻ�����ȥ��\n",
    }) );
	set("agi", 60);
	
	set_skill("move",50);
    	set_skill("unarmed",100);
    	set_skill("dodge",50);
    	set("combat_exp", 80000);
	set("max_gin", 500);
    	set("max_kee", 500);
    	set("max_sen", 5000);
    	set("eff_gin", 500);
    	set("eff_kee", 500);
	set("eff_sen", 5000);
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

	if( ob->query("combat_exp")<10000 ) 
		return;
	if( !ob || !visible(ob) || environment(ob) != environment() ) 
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
				tell_object(ob, "С�ֺ�ವ�һ�´���ͷ��������������������\n");
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
                say( "С�ֺ�֨֨�ؽ��˼�����\n");
			return;
		}
      	}
      	else
        {
        	say( "С�ֺ�����ʧ���ؿ����㼸��.\n");
		return;
	}
}