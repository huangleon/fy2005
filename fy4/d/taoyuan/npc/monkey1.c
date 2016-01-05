#include <ansi.h>

inherit NPC;
void create()
{
    	set_name("С����", ({ "monkey", "С����", "little monkey" }) );
    	set("race", "Ұ��");
    	set("age", 1);
    	set("gender", "����");
    	set("long", "С������ԲԲ�ĳ�������������´������㣬�ƺ��ڹ۲���Ķ�����
��Ҳ����Խ�С����һЩ�򵥵Ķ�������������裩\n");
    	set("attitude","peaceful");
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"С����ץ��ץͷ��\n",
    	}) );
		set("can_carry", 1);
    	set("no_heal",1);
		set("agi", 50);
		set("per",30);
		set("str",30);
		set("combat_exp", 100000);
	
		set_skill("move",500);
    	set_skill("unarmed",400);
    	set_skill("dodge",500);
      
    	setup();
}

void init() {
	add_action("do_teach", "teach");
	add_action("do_kill","kill");
	add_action("do_fight","fight");
}

int do_kill(string arg)
{
	object me;
	me = this_player();
	if (arg !="monkey" && arg !="С����") 
	{	
		return 0;
	}else
	{
		if (this_object()->query_temp("is_unconcious"))
		{
			return 0;

		}else
		{
			message_vision("$N�ӵ���ץ��һ��������$n��һ�ӣ�����һ���������ɱ���ȥ��\n",this_object(),me);
			message_vision("$N���ӵ���ͷ�������࣬�����ᣬ�������ġ�\n",me);
			destruct(this_object());
			return 1;
		}

	}
}

int do_fight(string arg)
{
	object me;
	me = this_player();
	if (arg !="monkey" && arg !="С����") 
	{	
		return 0;
	}else
	{
		if (this_object()->query_temp("is_unconcious"))
		{
			return 0;

		}else
		{
			message_vision("$N�ӵ���ץ��һ��������$n��һ�ӣ�����һ���������ɱ���ȥ��\n",this_object(),me);
			message_vision("$N���ӵ���ͷ�������࣬�����ᣬ�������ġ�\n",me);
			destruct(this_object());
			return 1;
		}

	}

}

int do_teach(string arg) {
	string action, dest, act, obj;
	object ob, me, bb;
	int	result;
	
	me = this_player();
    if(!arg) {
  		return notify_fail("��Ҫ��˭ʲ���£�\n");	
	} else if(sscanf(arg, "monkey %s monkey", action) == 1) {
		dest = "monkey";
	} else if(sscanf(arg, "monkey %s", action) == 1 ) {

    } else {
        return notify_fail("��Ҫ��˭ʲ���£�\n");	
   	}
 	sscanf(action, "%s %s", act, obj);
//    write(sprintf("action is %s \ndest is %s\n act is %s\n", action, dest, act)); 
	result = me->ccommand(sprintf("%s %s", action, dest? dest : ""));
	if(act == "kill" || act == "go" || act == "vote") {
		message_vision("$N���Ŵ����۾�������������$n���ƺ�������������ʲô��\n",this_object(),me);
		return 1;
	}
	if(result) {
	    //if(time() - query("time") > 10) 
		if ( 1== 1)
		{
	        if( act == "wield" || act == "unwield" ) 
			{
				if( !present("bamboo", this_object()) ) 
				{
	                message_vision("$Nץ�������������룬�ӹ�ľ���ó�һ����Ƭ��\n", this_object(), me);
	                bb = new(__DIR__"obj/zhupian");
	                bb->move(this_object());
	            }
	            ccommand(sprintf("%s zhu pian", act));
	            set("time", time());
	          
	        } else if (act == "eat")
	        {	
				message_vision("$N�ڹ�ľ����������һ������һ��Ұ��ҧ�˼��ڣ�������һ�ӡ�\n", this_object(), me);
	            set("time", time());
	        }else if (act == "drop")
	        {
				if( present("bamboo", this_object()) ) 
				{
					ccommand(sprintf("%s zhu pian", act));
	            }
	            set("time", time());
	        }else if (act == "drink")
	        {		
				object *list;
				int i, can_drink;
				//if ((int)this_object()->query("water") >= 380) 
				list = all_inventory(this_object());
				i = sizeof(list);
				can_drink = 0;
				while (i--) 
				{
					if ((string)list[i]->query("liquid/type") == "alcohol") 
					{
						ob = list[i];
						can_drink = 1;
					}
				}
				if (can_drink) 
				{
					command("drink "+(string)ob->query("id"));
					set("water",100);		// So it can drink more.
					if ((int)ob->query("liquid/remaining") == 0)
						command("drop " + ob->query("id"));
				}
				else 
					message_vision("$N�Ҳ��������ȣ�����ץ��������
\n", this_object());
				set("time", time());

	        }else{
	    	    ccommand(sprintf("%s %s", action, dest? me->query("id") : ""));
	            set("time", time());
	        }
	    } else {
	        message_vision("$N���ͷ�����������$nЦ��Ц��\n",this_object(), me);
	    }
	}
	return 1;
}

int accept_object(object who,object ob)
{
	
	object *list,obj;
	int i;
    list = all_inventory(this_object());
    i = sizeof(list);
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol" && (int)list[i]->query("liquid/remaining") > 0) 
		{
            obj = list[i];
        }
    }
	if (obj)
	{
		message_vision("$N�ӻ���������һ��$n��ָ��ָ��һ������֮ɫ��\n",this_object(),obj);
		return 0;
	}
	if ((string)ob->query("liquid/type"))
	{
		if ((int)ob->query("liquid/remaining") == 0) 
		{
	        message_vision("$N����$nҡ��ҡ������������һ�����˿�ȥ��\n",this_object(),ob);    
			//command("drop "+ob->query("id"));
			return 1;
		}

		if ((string)ob->query("liquid/type")!="alcohol")
		{
			
			message_vision("$N����$n�ο����ӣ������š��ܲ�м��һ�����˿�ȥ��\n",this_object(),ob);    
			//command("drop "+ob->query("id"));
			return 1;
        }
        else {
			message_vision("$N�ӹ�$n�������ᣬϲ��ץ��������\n",this_object(),ob);
            return 1;
        }

	}else return 0;
}

void die()
{
	object book;
	book = new(BOOKS"skill/animal-training_50");
	book-> move(environment(this_object()));
	message_vision("������ʲô��$N���ϵ���������\n",this_object());
	::die();	
}

