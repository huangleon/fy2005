// Moneyd.c -- by Silencer@fy4 workgroup
// I put these functions into daemon since they have more use than banker/pawner.
// Adding Creditcard to solve carry issues  1/11/2006

#include <dbase.h>
#include <ansi.h>

//   ת���� 9 ���ƽ� 9 ������ 10 ��Ǯ
string money_str(int amount) {
	string c_money;
	int i_gold, i_silver, i_coin;
	i_gold = amount / 10000;
	i_silver = (amount%10000)/100;
	i_coin = (amount%100);
	if (i_coin)
		c_money = chinese_number(i_coin) + "��Ǯ";
	else c_money = "";
	if (i_silver)
		c_money = chinese_number(i_silver) + "������" + c_money;
	if (i_gold ) 
		 c_money = chinese_number(i_gold) + "���ƽ�" + c_money;
	return c_money;
}

//   ת���� ��ʮ�������� ʮ��Ǯ
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}


//	��Ǯ --- ע�⣺5�ֻ��Ҳ��ܱ�֤����(inventory MAX_LIMIT ����)
//	flag = 1, ֧ȡ��Ǯ, flag = 0, ���� creditcard
varargs void pay_player(object who, int amount, int flag)

{
	object ob;

//	CREDIT_CARD	
	if (who->query("env/e_money")&& !flag){
		who->add("deposit",amount);
		tell_object(who,"���������ת����"+money_str(amount)+"��\n");
		return;
	}		
		
	if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}


//	CREDIT_CARD	
void  charge_him(object who, int amount){
		who->add("deposit",-amount);	
		tell_object(who,"��������˻���ת����"+ money_str(amount)+"��\n");
}

//	���� --- ͬ�ϣ����ܱ�֤һ���ɹ���
//  ������Ǵݻ����н�Ǯ��Ȼ���amount���Ľ�Ǯ������ԭ���ĸ�Ǯ��ʽ
void pay_him(object who, int amount)
{
		object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
		if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);
		pay_player(who, amount);
}


//	����Ǯô��flag = 1 ֻ�������, flag = 0 ����credit card ����
varargs int affordable(object me, int amount,int flag )
{
        int total;
        object cash, tencash, gold, silver, coin;

//	CREDIT_CARD        
        if (me->query("env/e_money") && !flag){
        	total = me->query("deposit");
        	if (total < amount)	return 0;
        	return total;
    	}
        
        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);
        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();
        if( total < amount ) return 0;
        return total;
}

//	������Ʒ��⣬�����Ժ���������ܡ�
void arresthim(object me)
{
	object *inv;
	object npc;
	if (objectp(me))
	{
//		message_vision("$NͻȻ��Ц���������ǶԲ�����λ"+RANK_D->query_respect(me)+"�ˣ����Ķ����ٲ���Ҫ��顣��\n\n", npc);
		message_vision(HIR"�������������������$N��Ц����������þ��ˣ���ү����һ�˰ɡ���\n\n"NOR, me);
		tell_object(me,YEL"�����д������ɺ����̫�١�\n");
		message_vision("�����$N��Ц����������������׷��С͵�Ѿ��ܾ��ˣ��ԹԸ������߰ɣ��� \n",me);
		message_vision("���콫$NѺ����Ρ� \n\n"NOR,me);
		me->set("vendetta/authority", 1);
		me->move("/d/jinan/laofang1");
		message_vision(HIY"\n$N���ѿ����еĶ�����һ���߽����η���\n"NOR,me);
		inv = all_inventory(me);
		for(int i=0; i<sizeof(inv); i++) 
		{
			if (inv[i]->query("id")=="treasure box")	
				inv[i]->do_qqsave(me);
        	else if (!inv[i]->query("no_drop"))
        		destruct(inv[i]);
		}
	}
	return;
}
