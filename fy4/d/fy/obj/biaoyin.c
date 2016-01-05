
#include <ansi.h>
inherit MONEY;
void create()
{
	//set_name("����", ({"silver", "ingot", "silver_money"}));
	set_name("����", ({"biaoyin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "�׻��������ӣ��˼��˰������ӡ�\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 37);
		set("illegal",1);
	}
	set_amount(1);
}

void init()
{
	
	add_action("do_deposit","deposit");
	add_action("do_buy","buy");

}

int check_money(object me)
{
	object cash, tencash, gold, silver, coin;
	
	tencash = present("tenthousand-cash_money", me);
	cash = present("thousand-cash_money", me);
	gold = present("gold_money",me);
	silver = present("silver_money",me);
	coin = present("coin_money",me);

	if ( tencash || cash || gold || silver || coin )
		return 1;
	else
		return 0;

}

int do_buy(string arg)
{
	object me;
	string item, targ;
	object ob, owner;
	me = this_player();
	if (!present(this_object(),me))
	{
		return 0;
	}
	if( me->is_busy() || !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("ָ���ʽ��buy <ĳ��> from <ĳ��>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("��Ҫ��˭������\n");

	if (!check_money(me))
	{
		tell_object(me,"��Щ�����Ǽ����ù�ģ����ܾ���ô�ó��������� \n");
		return 1;
	}
	return 0;
}


int do_deposit(string arg)
{
	object me,bankowner;
	object bukuai1,bukuai2,*inv;
	int amount,i;
	string type;
	me = this_player();
	if (!present(this_object(),me))
	{
		return 0;
	}
	if (present("shiyi",environment(me)))
	{
		bankowner = present("shiyi",environment(me));
	}
	if (present("nangong",environment(me)))
	{
		bankowner = present("nangong",environment(me));
	}

	if (present("ying",environment(me)))
	{
		bankowner = present("shiyi",environment(me));
	}

	if (bankowner)

	{
		if(!arg || sscanf(arg, "%d %s", amount, type)!=2 ) {
			return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
		}
		if(amount <= 0) {
			return notify_fail("ָ���ʽ��deposit <����> <��������>\n");
		}
		if (type == "biaoyin")
		{
			message_vision("$n����$N������������Ȼ̧ͷ��$NЦ������λ"+ RANK_D->query_respect(me) + "���е����\n",me,bankowner);
			message_vision("$n�������������֡� \n",me,bankowner);
//			bukuai1 = new("/d/fy/npc/bukuai");
//			bukuai2 = new("/d/fy/npc/bukuai");
//			bukuai1->move(environment(me));
//			bukuai2->move(environment(me));
			message_vision(HIR"\nͻȻ�Ӱ������������������$N�µ������ҽ��������������������þ��ˣ�\n"NOR, me);
			message_vision(HIR"�����$N��Ц����������߾�񣬹ԹԸ������߰ɣ� \n"NOR,me);
			message_vision(HIR"���콫$NѺ����Ρ� \n\n"NOR,me);
//			destruct(bukuai1);
//			destruct(bukuai2);
			me->set("vendetta/authority", 1);
			me->move("/d/jinan/laofang2");
			message_vision(HIY"$N���ѿ����еĶ�����һ���߽����η���\n"NOR,me);
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++) 
			{
                if (inv[i] != this_object())
                {
					if (inv[i]->query("id")=="treasure box")	
						inv[i]->do_qqsave(me);
                	else if (!inv[i]->query("no_drop"))
                		destruct(inv[i]);
                }

			}
			destruct(this_object());
			return 1;
		}
	}
	return 0;
	
}
