/*  Modified by Silencer 3/07/2003
	1.added numerous notify_fail messages, 
	2.do_drop or fly will always clear conditoin,
	3. No more unnecessary hawk-trainer kill,
*/

#include <ansi.h>
#include <globals.h>
inherit NPC;
string player_env(object target, object me);

//void eatMeat(object ob);
void create()
{
    	set_name(HIC"��ӥ"NOR, ({ "big hawk","hawk" }) );
    	set("race", "����");
    	set("age", 1);
    	set("gender", "����");
    	set("long","
һֻ������צ�Ĳ�ӥ����һ˫�����������۾��������㿴�����ް������
֮�⣬�е������ȥץ����(catch)��������Ҳ��������ιʳ��(feed)��\n");
    	set("attitude","peaceful");
    
		set("weight", 3000);
		set("agi", 40);
		set("per",30);
		set("str",100);

		set("resistance/kee",100);
		set("resistance/gin",100);
		set("resistance/sen",100);
		
		set_skill("move",800);
    	set_skill("unarmed",800);
    	set_skill("dodge",800);
    	
    	set("combat_exp", 7000000);
  
		set("marks/chained",1);
		set("marks/trained",0);
		set("no_give", 1);
		setup();
}


void init() 
{
	::init();
	add_action("do_catch", "catch");
	add_action("do_feed","feed");
	add_action("do_chain",({"chain","tie"}));
	add_action("do_drop","drop");
}


int checkChained()
{
	
	object hawk;
	hawk = this_object();
	if (hawk->query("marks/chained"))
	{
		object room;
		room = find_object("/d/huashan/fupi");
		if(environment() == room && room->query("item_desc") == 0)
		{
			room->set("item_desc", ([
			"chain": "һ��ϵӥ�õ�ϸϸ�ĺ�ɫ�������ƺ������������ġ�\n �����룬��֪����������Կ�������Ҳ�����ʲô���Կ���(chop)���� \n",
			"����":"һ��ϵӥ�õ�ϸϸ�ĺ�ɫ�������ƺ������������ġ� \n �����룬��֪����������Կ�������Ҳ�����ʲô���Կ���(chop)����\n",
			]) );
		}
		//return notify_fail("��ӥ�Ľ��ϻ�ϵ�������أ� \n");
		return 1;
	}
	return 0;
}


int do_catch(string arg) 
{
	object me, hawk, chain, *inv;
	object hawktrainer;
	int i;
	me = this_player();
	hawk=this_object();
	if(!arg) 
	{
		return notify_fail("����ץʲô��\n");
	}
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
		
	if(arg != "hawk" && arg != "��ӥ" && arg!= "big hawk") 
	{
		return notify_fail("���������ץ��ס��\n");
	}
	
	if(!present(hawk, environment(me)))
	{
        	return notify_fail("���û�в�ӥ��\n");
    	}
	
	if( hawk->query("marks/trained"))
	{
        	return notify_fail("��ӥ�Ѿ����㸩�������ˡ�\n");
    	}
    	
	
	if (hawktrainer=present("trainer",environment(hawk)))
	{
		message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       hawktrainer,this_player());
        	hawktrainer->ccommand("kick "+me->get_id());
        	me->perform_busy(1);
        	return 1;
	}
	if (checkChained())
	{
		return notify_fail("��ӥ�Ľ��ϻ�ϵ�������أ� \n");
	}
	
	if (random(4))
	{
		message_vision(HIW"��ӥһ�����У�����$N��Ҫ������\n"NOR,me);
	}
	else
	{
		message_vision(HIR"��ӥһ�ĳ���������һ˫��צץ��$N��ǰ��\n"NOR,me);
		inv = all_inventory(me);
		for (i=0;i<sizeof(inv);i++ )
		{
			//write (inv[i]->name()+":"+inv[i]->query("equipped")+"\n");
			if (objectp(inv[i]) && (inv[i]->name()==YEL"����"NOR) && (inv[i]->query("equipped")=="worn"))
			{
				message_vision(HIW"��ӥ��˫צž�ػ���$N�������ϣ����հ������� \n"NOR,me);
				return 1;
			}
		}		
		tell_object(me, HIR"��˫��һ���ʹ�� \n �����ǰһƬ��ڡ����� \n"NOR);
//		me->add_temp("block_msg/all", 1);	-- too many loopholes.
	}
	me->perform_busy(1);
	return 1;
}


void eatMeat(object me)
{
	int avai,remain;
	object hawk,wolfmeat;
	hawk = this_object();
	call_out("eatMeat",20,me);
	if (!present(hawk,me))
	{
		remove_call_out("eatMeat");
		me->change_condition_duration("hawk_claw",0);
		message_vision("$N��Хһ�����򳤿շ�ȥ��\n",hawk);
		destruct(hawk);
	}
	if (wolfmeat = present("wolfmeat",me))
	{
		remain = (int)wolfmeat->query("food_remaining") * (int)wolfmeat->query("food_supply");
		avai = 100;
		//avai = (int)hawk->max_food_capacity() - (int)hawk->query("food");
		//make avai a certain amount to make hawk eat faster
		if( remain > avai )
		{
			add("food_remaining", -(avai/(int)wolfmeat->query("food_supply")));
		}
		else
		{
			//hawk->add("food",remain);
			wolfmeat->set("food_remaining", 0);
		}
			wolfmeat->set("value", 0);
			if( !wolfmeat->query("food_remaining") ) 
			{
				//meat is gone
				message_vision("$N��ʣ�µ�" + name() + "�Ե�ǬǬ������\n", hawk);
				if( !wolfmeat->finish_eat() )
					destruct(wolfmeat);
				message_vision("$N����$n���е��⣬��������з�ȥ��\n",hawk,me);
				me->change_condition_duration("hawk_claw",0);
				remove_call_out("eatMeat");
				destruct(hawk);
			}
			else 
				message_vision("$N����$nҧ�˼��ڡ�\n", hawk,wolfmeat);
	}
	else
	{
		//dunno why have to do this
		message_vision("$n���е��ⱻ�����ˣ�$N��������з�ȥ��\n",hawk,me);
		me->change_condition_duration("hawk_claw",0);
		remove_call_out("eatMeat");
		destruct(hawk);
	}
	return ;
}


int do_drop(string arg)
{
	object me,hawk;
	hawk = this_object();
	me = this_player();
	
	if (arg != "hawk" && arg !="��ӥ")
	{
		return 0;
	}
	//seems no need to check so many status, just for caution
	if(!present(hawk, me) || hawk->query("marks/owner"))
	{
		return 0;
	}
	me->change_condition_duration("hawk_claw",0);
	remove_call_out("eatMeat");
	if (hawk->query("marks/feeding"))
	{
		message_vision("$N�ֱ۳�ʹ����������ӥ����������\n",me);
	}
	message_vision("��ӥ�ڿ���������Ȧ�������ȥ��\n",me);
	destruct(hawk);
	return 1;
}
     
int do_feed(string arg)
{
	object me;
	object wolfmeat,leathersleeves,hawktrainer;
	object hawk;
	string argmeat, arghawk;
	hawk = this_object();
	me = this_player();
	if(!(present(hawk, environment(me))) || hawk->query("marks/trained"))
	{
        	return 0;
    	}
	if(!arg) 
	{
		return notify_fail("��Ҫι˭ʲ�ᶫ����(feed ĳ�� to ĳ��)\n");
    	}
    	if(sscanf(arg, "%s to %s", argmeat, arghawk)==2 || sscanf(arg, "%s %s", arghawk, argmeat)==2 );
    	else 
	{
		return notify_fail("��Ҫι˭ʲ�ᶫ����(feed ĳ�� to ĳ��)\n");
    	}
    
	if (arghawk != "hawk" && arghawk != "��ӥ" && arghawk != "big hawk")
	{
		return notify_fail("�㲻��ι"+arghawk+"��\n");
	}
	
	if (argmeat =="wolf meat" && arg ==YEL"���⸬"NOR)
	{
		return notify_fail("��ӥ���������"+argmeat+"�ƺ�ûʲô��Ȥ���������͵Ķ����ɡ�\n");
	}
	
	if (argmeat !="wolfmeat" && arg !="���⸬")
	{
		return notify_fail("��ӥ���������"+argmeat+"�ƺ�ûʲô��Ȥ���������͵Ķ����ɡ�\n");
	}
	
	if (!wolfmeat=present("wolfmeat",me))
	{	
		return notify_fail("������û�����⸬��\n");
	}
	
	if (!wolfmeat->query("hawk_food"))
	{
		return notify_fail("��ӥ��������⸬���˿����ƺ�ûʲô��Ȥ��Ҳ����ֻ�����ĸ���Ȥ��\n");
	}
	
	if (checkChained())
	{
		return notify_fail("��ӥ�Ľ��ϻ�ϵ�������أ����ܷɹ������⣡\n");
	}
	
	if (hawktrainer = present("hawk trainer",this_object()))
	{

        	message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       hawktrainer,me);
        	hawktrainer->ccommand("kick "+me->get_id());
        	me->perform_busy(1);
        	return 1;
    	}
	
	message_vision("$N�����ó����⸬������ӥ��\n ",me);
	if (random(10) && me->query("kar")<=20)
	{
		message_vision("��ӥ���ɲ����ؿ���$N��\n" ,me);
		return 1;
	}
	if (hawk->move(me))
	{
		message_vision("��ӥ����$N���ֱۣ���$N���������⸬����������\n",me);
		if (!leathersleeves=present("leather sleeves",me))
		{
			me->apply_condition("hawk_claw",10);
		}
		hawk->set("marks/feeding",1);
		call_out("eatMeat",10,me);
	}
	else
	{
		tell_object(me,"�������޷����ܲ�ӥ��������\n");
	}
	return 1;
}

int do_chain(string arg)
{
	object hawk, me,chain, new_hawk;
	hawk = this_object();
	me = this_player();
	
	
	if (arg != "hawk" && arg !="��ӥ" && arg!= "big hawk")
	{
		return notify_fail("��û��˩ס���������\n");
	}
	
	if (!chain = present("chain",me))
	{
		return notify_fail("������û����������\n");
	}
	
	if (!present(hawk, me))
		return notify_fail("��ӥ���������ϡ�\n");
		
	if (!hawk->query("marks/feeding"))
		return notify_fail("��ӥ����ؿ����㣬���æ����������\n");
	
	if (me->query_condition("hawk_claw"))
		return notify_fail("������Ѫ��ֹ��˩ס��ӥ������ˣ����ǿ�������°�(drop)��\n");
	
	message_vision("$N��$næ�ų����⸬������ذ�һ��С����ϵ�������ϡ�\n",me,hawk);
	destruct(chain);
	
	hawk->set("marks/feeding",0);
	remove_call_out("eatMeat");
	
	//now we can stick a new hawk with the player
		
	new_hawk = new(__DIR__"hawk_trained");
	new_hawk->set("marks/owner",me->name());
	if	(!new_hawk->move(me))
		message_vision("$n�����˾���һչ��������գ�ת�ۼ���ʧ�ڰ��Ƽ䡣\n",me,hawk);
		
	destruct(hawk);	
	return 1;

}
