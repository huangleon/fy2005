// buy.c
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string item, targ;
	object ob, owner;
	int price, afford, change;
	if( arg ) {
		//-> Added by neon :P	
	    	arg = replace_string(arg, "$BLK$", BLK);
	    	arg = replace_string(arg, "$RED$", RED);
	    	arg = replace_string(arg, "$GRN$", GRN);
	    	arg = replace_string(arg, "$YEL$", YEL);
	    	arg = replace_string(arg, "$BLU$", BLU);
	    	arg = replace_string(arg, "$MAG$", MAG);
	    	arg = replace_string(arg, "$CYN$", CYN);
	    	arg = replace_string(arg, "$WHT$", WHT);
	    	arg = replace_string(arg, "$HIR$", HIR);
	    	arg = replace_string(arg, "$HIG$", HIG);
	    	arg = replace_string(arg, "$HIY$", HIY);
	    	arg = replace_string(arg, "$HIB$", HIB);
	    	arg = replace_string(arg, "$HIM$", HIM);
	    	arg = replace_string(arg, "$HIC$", HIC);
	    	arg = replace_string(arg, "$HIW$", HIW);
	    	arg = replace_string(arg, "$NOR$", NOR);
	}
	
	if( me->is_busy())
		return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
		
	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("ָ���ʽ��buy <ĳ��> from <ĳ��>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("��Ҫ��˭������\n");

	if( userp(owner) ) {
		message_vision("$N����$n����" + item + "����\n", me, owner);
		return 1;
	}

	if (sizeof(all_inventory(me))>=26)
		return notify_fail("���Ѿ�����̫�ණ���ˣ�\n");

	// ������������һ���ɵ��õ��жϣ�����˵����������ϲ������ˣ����鲻�ò��������ˡ�������
	if (!owner->legit_buyer(me))
		return notify_fail(owner->name()+"��Ը�����������ס�\n");

/*	if (me->query_temp("timer/buy")+2 > time())
		return notify_fail(owner->name()+"��Ц�������͹��Ժ����Ͼ����к�����\n");
	me->set_temp("timer/buy",time());*/
				
	if( (price = owner->buy_object(me, item)) < 1 )
		return notify_fail("�Է�����û������Ҫ�Ķ�����\n");

	if( afford = MONEY_D->affordable(me, price) ) {
		if(owner->compelete_trade(me, item) ) {
			if (me->query("env/e_money")) {
				MONEY_D->charge_him(me,price);
			} else
			{
				MONEY_D->pay_him(me, afford-price);
			}
			owner->add("richness",price);
		} else 
			return notify_fail("����û�����ɡ�\n");
		
		return 1;
	} else
		return notify_fail("���Ǯ������\n");
}

int help(object me)
{
   write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	buy <something> from <someone>[0m
[0;1;37m����������������������������������������������������������������[0m   

��һָ��������Դ��̷���������Ʒ��

�����ʹ��Ӣ��ID���������֡�����˵С����waiter��������һ��
ţƤ�ƴ���jiudai�������������Ϊ��
buy jiudai from waiter

������������Ʒ����ɫ��ô���أ���������¹���

buy <��ɫ����><��Ʒ����>$NOR$ from <someone>

<��ɫ����>

$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ            $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ

����˵��Ҫ��waiter������һ��[1;32m���콣��[0m
����Ϊ ��
buy $HIG$���콣��$NOR$ from waiter

[0;1;37m����������������������������������������������������������������[0m   

HELP
   );
   return 1;
}

/*
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

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

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

*/
